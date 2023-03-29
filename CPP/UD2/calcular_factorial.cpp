#include <iostream>

using namespace std;

int main (){
	int numero=0,i=0;
	int factorial=1;//si lo inicializamos a 0 0*x=0 entonces simpre sera igual a 0
	
	cout<<"digame un numero y le calculare el factorial de ese numero";
	cin>>numero;
	for (i=1;i<=numero;i++){
		factorial=i*factorial;
	}
	cout<<"el factorial de "<<numero<<"es: "<<factorial<<endl;
}
