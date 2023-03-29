#include <iostream>

using namespace std;

int main(){

int toro_velocidad=0,numero_de_toros;//LAS entradas
int i=0;
int v_max=0;////las salidas

do{
	cout<<"digame cuantos toros hay "<<endl;
	cin>>numero_de_toros;
	if (numero_de_toros<=0){
		cout<<"debe de haber almenos un toro en la carrera insertelo otra vez"<<endl;
	}
}
//procesamientio del programa 
while (numero_de_toros<=0);// debe de haber un toro al menos en la carrera por lo que si introduce un numero mas pqueño se le pregunta otra vez 

for (i=0;i<numero_de_toros && toro_velocidad !=-1 ;i++){
	do {//este bucle controla que la velcidad no sea negativa ni mayor que 100 pero si puede ser -1 
		cout<<"digame la velocidad de un toro si introduce -1 se entiede que usted no quire intrducir 	mas velocdidades "<<endl;
		cin>>toro_velocidad;
		if (toro_velocidad>v_max){
			v_max=toro_velocidad;
		}
		if(toro_velocidad <= 0 &&  toro_velocidad != -1  || toro_velocidad>=100){
		cout<<"la velocidad debe de estrar por encima de 0 o ser -1 o estar por encima de 100"<<endl;
		}
		
	}
	while (toro_velocidad>= -1 && toro_velocidad != 0 && toro_velocidad>=100);
	cout<<"la velocidad que debe de llevar el corredor por ahora es "<<v_max<<endl;
}

}
