#include <iostream>

using namespace std;

int main (){
	int numero=0,i=0;
	int sumatoria=0;
	
	cout<<"digame un numero y le calculare la sumatoria  de ese numero";
	cin>>numero;
	for (i=0;i<=numero;i++){
		sumatoria=i+sumatoria;
	}
	cout<<"el sumatoria de "<<numero<<"es: "<<sumatoria<<endl;
}
