#include<iostream>
using namespace std;
/*
@brief esta funcion muestra al usuario un menu con la bienvenida , la lista de precios y la opcion para salir 
@pre ningua precondicion
@post ningua postcondicion
@return nada
@autor Francisco Arroyo Lopez
@ver 1.0
*/
void menu(){
	cout<<"hola usuario le mostrara el toral de horas que deben de pagar por esacionarse  "<<endl;
	cout<<"*************lista de precios***************"<<endl;
	cout<<"* de 0H a 3H ------------------------- 2 € *"<<endl;
	cout<<"* desde 3h a 24-------------------- 0.5€/h *"<<endl;
	cout<<"* 24H----------------------------------10h *"<<endl;
	cout<<"********************************************"<<endl;
	cout<<"pulse s para dejar de añadir coches "<<endl;
}
/*
@brief esta funcion controla que las horas introducidas son corectas
@pre que el usuaro nos de una hora es decir que exita una varaible de tipo double para comparar
@post coche_horas > 0  && coche_horas <=24
@return resultado del control (ture o false )
@autor Francisco Arroyo Lopez
@ver 1.0
*/
bool control(double numero_horas){
	bool control=false ;
	if (numero_horas > 0  && numero_horas<=24){
		control=true ;
	}
	return control;
}
/*
@brief esta funcion se encarga de cacular cuanto va a pagar el coche e ir sumadolo al toal
@pre coche_horas > 0  && coche_horas <=24
@post nada
@return total_dinero y total_horas y el cargo_actual
@autor Francisco Arroyo Lopez
@ver 1.0
*/
void anadir_coche(double coche_horas , double  &total_dinero ,double &total_horas , double &actual_dinero){
	total_horas = coche_horas + total_horas;
	if (coche_horas <=3 ){
		actual_dinero=2;
	}
	else{ 
	 	 if (coche_horas > 3.0 && coche_horas < 24.0 ){
			coche_horas=coche_horas-3.0;
			actual_dinero=2.0+(coche_horas*0.5);
		}
		else 
		actual_dinero=10.0;
	}
	total_dinero=actual_dinero+total_dinero;
	
	
}
/*
@brief esta funcion muestra al usuario un mensaje de salida  
@pre que sea  fin del programa
@post el programa termina 
@return nada 
@autor Francisco Arroyo Lopez
@ver 1.0
*/
void despedida (){
cout<<"adios.."<<endl;
}
int main(){
	//1ºdeclaracion de variables 
	double  coche_horas=0.0;
	double  total_horas=0.0 , total_dinero=0.0,cargo_actual=0.0;
	char salirOContinuar ='a';
	bool control_r=false; 
	//2ºse muestra un menu por pantalla con la opcion para salir y la lista de precios
	menu();
	//3ºse piede al usuario que inroduzca coches mientras no pulse la tecla de salida 

	do{//por si el usuario tiene sin darse cuenta las mayusculas activadas
		if (!((salirOContinuar == 's') || ( salirOContinuar =='S'))){
			do{
				cout <<" \n digame el numero de horas que ha estado : ";
				cin>>coche_horas;
				//4º se ejerce un control sobre las horas de coche y si es postiva se añade las horas a la cuenta si no pide las horas otra vez
				control_r = control(coche_horas);
			}
			while (control_r==false );
		}
		anadir_coche(coche_horas,total_dinero,total_horas,cargo_actual);
		cout<<" el cargo actual es : "<<cargo_actual;
		cargo_actual=0;

		cout<<"\n introduzca cualquir telca para añadir otro coche o pulse s para salir : ";
		cin>>salirOContinuar;
	}
	while (!((salirOContinuar == 's') || ( salirOContinuar =='S' )) );

	//5ºse muestra al usuario el total
	cout<<" el total de horas son : "<<total_horas<<"y el total del dinero es "<<total_dinero<<endl;

	//6ºdespedida (fin de interfaz)
	despedida();
}
