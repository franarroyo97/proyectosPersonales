#include <iostream>

using namespace std;

int main(){
	double numero1=0,numero2=0;
	char eleccion=' ';
	double resultado=0;

	cout<<"digame el primer numero"<<endl;
	cin>> numero1;
	cout<<"digame el segundo numero"<<endl;
	cin>> numero2;
	cout<<"digame que desa hacer para sumar pulse s para dividir d para multiplciar m para restar r"<<endl;
	cin>>eleccion;

	switch(eleccion){
		case 's':
		case 'S':
			resultado = numero1+numero2;
			cout<<"el resultado es "<<resultado<<endl;
			break ;
		case 'd':
		case 'D':
			resultado = numero1/numero2;
			cout<<"el resultado es "<<resultado<<endl;
			break;
		case 'm':
		case 'M':
			resultado = numero1*numero2;
			cout<<"el resultado es "<<resultado<<endl;
			break;
		case 'r':
		case 'R':
			resultado = numero1-numero2;
			cout<<"el resultado es "<<resultado<<endl;
			break;
		default:
			cout<<eleccion<<" no es una opcion correcta "<<endl;
	}
}
