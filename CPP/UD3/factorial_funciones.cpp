#include<iostream>

using namespace std;
//declarando una funcion que te calcula en factorial de numero que usted eliga factorial(numero)
int factorial () {

	int solucion=1, i=0; 
	int numero=0 ;

	cout<<"digame de que numero le calclulo en factorial"<<endl;
	cin>>numero;

	for ( i=1 ; i<=numero ; i++ ){
		solucion = solucion *i;
	}

	return solucion;
	
}

int main(){
	
	cout<<factorial();
}
