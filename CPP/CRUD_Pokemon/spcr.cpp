#include <iostream>
#include <string>
#include <stdlib.h>
#include "spcr.h"


using namespace std;

int main(){
	char respuesta;
	Spcr sistema;
	cout<<"hola"<<endl;
	sistema.bienvenida();
	cin>>respuesta;
	while (cin.fail()){
		cin.clear();
		cin.ignore(100,'\n');
		cerr<<"fallo al insertar datos intentelo otra vez"<<endl;
		cin>>respuesta;
				
	}
	if(respuesta=='s' || respuesta=='s'){
		sistema.importarFichero();
		sistema.autentificacion();
		cout<<"autentificacion correcta"<<endl;
		
		sistema.menuPrincipal();
		
	}
	else{
	cout<<"añadiendo usuarios , pokemon y habilidades de forma prederminada"<<endl;
	//sistema.anadir();
	
	
	}
}
