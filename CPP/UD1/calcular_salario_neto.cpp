#include <iostream>
using namespace std;

int main(){
	const double IRPF=0.18,SS=0.047;
	double salario_bruto ,salario_neto,descuento_ss ,descuento_irpf;

	cout <<"soy el programa de Francisco Arroyo"<<endl;
	cout << "¿cual es su salario burto? "<<endl; 
	cin >> salario_bruto;
	descuento_ss=salario_bruto * SS;
	descuento_irpf =salario_bruto * IRPF;
	salario_neto=salario_bruto-(descuento_ss+descuento_irpf);
	cout <<"su salario neto es :  "<<salario_neto<<endl;
	
}
