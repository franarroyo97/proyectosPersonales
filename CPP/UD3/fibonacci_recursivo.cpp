#include <iostream>
using namespace std; 

#define AZUL "\033[1;34m"
#define MORADO "\033[1;35m"
#define ROJO "\033[1;31m"
#define VERDE "\033[1;32m"
#define NORMAL "\033[0m"
#define CIAN_F "\33[1;46m"

int fibonacci (int  numero){//se tiene en cuenta la siguente formula : fibonacci de n= fibonacci(n-1)+fibonacci(n-2)
	long int resultado=0;
	if (numero==0){
		resultado=0;
	}
	else if (numero==1){
		resultado=1;
	}
	else {
		resultado=fibonacci(numero-1)+fibonacci(numero-2);
	}
	return resultado;
}
int main(){
	int numero;
	
	cout<<"digame el numero del que desas calcular la sucesion de fibonacci"<<endl;
	do{
		cin>>numero;
		if (numero<0){
			cout<<ROJO<<"su numero es menor que 0 digame un numero mayor que 0"<<NORMAL<<endl;
		}
	}
	while (numero<0);
	cout<<CIAN_F<<VERDE<<fibonacci(numero)<<"es el resultado"<<NORMAL<<endl;
}


