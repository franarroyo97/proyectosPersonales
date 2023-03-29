#include <iostream>

using namespace std;

int main(){
	double nota;

	cout<<"digame su nota "<<endl;
	cin>>nota;

	if (nota>=0 && nota<=10){
		if (nota<5){
			cout<<"usted a suspendido con una nota de  "<<nota<<endl;
		}
		if (nota>=5 && nota<=7){
			cout<<"usted a sacado un aprobado con una nota de "<<nota<<endl;
		}
		if (nota>7 && nota<=9){
			cout<<"usted a sacado un notable con una nota de "<<nota<<endl;
		}
		if (nota>9){
			cout<<"usted a sacado un sobresaliente con una nota de "<<nota<<endl;
		}
		
	}
	else {
		cout<<"su nota no puede ser mayor que 10 ni menor que 0 usted a introducido "<<nota<<endl;
	}
}
