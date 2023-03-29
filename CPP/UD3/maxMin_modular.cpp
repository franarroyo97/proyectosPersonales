#include <iostream>

using namespace std;

long double  max_min(int veces){//el numero de veces que se le preguntara al usuario
int contador=0; 
long double numero=0 ;//por si el usuario introduce un numero muy grande 
long double  maximo=0,minimo=0;//por si el usuario introduce un numero muy grande 
bool entrada = false ;
while(contador != veces){
		cout << "¿numero?"<<endl;
		cin>>numero;
		if ( entrada == false ){
			maximo = numero;
			minimo = numero;
			entrada = true ;
		}
		if (numero>maximo){
			maximo=numero;
		}
		if(numero<minimo){
			minimo=numero;
		}
		contador ++;
	}
	cout<<"el minimo es: "<<minimo<<"maximo es: "<<maximo<<endl;
}
int main(){
int numero;
cout <<"¿cuantos numeros vas a comprar ?"<<endl;
cin>>numero;
max_min(numero);
}
