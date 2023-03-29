#include <iostream>

using namespace std;

int main(){
	int multipo,tope;
	int control=0;
	cout<<"hola,soy el programa de calcular la tabla del 7 digame cuantos numeros de la tabla del 7 quiere que le diga"<<endl;
	cin>>tope;
	do{
	cout<<"7 * "<<control<<" = " <<control*7<<endl;
	control++;
	}
	while (control<=tope);
}
