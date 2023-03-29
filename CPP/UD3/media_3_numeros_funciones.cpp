#include<iostream>

using namespace std;
double media (double  numero1,double  numero2,double numero3){
	double media_enf;//le pongo enf(en funcion )para que la variavle no se llame igual que la funcion
	
	media_enf=(numero1+numero2+numero3)/3;
	return media_enf;

}
int main (){
	double  numero1,numero2,numero3;
	cout<<"dime numero 1"<<endl;
	cin>>numero1;
	cout<<"dime numero 2"<<endl;
	cin>>numero2;
	cout<<"dime numero 1"<<endl;
	cin>>numero3;
	
	cout<<media(numero1,numero2,numero3)<<" es la media"<<endl;
}
