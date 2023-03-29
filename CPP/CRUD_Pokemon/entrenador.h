#include<iostream>
#include <string>
#include <stdlib.h>
#include "pokemon.h"
#ifndef entrenador_h
#define entrenador_h
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

using namespace std;
class Entrenador{
	protected:
	int id;
	string nombre;
	string passw;
	double monedero;
	Pokemon **mochila;
	Pokemon ** listaBusqueda;//guarda los pokemon que se quieran buscar si (que esten en la mochila)
	int totalPokemonMochila;
	int victorias;
	int pokemonActivo;//Posiión en el vector mochila del primer pokemon que saldrá, y -1 si no hay pokemon activo, estará entre 0- total pokemon
	double valoracionMochila;
	double valoracionEntrenador; 
	public:
	//CONSTRUCTORES
	Entrenador();
	Entrenador(int id,string name,string passw,double monedero,int victorias,int pokemonActivo);
	Entrenador(Entrenador &entrenador);
	//DESTRUCTORES
	~Entrenador();
	//SET y GET
	inline int GetId(){return this->id;}
	inline string GetNombre(){return this->nombre;}
	inline string GetPassw(){return this->passw;}
	inline double GetMonedero(){return this->monedero;}
	inline Pokemon ** GetMochila(){return this->mochila;}
	inline Pokemon * GetMochilaPos(int pos){return this->mochila[pos];}
	inline Pokemon ** GetlistaBusqueda(){return this->listaBusqueda;}
	inline Pokemon * GetlistaBusquedaPos(int pos){return this->listaBusqueda[pos];}
	inline int GetTotalPokemonMochila(){return this->totalPokemonMochila;}
	inline int GetVictorias(){return this->victorias;}
	inline int GetPokemonActivo(){return this->pokemonActivo;}
	inline double GetValoracionMochila(){return this->valoracionMochila;}
	inline double GetValoracionEntrenador(){return this->valoracionEntrenador;}
	inline void SetId(int id){this->id=id;}
	inline void SetNombre(string nombre){this->nombre=nombre;}
	inline void SetPassw(string passw){this->passw=passw;}
	inline void SetMonedero(double monedero){this->monedero=monedero;}
	inline void SetMochila(Pokemon** mochila){this->mochila=mochila;}
	inline void SetMochilaPos(int i,Pokemon *pokemon){this->mochila[i]=pokemon;}
	inline void SetListaBusqueda(Pokemon** listaBusqueda){this->listaBusqueda=listaBusqueda;}
	inline void SetListaBusquedaPos(Pokemon* listaBusqueda,int pos){this->listaBusqueda[pos]=listaBusqueda;}
	inline void SetTotalPokemonMochila(int totalPokemonMochila){this->totalPokemonMochila=totalPokemonMochila;}
	inline void SetVictorias(int victorias){this->victorias=victorias;}
	inline void SetPokemonActivo(int pokemonActivo){this->pokemonActivo=pokemonActivo;}
	inline void SetvaloracionMochila(double valoracionMochila ){this->valoracionMochila=valoracionMochila;}
	inline void SetvaloracionEntrenador(double valoracionEntrenador ){this->valoracionEntrenador=valoracionEntrenador;}
	/**
	@brief imprime por pantalla todos los valores actuales de una Entrenador incluso el pokemon con sus habilidades
	@param ningua
	@pre que exista el objeto 
	@post ningua postcondicion
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void print();
	//sobrecarga del operador igual
	Entrenador& operator=(Entrenador &entrenador);
	/**
	@brief permite comprar un pokemon  al sistema
	@param Pokemon * pokemonAcomprar
	@pre que exista el pokemon a comprar
	@post el pokemon pertenece ya al entrenador
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void comprarPokemon(Pokemon * pokemonAcomprar);
	/**
	@brief permite vender un pokemon a un entrenador de la poscion "poscion"
	@param int posicion, Entrenador &e
	@pre que exista el pokemon a vender y el entrenador al que se lo vamos a vender
	@post el pokemon ya no pertenece  al entrenador
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void venderPokemon(int posicion, Entrenador &e);
	/**
	@brief permite controlar el pokemon activo en una batalla  asingando como pokemon activo el pokemon de la poscion que se pase
	@param int posicion
	@pre que exista el pokemon que sera activo
	@post la poscion del pokemon activo cambia
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void setPokemonActivo(int posicion);
	/**
	@brief si un entrenador gana una batalla se quedara con un pokemon del entreador que perdio este modulo asigna ese pokemon a su nuevo entreador y lo quita de su aterior dueño
	@param Pokemon* pokemonGanado
	@pre que se gane una batalla 
	@post el pokemon ahora pertenece al entreandor ganador y deja de pertenecer al perdedor
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void ganarPokemon(Pokemon* pokemonGanado);
	/**
	@brief ataca segun una formula predetermianda a un pokemon
	@param Pokemon* rival
	@pre niguna
	@post el pokemon atacado llama a su modulo recibir daño
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void atacarPokemon(Pokemon * rival);
	/**
	@brief nos permite añadir un pokemon a la mochila este modulo se encarga de resdimesionar el vector de punteros a punteros y asignar el nuevo pokemon que se le pase por parametros 
	@param Pokemon* pokemon
	@pre niguna
	@post el pokemon pertenece a un entreador
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void anadirPokemonMochila(Pokemon* pokemon);
	/**
	@brief nos permite eliminar un pokemon de la mochila este modulo se encarga de resdimesionar el vector de punteros a punteros y borrar el pokemon de la mochila de la posicion que se le pasae por parametros 
	@param int id
	@pre niguna
	@post el pokemon pertenece a un entreador
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void eliminarPokemonMochila(int id);
	/**
	@brief imprime por pantalla todos los valores actuales de la mochila de un entrador
	@param ningua
	@pre que exista el objeto 
	@post ningua postcondicion
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void imprimirMochila();
	/**
	@brief imprime por pantalla todos los valores
	@param ninguno
	@pre que exista el objeto 
	@post ningua postcondicion
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void imprimirListadeBusqueda();
	/**
	@brief calcula el valor de un entreanodor segun una formula predeterminada
	@param ninguno
	@pre que exista el objeto 
	@post el entreador tendra asignado su nuevo valor
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void calcularValorEntrenador();
	/**
	@brief calcula el valor de la mochila de un entrador segun una formula predeterminada
	@param ninguno
	@pre que exista el objeto 
	@post el entreador tendra asignado su nuevo valor de mochila
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void calcularValorMochila();
		/**
	@brief busca un pokemon por id 
	@param ninguno
	@pre que exista el objeto 
	@post el entreador tendra asignado su nuevo valor de mochila
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	int buscarPokemon(int id);

};
Entrenador::Entrenador(){
	cout<<"DEBUG: constructor por defecto de Entrenador "<<endl;
	SetId(0);
	SetNombre("");
	SetPassw("");
	SetMonedero(0.0);
	SetMochila(NULL);
	SetListaBusqueda(NULL);
	SetTotalPokemonMochila(0);
	SetVictorias(0);
	SetPokemonActivo(0);
	SetvaloracionMochila(0.0);
	SetvaloracionEntrenador(0.0);
	
	
}
Entrenador::Entrenador(int id,string nombre,string passw,double monedero,int victorias ,int pokemonActivo){

	cout<<"DEBUG: constructor por parametroa de Entrenador "<<endl;
	SetId(id);
	SetNombre(nombre);
	SetPassw(passw);
	SetMonedero(monedero);
	SetMochila(NULL);
	SetListaBusqueda(NULL);
	SetTotalPokemonMochila(0);
	SetVictorias(victorias);
	SetPokemonActivo(pokemonActivo);
	SetvaloracionMochila(0.0);
	SetvaloracionEntrenador(0.0);
}
Entrenador::Entrenador(Entrenador& entrenador){
	this->SetId(entrenador.GetId());
	this->SetNombre(entrenador.GetNombre());
	this->SetPassw(entrenador.GetPassw());
	this->SetMonedero(entrenador.GetMonedero());
	this->SetTotalPokemonMochila(entrenador.GetTotalPokemonMochila());
	this->SetVictorias(entrenador.GetVictorias());
	this->SetPokemonActivo(entrenador.GetPokemonActivo());
	this->SetvaloracionMochila(entrenador.GetValoracionMochila());
	this->SetvaloracionEntrenador(entrenador.GetValoracionEntrenador());
	this->mochila=new Pokemon*[entrenador.GetTotalPokemonMochila()];
	for(int i=0;i<entrenador.GetTotalPokemonMochila();i++){
		this->mochila[i]=entrenador.mochila[i];
	}
}
Entrenador::~Entrenador(){
	cout<<"DEBUG: destructor de entrenador "<<endl;
	SetId(0);
	SetNombre("");
	SetPassw("");
	SetMonedero(0.0);
	
	SetListaBusqueda(NULL);
	SetVictorias(0);
	SetPokemonActivo(0);
	SetvaloracionMochila(0.0);
	SetvaloracionEntrenador(0.0);
	
	if(this->GetTotalPokemonMochila() !=0 ){
	for(int i=0;i<this->GetTotalPokemonMochila();i++){
		//cout<<this->GetNombre()<<endl;
		//delete this->mochila[i];
	}
	}
	delete [] this->mochila;
	SetTotalPokemonMochila(0);
	//SetMochila(0);
	
	
}
void Entrenador::print(){
	cout<<RED_COLOR<<endl;
	cout<<"Entrenador ID: "<<this->GetId()<<endl;;
	cout<<"Entrenador nombre: "<<this->GetNombre()<<endl;
	cout<<"contraseña: "<<this->GetPassw()<<endl;
	cout<<"dinero en el Monedero: "<<this->GetMonedero()<<endl;;
	cout<<"Pokemons en la Mochila: "<<this->GetTotalPokemonMochila()<<endl;
	cout<<"victorias: "<<this->GetVictorias()<<endl;
	cout<<"pokemon Activo (ultimo pokemon usado): "<<this->GetPokemonActivo()<<endl;
	cout<<"valor de la mochila (valor total de los pokemos que hay en la mochila): "<<this->GetValoracionMochila()<<endl;
	cout<<"valoracion del entrenador "<<this->GetValoracionEntrenador()<<endl;
	cout<<"DEBUG: el total de los pokemon en la mochila es "<<this->GetTotalPokemonMochila()<<endl;
	cout<<NORMAL;
	if(this->GetTotalPokemonMochila()>0){
		cout<<"entro en el if"<<endl;
		for(int i=0;i<this->GetTotalPokemonMochila();i++){
			cout<<"habilidad numero "<<i<<endl;
			this->mochila[i]->print();
		}
	}

}
Entrenador& Entrenador::operator=(Entrenador &entrenador){
	cout<<"DEBUG:Entrenador operador="<<endl;
	if (this != &entrenador){
		this->SetId(entrenador.GetId());
		this->SetNombre(entrenador.GetNombre());
		this->SetPassw(entrenador.GetPassw());
		this->SetMonedero(entrenador.GetMonedero());
		this->SetVictorias(entrenador.GetVictorias());
		this->SetPokemonActivo(entrenador.GetPokemonActivo());
		this->SetvaloracionMochila(entrenador.GetValoracionMochila());
		this->SetvaloracionEntrenador(entrenador.GetValoracionEntrenador());
		this->mochila=new Pokemon*[entrenador.GetTotalPokemonMochila()];
		for(int i=0;i<entrenador.GetTotalPokemonMochila();i++){
			this->mochila[i]=entrenador.mochila[i];
		}
		this->SetTotalPokemonMochila(entrenador.GetTotalPokemonMochila());
	}
	return *this;
}
void Entrenador::anadirPokemonMochila(Pokemon * pokemon){
	Pokemon** paux=new Pokemon*[this->GetTotalPokemonMochila()+1];
	Pokemon* copiaDePokemon=pokemon;
	if (paux==0){
		cerr<<"memoria insuficinte ejecucion abortada"<<endl;
		exit(-1);
	}
	for (int i=0;i<this->GetTotalPokemonMochila();i++){
		paux[i]=this->mochila[i];
	}
	if(this->GetTotalPokemonMochila()>0){
		delete [] this->mochila;
	}
	this->SetMochila(paux);
	this->mochila[this->GetTotalPokemonMochila()]=copiaDePokemon;
	this->SetTotalPokemonMochila((this->GetTotalPokemonMochila())+1);
	//delete [] paux;
	

}
int Entrenador::buscarPokemon(int id){
	bool enc=false;
	int posicion_mochila=-1;
	for(int i=0;i<this->GetTotalPokemonMochila() && enc==false;i++){
		if (id==this->GetMochilaPos(i)->GetId()){
			posicion_mochila=i;
		}
	}
	return posicion_mochila;
}
void Entrenador::eliminarPokemonMochila(int id){
	int posBorrar=buscarPokemon(id);
	Pokemon** paux=new Pokemon*[this->GetTotalPokemonMochila()];
	for(int i=0;i<this->GetTotalPokemonMochila()-1;i++){
		paux[i]=this->mochila[i];
		if(i==posBorrar){
			paux[i]=this->mochila[this->GetTotalPokemonMochila()-1];
			}
	}
	this->SetTotalPokemonMochila((this->GetTotalPokemonMochila())-1);
	delete [] this->GetMochila();
	this->SetMochila(paux);
}	
void Entrenador::comprarPokemon(Pokemon* pokemonAcomprar){
	if(pokemonAcomprar->GetPrecio()<=this->GetMonedero()){
		anadirPokemonMochila(pokemonAcomprar);
		this->SetMonedero(this->GetMonedero()-pokemonAcomprar->GetPrecio());
	}
	else
		cout<<"usted no tiene el dinero suficiene este es el valor de su monedeo: "<<this->GetMonedero()<<" y este el precio del pokemon"<<pokemonAcomprar->GetPrecio()<<endl;
}
void Entrenador::calcularValorMochila(){
	double val=0;
	for(int i=0;i<this->GetTotalPokemonMochila()-1;i++){
		val=this->GetMochilaPos(i)->GetPrecio()+val;
	}
	SetvaloracionMochila(val);
}
void Entrenador::calcularValorEntrenador(){
	double val=0;
	this->calcularValorMochila();
	val=GetValoracionMochila()*(this->GetVictorias());
	SetvaloracionEntrenador(val);
}
#endif