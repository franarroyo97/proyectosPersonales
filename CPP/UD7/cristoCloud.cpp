#include <iostream>
#include <stdlib.h>
using namespace std;
//declracion de estructuras
struct Fichero{
	string ruta;
	string tipo;
	unsigned long int tamanio;// se guarda en bytes
};
struct Usuario {
	string login;
	string nombre;
	string apellido;
	string perfil_usuario;
	Fichero *v_ficherosusuarios;//apunta a un dato del tipo Fichero declarado en la linea 1
	int dim_vficheros;//dimension del vector
	int totalficherosusuario;//utiles del vector
};
struct Tablausuarios{
	Usuario** punteroapuntero; // usuarios va a ser reservado de forma dinamica por esto este puntero a usuarios es un puntero a puntero (estructura declarada en la liena 7)
	int totaltuplas;//son las tuiles de la tabla usuario que simpre seran iguales a las utiles
};
//fin de declaracion de estructuras
//declaracion de los modulos set y get
string GetFicheroRuta(Fichero *fichero){
	return fichero->ruta;
}
string GetFicheroTipo(Fichero *fichero){
	return fichero->tipo;
}
unsigned long int GetFicheroTamanio(Fichero *fichero){
	return fichero->tamanio;
}
void SetFicheroRuta(Fichero *fichero,string ruta){
	fichero->ruta=ruta;	
}
void SetFicheroTipo(Fichero *fichero,string tipo){
	fichero->tipo=tipo;
}
void SetFicheroTamanio(Fichero *fichero,unsigned long int tamanioa){
	fichero->tamanio=tamanioa;

}
string GetUsuarioLogin(Usuario *usuario){
	return usuario->login;
}
string GetUsuarioNombre(Usuario *usuario){
	return usuario->nombre;
}
string GetUsuarioApellido(Usuario *usuario){
	return usuario->apellido;
}
string GetUsuarioPerfil_usuario(Usuario *usuario){
	return usuario->perfil_usuario;
}
Fichero GetUsuarioV_ficherosusuarios(Usuario *usuario,int pos){
	return usuario->v_ficherosusuarios[pos];
}
int GetUsuarioDim_vficheros(Usuario *usuario){
	return usuario->dim_vficheros;
}
int GetUsuarioTotalficherosusuario(Usuario *usuario){
	cout<<"entro en el get de total ficheros"<<endl;
	return usuario->totalficherosusuario;
	cout<<"salgo ..."<<endl;
}
void SetUsuarioLogin(Usuario *usuario,string login){
	usuario->login=login;
}
void SetUsuarioNombre(Usuario *usuario,string nombre){
	usuario->nombre=nombre;
}
void SetUsuarioApellido(Usuario *usuario,string apellido){
	usuario->apellido=apellido;
}
void SetUsuarioPerfil_usuario(Usuario *usuario,string perfil_usuario){
	usuario->perfil_usuario=perfil_usuario;
}
void SetUsuarioDim_vficheros(Usuario *usuario,int dim_vficheros){
	usuario->dim_vficheros=dim_vficheros;
}
void SetUsuarioTotalficherosusuario(Usuario *usuario,int totalficherosusuario ){
	usuario->totalficherosusuario=totalficherosusuario;
}
Usuario ** GetTablausuariosUsuario(Tablausuarios *tablausuarios){
	return tablausuarios->punteroapuntero;
}
int GetTablausuariosTotaltuplas(Tablausuarios *tablausuarios){
	return tablausuarios->totaltuplas;
}
void SetTablausuariosusuario(Tablausuarios *tabla,Usuario** usuario){
	tabla->punteroapuntero=usuario;
}
void SetTablausuariosTotaltuplas(Tablausuarios *tabla,int totaltuplas){
	tabla->totaltuplas=totaltuplas;
}
//fin de declaracion de los modulos set y get 
Fichero* CreateFichero(string ruta,string tipo,unsigned long int tamanio){
	Fichero* f=new Fichero;
	if (f==0){
		cerr<<"fallo al asignar la memoria"<<endl;
		exit(-1);
	}
	cout<<"entro en los set de createfichero"<<endl;
	SetFicheroRuta(f,ruta);
	SetFicheroTipo(f,tipo);
	SetFicheroTamanio(f,tamanio);
	cout<<"salgo de los set de cretate fichero"<<endl;
	return f;
}
void DropFichero(Fichero *f){
	delete f;
	f=0;
}
Usuario* CreateUsuario(string login,string nombre,string apellido,string perfil_usuario,int dim_vficheros){
	Usuario *u= new Usuario;
	if (u==0){
		cerr<<"ERROR.no hay memoria suficiente se abortara la ejeucion"<<endl;
		exit(-1);
	}
	SetUsuarioLogin(u,login);
	SetUsuarioNombre(u,nombre);
	SetUsuarioApellido(u,apellido);
	SetUsuarioPerfil_usuario(u,perfil_usuario);
	SetUsuarioDim_vficheros(u,dim_vficheros);
	SetUsuarioTotalficherosusuario(u,0);
	return u;
}
void DropUsuario(Usuario *u){
	delete [] u->v_ficherosusuarios;
	delete u;
}
void PrintFichero(Fichero *fichero){
	cout<<"DATOS DEL FICHERO:"<<GetFicheroRuta(fichero)<<endl ;
	cout<<" tipo:"<<GetFicheroTipo(fichero)<<endl;
	cout<<"tamaño:"<<GetFicheroTamanio(fichero)<<endl;

}
void PrintUsuario(Usuario *usuario){
	cout<<"login: "<<GetUsuarioLogin(usuario)<<endl;
	cout<<"nombre: "<<GetUsuarioNombre(usuario)<<endl;
	cout<<"apellido: "<<GetUsuarioApellido(usuario)<<endl;
	cout<<"peril_usuario: "<<GetUsuarioPerfil_usuario(usuario)<<endl;
	cout<<"maximo de ficheros: "<<GetUsuarioTotalficherosusuario(usuario)<<endl;
	cout<<"ficheros almezenados: "<<GetUsuarioDim_vficheros(usuario)<<endl;
}
	
void SetUsuarioV_ficherosusuarios(Usuario *usuario,Fichero *V_ficherosusuarios,int pos){//pos son las utiles
	if(pos<GetUsuarioTotalficherosusuario(usuario)){
			
		usuario->v_ficherosusuarios[pos]=*V_ficherosusuarios;
		SetUsuarioDim_vficheros(usuario,GetUsuarioDim_vficheros(usuario)+1);
	}
	else 
		cout<<"hay que redimensonar"<<endl;

}
void deleteFicherodeUsuario(Fichero file,Usuario *u){
	//SetUsuarioV_ficherosusuarios(u,NULL,&file);
}
int main(){
	int  opcion=1;
	Fichero *ptrf=0;
	Usuario *ptru=0;
	switch(opcion){
		case 1:
			ptrf=CreateFichero("/usuario/hola.txt",".TXT",1024);
			PrintFichero(ptrf);
			cout<<"direccion del fichero"<<ptrf<<endl;
			DropFichero(ptrf);
			cout<<"direccion del fichero"<<ptrf<<endl;
			PrintFichero(ptrf);
			ptru=CreateUsuario("usuario1","pepe","suarez","admin",1);
			cout<<"hora el total de fiichros usuario es "<<GetUsuarioTotalficherosusuario(ptru);
			SetUsuarioTotalficherosusuario(ptru,10);
			cout<<"hora el total de fiichros usuario es "<<GetUsuarioTotalficherosusuario(ptru);
			PrintUsuario(ptru);
			
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		default:
			cerr<<"opcion no contemplada usted a introducido "<<opcion<<endl;
	}
}
