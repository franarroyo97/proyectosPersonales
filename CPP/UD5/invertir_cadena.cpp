#include <iostream>
using namespace std;
void invertir_cadena(char vector[],int utiles_vector){
	const int DIM_AUX=utiles_vector;	
	char aux[DIM_AUX];
	int cuenta=0;
	for(int i=utiles_vector-1;i >= 0;i--){
		cout<<"entro en el for"<<endl;
		aux[cuenta]=vector[i];
		cout<<aux[cuenta]<<vector[i]<<endl;
		cuenta++;
	}
	for(int i=0;i<DIM_AUX;i++){
			cout<<aux[i]<<" segundo for"<<endl;
			vector[i]=aux[i];
	}
}
void inprimir_vector(char vector[],int utiles_vector){
	for(int i=0;i<utiles_vector;i++){
		cout<<vector[i];
		if (i<utiles_vector-1){
			cout<<",";
		}

	}
	cout<<endl;
}

int main(){
	int const DIM_VECTOR=11;
	char vector[DIM_VECTOR]={'h','o','l','a',' ','m','u','n','d','o'};
	int utiles_vector=11;
	invertir_cadena(vector,utiles_vector);
	inprimir_vector(vector,utiles_vector);
}
