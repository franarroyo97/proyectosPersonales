#include <cmath>
#include <iostream>
//x=-b+-r2(b2-4*(ac))/2a
using namespace std;

int main(){
	double a,b,c;
	double solucion;
	double discriminante;
	cout<< "digame a" <<endl;
	cin >> a;
	cout<< "digame b" <<endl;
	cin >> b;
	cout<< "digame c" <<endl;
	cin >> c;
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
	
