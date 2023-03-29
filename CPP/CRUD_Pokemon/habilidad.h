#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#ifndef habilidad_h
#define habilidad_h

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

class Habilidad {
	protected:
	int id;
	string nombre;
	int dano;
	int precio;
	int pp;
	string tipo;
	public:
	//CONSTRUCTORES y DESTRUCTORES
	Habilidad();
	Habilidad(int id,string nombre, int dano,int precio, int pp, string tipo);
	Habilidad(Habilidad &habilidad);
	~Habilidad();
	//MODULOS SET Y GET
	inline void SetId(int id){this->id=id;}
	inline void SetNombre(string nombre){this->nombre=nombre;}
	inline void SetDano(int dano){this->dano=dano;}
	inline void SetPrecio(int precio){this->precio=precio;}
	inline void SetPp(int pp){this->pp=pp;}
	inline void SetTipo(string tipo){this->tipo=tipo;}
	inline int GetId(){return this->id;}
	inline string GetNombre(){return this->nombre;}
	inline int GetDano(){return this->dano;}
	inline int GetPrecio(){return this->precio;}
	inline int GetPp(){return this->pp;}
	inline string GetTipo(){return this->tipo;}
	//SOBRECARGAS
	Habilidad& operator=(Habilidad &h);
	ostream& operator<<(ostream& flujo);//no se usa 
/**
@brief imprime por pantalla todos los valores actuales de una habilidad
@param ningua
@pre que exista el objeto 
@post ningua postcondicion
@return nada
@autor Francisco Arroyo Lopez
@ver 1.0
**/
	void print();
};
Habilidad::Habilidad(){
	cout<<"DEBUG: Constructor por defecto de habilidad "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetDano(0);
	this->SetPrecio(0);
	this->SetPp(0);
	this->SetTipo("");
	
}
Habilidad::Habilidad(int id,string nombre, int dano,int precio, int pp, string tipo){
	//cout<<"DEBUG: Constructor por parametros de habilidad "<<endl;
	this->SetId(id);
	this->SetNombre(nombre);
	this->SetDano(dano);
	this->SetPrecio(precio);
	this->SetPp(pp);
	this->SetTipo(tipo);
}
Habilidad::Habilidad(Habilidad &h){
	//cout<<"DEBUG: Constructor por copia de habilidad "<<endl;
	this->SetId(h.GetId());
	this->SetNombre(h.GetNombre());
	this->SetDano(h.GetDano());
	this->SetPrecio(h.GetPrecio());
	this->SetTipo(h.GetTipo());
	this->SetPp(h.GetPp());
	this->SetTipo(h.GetTipo());
}
Habilidad& Habilidad::operator=(Habilidad &h){
	if(this != &h){
		this->SetId(h.GetId());
		this->SetNombre(h.GetNombre());
		this->SetDano(h.GetDano());
		this->SetTipo(h.GetTipo());
		this->SetPp(h.GetPp());
		this->SetTipo(h.GetTipo());
	}
	return *this;
}
ostream& Habilidad::operator<<(ostream& salida){//no se usa 
	salida<<"\t \t id: "<<this->GetId()<<endl;
	salida<<"\t \t Nombre: "<<this->GetNombre()<<endl;
	salida<<"\t \t daño: "<<this->GetDano()<<endl;
	salida<<"\t \t Tipo"<<this->GetTipo()<<endl;
	salida<<"\t \t PP: "<<this->GetPp()<<endl;
	salida<<"\t \t Tipo: "<<this->GetTipo()<<endl;
	return salida;
}
Habilidad::~Habilidad(){
	cout<<"DEBUG:destructor de habilidad "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetDano(0);
	this->SetPp(0);
	this->SetTipo("");
}
void Habilidad::print(){
	cout<<PURPLE_COLOR;
	cout<<"\t \t id: "<<this->GetId()<<endl;
	cout<<"\t \t Nombre: "<<this->GetNombre()<<endl;
	cout<<"\t \t daño: "<<this->GetDano()<<endl;
	cout<<"\t \t PP: "<<this->GetPp()<<endl;
	cout<<"\t \t Tipo: "<<this->GetTipo()<<endl<<endl;
	cout<<NORMAL;
}
#endif