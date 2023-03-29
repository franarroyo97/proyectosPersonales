#include <cmath>
#include <iostream>
using namespace std;

double ecuacion_grado2(double a,double b,double c,double &solucion ){
	double discriminante;
	discriminante=(b*b)-((4*(a*c)));
	
if (discriminante < 0){
		cout<<"no tiene solucion perteneciente a los numeros reales "<<endl;
	}
	
else {	
	solucion=(-b)-(sqrt((b*b)-(4*(a*c))))/(2*a);
	cout<<"la primera solucion es: "<<solucion<<endl;
	solucion=(-b)+(sqrt((b*b)-(4*(a*c))))/(2*a);
	cout<<"la segunda  solucion es: "<<solucion<<endl;
	}
}
int main(){
double  a ,b,c,solucion=0;
cout<< "digame a" <<endl;
cin>>a;
cout<< "digame b" <<endl;
cin >> b;
cout<< "digame c" <<endl;
cin >> c;
ecuacion_grado2(a,b,c,solucion);


}
