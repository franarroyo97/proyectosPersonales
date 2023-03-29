#include<iostream>
using namespace std;
int ordenar_ordenados(int vector1[],int utiles_vector1,int vector2[],int utiles_vector2,int vector_ordenado[] ,int DIM_VECTOR_ORDENADO,int & utiles_vector_ordenado){
	int j=0;
	int i=0;
	while (i < utiles_vector1 && j <utiles_vector2  ){
			if(vector1[i] <vector2[j]){
				vector_ordenado[utiles_vector_ordenado]=vector1[i];
				utiles_vector_ordenado++;
				i++ ;
				}
			else if(vector1[i]>vector2[j]){
				vector_ordenado[utiles_vector_ordenado]=vector2[j];
				utiles_vector_ordenado++;
				j++;
				}
			else if (vector1[i]==vector2[j]){
				vector_ordenado[utiles_vector_ordenado]=vector1[i];
				utiles_vector_ordenado++;
				vector_ordenado[utiles_vector_ordenado]=vector2[j];
				utiles_vector_ordenado++;
				j++;
				i++;
				}
		cout<<"la j vale "<<j<<endl;
		cout<<"la i vale "<<i<<endl;
		}
	while(j!=i){
		cout<<"while la j vale "<<j<<endl;
		cout<<"while la i vale "<<i<<endl;
		if(j>i){
			cout <<"entro en el if"<<endl;
			vector_ordenado[utiles_vector_ordenado]=vector1[i];
			utiles_vector_ordenado++;
			i++;
		}
		else {
			cout <<"entro en el else "<<endl;
			
			vector_ordenado[utiles_vector_ordenado]=vector2[j];
			utiles_vector_ordenado++;
			j++;
		}
		cout<<"while la j vale final "<<j<<endl;
		cout<<"while la i vale final "<<i<<endl;
	}
	
}
void imprime_vector(int vector[],int util_vector){
	cout<<"este es el resultado del vector1: ";
	for(int i=0;i<util_vector;i++){
		cout<<vector[i]<<" ";
	}
	cout<<endl;
}
int main(){
	const int DIM_VECTOR1=12;
	int vector1[DIM_VECTOR1]={-130,-7,0,5,5,19,60,123,532,999};
	int utiles_vector1=10;
	const int DIM_VECTOR2=12;
	int vector2[DIM_VECTOR1]={-13,-7,1,9,10,30,45,50,701,870};
	int utiles_vector2=10;
	int const DIM_VECTOR_ORDENADO=100;
	int vector_ordenado[DIM_VECTOR_ORDENADO]={0};
	int utiles_vector_ordenado=0;
	ordenar_ordenados(vector1,utiles_vector1,vector2,utiles_vector2,vector_ordenado ,DIM_VECTOR_ORDENADO,utiles_vector_ordenado);
	imprime_vector(vector_ordenado,utiles_vector_ordenado);
}
