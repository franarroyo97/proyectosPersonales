#include<iostream>
#include <string>
#include <stdlib.h>
#include "habilidad.h"
#include <typeinfo>
#include<cmath>
using namespace std;
#ifndef pokemon_h
#define pokemon_h
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
class Pokemon {
	protected:
	int id;
	string nombre;
	int vida;
	int ataque;
	int defensa;
	int velocidad;
	int precio;
	int precioCurar;
	Habilidad* vectorHabildades;
	int totalHabilidades;
	public:
	//constructore y destructores
	Pokemon();
	Pokemon(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar);
	Pokemon(Pokemon &Pokemon);
	~Pokemon();
	//set y get
	inline void SetId(int id){this->id=id;}
	inline void SetNombre( string nombre) {this->nombre=nombre;}
	inline void SetVida(int vida) {this->vida=vida;}
	inline void SetAtaque(int ataque) {this->ataque=ataque;}
	inline void SetDefensa(int defensa) {this->defensa=defensa;}
	inline void SetVelocidad(int velocidad) {this->velocidad=velocidad;}
	inline void SetPrecio(int precio){this->precio=precio;}
	inline void SetPrecioCurar(int precioCurar){this->precioCurar=precioCurar;}
	inline void SetVectorHabilidades(Habilidad * habilidad){this->vectorHabildades=habilidad;}
	inline void SetVectorHabilidadesPos(int i,Habilidad habilidad){this->vectorHabildades[i]=habilidad;}
	inline void SetTotalHabilidades(int totalHabilidades){this->totalHabilidades=totalHabilidades;}
	inline int GetId(){return this->id;}
	inline string GetNombre(){return this->nombre;}
	inline int GetVida(){return this->vida;}
	inline int GetAtaque(){return this->ataque;}
	inline int GetDefensa(){return this->defensa;}
	inline int GetVelocidad(){return this->velocidad;}
	inline int GetPrecio(){return this->precio;}
	inline int GetPrecioCurar(){return this->precioCurar;}
	inline Habilidad * GetVectorHabilidades(){return this->vectorHabildades;}
	inline Habilidad  GetVectorHabilidadesPos(int i){return this->vectorHabildades[i];}
	inline int GetTotalHabilidades(){return this->totalHabilidades;}
	//sobrecarga de opreades
	Pokemon& operator=(Pokemon &poke);
	ostream& operator<<(ostream& flujo);//no se usa 
	/**
	@brief imprime un pokemon con sus habilidades
	@param nada
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	
	**/
	virtual void print();
	/**
	@brief añade una habilidad a el pokemon
	@param Habilidad *h
	@pre que la habilidad exista
	@post la habilidad es añadida a un pokemon
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	
	**/
	void AnadirHabilidad(Habilidad *h);
	/**
	@brief permite borrar una habilidad de un pokemon que ocupe en el vector la poscion que se le pase por parametros
	@param int pos
	@pre que la habilidad exista
	@post la habilidad es borrada
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	void jugarBatalla();
	void exportarFichero();
	**/
	void BorrarHabilidad(int pos);
	/**
	@brief permite borrar una habilidad de un pokemon que ocupe en el vector la poscion que se le pase por parametros
	@param int pos,Pokemon *p
	@pre que la habilidad exista
	@post la habilidad es borrada
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	void jugarBatalla();
	void exportarFichero();
	**/
	void UsarHabilidad(int pos,Pokemon *p);
	/**
	@brief cura un pokemon es deicr establece su salud a 100
	@param int pos,Pokemon *p
	@pre que la habilidad exista
	@post la habilidad es borrada
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void curacion();
	/**
	@brief meto virtual que es definido tambien en todas sus clases hijas (Poekemonagua ,pokemonFuego Y pokemonPlanta) calcula el daño segun el pokemon del que reciba el ataque
	@param Pokemon * riva
	@pre ninguna
	@post el pokemon resibe daño
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	virtual void recibirDanoDePokemon(Pokemon * rival,int i){};
	/**
	@brief sube el nivel de un pokemon multiplicadno sus atributos
	@param ninguna
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void subirNivel();
	/**
	@brief calcula el precio de un pokemon segun una froma predeterminada
	@param ninguna
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void CalcularPecio();
	/**
	@brief calcula el precio que va tener un una curacion de un pokemon
	@param ninguna
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void CalcularPecioCuracion();
	
};
///////POKEMON DE TIPO AGUA
class PokemonAgua : public Pokemon {
	protected:
	double nivelAgua;
	public:
	PokemonAgua();
	PokemonAgua(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar,
	double nivelAgua );
	PokemonAgua(PokemonAgua &PokemonAgua);
	~PokemonAgua();
	inline void SetNivelAgua(double nivelAgua){this->nivelAgua=nivelAgua;}
	inline double GetNivelAgua(){return this->nivelAgua;}
	
	void print();
	
	void recibirDanoDePokemon(Pokemon * rival,int i);
};
PokemonAgua::PokemonAgua(){
	cout<<"DEBUG: constructor por defecto de pokemonAgua "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVectorHabilidades(NULL);
	this->SetVelocidad(0);
	this->SetTotalHabilidades(0);
	this->SetNivelAgua(0);
	
}
PokemonAgua::PokemonAgua(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar,
	double nivelAgua){
		
	this->SetId(id);
	this->SetNombre(nombre);
	this->SetVida(vida);
	this->SetAtaque(ataque);
	this->SetDefensa(defensa);
	this->SetVelocidad(velocidad);
	this->SetVectorHabilidades(new Habilidad[0]);
	this->SetTotalHabilidades(0);
	this->SetPrecio(precio);
	this->SetPrecioCurar(precioCurar);
	this->SetNivelAgua(nivelAgua);
}
PokemonAgua::~PokemonAgua(){
	cout<<"destructor de pokemon agua"<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVelocidad(0);
	if(this->GetTotalHabilidades() !=0 ){
	    delete [] this->vectorHabildades;
	}
	//this->SetVectorHabilidades(NULL);
	this->SetTotalHabilidades(0);
	this->SetNivelAgua(0);
	
}
void PokemonAgua::print(){
	cout<<GREEN_COLOR; 
	cout<<"\t id: "<<this->GetId()<<endl;
	cout<<"\t nombre: "<<this->GetNombre()<<endl;
	cout<<"\t vida: "<<this->GetVida()<<endl;
	cout<<"\t ataque: "<<this->GetAtaque()<<endl;
	cout<<"\t defensa: "<<this->GetDefensa()<<endl;
	cout<<"\t velocidad: "<<this->GetVelocidad()<<endl;
	cout<<"\t precio: "<<this->GetPrecio()<<endl;
	cout<<"\t precioCurar: "<<this->GetPrecioCurar()<<endl;
	cout<<"\t nivelAgua: "<<this->GetNivelAgua()<<endl;
	cout<<"\t HABILIDADADES == total:"<<GetTotalHabilidades()<<endl;
	cout<<"\t \t ===============HABILIDADADES====================="<<endl;
	cout<<NORMAL;
	if(this->GetTotalHabilidades()!=0){
		for(int i=0 ;i<this->GetTotalHabilidades(); i++){
			cout<<"la habilidad"<<i<<endl;
			this->vectorHabildades[i].print();

		}
	}
}

/////// POKEMON DE TIPO AGUA
///////POKEMON DE TIPO FUEGO
class PokemonFuego : public Pokemon {
	protected:
	double nivelfuego;
	public:
	PokemonFuego();
	PokemonFuego(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar,
	double nivelFuego );
	PokemonFuego(PokemonFuego &PokemonFuego);
	~PokemonFuego();
	inline void SetNivelFuego(double nivelFuego){this->nivelfuego=nivelFuego;}
	inline double GetNivelFuego(){return this->nivelfuego;}
	
	void print();
	
	void recibirDanoDePokemon(Pokemon * rival,int i);
};
PokemonFuego::PokemonFuego(){
	cout<<"DEBUG: constructor por defecto de pokemonFuego "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVectorHabilidades(NULL);
	this->SetVelocidad(0);
	this->SetTotalHabilidades(0);
	this->SetNivelFuego(0);
	
}
PokemonFuego::PokemonFuego(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar,
	double nivelFuego){
		
	this->SetId(id);
	this->SetNombre(nombre);
	this->SetVida(vida);
	this->SetAtaque(ataque);
	this->SetDefensa(defensa);
	this->SetVelocidad(velocidad);
	this->SetVectorHabilidades(new Habilidad[0]);
	this->SetTotalHabilidades(0);
	this->SetPrecio(precio);
	this->SetPrecioCurar(precioCurar);
	this->SetNivelFuego(nivelFuego);
}
PokemonFuego::~PokemonFuego(){
	cout<<"destructor de pokemon fuego"<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVelocidad(0);
	if(this->GetTotalHabilidades() !=0 ){
	    delete [] this->vectorHabildades;
		cout<<"en el delete"<<endl;
	}
	this->SetTotalHabilidades(0);
	this->SetNivelFuego(0);
	
}
void PokemonFuego::print(){
	cout<<GREEN_COLOR;
	cout<<"\t id: "<<this->GetId()<<endl;
	cout<<"\t nombre: "<<this->GetNombre()<<endl;
	cout<<"\t vida: "<<this->GetVida()<<endl;
	cout<<"\t ataque: "<<this->GetAtaque()<<endl;
	cout<<"\t defensa: "<<this->GetDefensa()<<endl;
	cout<<"\t velocidad: "<<this->GetVelocidad()<<endl;
	cout<<"\t precio: "<<this->GetPrecio()<<endl;
	cout<<"\t precioCurar: "<<this->GetPrecioCurar()<<endl;
	cout<<"\t nivelFuego: "<<this->GetNivelFuego()<<endl;
	cout<<"\t HABILIDADADES == total:"<<GetTotalHabilidades()<<endl;
	cout<<"\t \t ===============HABILIDADADES====================="<<endl;
	cout<<NORMAL;
	if(this->GetTotalHabilidades()!=0){
		for(int i=0 ;i<this->GetTotalHabilidades(); i++){
			cout<<"la habilidad"<<i<<endl;
			this->vectorHabildades[i].print();

		}
	}
}


/////// POKEMON DE TIPO FUEGO
///////POKEMON DE TIPO PLANTA
class PokemonPlanta : public Pokemon {
	protected:
	double nivelplanta;
	public:
	PokemonPlanta();
	PokemonPlanta(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar,
	double nivelPlanta );
	PokemonPlanta(PokemonPlanta &PokemonPlanta);
	~PokemonPlanta();
	inline void SetNivelPlanta(double nivelPlanta){this->nivelplanta=nivelPlanta;}
	inline double GetNivelPlanta(){return this->nivelplanta;}
	
	void print();
	
	void recibirDanoDePokemon(Pokemon * rival, int i);
};
PokemonPlanta::PokemonPlanta(){
	cout<<"DEBUG: constructor por defecto de pokemonAgua "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVectorHabilidades(NULL);
	this->SetVelocidad(0);
	this->SetTotalHabilidades(0);
	this->SetNivelPlanta(0);
	
}
PokemonPlanta::PokemonPlanta(int id, string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar,
	double nivelPlanta){
		
	this->SetId(id);
	this->SetNombre(nombre);
	this->SetVida(vida);
	this->SetAtaque(ataque);
	this->SetDefensa(defensa);
	this->SetVelocidad(velocidad);
	this->SetVectorHabilidades(new Habilidad[0]);
	this->SetTotalHabilidades(0);
	this->SetPrecio(precio);
	this->SetPrecioCurar(precioCurar);
	this->SetNivelPlanta(nivelPlanta);
}
PokemonPlanta::~PokemonPlanta(){
	cout<<"destructor de pokemon planta"<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVelocidad(0);
	if(this->GetTotalHabilidades() !=0 ){
	    delete [] this->vectorHabildades;
		cout<<"en el delete"<<endl;
	}
	this->SetTotalHabilidades(0);
	this->SetNivelPlanta(0);
	
}
void PokemonPlanta::print(){
	cout<<GREEN_COLOR;
	cout<<"\t id: "<<this->GetId()<<endl;
	cout<<"\t nombre: "<<this->GetNombre()<<endl;
	cout<<"\t vida: "<<this->GetVida()<<endl;
	cout<<"\t ataque: "<<this->GetAtaque()<<endl;
	cout<<"\t defensa: "<<this->GetDefensa()<<endl;
	cout<<"\t velocidad: "<<this->GetVelocidad()<<endl;
	cout<<"\t precio: "<<this->GetPrecio()<<endl;
	cout<<"\t precioCurar: "<<this->GetPrecioCurar()<<endl;
	cout<<"\t nivelplanta: "<<this->GetNivelPlanta()<<endl;
	cout<<"\t HABILIDADADES == total:"<<GetTotalHabilidades()<<endl;
	cout<<"\t \t ===============HABILIDADADES====================="<<endl;
	cout<<NORMAL;
	if(this->GetTotalHabilidades()!=0){
		for(int i=0 ;i<this->GetTotalHabilidades(); i++){
			cout<<"la habilidad"<<i<<endl;
			this->vectorHabildades[i].print();

		}
	}
}


/////// POKEMON DE TIPO FUEGO
Pokemon::Pokemon(){
	cout<<"DEBUG: constructor por defecto de pokemon "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVectorHabilidades(NULL);
	this->SetVelocidad(0);
	this->SetTotalHabilidades(0);
	
}
Pokemon::Pokemon(int id,string nombre, int vida, int ataque, int defensa,int velocidad,int precio, int precioCurar){
	cout<<"DEBUG: constructor por parametros de pokemonAgua "<<endl;
	this->SetId(id);
	this->SetNombre(nombre);
	this->SetVida(vida);
	this->SetAtaque(ataque);
	this->SetDefensa(defensa);
	this->SetVelocidad(velocidad);
	this->SetVectorHabilidades(new Habilidad[0]);
	this->SetTotalHabilidades(0);
	this->SetPrecio(precio);
	this->SetPrecioCurar(precioCurar);
	
}
Pokemon::Pokemon(Pokemon &p){
	cout<<"DEBUG: Constructor por copia de Poekemon"<<endl;
		Habilidad* h=new Habilidad[p.GetTotalHabilidades()];
		if (h==0){
			cout<<"memoria insuficinte ejecucion abortada"<<endl;
			exit(-1);
		}
		this->SetId(p.GetId());
		this->SetNombre(p.GetNombre());
		this->SetVida(p.GetVida());
		this->SetAtaque(p.GetAtaque());
		this->SetDefensa(p.GetDefensa());
		this->SetVelocidad(p.GetVelocidad());
		this->SetPrecio(p.GetPrecio());
		this->SetPrecioCurar(p.GetPrecioCurar());
		if(p.GetTotalHabilidades()!=0){
			for(int i=0 ;i<this->GetTotalHabilidades(); i++){
				cout<<"antes del id"<<p.GetVectorHabilidadesPos(i).GetId()<<endl<<endl<<endl;
				h[i].SetId(p.GetVectorHabilidadesPos(i).GetId());
				h[i].SetNombre(p.GetVectorHabilidadesPos(i).GetNombre());
				h[i].SetDano(p.GetVectorHabilidadesPos(i).GetDano());
				h[i].SetPrecio(p.GetVectorHabilidadesPos(i).GetPrecio());
				h[i].SetPp(p.GetVectorHabilidadesPos(i).GetPp());
				h[i].SetTipo(p.GetVectorHabilidadesPos(i).GetTipo());
			}
			delete [] this->GetVectorHabilidades();
			this->SetVectorHabilidades(h);
			delete [] h;
			this->SetTotalHabilidades(p.GetTotalHabilidades());
		}
	
}
void Pokemon::print(){
	cout<<"\t id: "<<this->GetId()<<endl;
	cout<<"\t nombre: "<<this->GetNombre()<<endl;
	cout<<"\t vida: "<<this->GetVida()<<endl;
	cout<<"\t ataque: "<<this->GetAtaque()<<endl;
	cout<<"\t defensa: "<<this->GetDefensa()<<endl;
	cout<<"\t velocidad: "<<this->GetVelocidad()<<endl;
	cout<<"\t precio: "<<this->GetPrecio()<<endl;
	cout<<"\t precioCurar: "<<this->GetPrecioCurar()<<endl;
	cout<<"\t HABILIDADADES == total:"<<GetTotalHabilidades()<<endl;
	cout<<"\t \t ===============HABILIDADADES====================="<<endl;
	if(this->GetTotalHabilidades()!=0){
		for(int i=0 ;i<this->GetTotalHabilidades(); i++){
			cout<<"la habilidad"<<i<<endl;
			this->vectorHabildades[i].print();

		}
	}
	
}
Pokemon::~Pokemon(){
	cout<<"DEBUG: destructor de pokemon "<<endl;
	this->SetId(0);
	this->SetNombre("");
	this->SetVida(0);
	this->SetAtaque(0);
	this->SetDefensa(0);
	this->SetVelocidad(0);
	if(this->GetTotalHabilidades() !=0 ){
	    delete [] this->vectorHabildades;
		cout<<"en el delete"<<endl;
	}
	//this->SetVectorHabilidades(NULL);
	this->SetTotalHabilidades(0);
	
}
ostream& Pokemon::operator << (ostream& salida){//no se usa 
	salida<<"id: "<<this->GetId()<<endl;
	salida<<"nombre: "<<this->GetNombre()<<endl;
	salida<<"vida: "<<this->GetVida()<<endl;
	salida<<"ataque: "<<this->GetAtaque()<<endl;
	salida<<"defensa: "<<this->GetDefensa()<<endl;
	salida<<"velocidad: "<<this->GetVelocidad()<<endl;
	salida<<"HABILIDADADES =============================="<<endl;
	for(int i=0 ;i<this->totalHabilidades; i++){
		this->GetVectorHabilidadesPos(i).print();
	}
	return salida;
}
Pokemon& Pokemon::operator=( Pokemon &p){
	cout<<"pokemon operador="<<endl;
	if(this != &p ){	
		Habilidad* h=new Habilidad[p.GetTotalHabilidades()];
		if (h==0){
			cout<<"memoria insuficinte ejecucion abortada"<<endl;
			exit(-1);
		}
		this->SetId(p.GetId());
		this->SetNombre(p.GetNombre());
		this->SetVida(p.GetVida());
		this->SetAtaque(p.GetAtaque());
		this->SetDefensa(p.GetDefensa());
		this->SetVelocidad(p.GetVelocidad());
		this->SetPrecio(p.GetPrecio());
		this->SetPrecioCurar(p.GetPrecioCurar());
		if(p.GetTotalHabilidades()!=0){
			for(int i=0 ;i<this->GetTotalHabilidades(); i++){
				h[i].SetId(p.GetVectorHabilidadesPos(i).GetId());
				h[i].SetNombre(p.GetVectorHabilidadesPos(i).GetNombre());
				h[i].SetDano(p.GetVectorHabilidadesPos(i).GetDano());
				h[i].SetPrecio(p.GetVectorHabilidadesPos(i).GetPrecio());
				h[i].SetPp(p.GetVectorHabilidadesPos(i).GetPp());
				h[i].SetTipo(p.GetVectorHabilidadesPos(i).GetTipo());;
			}
			delete [] this->GetVectorHabilidades();
			this->SetVectorHabilidades(h);
			//delete [] h;
	}
	this->SetTotalHabilidades(p.GetTotalHabilidades());
	}
	return *this;
}
void Pokemon::AnadirHabilidad(Habilidad *h){
	Habilidad* haux=new Habilidad[this->GetTotalHabilidades()+1];
	Habilidad copiaH=*h;
	if (haux==0){
		cerr<<"memoria insuficinte ejecucion abortada"<<endl;
		exit(-1);
	}
	for(int i=0; i<this->GetTotalHabilidades();i++){
		haux[i]=this->vectorHabildades[i];
	}
	if(this->GetTotalHabilidades()!=0){
		delete [] this->GetVectorHabilidades();
	}
	this->SetVectorHabilidades(haux); //no lo hagas del reves!!!!!!!!!!!
	this->vectorHabildades[this->GetTotalHabilidades()]=copiaH;
	this->SetTotalHabilidades((this->GetTotalHabilidades())+1);
	//delete [] haux;
}
void Pokemon::BorrarHabilidad(int pos){
	
	
	Habilidad* haux=new Habilidad[this->GetTotalHabilidades()];
	for(int i=0;i<GetTotalHabilidades()-1;i++){
		haux[i]=this->vectorHabildades[i];
		if(i==pos){
			haux[i]=this->vectorHabildades[GetTotalHabilidades()-1];
			}
	}
	this->SetTotalHabilidades(GetTotalHabilidades()-1);
	delete [] this->GetVectorHabilidades();
	this->SetVectorHabilidades(haux);
}
void Pokemon::curacion(){
	this->SetVida(100);
}
void Pokemon::UsarHabilidad(int pos,Pokemon *p){
	int danoArrecibir=this->GetVectorHabilidadesPos(pos).GetDano();
	if(danoArrecibir>=0){
		recibirDanoDePokemon(p,pos); //p recibe daño de this
	}
	else {
		if(this->GetVida()+danoArrecibir >= 100){
			this->SetVida(this->GetVida()+danoArrecibir);
		}
		else {
			this->SetVida(100);
		}
	}
	
}
void Pokemon::subirNivel(){
	if (this->GetVida()*2<=100){
		this->SetVida(this->GetVida()*2);
	}
	else{
		this->SetVida(100);
	}
	this->SetAtaque(this->GetAtaque()*2);
	this->SetDefensa(this->GetDefensa()*2);
	this->SetVelocidad(this->GetVelocidad()*2);
}
void Pokemon::CalcularPecio(){
	double val=(this->GetVida()+this->GetDefensa()+this->GetVelocidad())*0.5;
	this->SetPrecio(val);
}
void PokemonAgua::recibirDanoDePokemon(Pokemon * rival,int i){
	double danio=0;
	if(PokemonAgua *p = dynamic_cast<PokemonAgua *>(rival)){
	danio=abs(this->GetDefensa() - rival->GetAtaque())+(rival->GetVectorHabilidadesPos(i).GetDano());


	}
	if(PokemonFuego *p = dynamic_cast<PokemonFuego *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())/(rival->GetVectorHabilidadesPos(i).GetDano());
		cout<<"resulto poco eficaz"<<endl;
	}
	if(PokemonPlanta *p = dynamic_cast<PokemonPlanta *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())*(rival->GetVectorHabilidadesPos(i).GetDano());
		cout<<"resulto muy eficaz"<<endl;
	 
	}
	this->SetVida(this->GetVida()-danio);

}
void PokemonFuego::recibirDanoDePokemon(Pokemon * rival,int i){
	double danio=0;
	if(PokemonAgua *p = dynamic_cast<PokemonAgua *>(rival)){
	danio=abs(this->GetDefensa() - rival->GetAtaque())*(rival->GetVectorHabilidadesPos(i).GetDano());
	cout<<"resulto muy eficaz"<<endl;

	}
	if(PokemonFuego *p = dynamic_cast<PokemonFuego *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())+(rival->GetVectorHabilidadesPos(i).GetDano());
	}
	if(PokemonPlanta *p = dynamic_cast<PokemonPlanta *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())/(rival->GetVectorHabilidadesPos(i).GetDano());
		cout<<"resulto poco eficaz"<<endl;
	}
	this->SetVida(this->GetVida()-danio);
	
}
void PokemonPlanta::recibirDanoDePokemon(Pokemon * rival,int i){
	double danio=0;
	if(PokemonAgua *p = dynamic_cast<PokemonAgua *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())/(rival->GetVectorHabilidadesPos(i).GetDano());
		cout<<"resulto poco eficaz"<<endl;

	}
	if(PokemonFuego *p = dynamic_cast<PokemonFuego *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())*(rival->GetVectorHabilidadesPos(i).GetDano());
		cout<<"resulto muy eficaz"<<endl;
	 
	}
	if(PokemonPlanta *p = dynamic_cast<PokemonPlanta *>(rival)){
		danio=abs(this->GetDefensa() - rival->GetAtaque())+(rival->GetVectorHabilidadesPos(i).GetDano());
	 
	}
	this->SetVida(this->GetVida()-danio);
}
void Pokemon::CalcularPecioCuracion(){
	double val=GetVida()*3*0.2;
	this->SetPrecioCurar(val);
}
#endif