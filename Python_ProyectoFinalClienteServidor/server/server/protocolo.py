'''
Created on 27 may. 2018

@author: Fnac
'''
from server import BaseDeDatos
import os;
import sys;
from _codecs import decode
import datetime
logDelChat=list();
def get_size(the_path):
    """Get size of a directory tree or a file in bytes."""
    
    path_size = 0
    for path, directories, files in os.walk(the_path):
        for filename in files:
            path_size += os.lstat(os.path.join(path, filename)).st_size
        for directory in directories:
            path_size += os.lstat(os.path.join(path, directory)).st_size
    path_size += os.path.getsize(the_path)
    return path_size
def Ptrotoclo(peticion,cliente,bd,logDelChat):
    print("peticion -> "+peticion)
    arrayMensage = peticion.split("#")
    respuesta =""
    
    if(arrayMensage[1] =="login"):
       
        usuario = arrayMensage[2]
        contrasena = arrayMensage[3]
        
        if( BaseDeDatos.login(usuario, contrasena,bd)):
            respuesta="protocolo#login_ok"
            print("log");
        else:
            respuesta="protocolo#login_no"
        cliente.send(str.encode(respuesta))
    if(arrayMensage[1] =="registro"):
        usuario = arrayMensage[2]
        contrasena = arrayMensage[3]
        descripcion=arrayMensage[4]
        ruta="d";
        ruta= "datos/img/"+usuario+"/";
        
        if( BaseDeDatos.UpdateRegistrarUsuario(usuario, contrasena, descripcion,bd)):
            if not os.path.isdir(ruta):
                    os.makedirs(ruta)
            respuesta="protocolo#user_Registrado#imaen?"
            cliente.send(str.encode(respuesta))
            msg="";
            
            msg= cliente.recv(1024)
            msgAcom=msg
            while (msg != b'FINDETRANSMISION'):
               
                    msg= cliente.recv(1024)
                    if(msg !=b'FINDETRANSMISION'):
                        msgAcom += msg
                 
                    print(msg)    
            print("imagen transmitda")
            fecha = str(datetime.datetime.now().isoformat())
            fecha=fecha.replace(':', '_')
            fecha= fecha.replace('.', '-')
            print("fecha:"+fecha)
            rutaImg="C:/Users/Fnac/eclipse-workspace/server/server/"+ruta+fecha+".jpg"
            BaseDeDatos.UpdateRutaImg(usuario, rutaImg, bd)
            file = open(rutaImg,"wb")
            file.write(msgAcom.strip())
            print("imagen escrita")
        else:
            respuesta="protocolo#user_No_Registrado"
            cliente.send(str.encode(respuesta))
    if(arrayMensage[1] =="conectar"): 
        print("conexion") 
        usuario = arrayMensage[2]
        BaseDeDatos.UpadateUsuarioConectado(usuario, bd)
        respuesta="protocolo#user_conectado"
        cliente.send(str.encode(respuesta))
    if(arrayMensage[1] =="desconectar"):  
        usuario = arrayMensage[2]
        BaseDeDatos.UpdateUsuarioDesconectado(usuario, bd)
        respuesta="protocolo#user_desconectado"
        cliente.send(str.encode(respuesta))
    if(arrayMensage[1] == "GetUsuariosConectadsos"):
        usuariosYrutas = BaseDeDatos.getUsuariosConectados(bd)
        contadorRutas=0
        contadorUsuarios=0
        while len(usuariosYrutas[0]) > contadorUsuarios:
            relleno ='0'
            mensaje = str(usuariosYrutas[0][contadorUsuarios])  
            while len(mensaje) != 1024:
                mensaje += str(relleno)
            cliente.send(str.encode(mensaje))
            print(usuariosYrutas [0][contadorUsuarios])
            mensage = "#protocolo#tamImg#"+str(get_size(usuariosYrutas[1][contadorRutas]));
            print("longuitud:"+str(get_size(usuariosYrutas[1][contadorRutas])))
            while len(mensage) != 1024:
                mensage +='u' 
            cliente.send(str.encode(mensage));
            print(mensage)
            file=open( usuariosYrutas[1][contadorRutas],'rb')
            paquete = file.read(1024)
            while paquete != b'': 
                print(paquete)
                
                cliente.send(paquete)
                    
                paquete = file.read(1024)
            
                
                                
            print("NV:fin de imagen")
            
            contadorUsuarios +=1
            contadorRutas +=1
        relleno ='0'
        mensaje = "fin de transmision"         
        while len(mensaje) != 1024:
            mensaje +=str(relleno)
        print("fin de transms")
        cliente.send(str.encode(mensaje))  
    if(arrayMensage[1] == "gethistoria") :
        historia =  BaseDeDatos.getHistorias(arrayMensage[2],bd)  
        paquete = "protocolo#histoira#"+historia
        print("hitoria:"+paquete)
        cliente.send(str.encode(paquete))
    if(arrayMensage[1]== "mensajePoraElChat"):
        logDelChat.append(arrayMensage[2])
      
    if(arrayMensage[1]== "getLogDelChat"):  
        respuesta = "protocolo#envlog"
        for i in logDelChat:
            respuesta+="#"+i
            
        cliente.send(str.encode(respuesta))   
        print(respuesta)
    if(arrayMensage[1]=="GetAllUsuarios"):
        usuariosYrutas = BaseDeDatos.getAllUsuarios(bd)
        contadorRutas=0
        contadorUsuarios=0
        while len(usuariosYrutas[0]) > contadorUsuarios:
            relleno ='0'
            mensaje = str(usuariosYrutas[0][contadorUsuarios])  #lo del relleno es por que en c# se le de x en x bytes en mi caso 1024 si envio menos descuardo el indice por lo que los mensajes se desordenan 
            while len(mensaje) != 1024:
                mensaje += str(relleno)
            cliente.send(str.encode(mensaje))
            print(usuariosYrutas [0][contadorUsuarios])
            mensage = "#protocolo#tamImg#"+str(get_size(usuariosYrutas[1][contadorRutas]));
            print("longuitud:"+str(get_size(usuariosYrutas[1][contadorRutas])))
            while len(mensage) != 1024:
                mensage +='u' 
            cliente.send(str.encode(mensage));
            print(mensage)
            file=open( usuariosYrutas[1][contadorRutas],'rb')
            paquete = file.read(1024)
            while paquete != b'': 
                print(paquete)
                
                cliente.send(paquete)
                    
                paquete = file.read(1024)
            
                
                                
            print("NV:fin de imagen")
            
            contadorUsuarios +=1
            contadorRutas +=1
        relleno ='0'
        mensaje = "fin de transmision"         
        while len(mensaje) != 1024:
            mensaje +=str(relleno)
        print("fin de transms")
        cliente.send(str.encode(mensaje)) 
    if(arrayMensage[1]=="PeticionDeAmistad"):
        BaseDeDatos.upadatePeticionDeAmistad(arrayMensage[2], arrayMensage[3], bd)
    if(arrayMensage[1]=="getPeticionesDeAmistadSinAtender"):
        usuariosSinAtender =list()
        usuariosSinAtender= BaseDeDatos.getPeticionesSinAtendender(arrayMensage[2] ,bd)
        respuesta = "#protoclo#tusPeticiones"
        for i in usuariosSinAtender:
            respuesta+="#"+i  
        print(respuesta)
        cliente.send(str.encode(respuesta))
    if(arrayMensage[1]=="aceptarAmistad"):
        BaseDeDatos.UpadateAceparAmistad(arrayMensage[2],arrayMensage[3],bd)
    if(arrayMensage[1]=="subirImagen"):
        usuario = arrayMensage[2]
        ruta= "datos/img/"+usuario+"/";
        if( True):
            if not os.path.isdir(ruta):
                    os.makedirs(ruta)
            respuesta="protocolo#ImagenInsertadaEnTabla#imagen?"
            cliente.send(str.encode(respuesta))
            msg="";
            
            msg= cliente.recv(1024)
            msgAcom=msg
            while (msg != b'FINDETRANSMISION'):
               
                    msg= cliente.recv(1024)
                    if(msg !=b'FINDETRANSMISION'):
                        msgAcom += msg
                 
                    print(msg)    
            print("imagen transmitda")
            fecha = str(datetime.datetime.now().isoformat())
            fecha=fecha.replace(':', '_')
            fecha= fecha.replace('.', '-')
            print("fecha:"+fecha)
            rutaImg="C:/Users/Fnac/eclipse-workspace/server/server/"+ruta+fecha+".jpg"
            BaseDeDatos.UpdateGuardarImagen(usuario,rutaImg,bd)
            file = open(rutaImg,"wb")
            file.write(msgAcom.strip())
            print("imagen escrita")
    if(arrayMensage[1]=="GetFotos"):
        usuariosYrutas = BaseDeDatos.getImagenesDeUnUsario(bd,arrayMensage[2])
        contadorRutas=0
        contadorUsuarios=0
        while len(usuariosYrutas[0]) > contadorUsuarios:
            relleno ='0'
            mensaje = str(usuariosYrutas[0][contadorUsuarios])  
            while len(mensaje) != 1024:
                mensaje += str(relleno)
            cliente.send(str.encode(mensaje))
            print(usuariosYrutas [0][contadorUsuarios])
            mensage = "#protocolo#tamImg#"+str(get_size(usuariosYrutas[1][contadorRutas]));
            print("longuitud:"+str(get_size(usuariosYrutas[1][contadorRutas])))
            while len(mensage) != 1024:
                mensage +='u' 
            cliente.send(str.encode(mensage));
            print(mensage)
            file=open( usuariosYrutas[1][contadorRutas],'rb')
            paquete = file.read(1024)
            while paquete != b'': 
                print(paquete)
                
                cliente.send(paquete)
                    
                paquete = file.read(1024)
            
                
                                
            print("NV:fin de imagen")
            
            contadorUsuarios +=1
            contadorRutas +=1
        relleno ='0'
        mensaje = "fin de transmision"         
        while len(mensaje) != 1024:
            mensaje +=str(relleno)
        print("fin de transms")
        cliente.send(str.encode(mensaje)) 
    if(arrayMensage[1]=="GetFotosDeMisAmigos"):
        usuariosYrutas = BaseDeDatos.getImagenesDeAmigos(bd,arrayMensage[2])
        contadorRutas=0
        contadorUsuarios=0
        if(len(usuariosYrutas) >0):
            while len(usuariosYrutas[0]) > contadorUsuarios:
                relleno ='0'
                mensaje = str(usuariosYrutas[0][contadorUsuarios])  
                while len(mensaje) != 1024:
                    mensaje += str(relleno)
                cliente.send(str.encode(mensaje))
                print(usuariosYrutas [0][contadorUsuarios])
                mensage = "#protocolo#tamImg#"+str(get_size(usuariosYrutas[1][contadorRutas]));
                print("longuitud:"+str(get_size(usuariosYrutas[1][contadorRutas])))
                while len(mensage) != 1024:
                    mensage +='u' 
                cliente.send(str.encode(mensage));
                print(mensage)
                file=open( usuariosYrutas[1][contadorRutas],'rb')
                paquete = file.read(1024)
                while paquete != b'': 
                    print(paquete)
                    
                    cliente.send(paquete)
                        
                    paquete = file.read(1024)
                
                    
                msg = str(usuariosYrutas[2][contadorUsuarios])
                while len(msg ) != 1024:
                    msg +='0'
                cliente.send(str.encode(msg))             
                print("NV:fin de imagen")
                
                contadorUsuarios +=1
                contadorRutas +=1
        relleno ='0'
        mensaje = "fin de transmision"         
        while len(mensaje) != 1024:
            mensaje +=str(relleno)
        print("fin de transms")
        cliente.send(str.encode(mensaje)) 
        return respuesta
    if(arrayMensage[1]=="comentar"):
        BaseDeDatos.InsertComentario(arrayMensage[2],arrayMensage[3],arrayMensage[4],bd)
    if(arrayMensage[1]=="getComentarios"):
        usuariosYcomentarios=  BaseDeDatos.getcomentarios(arrayMensage[2],bd)
        cont=0
        msg="protocolo#envComentarios"
        for I in usuariosYcomentarios[0]:
            msg+="#"+usuariosYcomentarios[1][cont]+"#"+I
        cliente.send(str.encode(msg))
    if(arrayMensage[1]=="enviarBoto"):
        BaseDeDatos.enviarBoto(arrayMensage[2],arrayMensage[3],arrayMensage[4],bd)
    if(arrayMensage[1]=="getPuntuacion"):
        puntos=BaseDeDatos.getPuntos(arrayMensage[2],bd)
        msg="protocolo#envPuntos"
        for i in puntos:
            msg += "#"+str(i)
        print(msg)
        cliente.send(str.encode(msg))