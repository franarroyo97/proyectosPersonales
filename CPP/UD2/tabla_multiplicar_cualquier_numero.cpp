#include <iostream>

using namespace std;

int main(){
	int multiplo,tope;
	int control=0;
	cout<<"hola,soy el programa de calcular la tabla del numero que usted me diga "<<endl<<"porfavor digame el numero... "<<endl;
	cin>>multiplo;
	cout<<"ahora digame el tope de la tabla le hare la tabla desde 0 a el tope que usted me indique ";
	cin>>tope;
	do{
	cout<<multiplo<<" * "<<control<<" = " <<control*multiplo<<endl;
	control++;
	}
	while (control<=tope);
}
