#include <iostream>

using namespace std;

int main (){
	int a,b,modulo;
	cout<<"digame dos ;numeros yo le darece el MCD"<<endl;
	cout<<"digame a"<<endl;
	cin>>a;
	cout<<"digame b"<<endl;
	cin>>b;

	if(a%b==0){
		cout<<b<<"es el MCD"<<endl;
	}
	else {
		while(a%b==0){	
			a=b;
			b=modulo;
			modulo=a%b;
		}
		cout<<b<<"es el MCD"<<endl;
	}
}
