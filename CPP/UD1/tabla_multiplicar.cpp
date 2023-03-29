#include <iostream>
using namespace std;

int main() {
	double numero_introducido;
	double resultado;
	
	cout<<"digame un numero y yo le dire los numeros del 0 al 10 de la trabla de multpicar de ese numero";
	cin>>numero_introducido;//Si el usuario introduce una letra el programa no funciona bien 

	resultado=numero_introducido*0;
	cout<<numero_introducido<<"*0 = "<<resultado<<endl;
	resultado=numero_introducido*1;
	cout<<numero_introducido<<"*1 = "<<resultado<<endl;
	resultado=numero_introducido*2;
	cout<<numero_introducido<<"*2 = "<<resultado<<endl;
	resultado=numero_introducido*3;
	cout<<numero_introducido<<"*3 = "<<resultado<<endl;
	resultado=numero_introducido*4;
	cout<<numero_introducido<<"*4 = "<<resultado<<endl;
	resultado=numero_introducido*5;
	cout<<numero_introducido<<"*5 = "<<resultado<<endl;
	resultado=numero_introducido*6;
	cout<<numero_introducido<<"*6 = "<<resultado<<endl;
	resultado=numero_introducido*7;
	cout<<numero_introducido<<"*7 = "<<resultado<<endl;
	resultado=numero_introducido*8;
	cout<<numero_introducido<<"*8 = "<<resultado<<endl;
	resultado=numero_introducido*9;
	cout<<numero_introducido<<"*9 = "<<resultado<<endl;
	resultado=numero_introducido*10;
	cout<<numero_introducido<<"*10 = "<<resultado<<endl;
}
