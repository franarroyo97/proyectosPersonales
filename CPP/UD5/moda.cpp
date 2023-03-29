#include<iostream>
using namespace std;
int moda(int vector[],int utiles_vector){
	int contador=0;
	int moda=0;
	int n_moda=0;
	for(int i=0;i<utiles_vector;i++){
		for(int j=i;j<utiles_vector;j++){
			if(vector[j]==vector[i]){
			contador++;
			}
		}
		if(contador>n_moda){
			moda=vector[i];
			n_moda=contador;
			contador=0;
		}
		contador=0;
	}
	return moda;
}
int main(){
	int const DIM_VECTOR=10;
	int vector[DIM_VECTOR]={0};
	int utiles_vector=0;
	cout<<"digame numeros y le calculare la moda"<<endl;
	for(int i=0;utiles_vector<DIM_VECTOR;i++){
		cout<<"dime el "<<i<<"º numero"<<endl;
		cin>>vector[i];
		utiles_vector++;
	}
	cout<<"la moda es "<<moda(vector,utiles_vector)<<endl;
}
