#include<iostream>
using namespace std;

int main(){
	double nota_teoria,nota_practicas,nota_problemas;//70%,20%,10% respectivamente 
	double nota_global;

	cout<<"digame las notas que saco en teoria en praticas y probleas EN ESE ORDEN "<<endl;
	cin>>nota_teoria>>nota_practicas>>nota_problemas;
	nota_teoria=nota_teoria*0.70;
	nota_practicas=nota_practicas*0.20;
	nota_problemas=nota_problemas*0.10;
	nota_global=nota_teoria+nota_practicas+nota_problemas;
	cout<<"su nota es "<<nota_global<<endl;
}
