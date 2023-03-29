#include <iostream>

using namespace std;

int main (){
	int  a=0,b=0,x=0;//entedemos a y b como el intervalo [a,b] y x el numero del que queremos saber los multiplos

	cout<<"le dire los divisores de un numero en el rango [a,b]"<<endl;
	cout<<"digame a del rango[a,b]"<<endl;
	cin>>a;
	cout<<"digame b del rango[a,b]"<<endl;
	cin>>b;
	cout<<"ahora digame el numero "<<endl;
	cin>>x;

	for(a=a;a<=b;a++){
		if (a%x==0){
			cout<<a<<"es un divisor de "<<x<<endl;
		}
	}
}
