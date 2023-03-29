#include<iostream>
using namespace std;
bool busqueda_secuencial(int vector[],int utiles_vector,int buscar){
	bool esta=false; 
	bool bandera_parada=false;
	for (int i=0;i<utiles_vector && bandera_parada==false;i++){
		if(buscar==vector[i]){
		esta=true;
		bandera_parada=true;
		}
		else {
		esta=false;
		}
	}
	return esta;
}
int main(){
	const int DIM_VECTOR =10;
	int vector[DIM_VECTOR]={2,5,1,9,11,31,7,8,71,9};
	int utiles_vector=10;
	int buscar=0;
	bool encontrado=false;
	cout<<"dime el numero a buscar"<<endl;
	cin>>buscar;
	encontrado=busqueda_secuencial(vector,utiles_vector,buscar);
	if (encontrado==true){
		cout<<buscar<<" esta "<<endl;
	}
	else {
		cout<<buscar<<" no esta"<<endl;
	}
	
}
