#include <iostream>

using namespace std;
int intervalo_primos(int a, int b){
	int i=0,cuenta=0, j=0;

	
	for (j=a;j<=b;j++){
		for (i=2;i<j & cuenta!=1;i++){
			if(j%i==0){
				cuenta++;//un numero es primo si solo tiene dos divisores 
			}
			}
		if (cuenta==0){
		cout<<j<<" es primo "<<endl;
		}
		cuenta=0;	
		
	}
}

int main (){
int a=0,b=0;
cout<<"hola este programa le dira los numeros primos en un intervalo [a,b]"<<endl;
cout<<"digame a"<<endl;
cin>>a;
cout<<"digame b"<<endl;
cin>>b;
intervalo_primos(a,b);
	
}
