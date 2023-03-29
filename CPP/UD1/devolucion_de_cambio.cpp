#include <iostream>
using namespace std;

int main(){
	double precio,pagado;
	double centimos; //100*(1.54-2)

	cout << "esriba precio  ";
	cin >> precio;
	cout <<" esriba dinero entregado";
	cin >> pagado;
	centimos = 100*(pagado - precio);
	cout<< "hay que devolver: "<< centimos<<"céntimos"<<endl;
}

