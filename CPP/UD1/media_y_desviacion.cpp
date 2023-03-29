#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double numero1,numero2,numero3 ;
	double media,desviacion ;

	cout<<"digame las 3 numeros reales y yo le dare la media y las desciacion tipca de estos "<<endl;
	cin>>numero1>>numero2>>numero3;
	media=(numero1+numero2+numero3)/3;
	desviacion=(sqrt(pow(numero1-media,2))+sqrt(pow(numero2-media,2))+sqrt(pow(numero2-media,2)))/3;//si numero1,numero2 y numero3 entonces raiz de 0  = inf 
	cout<<"la media es "<<media<<" la desviación tipica es "<<desviacion<<endl;
}
	
