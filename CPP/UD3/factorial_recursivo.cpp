#include <iostream>
using namespace std;

long int factorial(int numero){
	long int resultado=0;
	if (numero == 0){
		resultado=1;
	}
	else if (numero > 0){
		resultado=numero*factorial(numero-1);
	}
	return resultado;
}
int main(){
	int numero;
	cout <<"digame un numero y le dire el factorial de ese numero"<<endl;
	do{
		cin>>numero;
		if (numero<0){
			cout<<"usted a introducido un numero menor que 0 "<<endl;
		}
	}
	while (numero<0);
	cout<<"el resultado es "<<factorial(numero)<<endl;
	
}
