#include <iostream>
using namespace std;

int MCD(int a, int b){
	int modulo=0;

	while(a%b==0){	
		a=b;
		b=modulo;
		modulo=a%b;
	}
	return b;
}

int MCM(int a , int b){//MCM(a,b)=(a.b)/MCD(a,b)
	int MCM=0;
	MCM=(a*b)/(MCD(a,b));
	return MCM;

}
int main(){
	int numero1=0,numero2=0;

	cout<<"digame el primer numero "<<endl;
	cin>>numero1;
	cout<<"digame el segundo numero "<<endl;
	cin>>numero2;
	cout<<MCM(numero1,numero2)<<"es el MCM de "<<numero1<<" y "<<numero2<<endl;
}
