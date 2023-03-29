#include <iostream>

using namespace std;

int main(){
	int contador=0; 
	long double numero=0 ;
	long double  maximo=0,minimo=0;
	bool entrada = false ;
	
	while(contador != 100){
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
