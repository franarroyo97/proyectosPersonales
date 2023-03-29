#include <iostream>
using namespace std; 

int main(){
	double primer_numero,segundo_numero;
	double suma,resta,producto,division;
	
	cout<<"hola , este progama le da la suma , la resta , el producto y la division de dos numeros reales "<<endl;
	cout<<"digame el primer numero "<<endl;
	cin>>primer_numero;// si el usuario introduce una letra da error 
	cout<<"digame el segundo numero"<<endl;
	cin>>segundo_numero;//si el usuario introduce una letra da error
	suma=primer_numero + segundo_numero;
	resta=primer_numero - segundo_numero;
	producto=primer_numero * segundo_numero;
	division=primer_numero / segundo_numero;// si el usuario introduce como segundo numero 0 da un error en este caso nos retorna inf ¿x/0 = infinito?
	cout<<"la suma es :"<<suma<<endl;
	cout<<"la resta es :"<<resta<<endl;
	cout<<"la producto es :"<<producto<<endl;
	cout<<"la division es "<<division<<endl;
	
	 
}
