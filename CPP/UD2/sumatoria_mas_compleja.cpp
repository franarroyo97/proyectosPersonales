#include <iostream>

using namespace std;

int main(){
	int i=1,tope=0;
	double solucion=0;

	cout<<"¿cuantas veces desa que le haga la sumatoria? un numero que no sea postivo da por terminado el programa "<<endl;
	cin>>tope;
	
	while (tope>0){
		for (i=1;i<=tope;i++){
			solucion=solucion+((i-1.0)/i);//¡poner 1.0 es importante !
		}
		cout<<"la solucion es : "<<solucion<<endl;
		tope=-1;
	}
}
