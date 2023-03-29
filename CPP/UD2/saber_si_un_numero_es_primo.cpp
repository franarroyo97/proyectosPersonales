#include <iostream>

using namespace std;

int main (){
	int i=0,numero=0,cuenta=0;

	cout<<"hola este programa le dira si un numero es primo o no";
	cin>>numero;

	for (i=1;i<=numero && numero<=3;i++){
		if(numero%i==0 ){
			cuenta++;//un numero es primo si solo tiene dos divisores 
		}
	 }
	if (cuenta==2){
		cout<<numero<<"es primo"<<endl;
	}
	else {
		cout<<numero<<"no es primo"<<endl;
	}
}
