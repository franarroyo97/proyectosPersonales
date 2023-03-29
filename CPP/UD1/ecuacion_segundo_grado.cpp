#include <cmath>
#include <iostream>
//x=-b+-r2(b2-4*(ac))/2a
using namespace std;

int main(){
	double a,b,c;
	double solucion;
	
	cout<< "digame a" <<endl;
	cin >> a;
	cout<< "digame b" <<endl;
	cin >> b;
	cout<< "digame c" <<endl;
	cin >> c;

	cout<<sqrt(4)<<"test de sqrt"<<endl;	
	solucion=-b-(sqrt((b*b)-(4*(a*c))))/(2*a);//si 4*a*c es >b2 no tiene solucion pertenecite a los numeros reales responde nan not is a number 
	cout<<"la primera solucion es: "<<solucion<<endl;
	solucion=-b+(sqrt((b*b)-(4*(a*c))))/(2*a);
	cout<<"la segunda  solucion es: "<<solucion<<endl;
	
}
	
