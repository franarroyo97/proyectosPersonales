#include <iostream>

using namespace std;

int main(){
	int tope=0 ,i=0;

	cout <<"digame cuantos numeros de la tabla del site quire que le muestre"<<endl;
	cin>>tope;
	
	if (tope>0){
		while (i<=tope){
			cout<<"7 * "<<i<<"= "<<7*i<<endl;
			i++;
		
		}
	}
	else {
		cout<<"tiene que ser un numero postivo !"<<endl;
	}
}
