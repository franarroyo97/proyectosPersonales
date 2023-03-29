'''
Created on 19 may. 2018

@author: Fnac
'''
#!/usr/bin/python
# -*- coding: utf-8 -*-
 
# Ejemplo cliente - servidor en python
# Programa Servidor
# www.elfreneticoinformatico.com


#Importacines:
import threading
import socket #utilidades de red y conexion
import sys
import server
from server import BaseDeDatos, protocolo
import string


def clientef( cliente, direccion,logDelChat):
    try:
        datoss= list()
    
        print("Conexion establecida con %s:%s" %(direccion[0], direccion[1]))
        
        datos = cliente.recv(1024)
        datos = datos.decode()
        datoss.append(datos)
     
    
        print(datos) 
        t = threading.Thread(target= protocolo.Ptrotoclo, args=(datos,cliente,bd,logDelChat))
        t.start()
        datos = ""
            
    except:
        print ("exeptcion de conexion con el cliente: ",direccion[0], sys.exc_info()[0])


ip = "192.168.1.133"
puerto = 777
dataConection = (ip, puerto)
conexionesMaximas = 20

#Creamos el servidor.
#socket.AF_INET para indicar que utilizaremos Ipv4
#socket.SOCK_STREAM para utilizar TCP/IP (no udp)
socketServidor = socket.socket(socket.AF_INET,socket.SOCK_STREAM)


socketServidor.bind(dataConection) #Asignamos los valores del servidor
socketServidor.listen(conexionesMaximas) 
hebras = list()
print("conectando con la base de datos")


print("Conectado con la bd")
try:
    bd=BaseDeDatos.bdon("localhost", "root", "", "proyectofindecurso")
except:
    print ("error al conectar con la base de datos No se puede continuar...", sys.exc_info()[0])
    sys.exit()
try:
    print("Esperando conexiones en %s:%s" %(ip, puerto))
    logDelChat  = list()
    while True:
        cliente, direccion = socketServidor.accept()
        thr = threading.Thread(target=clientef,args=(cliente,direccion,logDelChat))
        thr.start()
except:
    print("desconexion detectada") 
