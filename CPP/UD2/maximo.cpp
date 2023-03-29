#include <iostream>

using namespace std;

int main(){
	double numero1=0,numero2=0,numero3=0;

	cout<<"digame el primer numero"<<endl;
	cin>>numero1;
	cout<<"digame el segundo numero"<<endl;
	cin>>numero2;
	cout<<"digame el tercer numero"<<endl;
	cin>>numero3;
	
	if (numero1>=numero2 && numero1>=numero3){
		if (numero1==numero2 && numero1==numero3){
			cout<<"los numeros son iguales"<<endl;
			
		}
		else {
			cout<<numero1<<" es el maximo"<<endl;
		}
		
	
	}
	else {// ya sabemos que no son todos los numeros iguales y que numero 1 no es el mayor 
		if(numero2>numero1 && numero2>numero3){
			cout<<numero2<<" es el maximo"<<endl;
		}

		else { 
			cout<<numero3<<" es el maximo"<<endl;
		}
	}
	
}
