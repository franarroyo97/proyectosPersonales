#include<iostream>
#include <string>
#include <stdlib.h>
#include "entrenador.h"
using namespace std;
#ifndef spcr_h
#define spcr_h
#include <fstream>
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

class Spcr{
	protected:
	Entrenador * listaUsuarios;
	int totalUsuarios;
	Entrenador * entrenadorActivo;
	Pokemon ** pokedex;
	int totalPokedex;
	Habilidad * listaHabilidades; //Habilidades disponibles en el juego
	int totalListaHabilidades;
	public:
	Spcr();
	~Spcr();
	//modulos que se encargan de redimesinar sus respectivos vectores
	void redimesionarListaUsuarios(int tanamio);
	void redimesionarPokedex(int  Tamanio);
	void redimesionarListaHabilidades(int  Tamanio);
	//modulos GET
	inline Entrenador * GetListaUsuarios(){return this->listaUsuarios;}
	inline Entrenador GetListaUsuariosPos(int i){return this->listaUsuarios[i];}
	inline int GetTotalUsuarios(){return this->totalUsuarios;}
	inline Entrenador* GetEntrenadorActivo(){return this->entrenadorActivo;}
	inline Pokemon** GetPokedex(){return this->pokedex;}
	inline Pokemon* GetPokedexPos(int i){return this->pokedex[i];}
	inline int GetTotalPokedex(){return this->totalPokedex;}
	inline Habilidad* GetListaHabilidades(){return this->listaHabilidades;}
	inline Habilidad GetListaHabilidadesPos(int i){return this->listaHabilidades[i];}
	inline int GetTotalListaHabilidades(){return this->totalListaHabilidades;}
	
	//modulos SET
	inline void SetListaUsuarios(Entrenador * listaDeUsuarios){this->listaUsuarios=listaDeUsuarios;}
	inline void SetListaUsuariosPos(Entrenador usuario, int i){this->listaUsuarios[i]=usuario;}
	inline void SetTotalUsuarios(int totalDeUsuarios){this->totalUsuarios=totalDeUsuarios;}
	inline void SetEntreadorActico(Entrenador* EntrenadorActivo){this->entrenadorActivo=EntrenadorActivo;}
	inline void SetPokedex(Pokemon** pokedex){this->pokedex=pokedex;}
	inline void SetPokedexPos(Pokemon *pokedex,int i){this->pokedex[i]=pokedex;}
	inline void SetTotalPokedex(int totalPokedex){this->totalPokedex=totalPokedex;}
	inline void SetListaHabilidades(Habilidad* listaHabilidades){this->listaHabilidades=listaHabilidades;}
	inline void SetListaHabilidadesPos(Habilidad habilidad,int i){this->listaHabilidades[i]=habilidad;}
	inline void SettotalListaHabilidades(int totalHabilidades){this->totalListaHabilidades=totalHabilidades;}
	/**
	@brief añade manualmente unas cuantas habilidads , pokemons y entreandores al sistema 
	@param ninguno
	@pre ninguna 
	@post hay nuevos usuarios , hablidades y pokemnos en el sistema
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void anadir();
	/**
	@brief da la bienvenida al usuario y le pregunta si quire importar datos
	@param ninguno
	@pre ninguna 
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void bienvenida();
	/**
	@brief importa datos de un fichero
	@param ninguno
	@pre ninguna 
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void importarFichero();
	/**
	@brief pide login y contraseña a un  
	@param ninguno
	@pre ninguna 
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void autentificacion();
	/**
	@brief imrpime un menu principal e implementa toadas las funcionalidades 
	@param ninguno
	@pre ninguna 
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void menuPrincipal();
	/**
	@brief nos permite añadir un nuevo pokemon al sis
	@param ninguno
	@pre ninguna 
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void agregarPokemonalSistema();
	/**
	@brief nos permite eliminar un pokemon del sistema
	@param ninguno
	@pre ninguna 
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void eliminarPokemondelSistema();
	/**
	@brief nos perimte buscar un pokemon en el sistema por nombre y retorna la poscion del mismo en el vector
	@param string nombr
	@pre que exista si no retorta -1
	@post ninguna
	@return int con la poscion 
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	int buscarPokemonSistema(string nombre);
	/**
	@brief nos perimte modifcar datos de un pokemon en el sistema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void modificarDatosPokemonSistema();
	/**
	@brief hace la media del  valor de todos pokemon y enseña el valor por patalla
	@param ninguno
	@pre ninguna
	@post ninguna
	@return int con la poscion 
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void consultarPrecioMedioMercadoPokemon();
	/**
	@brief nos permite añadir un nuevo usuario a nuestro sistema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return int con la poscion 
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void agregarNuevoEntrenadoSistema();
	/**
	@brief nos permite eliminar un usuario del sitema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return int con la poscion 
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void eliminarEntrenadordelSistema();
	/**
	@brief nos permite buscar un entreandor en el sistema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void buscarEntrenadorEnSistema();
	/**
	@brief nos permite alterar los datos de un entreandor en el sisema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void modificarDatosEntrenadorSitema();
	/**
	@brief muestra un top 3 de los pokemon por su valor y los ordena en el vector (de menos a mas)
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void rankingTop3GeneralPokemon();
	/**
	@brief muestra un top 3 de los pokemon por su valor y los ordena en el vector (de menos a mas) y demas tiene en cuenta su tipo es decir se dara el ranking segun el tipo de pokemon
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void rankingTop3PorTipoPokemon();
	/**
	@brief muestra un top de todos los entranodres en el sistema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void rankingDeEntrenadores();
	/**
	@brief muestra datos de un entrador es decir su lsita de pokemon
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada 
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void consultarListaPokemon();
	/**
	@brief compra un pokemon al sistema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void comprarPokemon();
	/**
	@brief vende un pokemon al sismtema
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void venderPokemon();
	/**
	@brief cura un pokemon
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void curarPokemon();
	/**
	@brief asinga una habilidad a un pokemon
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void asignarHabilidadPokemon();
	/**
	@brief quita un habilidad a un pokemon
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	**/
	void desasignarHabilidadPokemon();
	/**
	@brief perite hacer luchar un pokemon con otro
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	void jugarBatalla();
	void exportarFichero();
	**/
	void jugarBatalla();
	/**
	@brief perite exportar datos de un a un fichero
	@param ninguno
	@pre ninguna
	@post ninguna
	@return nada
	@autor Francisco Arroyo Lopez
	@ver 1.0
	void jugarBatalla();
	void exportarFichero();
	**/
	void exportarFichero();
	/**
	@brief perite buscar un usuario por nombre y retora su poscion el el vector
	@param string nombre
	@pre ninguna
	@post ninguna
	@return int con la poscion 
	@autor Francisco Arroyo Lopez
	@ver 1.0
	void jugarBatalla();
	void exportarFichero();
	**/
	int  buscarUsuarioNombre(string nombre);
	
	void buscarPokemonConLista();

};
Spcr::Spcr(){
	SetListaUsuarios(0);
	SetTotalUsuarios(0);
	SetEntreadorActico(0);
	SetPokedex(0);
	SetTotalPokedex(0);
	SetListaHabilidades(0);
	SettotalListaHabilidades(0);
	
}
Spcr::~Spcr(){
	cout<<"destuyendo el sistema"<<endl;
	delete [] GetListaHabilidades();
	SetListaHabilidades(NULL);
	SettotalListaHabilidades(0);
	for(int i=0;i<GetTotalPokedex();i++){
		delete GetPokedexPos(i);
	}
	cout<<"por ok"<<endl;
	delete [] GetPokedex();
	SetPokedex(NULL);
	SetTotalPokedex(0);
	delete [] GetListaUsuarios();
	SetListaUsuarios(NULL);
	SetTotalUsuarios(0);
}

void Spcr::redimesionarListaUsuarios(int  Tamanio){
	Entrenador* nuevoE=new Entrenador[Tamanio];
	for(int i=0;i<GetTotalUsuarios();i++){
		nuevoE[i]=this->listaUsuarios[i];
	}
	if(GetTotalUsuarios()<0)
		delete [] this->listaUsuarios;
	this->listaUsuarios=nuevoE;
	
}
void Spcr::redimesionarPokedex(int  Tamanio){
	Pokemon** nuevoP=new Pokemon*[Tamanio];
	for(int i=0;i<GetTotalPokedex();i++){
		nuevoP[i]=this->pokedex[i];
	}
	if(GetTotalPokedex()<0)
		delete [] this->pokedex;
	this->pokedex=nuevoP;
	
}
void Spcr::redimesionarListaHabilidades(int  Tamanio){
	Habilidad* nuevoH=new Habilidad[Tamanio];
	for(int i=0;i<GetTotalListaHabilidades();i++){
		nuevoH[i]=this->listaHabilidades[i];
	}
	if(GetTotalListaHabilidades()<0)
		delete [] this->listaHabilidades;
	this->listaHabilidades=nuevoH;
	
}
int Spcr::buscarPokemonSistema(string nombre){
	int pos=-1;
	for(int i=0;i<this->GetTotalPokedex();i++){
		if(GetPokedexPos(i)->GetNombre()==nombre){
			pos=i;
		}
	}
	return pos;
}
void Spcr::buscarEntrenadorEnSistema(){
	int pos=-1;
	string nombre="";
	cout<<"Digame el Nombre del Entrenador A buscar"<<endl;
	cin>>nombre;
	pos=buscarUsuarioNombre(nombre);
		if(pos==-1){
			cout<<"el login no exite"<<endl;
		}
		else{
			this->GetListaUsuariosPos(pos).print();
		}
}
void Spcr::importarFichero(){
	bool entrada=false;
	int posOcu=0;
	string cadena;
	int totalentrenadores=0;
	int id=0;
	string nombre;
	string passwd;
	double monedero;
	int totalPokemonMochila;
	int victorias;
	int posOcu2=0;
	int totalPokemon=0;
	int idP=0;
	string nombreP="";
	int saludP=0;
	int ataqueP=0;
	int defensaP=0;
	int velocidadP=0;
	int nivelP=0;
	double nivelTipo=0;
	Pokemon* p=0;
	int totalHabilidades=0;
	int posOcu3=0;
	int idH=0;
	string nombreH="";
	int danioH=0;
	int pp=0;
	Habilidad* h=0;
	string tipoH="";
	Entrenador* ve=0;
	fstream fichero("entrenadores.xml");
	string pausa="";
	bool encotrado=false;
   while(!fichero.eof()) {
	   fichero >> cadena;
		fichero >> cadena;
		fichero >> totalentrenadores;
		//this->listaUsuarios=new Entrenador[totalentrenadores+1];
		 //this->SetTotalUsuarios(totalentrenadores);
		 fichero >> cadena;
		 fichero >> cadena;
		
		while(posOcu < totalentrenadores){
			fichero>>cadena;
			cout<<"ojo =>"<<cadena;
			if (cadena=="</entrenador>"){
			fichero>>cadena;
				if (cadena=="<entrenador>")
					fichero>>cadena;
			}
			fichero>>id;
			fichero>>cadena;
			fichero>>cadena;
			fichero>>nombre;
			cout<<nombre<<" nombre"<<endl;
			fichero>>cadena;
			fichero>>cadena;
			fichero>>passwd;
			fichero>>cadena;
			fichero>>cadena;
			fichero>>monedero;
			fichero>>cadena;
			fichero>>cadena;
			fichero>>victorias;
			fichero>>cadena;
			fichero>>cadena;
			cout<<"esta es la cadena"<<cadena<<endl;
			redimesionarListaUsuarios(GetTotalUsuarios()+1);
			Entrenador* e1=new Entrenador(id,nombre,passwd,monedero,victorias,-1);
			this->SetListaUsuariosPos(*e1,GetTotalUsuarios());
			SetTotalUsuarios(GetTotalUsuarios()+1);
			cout<<posOcu<<"sera la poscion de este entrenador"<<endl;
			fichero>>cadena;
			fichero>>totalPokemon;		
			posOcu2=0;
			cout<<posOcu2<<"-"<<totalPokemon<<endl;
			while(posOcu2<totalPokemon){
			//this->SetTotalPokedex(this->GetTotalPokedex()+1);
			fichero>>cadena;
			fichero>>cadena;
			cout<<cadena<<"soy la cadena PRINCIPO de un POKEMON"<<posOcu2<<" | "<<totalPokemon<<endl;
			if(cadena != "<id>"){
				fichero>>cadena;
			}
				fichero>>idP;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>nombreP;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>saludP;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>ataqueP;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>defensaP;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>velocidadP;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>nivelP;
				fichero>>cadena;
				fichero>>cadena;
				cout<<cadena<<endl;
				encotrado=false;
				for(int i=0;i<GetTotalPokedex();i++){
					if(this->pokedex[i]->GetId()==idP)
						encotrado=true;
				}
				if(cadena=="<nivelplanta>"){
					fichero>>nivelTipo;
					PokemonPlanta* p1=new PokemonPlanta(idP, nombreP,saludP,ataqueP,defensaP,velocidadP,0,0,nivelTipo);
					p1->CalcularPecio();
					p1->CalcularPecioCuracion();
					if (encotrado==false){
						redimesionarPokedex(GetTotalPokedex()+1);
						SetPokedexPos(p1,GetTotalPokedex());
						SetTotalPokedex(GetTotalPokedex()+1);
					}
					this->listaUsuarios[posOcu].anadirPokemonMochila(p1);
				}
				else if(cadena=="<nivelagua>") {
					fichero>>nivelTipo;
					PokemonAgua* p1=new PokemonAgua(idP, nombreP,saludP,ataqueP,defensaP,velocidadP,0,0,nivelTipo);
					p1->CalcularPecio();
					p1->CalcularPecioCuracion();
					if(encotrado==false){
						redimesionarPokedex(GetTotalPokedex()+1);
						SetPokedexPos(p1,GetTotalPokedex());
						SetTotalPokedex(GetTotalPokedex()+1);
					}
					this->listaUsuarios[posOcu].anadirPokemonMochila(p1);
					//this->listaUsuarios[posOcu].anadirPokemonMochila(new PokemonAgua(idP, nombreP,saludP,ataqueP,defensaP,velocidadP,nivelP*35,nivelP*10,nivelTipo));
				}
				else if(cadena=="<nivelfuego>"){
					fichero>>nivelTipo;
					PokemonFuego* p1=new PokemonFuego(idP, nombreP,saludP,ataqueP,defensaP,velocidadP,0,0,nivelTipo);
					p1->CalcularPecio();
					p1->CalcularPecioCuracion();
					if(encotrado==false){
						redimesionarPokedex(GetTotalPokedex()+1);
						SetPokedexPos(p1,GetTotalPokedex());
						SetTotalPokedex(GetTotalPokedex()+1);
					}
					this->listaUsuarios[posOcu].anadirPokemonMochila(p1);
					//this->listaUsuarios[posOcu].anadirPokemonMochila(new PokemonFuego(idP, nombreP,saludP,ataqueP,defensaP,velocidadP,nivelP*35,nivelP*10,nivelTipo));
				}
				
				fichero>>cadena;
				fichero>>cadena;
				fichero>>cadena;
				fichero>>totalHabilidades;
				cout<<"total habilidades"<<totalHabilidades<<endl;
				cout<<posOcu3<<" "<<totalHabilidades<<endl;
				posOcu3=0;
				fichero>>cadena;
				fichero>>cadena;
				while(posOcu3<totalHabilidades){
					if(cadena!="<habilidad>"){
						fichero>>cadena;
					}
					fichero>>cadena;
					fichero>>idH;
					fichero>>cadena;
					fichero>>cadena;
					fichero>>nombreH;
					fichero>>cadena;
					fichero>>cadena;
					fichero>>danioH;
					fichero>>cadena;
					fichero>>cadena;
					fichero>>pp;
					fichero>>cadena;
					fichero>>cadena;
					fichero>>tipoH;
					fichero>>cadena;
					fichero>>cadena;
					cout<<cadena<<"soy la cadena final de una habilidad"<<endl;
					Habilidad* h1= new Habilidad(idH,nombreH,danioH,((danioH*pp)/10),pp,tipoH);
					encotrado=false;
					for(int i=0;i<GetTotalListaHabilidades();i++){
						if(this->listaHabilidades[i].GetId()==idH)
							encotrado=true;
					}
					if (encotrado==false){
						redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
						SetListaHabilidadesPos(*h1,GetTotalListaHabilidades());
						SettotalListaHabilidades(GetTotalListaHabilidades()+1);
					}
					this->listaUsuarios[posOcu].GetMochilaPos(posOcu2)->AnadirHabilidad(h1);
					//this->listaUsuarios[posOcu].GetMochilaPos(posOcu2)->AnadirHabilidad(h);
					//delete h;
					posOcu3++;
				}
				fichero>>cadena;
				fichero>>cadena;
				posOcu2++;
				//delete p;
				cout<<cadena<<"soy la cadena final de un POKEMON"<<posOcu2<<" | "<<totalPokemon<<endl;
				
			}
			cout<<"==============================="<<endl;
			this->listaUsuarios[GetTotalUsuarios()-1].print();
			posOcu++;
			fichero>>cadena;
			cout<<cadena<<"soy la cadena final de un MOCHILA EE"<<endl;
		}	
		
	}
  fichero.close();
}
/*void Spcr:: anadir(){
	//this->SetListaUsuariosPos(e1,GetTotalUsuarios())
	redimesionarListaUsuarios(1);
	Entrenador* e1=new Entrenador(1,"juan","juan",9999,7,-1);
	this->SetListaUsuariosPos(*e1,GetTotalUsuarios());
	SetTotalUsuarios(GetTotalUsuarios()+1);
	redimesionarListaUsuarios(GetTotalUsuarios()+1);
	Entrenador* e2=new Entrenador(2,"pepe","pepe",9999,5,-1);
	this->SetListaUsuariosPos(*e2,GetTotalUsuarios());
	SetTotalUsuarios(GetTotalUsuarios()+1);
	redimesionarListaUsuarios(GetTotalUsuarios()+1);
	Entrenador* e3=new Entrenador(3,"admin","admin",1000,15,-1);
	this->SetListaUsuariosPos(*e3,GetTotalUsuarios());
	SetTotalUsuarios(GetTotalUsuarios()+1);
	PokemonFuego* p1=new PokemonFuego(1,"Charmander",20, 7, 3,5,0,0,1.6);
	p1->CalcularPecio();
	p1->CalcularPecioCuracion();
	redimesionarPokedex(GetTotalPokedex()+1);
	SetPokedexPos(p1,GetTotalPokedex());
	SetTotalPokedex(GetTotalPokedex()+1);
	PokemonFuego* p2=new PokemonFuego(2,"cyndaquil",27, 5, 5,7,0,0,1.3);
	p2->CalcularPecio();
	p2->CalcularPecioCuracion();
	redimesionarPokedex(GetTotalPokedex()+1);
	SetPokedexPos(p2,GetTotalPokedex());
	SetTotalPokedex(GetTotalPokedex()+1);
	PokemonAgua* p3=new PokemonAgua(3,"squirtle",21,10, 2,4,0,0,1.4);
	p3->CalcularPecio();
	p3->CalcularPecioCuracion();
	redimesionarPokedex(GetTotalPokedex()+1);
	SetPokedexPos(p3,GetTotalPokedex());
	SetTotalPokedex(GetTotalPokedex()+1);
	PokemonAgua* p4=new PokemonAgua(4,"totodile",30,3, 6,7,0,0,1.1);
	p4->CalcularPecio();
	p4->CalcularPecioCuracion();
	redimesionarPokedex(GetTotalPokedex()+1);
	SetPokedexPos(p4,GetTotalPokedex());
	SetTotalPokedex(GetTotalPokedex()+1);
	PokemonPlanta* p5=new PokemonPlanta(5,"bulbasaur",20,13, 4,6,0,0,1.2);
	p5->CalcularPecio();
	p5->CalcularPecioCuracion();
	redimesionarPokedex(GetTotalPokedex()+1);
	SetPokedexPos(p5,GetTotalPokedex());
	SetTotalPokedex(GetTotalPokedex()+1);
	PokemonPlanta* p6=new PokemonPlanta(5,"chikorita",25,10, 8,4,0,0,1.4);
	p6->CalcularPecio();
	p6->CalcularPecioCuracion();
	redimesionarPokedex(GetTotalPokedex()+1);
	SetPokedexPos(p6,GetTotalPokedex());
	SetTotalPokedex(GetTotalPokedex()+1);
	Habilidad* h1= new Habilidad(1,"latigo_cepa",5,10,30,"planta");
	redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
	SetListaHabilidadesPos(*h1,GetTotalListaHabilidades());
	SettotalListaHabilidades(GetTotalListaHabilidades()+1);
	GetPokedexPos(4)->AnadirHabilidad(&(GetListaHabilidadesPos(0)));
	GetPokedexPos(5)->AnadirHabilidad(&(GetListaHabilidadesPos(0)));

	Habilidad* h2= new Habilidad(2,"pistola_agua",10,10,15,"Agua");
	redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
	SetListaHabilidadesPos(*h2,GetTotalListaHabilidades());
	SettotalListaHabilidades(GetTotalListaHabilidades()+1);
	GetPokedexPos(2)->AnadirHabilidad(&(GetListaHabilidadesPos(1)));
	GetPokedexPos(3)->AnadirHabilidad(&(GetListaHabilidadesPos(1)));
	Habilidad* h3= new Habilidad(4,"ascuas",15,10,5,"fuego");
	redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
	SetListaHabilidadesPos(*h2,GetTotalListaHabilidades());
	SettotalListaHabilidades(GetTotalListaHabilidades()+1);
	GetPokedexPos(0)->AnadirHabilidad(&(GetListaHabilidadesPos(1)));
	GetPokedexPos(1)->AnadirHabilidad(&(GetListaHabilidadesPos(1)));
	Habilidad* h4= new Habilidad(3,"surf",35,60,6,"Agua");
	redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
	SetListaHabilidadesPos(*h4,GetTotalListaHabilidades());
	SettotalListaHabilidades(GetTotalListaHabilidades()+1);
	Habilidad* h5= new Habilidad(3,"drenadoras",40,200,50,"planta");
	redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
	SetListaHabilidadesPos(*h5,GetTotalListaHabilidades());
	SettotalListaHabilidades(GetTotalListaHabilidades()+1);
	Habilidad* h6= new Habilidad(3,"lanza_llamas",70,100,15,"fuego");
	redimesionarListaHabilidades(GetTotalListaHabilidades()+1);
	SetListaHabilidadesPos(*h6,GetTotalListaHabilidades());
	SettotalListaHabilidades(GetTotalListaHabilidades()+1);
}*/
void Spcr::bienvenida(){
	cout<<"##########################################################################################################"<<endl;
	cout<<"#bienvenido al SPCR ¿desa importar datos? pulse s para importar o otra tecla para continuar sin importar #"<<endl;
	cout<<"##########################################################################################################"<<endl;
}
int Spcr::buscarUsuarioNombre(string nombre){
	int pos=-1;
	for(int i=0;i<this->GetTotalUsuarios();i++){
		cout<<"este es el nombre"<<GetListaUsuariosPos(i).GetNombre()<<endl;
		if(GetListaUsuariosPos(i).GetNombre()==nombre){
			pos=i;
		}
	}
	return pos;
}
void Spcr:: autentificacion(){
	int pos=0;
	string nombre="";
	string contrasena="";
	bool correcto=false;
	do{
		cout<<"¿login?"<<endl;
		cin>>nombre;
		pos=buscarUsuarioNombre(nombre);
		if(pos==-1){
			cout<<"el login no exite"<<endl;
		}
	}while(pos==-1);
	do{
		cout<<"¿contrasena para: "<<nombre<<" ?"<<endl;
		 cin>>contrasena;
	}while(GetListaUsuariosPos(pos).GetPassw()!=contrasena);
	this->entrenadorActivo=&listaUsuarios[pos];
	listaUsuarios[pos].print();
	cout<<"el usuario activo es "<<pos<<endl;
	this->entrenadorActivo->print();
}
void Spcr::agregarPokemonalSistema(){
	string nombre="";
	int vida=0;
	int ataque=0;
	int velocidad=0;
	int defensa=0;
	string tipo="";
	int nivel=0;
	bool  tipo_ok=false;
	int posEnc=0;
	cout<<"¿nombre?"<<endl;
	cin>>nombre;
	cout<<"¿salud?"<<endl;
	cin>>vida;
	cout<<"¿ataque?"<<endl;
	cin>>ataque;
	cout<<"¿velocidad?"<<endl;
	cin>>velocidad;
	cout<<"¿defensa?"<<endl;
	
	cin>>defensa;
	cout<<"nivel"<<endl;
	cin>>nivel;
	do{
		cout<<"¿su tipo?"<<endl;
		cin>>tipo;
		if(tipo=="planta"){
			PokemonPlanta* pkm=new PokemonPlanta(GetTotalPokedex()+1,nombre,vida,ataque, defensa,velocidad,0,0,nivel);
			tipo_ok=true;
			pkm->CalcularPecio();
			pkm->CalcularPecioCuracion();
			redimesionarPokedex(GetTotalPokedex()+1);
			SetPokedexPos(pkm,GetTotalPokedex());
			SetTotalPokedex(GetTotalPokedex()+1);
			pkm->print();
			cout<<"ahora puede añadir este nuevo pokemon a un entrenador existente en el sisema"<<endl;
			cin>>nombre;
			posEnc=buscarUsuarioNombre(nombre);
			if(posEnc !=-1){
				this->listaUsuarios[posEnc].anadirPokemonMochila(pkm);
			}
		}
		else if(tipo=="fuego"){
			PokemonFuego* pkm=new PokemonFuego(GetTotalPokedex()+1,nombre,vida,ataque, defensa,velocidad,0,0,nivel);
			tipo_ok=true;
			pkm->CalcularPecio();
			pkm->CalcularPecioCuracion();
			redimesionarPokedex(GetTotalPokedex()+1);
			SetPokedexPos(pkm,GetTotalPokedex());
			SetTotalPokedex(GetTotalPokedex()+1);
			pkm->print();
			cout<<"ahora puede añadir este nuevo pokemon a un entrenador existente en el sisema"<<endl;
			cin>>nombre;
			posEnc=buscarUsuarioNombre(nombre);
			if(posEnc !=-1){
				this->listaUsuarios[posEnc].anadirPokemonMochila(pkm);
			}
		}
		else if(tipo=="agua"){
			PokemonAgua* pkm=new PokemonAgua(GetTotalPokedex()+1,nombre,vida,ataque, defensa,velocidad,0,0,nivel);
			tipo_ok=true;
			pkm->CalcularPecio();
			pkm->CalcularPecioCuracion();
			redimesionarPokedex(GetTotalPokedex()+1);
			SetPokedexPos(pkm,GetTotalPokedex());
			SetTotalPokedex(GetTotalPokedex()+1);
			pkm->print();
			cout<<"ahora puede añadir este nuevo pokemon a un entrenador existente en el sisema"<<endl;
			cin>>nombre;
			posEnc=buscarUsuarioNombre(nombre);
			if(posEnc !=-1){
				this->listaUsuarios[posEnc].anadirPokemonMochila(pkm);
			}
		}
	}while(tipo_ok==false);
	
}


void Spcr::eliminarPokemondelSistema(){
	string nombre;
	int posEliminar=-1;
	int idBorrrar=-1;
	cout<<"digame el nombre"<<endl;
	cin>>nombre;
	posEliminar=buscarPokemonSistema(nombre);
	cout<<"esta es la poscion a eliminar: "<<posEliminar<<endl;
	cout<<"Y este es el total de pokemon (en la pokedex) antes de eliminar: "<<this->GetTotalPokedex()<<endl;
	if(posEliminar!=-1){
		Pokemon** paux=new Pokemon*[this->GetTotalPokedex()];
		for(int i=0;i<this->GetTotalPokedex()-1;i++){
			paux[i]=this->pokedex[i];
			if(i==posEliminar && this->GetTotalPokedex()-1!=posEliminar){
				cout<<"voy a cambiar la poscion "<<i<<" por la poscion"<<this->GetTotalPokedex()-1<<endl;
				paux[i]=this->pokedex[this->GetTotalPokedex()-1];
				}
		}
		for(int i=0;i<GetTotalUsuarios();i++){
			idBorrrar=this->pokedex[posEliminar]->GetId();
			if(idBorrrar != -1){
				cout<<"el id es "<<idBorrrar<<endl;
				for(int j=0;j<this->listaUsuarios[i].GetTotalPokemonMochila();j++){
					cout<<"entro en el for"<<endl;
					if(this->listaUsuarios[i].GetMochilaPos(j)->GetId()==idBorrrar)
					this->listaUsuarios[i].eliminarPokemonMochila(idBorrrar);
				}
			}
		}
		this->SetTotalPokedex((GetTotalPokedex())-1);
		delete [] this->GetPokedex();
		this->SetPokedex(paux);
		cout<<"Y este es el total de pokemon (en la pokedex) despues de eliminar: "<<this->GetTotalPokedex()<<endl;
		//this->GetPokedexPos(posEliminar)->print();
		
	}
	else 
		cout<<"no existe "<<endl;
}
void Spcr::consultarPrecioMedioMercadoPokemon(){
	double precioTotal=0;
	for(int i=0;i<this->GetTotalPokedex();i++){
		precioTotal=this->pokedex[i]->GetPrecio()+precioTotal;
	}
	precioTotal=(precioTotal)/(this->GetTotalPokedex());
	cout<<"el precio medio es: "<<precioTotal<<endl;
}
void Spcr::modificarDatosPokemonSistema(){
	int posModi=0;
	string nombre="";
	int datoEntero=0;
	cout<<"dime el nombre del pokemon a modificar"<<endl;
	cin>>nombre;
	char opcion;
	posModi=buscarPokemonSistema(nombre);
	if(posModi != -1){
			this->GetPokedexPos(posModi)->print();
			cout<<"========================================"<<endl;
			cout<<"¿que atributo quire modicar ?"<<endl;
			cout<<"1.nombre"<<endl;
			cout<<"2.vida"<<endl;
			cout<<"3.ataque"<<endl;
			cout<<"4.defensa"<<endl;
			cout<<"5.velocidad"<<endl;
			cout<<"otra tecla :nada"<<endl;
			cin>>opcion;
			switch (opcion){
				case '1':
				cout<<"¿nuevo nombre?"<<endl;
				cin>>nombre;
				this->GetPokedexPos(posModi)->SetNombre(nombre);
				break;
				case '2':
				cout<<"¿nueva vida?"<<endl;
				cin>>datoEntero;
				this->GetPokedexPos(posModi)->SetVida(datoEntero);
				break;
				case '3':
				cout<<"¿nuevo ataque?"<<endl;
				cin>>datoEntero;
				this->GetPokedexPos(posModi)->SetAtaque(datoEntero);
				break;
				case '4':
				cout<<"¿nueva defensa?"<<endl;
				cin>>datoEntero;
				this->GetPokedexPos(posModi)->SetDefensa(datoEntero);
				break;
				case '5':
				cout<<"¿nueva velocidad?"<<endl;
				cin>>datoEntero;
				this->GetPokedexPos(posModi)->SetVelocidad(datoEntero);
				break;
				
				default:
				cout<<"ningun atributo cambiado"<<endl;
				break;
			}
			this->GetPokedexPos(posModi)->CalcularPecio();
			this->GetPokedexPos(posModi)->CalcularPecioCuracion();
			this->GetPokedexPos(posModi)->print();
	}
	else
		cout<<"No encontrado"<<endl;
}
void Spcr::agregarNuevoEntrenadoSistema(){
	string nombre="";
	string passw="";
	double monedro=0;
	int victorias=0;
	Entrenador* ent=0;
	cout<<"¿nombre?"<<endl;
	cin>>nombre;
	cout<<"¿contrasena?"<<endl;
	cin>>passw;
	cout<<"¿valor del monedero?"<<endl;
	cin>>monedro;
	cout<<"¿victorias?"<<endl;
	cin>>victorias;
	ent=new Entrenador(GetTotalUsuarios()+1,nombre,passw,monedro,victorias,-1);
	redimesionarListaUsuarios(GetTotalUsuarios()+1);
	this->SetListaUsuariosPos(*ent,GetTotalUsuarios());
	SetTotalUsuarios(GetTotalUsuarios()+1);
	this->GetListaUsuariosPos(GetTotalUsuarios()-1).print();
	
}
void Spcr::eliminarEntrenadordelSistema(){//

	string nombre;
	int posEliminar=-1;
	cout<<"digame el nombre"<<endl;
	cin>>nombre;
	posEliminar=buscarUsuarioNombre( nombre);
	cout<<"este es el total de usuarios antes de eliminar "<<this->GetTotalUsuarios()<<"...."<<posEliminar<<endl;
	if(posEliminar!=-1){
		Entrenador* paux=new Entrenador[this->GetTotalUsuarios()];
		for(int i=0;i<this->GetTotalUsuarios();i++){
			paux[i]=this->listaUsuarios[i];
			if(i==posEliminar && posEliminar!=GetTotalUsuarios()-1){
				paux[i]=this->listaUsuarios[this->GetTotalUsuarios()-1];
			}
		}
		//delete [] this->listaUsuarios;
		if(posEliminar!=GetTotalUsuarios()-1){
			this->SetListaUsuarios(paux);
		}
		this->SetTotalUsuarios((GetTotalUsuarios())-1);
		cout<<"este es el total de usuarios despues de eliminar "<<this->GetTotalUsuarios()<<endl;
		//this->GetListaUsuariosPos(posEliminar).print();
	}
	else 
	cout<<"no existe"<<endl;
		
}

void Spcr::modificarDatosEntrenadorSitema(){
	int pos=0;
	string nombre="";
	string passwd="";
	int datoEntero=0;
	char opcion;
	cout<<"dime el nombre usuario modificar"<<endl;
	cin>>nombre;
	
	pos=buscarUsuarioNombre(nombre);
	if(pos != -1){
			this->GetListaUsuariosPos(pos).print();
			cout<<"========================================"<<endl;
			cout<<"¿que atributo quire modicar ?"<<endl;
			cout<<"1.nombre"<<endl;
			cout<<"2.contraseña"<<endl;
			cout<<"3.monedero"<<endl;
			cout<<"4.victorias"<<endl;
			cout<<"otra tecla :nada"<<endl;
			cin>>opcion;
			switch (opcion){
				case '1':
				cout<<"¿nuevo nombre?"<<endl;
				cin>>nombre;
				this->listaUsuarios[pos].SetNombre(nombre);
				cout<<this->GetListaUsuariosPos(pos).GetNombre()<<"SERA EL NOMBRE"<<endl;
				break;
				case '2':
				cout<<"¿nueva contrasena?"<<endl;
				cin>>nombre;
				this->listaUsuarios[pos].SetPassw(passwd);
				break;
				case '3':
				cout<<"¿nuevo valor del monedero?"<<endl;
				cin>>datoEntero;
				this->listaUsuarios[pos].SetMonedero(datoEntero);
				break;
				case '4':
				cout<<"¿nuevas victorias?"<<endl;
				cin>>datoEntero;
				this->listaUsuarios[pos].SetVictorias(datoEntero);
				break;
				default:
				cout<<"ningun atributo cambiado"<<endl;
				break;
			}
			//this->GetListaUsuariosPos(pos).calcularValorEntrenador();
			//this->GetListaUsuariosPos(pos).calcularValorMochila();
			this->GetListaUsuariosPos(pos).print();
	}
	else
		cout<<"No encontrado"<<endl;
}
void Spcr::consultarListaPokemon(){
	int pos=0;
	string nombre="";
		cout<<"dime el nombre usuario a imprimir"<<endl;
		cin>>nombre;
	
	pos=buscarUsuarioNombre(nombre);
	this->GetListaUsuariosPos(pos).print();
}
void Spcr::comprarPokemon(){
	int pos=0;
	int pos2=0;
	int pos3=0;
	string nombre="";
		cout<<"dime el nombre usuario a que va hacer la compra"<<endl;
		cin>>nombre;
		pos=buscarUsuarioNombre(nombre);
		cout<<"digame el nombre del pokemon a comprar"<<endl;
		cin>>nombre;
		pos2=buscarPokemonSistema(nombre);
		cout<<"¿a que usuario le quire comprar el pokemon?"<<endl;
		cin>>nombre;
		pos3=buscarUsuarioNombre(nombre);
		if(pos!=-1 && pos2!=-1 && pos!=pos3 && pos3!=-1){
			this->listaUsuarios[pos].comprarPokemon(this->pokedex[pos2]);
			this->listaUsuarios[pos3].eliminarPokemonMochila(this->pokedex[pos2]->GetId());
			cout<<"este es el resultado"<<endl;
			this->listaUsuarios[pos].print();
			this->listaUsuarios[pos3].print();
		}
		else 
			cout<<"algun dato no existe"<<endl;
		
}
void Spcr::venderPokemon(){
	int pos=0;
	int pos2=0;
	int id=0;
	string nombre="";
		cout<<"dime el nombre usuario a que va hacer la venta "<<endl;
		cin>>nombre;
		pos=buscarUsuarioNombre(nombre);
		cout<<"digame el nombre del pokemon a vender "<<endl;
		cin>>nombre;
		pos2=buscarPokemonSistema(nombre);
		if(pos!= -1 && pos2 != -1){
			id=GetPokedexPos(pos2)->GetId();
			this->listaUsuarios[pos].SetMonedero(this->GetPokedexPos(pos2)->GetPrecio()+this->listaUsuarios[pos].GetMonedero());
			this->listaUsuarios[pos].eliminarPokemonMochila(id);
		}
		else 
			cout<<"algun dato no existe"<<endl;
}
void Spcr::curarPokemon(){
	string nombre="";
	int pos=0;
	int pos2=0;
	int id=0;
	int posCura=0;
	cout<<"dime el nombre usuario a que va hacer curar a su pokemon (poner la salud a 100) "<<endl;
	cin>>nombre;
	pos=buscarUsuarioNombre(nombre);
	cout<<"digame el nombre del pokemon a curar"<<endl;
	cin>>nombre;
	pos2=buscarPokemonSistema(nombre);
	id=GetPokedexPos(pos2)->GetId();
	cout<<id<<endl;
	posCura=this->listaUsuarios[pos].buscarPokemon(id);
	if(pos!= -1 && pos2 != -1){
		this->listaUsuarios[pos].GetMochilaPos(posCura)->CalcularPecioCuracion();
		if(this->listaUsuarios[pos].GetMochilaPos(posCura)->GetPrecioCurar()<=this->listaUsuarios[pos].GetMonedero()){
			this->listaUsuarios[pos].GetMochilaPos(posCura)->curacion();
			this->listaUsuarios[pos].SetMonedero(this->listaUsuarios[pos].GetMonedero()-this->listaUsuarios[pos].GetMochilaPos(posCura)->GetPrecioCurar());
		}
		else{
			cout<<"no tienes dinero :("<<endl;
		}
	}
	else 
		cout<<"no encontrado"<<endl;
}
void Spcr::asignarHabilidadPokemon(){
	int pos=0;
	int pos2=0;
	string nombre="";
	int pospoke=0;
	int posH=0;
	int id=0;
	cout<<"dime el nombre usuario "<<endl;
	cin>>nombre;
	pos=buscarUsuarioNombre(nombre);
	cout<<"digame el nombre del pokemon "<<endl;
	cin>>nombre;
	pos2=buscarPokemonSistema(nombre);
	if(pos!= -1 && pos2 != -1){
		id=GetPokedexPos(pos2)->GetId();
		pospoke=this->listaUsuarios[pos].buscarPokemon(id);
		cout<<"digame el nombre de la habilidad a añadir"<<endl;
		cin>>nombre;
		cout<<"TOTAL HABILIDADES: "<<GetTotalListaHabilidades()<<endl;
		for(int i=0;i<this->GetTotalListaHabilidades();i++){
			cout<<listaHabilidades[i].GetNombre()<<endl;
			if(listaHabilidades[i].GetNombre()==nombre){
				posH=i;
			}
		}
		cout<<posH<<endl;
		this->listaUsuarios[pos].GetMochilaPos(pospoke)->AnadirHabilidad(&(GetListaHabilidadesPos(posH)));
	}
	else
		cout<<"no encontrado"<<endl;
}
void Spcr::desasignarHabilidadPokemon(){
	int pos=0;
	int pos2=0;
	string nombre="";
	int pospoke=0;
	int posH=0;
	int id=0;
	cout<<"dime el nombre usuario "<<endl;
	cin>>nombre;
	pos=buscarUsuarioNombre(nombre);
	cout<<"esta es la posicon"<<pos;
	cout<<"digame el nombre del pokemon "<<endl;
	cin>>nombre;
	pos2=buscarPokemonSistema(nombre);
	cout<<"esta es la posicon"<<pos2;
	if(pos!= -1 && pos2 != -1){
		id=GetPokedexPos(pos2)->GetId();
		pospoke=this->listaUsuarios[pos].buscarPokemon(id);
		cout<<"digame el nombre de la habilidad a borrar"<<endl;
		cin>>nombre;
		for(int i=0;i<this->GetTotalListaHabilidades();i++){
			if(listaHabilidades[i].GetNombre()==nombre){
				posH=i;
			}
		}
		this->listaUsuarios[pos].GetMochilaPos(pospoke)->BorrarHabilidad(posH);
	}
	else 
		cout<<"no encontrado"<<endl;
	
}
void Spcr::rankingTop3GeneralPokemon(){
	string pausa;
	bool entrada=true;
	Pokemon* aux;
	int cont=1;
	cout<<GetTotalUsuarios()<<endl;
	cin>>pausa;
	int pos=0;
	for(int i=0; i<this->GetTotalPokedex();i++){
		this->pokedex[i]->CalcularPecio();
	}
	for(int izq=0;entrada==true && izq<this->GetTotalPokedex();izq++){
		entrada=false;
		for(int i=this->GetTotalPokedex()-1; i>izq;i--){
			if(this->pokedex[i]->GetPrecio()< this->pokedex[i-1]->GetPrecio()){
					entrada=true;
					aux=pokedex[i];
					pokedex[i]=pokedex[i-1];
					pokedex[i-1]=aux;
				}
		}
	}
	for(int i=this->GetTotalPokedex()-1;i>=this->GetTotalPokedex()-3;i--){
		cout<<" POKEMON NUMERO "<<cont<<endl;
		pokedex[i]->print();
		cont++;
	}
	for(int i=0;i<this->GetTotalPokedex();i++){
		if(pokedex[i]->GetAtaque()>=pokedex[pos]->GetAtaque()){
			pos=i;
		}
	}
	cout<<"y este es el pokemon con el memjor ataque"<<endl;
	pokedex[pos]->print();
	pos=0;
	for(int i=0;i<this->GetTotalPokedex();i++){
		if(pokedex[i]->GetDefensa()<=pokedex[pos]->GetDefensa()){
			pos=i;
		}
	}
	cout<<"y este es el pokemon con la peor defensa"<<endl;
	pokedex[pos]->print();
}
void Spcr::rankingDeEntrenadores(){
	bool entrada=true;
	Entrenador aux;
	int cont=1;
	string pausa;
	for(int i=0; i<GetTotalUsuarios();i++){
		cout<<"En el for"<<i<<endl;
		//this->listaUsuarios[i].calcularValorEntrenador();
		listaUsuarios[i].print();
	}
	cout<<GetTotalUsuarios()<<endl;
	cin>>pausa;
	for(int izq=0;entrada==true && izq<this->GetTotalUsuarios();izq++){
		entrada=false;
		for(int i=this->GetTotalUsuarios()-1; i>izq;i--){
			if(this->listaUsuarios[i].GetValoracionEntrenador()< this->listaUsuarios[i-1].GetValoracionEntrenador()){
					entrada=true;
					aux=listaUsuarios[i];
					listaUsuarios[i]=listaUsuarios[i-1];
					listaUsuarios[i-1]=aux;
				}
		}
	}
	cout<<this->GetTotalUsuarios()<<endl;
	for(int i=this->GetTotalUsuarios()-1;i!=-1;i--){
		cout<<" Entrenador NUMERO "<<i<<" de"<<this->GetTotalUsuarios()<<endl;
		listaUsuarios[i].print();
		cont++;
	}
}
void Spcr::rankingTop3PorTipoPokemon(){
	string tipo="";
	string tipoInstrospecion="";
	int contador=0;
	bool entrada=true;
	Pokemon* aux;
	Pokemon** pok=new Pokemon*[this->GetTotalPokedex()];
	cout<<"digame el tipo de pokemon del cual quire que le haga el ranking"<<endl;
	cin>>tipo;
	int cont2=0;
	for(int i=0;i<this->GetTotalPokedex();i++){
		if(PokemonAgua *p = dynamic_cast<PokemonAgua *>(pokedex[i])){
			tipoInstrospecion="agua";
			if(tipo==tipoInstrospecion){
				pok[contador]=pokedex[i];
				contador++;
			}
			
		}
		if(PokemonFuego *p = dynamic_cast<PokemonFuego *>(pokedex[i])){
			tipoInstrospecion="fuego";
			if(tipo==tipoInstrospecion){
				pok[contador]=pokedex[i];
				contador++;
			}
			
		}
		if(PokemonPlanta *p = dynamic_cast<PokemonPlanta *>(pokedex[i])){
		 tipoInstrospecion="planta";
		 if(tipo==tipoInstrospecion){
				pok[contador]=pokedex[i];
				contador++;
			}
		cout<<"planta ok"<<endl;
		}
	}
	for(int izq=0;entrada==true && izq<contador;izq++){
		entrada=false;
		for(int i=contador-1; i>izq;i--){
			if(pok[i]->GetPrecio()< pok[i-1]->GetPrecio()){
					entrada=true;
					aux=pok[i];
					pok[i]=pok[i-1];
					pok[i-1]=aux;
				}
		}
	}
	cout<<"este es el ranking"<<endl;
	cout<<contador<<"es el valor del contador"<<endl;
	for(int i=contador-1;cont2<3 && cont2<contador;i--){
		pok[i]->print();
		cont2++;
	}
}
void Spcr::exportarFichero(){
	ofstream fichero;
	fichero.open("guardado.xml");
	fichero<<"<entrenadores>"<<endl;
	fichero<<"\t <totalentrenadores> "<<GetTotalUsuarios()<<" </totalentrenadores>"<<endl;
	for(int i=0;i<GetTotalUsuarios();i++){
		fichero<<"\t <entreandor>"<<endl;
		fichero<<"\t\t<id> "<<this->listaUsuarios[i].GetId()<<" </id>"<<endl;
		fichero<<"\t\t<login> "<<this->listaUsuarios[i].GetNombre()<<" </login>"<<endl;
		fichero<<"\t\t<password> "<<this->listaUsuarios[i].GetPassw()<<" </password>"<<endl;
		fichero<<"\t\t<monedero> "<<this->listaUsuarios[i].GetMonedero()<<" </monedero>"<<endl;
		fichero<<"\t\t<victorias> "<<this->listaUsuarios[i].GetVictorias()<<" </victorias>"<<endl;
		fichero<<"\t\t<mochila>"<<endl;
		fichero<<"\t\t\t<totalpokemonMochila> "<<this->listaUsuarios[i].GetTotalPokemonMochila()<<" </totalpokemonMochila>"<<endl;
		for(int j=0;j<this->listaUsuarios[i].GetTotalPokemonMochila();j++){
			fichero<<"\t\t\t<pokemon>"<<endl;
			fichero<<"\t\t\t\t<id> "<< this->listaUsuarios[i].GetMochilaPos(j)->GetId()<<" </id>"<<endl;
			fichero<<"\t\t\t\t<name> "<< this->listaUsuarios[i].GetMochilaPos(j)->GetNombre()<<" </name>"<<endl;
			fichero<<"\t\t\t\t<HP> "<< this->listaUsuarios[i].GetMochilaPos(j)->GetVida()<<" </HP>"<<endl;
			fichero<<"\t\t\t\t<ATK> "<< this->listaUsuarios[i].GetMochilaPos(j)->GetAtaque()<<" </ATK>"<<endl;
			fichero<<"\t\t\t\t<DEF> "<< this->listaUsuarios[i].GetMochilaPos(j)->GetDefensa()<<" </DEF>"<<endl;
			fichero<<"\t\t\t\t<SPD> "<< this->listaUsuarios[i].GetMochilaPos(j)->GetVelocidad()<<" </SPD>"<<endl;
			fichero<<"\t\t\t\t<nivel> "<< 1 <<" </nivel>"<<endl;
			if(PokemonAgua *p = dynamic_cast<PokemonAgua *>(this->listaUsuarios[i].GetMochilaPos(j))){
				fichero<<"\t\t\t\t<nivelagua> "<< 1.5<<" </nivelagua>"<<endl;
			}	
			if(PokemonFuego *p = dynamic_cast<PokemonFuego *>(this->listaUsuarios[i].GetMochilaPos(j))){
				fichero<<"\t\t\t\t<nivelfuego> "<<1.5<<" </nivelfuego>"<<endl;
					
			}
			if(PokemonPlanta *p = dynamic_cast<PokemonPlanta *>(this->listaUsuarios[i].GetMochilaPos(j))){
				fichero<<"\t\t\t\t<nivelplanta> "<<1.5<<" </nivelplanta>"<<endl;
			
			}
			fichero<<"\t\t\t\t<habilidades>"<<endl;
			fichero<<"\t\t\t\t\t<totalhabilidades> "<<this->listaUsuarios[i].GetMochilaPos(j)->GetTotalHabilidades()<<" </totalhabilidades>"<<endl;
			
			for(int k=0;k<this->listaUsuarios[i].GetMochilaPos(j)->GetTotalHabilidades();k++){
				cout<<k<<endl;
				fichero<<"\t\t\t\t\t<habilidad>"<<endl;
				fichero<<"\t\t\t\t\t\t<id> "<<this->listaUsuarios[i].GetMochilaPos(j)->GetVectorHabilidadesPos(k).GetId()<<" </id>"<<endl;
				fichero<<"\t\t\t\t\t\t<nombre> "<<this->listaUsuarios[i].GetMochilaPos(j)->GetVectorHabilidadesPos(k).GetNombre()<<" </nombre>"<<endl;
				fichero<<"\t\t\t\t\t\t<danio> "<<this->listaUsuarios[i].GetMochilaPos(j)->GetVectorHabilidadesPos(k).GetDano()<<" </danio>"<<endl;
				fichero<<"\t\t\t\t\t\t<PP> "<<this->listaUsuarios[i].GetMochilaPos(j)->GetVectorHabilidadesPos(k).GetPp()<<" </PP>"<<endl;
				fichero<<"\t\t\t\t\t\t<tipo> "<<this->listaUsuarios[i].GetMochilaPos(j)->GetVectorHabilidadesPos(k).GetTipo()<<" </tipo>"<<endl;
				fichero<<"\t\t\t\t\t</habilidad>"<<endl;
			}
			fichero<<"\t\t\t\t</habilidades>"<<endl;
			fichero<<"\t\t\t</pokemon>"<<endl;
		}
		
		fichero<<"\t\t</mochila>"<<endl;
		fichero<<"\t </entreandor>"<<endl;
	}
	fichero<<"</entrenadores>"<<endl;
	fichero.close();
}
void Spcr::buscarPokemonConLista(){
int pos=0;
int totalListaBusqueda=0;
int elec=0;
string nombre;
Pokemon** paux;
	do{
		cout<<"digame el nombre del pokemon que quire buscar"<<endl;
		cin>>nombre;
		pos=buscarPokemonSistema(nombre);
		if(pos != -1){
			paux=new Pokemon*[totalListaBusqueda +1];
			for(int i=0;i<totalListaBusqueda;i++){
				paux[i]=this->entrenadorActivo->GetlistaBusquedaPos(i);
			}
			if(totalListaBusqueda != 0 ){
				delete this->entrenadorActivo->GetlistaBusqueda();
			}
			this->entrenadorActivo->SetListaBusqueda(paux);
			this->entrenadorActivo->SetListaBusquedaPos(this->GetPokedexPos(pos),totalListaBusqueda);
			totalListaBusqueda++;
			for(int i=0;i<totalListaBusqueda;i++){
				this->entrenadorActivo->GetlistaBusquedaPos(totalListaBusqueda-1)->print();
			}
		}
		else{
			cout<<"No encontrado"<<endl;
		}
		cout<<"si quire seguir buscando pokemons pulse 1"<<endl;
		cin>>elec;
	}while(elec==1);
}
void Spcr::jugarBatalla(){
	int pos=0;
	int posAtaque=0;
	int poscionPokemonActivo=-1;
	string nombre="";
	int turno=0;
	cout<<"¿contra que usuario luchar?"<<endl;
	cin>>nombre;
	bool entreador1Pierde=false;
	bool entreador2Pierde=false;
	pos=buscarUsuarioNombre(nombre);
	if(pos!=-1){
		cout<<"turno del entreandor"<<this->entrenadorActivo->GetNombre()<<endl;
		for(int i=0;i<this->entrenadorActivo->GetTotalPokemonMochila();i++){
			cout<<"POKEMON Numero"<<i<<endl;
			this->entrenadorActivo->GetMochilaPos(i)->print();
		}
		do{
			cout<<"selecione su pokemon con el numero"<<endl;
			cin>>poscionPokemonActivo;
		}while(poscionPokemonActivo<0 || poscionPokemonActivo >= this->entrenadorActivo->GetTotalPokemonMochila());
		this->entrenadorActivo->SetPokemonActivo(poscionPokemonActivo);
		cout<<this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetNombre()<<" sera el proximo pokemon de "<<this->entrenadorActivo->GetNombre()<<endl;
		cout<<"ahora selecionara su pokemon el entrenador "<<this->listaUsuarios[pos].GetNombre()<<endl;
		for(int i=0;i<this->listaUsuarios[pos].GetTotalPokemonMochila();i++){
			cout<<"POKEMON Numero"<<i<<endl;
			this->listaUsuarios[pos].GetMochilaPos(i)->print();
		}
		do{
			cout<<"selecione su pokemon con el numero"<<endl;
			cin>>poscionPokemonActivo;
		}
		while(poscionPokemonActivo<0 || poscionPokemonActivo >= this->listaUsuarios[pos].GetTotalPokemonMochila());
		this->listaUsuarios[pos].SetPokemonActivo(poscionPokemonActivo);
		cout<<this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->GetNombre()<<"sera el proximo Pokemon de"<<this->listaUsuarios[pos].GetNombre();
		cout<<"que comienze la batalla"<<endl;
		cout<<this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetNombre()<<" VS"<<this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->GetNombre()<<endl;
		do{
			cout<<"tunro de "<<this->listaUsuarios[pos].GetNombre()<<endl;
			for(int i=0;i<this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->GetTotalHabilidades();i++){
				this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->GetVectorHabilidadesPos(i).print();
			}
			do{
				cout<<"selecione el ataque porfavor"<<endl;
				cin>>posAtaque;
			}while(posAtaque<0 || posAtaque>=this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->GetTotalHabilidades() );
			this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->recibirDanoDePokemon(this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo()),posAtaque);
			//cout<<"es la vida"<<this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetVida()<<endl;
			if(this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetVida()<=0){
				cout<<"entrenador1 pierde"<<endl;
				entreador1Pierde=true;
			}
			if(entreador1Pierde==false){
					cout<<"turno de "<<this->entrenadorActivo->GetNombre()<<endl;
					for(int i=0;i<this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetTotalHabilidades();i++){
						this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetVectorHabilidadesPos(i).print();
					}
				do{
				cout<<"selecione el ataque porfavor"<<endl;
				cin>>posAtaque;
				}while(posAtaque<0 || posAtaque>=this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo())->GetTotalHabilidades());
				this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->recibirDanoDePokemon(this->entrenadorActivo->GetMochilaPos(this->entrenadorActivo->GetPokemonActivo()),posAtaque);
				if(this->listaUsuarios[pos].GetMochilaPos(this->listaUsuarios[pos].GetPokemonActivo())->GetVida()<=0){
					cout<<"entrenador2 pierde"<<endl;
					entreador2Pierde=true;
				}
			}
		}while(entreador1Pierde==false && entreador2Pierde==false );
		if(entreador1Pierde=true){
			cout<<"el ganador es : "<<this->entrenadorActivo->GetNombre()<<endl;
		}
		else{
			cout<<"el ganador es : "<<this->listaUsuarios[pos].GetNombre()<<endl;
		}
	}
	else
		cout<<"no se encutra el entrenador"<<endl;
}
void Spcr::menuPrincipal(){
	bool salir=false;
	char opcion;
	string nombre="";
	string pause="";
	int pos=0;
	string elecion="";
	do{	
		cout<< YELLOW_COLOR;
		cout<<"###############################menu SPCR################################################"<<endl;
		cout<<"# 1.Importar Datos al Sistema desde Ficheros *.xml                                     #"<<endl;
		cout<<"# 2.Exportar Datos del Sistema a Ficheros *.xml                                        #"<<endl;
		cout<<"# 3.Ranking Top3 General Pokemon                                                       #"<<endl;
		cout<<"# 4.Ranking Top3 por Tipo de Pokemon                                                   #"<<endl;
		cout<<"# 5.Ranking Entrenadores                                                               #"<<endl;
		cout<<"# 6.Agregar Nuevo Pokemon al Sistema                                                   #"<<endl;
		cout<<"# 7.Eliminar Pokemon del Sistema                                                       #"<<endl;
		cout<<"# 8.Buscar Pokemon en el Sistema                                                       #"<<endl;
		cout<<"# 9.Modificar Datos Pokemon del Sistema                                                #"<<endl;
		cout<<"# A.Consultar Precio Medio Pokemon en el Sistema                                       #"<<endl;
		cout<<"# B.Agregar Nuevo Entrenador  al Sistema                                               #"<<endl;
		cout<<"# C.Eliminar Entrenador  del Sistema                                                   #"<<endl;
		cout<<"# D.Buscar Entrenador en el Sistema                                                    #"<<endl;
		cout<<"# E.Modificar Datos Entrenador del Sistema                                             #"<<endl;
		cout<<"# F.Consultar Lista de Pokemon y Ver el Estado de los Mismos                           #"<<endl;
		cout<<"# G.Comprar Pokemon                                                                    #"<<endl;
		cout<<"# H.Vender Podemon                                                                     #"<<endl;
		cout<<"# I.Curar Pokemon                                                                      #"<<endl;
		cout<<"# J.Asignar Habilidad a Pokemon                                                        #"<<endl;
		cout<<"# K.Desasignar Habilidad a Pokemon                                                     #"<<endl;
		cout<<"# L.Luchar                                                                             #"<<endl;
		cout<<"# M.salir                                                                              #"<<endl;
		cout<<"# N.print de todo lo importado                                                         #"<<endl;
		cout<<"# O.print de la lista de pokemon                                                       #"<<endl;
		cout<<"# p.print de la lista de habilidades                                                   #"<<endl;
		cout<<"# Q.limpiar pantalla y mostrar la ruta de trabajo                                      #"<<endl;
		cout<<"########################################################################################"<<endl;
		cout<<NORMAL;
		cin>>opcion;
	    switch (opcion){
		case '1':
		importarFichero();
		break;
		case '2':
		exportarFichero();
		break;
		case '3':
		rankingTop3GeneralPokemon();
		break;
		case '4':
		rankingTop3PorTipoPokemon();
		break;
		case '5':
		rankingDeEntrenadores();
		break;
		case '6':
		agregarPokemonalSistema();
		break;
		case '7':
		eliminarPokemondelSistema();
		break;
		case '8':
		buscarPokemonConLista();
		cin>>pause;
		break;
		case '9':
			modificarDatosPokemonSistema();
			cin>>pause;
		break;
		case 'A':
		consultarPrecioMedioMercadoPokemon();
		break;
		case 'B':
		agregarNuevoEntrenadoSistema();
		break;
		case 'C':
		eliminarEntrenadordelSistema();
		break;
		case 'D':
		buscarEntrenadorEnSistema();
		break;
		case 'E':
		modificarDatosEntrenadorSitema();
		break;
		case 'F':
		consultarListaPokemon();
		break;
		case 'G':
		comprarPokemon();
		break;
		case 'H':
		venderPokemon();
		break;
		case 'I':
		curarPokemon();
		break;
		case 'J':
		asignarHabilidadPokemon();
		break;
		case 'K':
		desasignarHabilidadPokemon();
		break;
		case 'L':
		jugarBatalla();
		break;
		case 'M':
		salir=true;
		break;
		case 'N':
		for(int i=0;i<GetTotalUsuarios();i++){
			cout<<"posicion numero"<<i<<endl;
			cout<<listaUsuarios[i].GetNombre()<<endl;
			cout<<"¿quiere sus datos completos?"<<endl;
			cin>>elecion;
			if(elecion=="s"){
				this->listaUsuarios[i].print();
			}
			
		}
		break;
		case 'O':
		for(int i=0;i<GetTotalPokedex();i++){
			pokedex[i]->print();
		}
		break;
		case 'P':
		for(int i=0;i<GetTotalPokedex();i++){
			listaHabilidades[i].print();
		}
		break;
		case 'Q':
		system("clear");
		cout<<"esta es la ruta de trabajo"<<endl;
		system("pwd");
		break;
		default:
		cout<<"opcion no contemplada"<<endl;
		
		}
	}while(salir==false);
}

#endif