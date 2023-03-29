#include<iostream>
using namespace std;

#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"

#define F_BLACK_COLOR "\033[1;40m"
#define F_RED_COLOR "\033[1;41m"
#define F_GREEN_COLOR "\033[1;42m"
#define F_YELLOW_COLOR "\033[1;43m"
#define F_BLUE_COLOR "\033[1;44m"
#define F_PURPLE_COLOR "\033[1;45m"
#define F_CYAN_COLOR "\033[1;46m"
#define F_WHITE_COLOR "\033[1;47m"

#define NORMAL "\033[0m"

struct alumno{
	string nombre;
	int nivel;
	string curso;
	int notas[5];
};
/******************
*declaramos los set y los get
@brief los set son funciones que se encargan de assinar el valor X al miembro Y de una estrucutra 
@biref los get son funcione que se encargar de obtener el valor Z del miembro Y de una estrucutra
@param los set necesitan una estrucutra a la que acceder
@param los get necesitan la estrucutra a la que se le va a cambiar el valor y el valor asignado 
********************/
string getNombre(const alumno &alumnox){
	return alumnox.nombre;
}
int  getNivel(const alumno &alumnox){
	return alumnox.nivel;
}
string getCurso(const alumno &alumnox){
	return alumnox.curso;
}
int  getNotas(const alumno &alumnox,int i){

	return alumnox.notas[i];
}
void setNombre(alumno &alumnox,string nuevo_valor){
	alumnox.nombre=nuevo_valor;
}
void setNivel(alumno &alumnox,int  nuevo_valor){
	alumnox.nivel=nuevo_valor;
}
void setCurso(alumno &alumnoX,string nuevo_valor){
	alumnoX.curso=nuevo_valor;
}
void setNotas(alumno &alumnoX,int nuevo_valor,int i){
	alumnoX.notas[i]=nuevo_valor;
}
//fin de declaracion de los set y los get
/*
@biref este modulo se encarga de mostrar por pantalla una estrucutra de tipo alumno 
@pre tendremos que tener una estrucutra de tipo alumno valida
@param estrucutra de tipo alumno
*/
void mostrar(alumno &alumnoX){
	cout<<BLUE_COLOR <<"nombre: "<<alumnoX.nombre<<NORMAL<<endl;
	cout<<YELLOW_COLOR<<"curso: "<<alumnoX.curso<<NORMAL<<endl;
	cout<<PURPLE_COLOR<<"nivel: "<<alumnoX.nivel<<NORMAL<<endl;
	cout<<RED_COLOR<<"notas: "<<endl;
	for(int i=0;i<5;i++){
		cout<<alumnoX.notas[i]<<" ";
	}
	cout<<endl<<NORMAL;
}
int main(){
	alumno alumno1={"jose Perez",1,"dam",{1,2,3,4,5}};
	string datoS;
	int datoI;
	alumno alumno2;

	setNombre(alumno2,getNombre(alumno1));
	setCurso(alumno2,getCurso(alumno1));
	setNivel(alumno2,getNivel(alumno1));
	for(int i=0;i<5;i++){
		setNotas(alumno2,getNotas(alumno1,i),i);
	}
	mostrar(alumno1);
	cout<<"segundo alumno "<<endl;
	mostrar(alumno2);
	cout<<"----------parte2-------"<<endl;

	cout<<F_GREEN_COLOR <<"dime un nombre"<<endl;
	getline (cin,datoS);
	setNombre(alumno1,datoS);
	setNombre(alumno2,getNombre(alumno1));
	
	cout<<"dime un curso"<<endl;
	cin.clear();
	getline (cin,datoS);
	setCurso(alumno1,datoS);
	setCurso(alumno2,getCurso(alumno1));
	
	cout<<"dime un Nivel"<<endl;
	cin.clear();
	cin>>datoI;
	setNivel(alumno1,datoI);
	setNivel(alumno2,getNivel(alumno1));
	
	for(int i=0;i<5;i++){
		cout<<"dime la nota "<<i<<endl;
		cin>>datoI;
		setNotas(alumno1,datoI,i);
		setNotas(alumno2,datoI,i);
	}
	cout<<NORMAL;

	mostrar(alumno1);
	cout<<"segundo alumno "<<endl;
	mostrar(alumno2);
}
