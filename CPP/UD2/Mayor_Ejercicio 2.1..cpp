#include <iostream>

using namespace std;

int main (){
	double numero1=0,numero2=0;
	
	cout<<"digame su primer numero "<<endl;
	cin>>numero1;
	cout<<"digame su segundo numero "<<endl;
	cin>>numero2;
	
	if (numero1>numero2){
		cout<<"el numero es mas grande "<<numero1<<endl;
	}
	if (numero1<numero2){
		cout<<"el numero es mas grande "<<numero2<<endl;
	}
	if (numero1 == numero2){
		cout<<"Los numeros son iguales"<<endl;
	}
}
