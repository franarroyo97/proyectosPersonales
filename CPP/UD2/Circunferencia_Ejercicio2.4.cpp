#include <iostream>

using namespace std;

int main(){
	const double pi=3.14;
	double radio=0,area=0,longitud=0;
	
	cout<<"digame el radio del circulo"<<endl;
	cin>>radio;
	

	if (radio<=0){
	cout<<"el radio de un circulo debe de ser mayor que 0"<<endl;
	}
	else {
	area=2*pi*(radio*radio);
	longitud = 2*pi*radio;
	cout<<"radio del circulo es	"<<radio<<endl;
	cout<<"area del circulo es	"<<area<<endl;
	cout<<"la longitud del circulo	"<<longitud<<endl;
	}
	
}

