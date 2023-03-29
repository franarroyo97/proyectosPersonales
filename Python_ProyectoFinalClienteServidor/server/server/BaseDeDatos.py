'''
Created on 19 may. 2018

@author: Fnac
'''
import pymysql
import sys
import array

def bdon (ip,usuario,contrasna,tabla): 
    db = pymysql.connect(ip,usuario,contrasna,tabla)
  
    return db

def UpdateRegistrarUsuario(usuario,contrasena,des,db):
    cursor= db.cursor()
    consulta= "INSERT INTO usuarios (usuario ,contrasena ,InformacionGeneral ,rutaImagenPrincipal) VALUES ('%s' , '%s' , '%s','nada')"  % \
    (  usuario ,contrasena ,des)
    try:
        cursor.execute(consulta)
        db.commit()
        return True
    except :
        print( sys.exc_info()[1])
        return False;
def UpdateRutaImg(usuario , ruta,db):
    cursor= db.cursor()
    consulta= "UPDATE usuarios SET rutaImagenPrincipal = '%s' WHERE usuario ='%s' "  % \
    (  ruta ,usuario )
    try:
        cursor.execute(consulta)
        db.commit()
        return True
    except :
        print( sys.exc_info()[1])
        return False;
def UpadateUsuarioConectado(usuario,db):
    cursor= db.cursor()
    consulta= "UPDATE usuarios SET conectado = '1' WHERE usuario ='%s' "  % \
    (  usuario )
    try:
        cursor.execute(consulta)
        db.commit()
        return True
    except :
        print( sys.exc_info()[1])
        return False;
def UpdateUsuarioDesconectado(usuario,db):
    cursor= db.cursor()
    consulta= "UPDATE usuarios SET conectado = '0' WHERE usuario ='%s' "  % \
    (  usuario )
    try:
        cursor.execute(consulta)
        db.commit()
        return True
    except :
        print( sys.exc_info()[1])
        return False;
def login(usuario,contrasena,db):
    cursor= db.cursor()
    consulta= "SELECT * FROM usuarios WHERE usuario ='%s' AND contrasena ='%s'" % \
    (  usuario ,contrasena )
    cursor.execute(consulta)
    registro = cursor.fetchone()
    respuesta= False
    if (registro != None):
        respuesta=True
    else:
        respuesta=False
    return respuesta
def getUsuariosConectados(bd):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    lista = list()
    consulta= "SELECT * FROM usuarios WHERE conectado ='1' "
    cursor.execute(consulta)
    usuarios = list()
    rutas = list()
    for i in cursor:
        usuarios.append( i['usuario'])
        rutas.append( i['rutaImagenPrincipal'])
    lista.append(usuarios)
    lista.append(rutas)
    return lista
def getHistorias(usuario,bd):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    lista = list()
    consulta= "SELECT InformacionGeneral  FROM usuarios WHERE usuario  = '"+usuario+"'"
    cursor.execute(consulta)
    lista = list()
    for i in cursor:
        lista.append(i['InformacionGeneral'])
    return lista[0]
def getAllUsuarios(bd):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    lista = list()
    consulta= "SELECT * FROM usuarios "
    cursor.execute(consulta)
    usuarios = list()
    rutas = list()
    for i in cursor:
        usuarios.append( i['usuario'])
        rutas.append( i['rutaImagenPrincipal'])
    lista.append(usuarios)
    lista.append(rutas)
    return lista
def upadatePeticionDeAmistad(de,hacia,db):
    cursor= db.cursor()
    consulta= "INSERT INTO amistades (Usuario ,PeticionesDeAmistad,admitido  ) VALUES ('%s' , '%s' ,0)" % \
    (  de ,hacia )
    cursor.execute(consulta)
def getPeticionesSinAtendender(usuario,db):
    cursor= db.cursor(pymysql.cursors.DictCursor)
    consulta= "SELECT PeticionesDeAmistad  FROM amistades WHERE Usuario  = '"+usuario+"' AND admitido='0'"
   
    cursor.execute(consulta)
    lista = list()
    for i in cursor:
        lista.append(i['PeticionesDeAmistad'])
    return lista
def UpadateAceparAmistad(usuario,PeticionesDeAmistad,db):
    consulta= "UPDATE amistades SET admitido = '1' WHERE Usuario ='%s' AND PeticionesDeAmistad='%s' "  % \
    (  usuario ,PeticionesDeAmistad)
    
    cursor= db.cursor()
 
    try:
        cursor.execute(consulta)
        db.commit()
        return True
    except :
        print( sys.exc_info()[1])
        return False;
def UpdateGuardarImagen(usuario,ruta,db):
    cursor= db.cursor()
    consulta= "INSERT INTO imagenes (dueno ,ruta) VALUES ('%s' ,'%s')"  % \
    (  usuario ,ruta)
    try:
        cursor.execute(consulta)
        db.commit()
        return True
    except :
        print( sys.exc_info()[1])
        return False;
def getImagenesDeUnUsario(bd,usuario):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    lista = list()
    consulta= "SELECT * FROM imagenes WHERE dueno='"+usuario+"'"
    cursor.execute(consulta)
    usuarios = list()
    rutas = list()
    for i in cursor:
        usuarios.append( i['dueno'])
        rutas.append( i['ruta'])
        print(i['ruta'])  
    lista.append(usuarios)
    lista.append(rutas)
    return lista
def getImagenesDeAmigos(bd,usaurio):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    lista = list()
    consulta= "SELECT PeticionesDeAmistad FROM amistades WHERE Usuario='"+usaurio+"' AND admitido='1'"
    cursor.execute(consulta)
    amigos=list()
    ids=list()
    for I in cursor:
        amigos.append(I['PeticionesDeAmistad'])
    
    for I in amigos:
        consulta= "SELECT * FROM imagenes WHERE dueno='"+I+"'"
        cursor.execute(consulta)
        usuarios = list()
        rutas = list()
      
        for i in cursor:
            usuarios.append( i['dueno'])
            rutas.append( i['ruta'])
            ids.append(i['idImagen'])
            lista.append(usuarios)
            lista.append(rutas)
            lista.append(ids)
    return lista
def InsertComentario(id,comentario,usuario,bd):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    print(id)
    consulta= "SELECT ruta FROM imagenes WHERE idImagen='"+id+"'"
    cursor.execute(consulta)
    ruta=cursor.fetchone()
    ruta=ruta['ruta']
    print(ruta)
    consulta="INSERT INTO imagenescomentarios (ruta,comentario,cometarioDe ) VALUES ('%s','%s','%s')"  % \
    (  ruta,comentario,usuario)
    try:
        cursor.execute(consulta)
        bd.commit()
        return True
    except :
        print( sys.exc_info()[1])
        exit()
        return False;
def getcomentarios(id,bd):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    consulta= "SELECT ruta FROM imagenes WHERE idImagen='"+str(id)+"'"
    cursor.execute(consulta)
    ruta=cursor.fetchone()
    print(id)
    ruta=ruta['ruta']
    usuariosYcomantios= list()
    usuariosYcomantios.append(list())
    usuariosYcomantios.append(list())
    print(ruta)
    consulta="select comentario, cometarioDe from  imagenescomentarios WHERE ruta = '%s' "  % \
    (ruta)
    cursor.execute(consulta)
    for I in cursor:
        usuariosYcomantios[0].append(I['comentario'])
        usuariosYcomantios[1].append(I['cometarioDe'])
    return usuariosYcomantios
def enviarBoto(id,boto,usuario,bd):
    cursor= bd.cursor()
    consulta= "SELECT * FROM puntuacion WHERE  usuario ='%s'" % \
    (  usuario)
    cursor.execute(consulta)
    registro = cursor.fetchone()
    print(str(registro))
    if (registro == None): #no existe 
        consulta="INSERT INTO puntuacion (id,boto,usuario  ) VALUES ('%s','%s','%s')"  % \
        (  id,boto,usuario )
        try:
            cursor.execute(consulta)
            bd.commit()
            
        except :
            print( sys.exc_info()[1])
            exit()
            
    else: #ahora que se que este usuario ya boto tengo que ver si es un cambio de boto o es el mismo
        consulta= "SELECT boto FROM puntuacion WHERE usuario ='%s'" % \
        (  usuario)
        cursor.execute(consulta)
        botoEnBd=cursor.fetchone()
        if str(boto) != str(botoEnBd):
            consulta= "UPDATE puntuacion SET  boto ='%s'" % \
            (boto)
            cursor
            cursor.execute(consulta)
            bd.commit()
def getPuntos(id,bd):
    cursor= bd.cursor(pymysql.cursors.DictCursor)
    consulta= "SELECT boto FROM puntuacion WHERE id='"+str(id)+"'"
    print(id)
    cursor.execute(consulta)
    puntos=list()
   
    for I in cursor:
        puntos.append(I['boto'])
        
    return puntos