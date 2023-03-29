#include <iostream>
#include <cmath>
using namespace std;

int main(){
	const int longitud=10;
	int notas[longitud];
	int i=0;
	float media=0,varianza=0,desviacion=0,sumatoria_notas=0,util_notas=0;
	for (i=0;i<longitud;i++){
		do{
			cout<<"dime la nota numero"<<i<<endl;
			cin>>notas[i];
			if (notas[i]<0 || notas[i]>10){
				cout<<"las notas tienen que ser del mayores o iguales que 0 y menor o iguales que 10"<<endl;
			}
			else {
				util_notas++;
			}
		}
		while (notas[i]<0 || notas[i]>10);
	}
	for (i=0;i<util_notas;i++){
		sumatoria_notas=sumatoria_notas+notas[i];
	}
	media=sumatoria_notas/longitud;
	//calculamos la varianza
	for (i=0;i<util_notas;i++){
		sumatoria_notas=sumatoria_notas+pow((notas[i]-media),2);
	}
	varianza=sumatoria_notas/util_notas;
	//calculamos la desviacion tipica
	desviacion=sqrt(varianza);
	cout<<"la media es: "<<media<<"la varianza es: "<<varianza<<"y la desviacion es: "<<desviacion<<endl;

}
