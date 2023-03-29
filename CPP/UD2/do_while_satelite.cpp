#include <iostream>

using namespace std;

int main(){
	int numero=1; 
	
	cout<<"satelite listo para recibir sus datos ( en formato numerico) para dejar de trasmitir introducza un numero menor que 0 ..."<<endl;

	do{
		cout<<"¿dato?..."<<endl;
		cin>>numero;
		cout<<"recibido"<<endl;
	}
	while (numero>=0);
	cout<<"fin de trasmision "<<endl;
}
