#include <iostream>
using namespace std;

void copiar_vector_primos(int const DIM_VECTOR_ENTRADA,int vector_entrada[],int utiles_vector_entrada,int const DIM_VECTOR_SALIDA,int vector_salida[],int utiles_vector_salida){
	int copiar=0;
	for (int i=0;i<utiles_vector_entrada;i++){
		if(vector_entrada[i]%2==0){
			vector_salida[i]=vector_entrada[i];
		}
		utiles_vector_salida++;
		
	}
	cout<<"resultado de la copia "<<endl;
	cout<<"este es el vector de entrada : ";
	for(int i=0;i<utiles_vector_entrada;i++){
		cout<<vector_entrada[i]<<", ";
	}
	cout<<"\n este es el vector de salida: ";
	for (int i=0;i<DIM_VECTOR_SALIDA;i++){
		cout<<vector_salida[i] <<", ";
	}
	cout<<endl;
}

int main(){
	int const DIM_VECTOR_ENTRADA=10;
	int const DIM_VECTOR_SALIDA=10;
	int vector_entrada[DIM_VECTOR_ENTRADA]={1,2,3,4,1,1,1,1,1,1},utiles_vector_entrada=10;
	int vector_salida[DIM_VECTOR_SALIDA]={0},utiles_vector_salida=0;

copiar_vector_primos	(DIM_VECTOR_ENTRADA,vector_entrada,utiles_vector_entrada,DIM_VECTOR_SALIDA,vector_salida,utiles_vector_salida);
}
