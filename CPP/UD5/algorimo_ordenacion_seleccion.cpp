#include<iostream>
using namespace std;
int ordenar_seleccion(int vector[],int utiles_vector){
	int pos_min=0;
	int aux;
	int j=0;
	int i=0;
	for(i=0;i<utiles_vector-1;i++){
		pos_min=i;
		for(j=i+1;j<utiles_vector;j++){
			//cout<<vector[pos_min]<<"pm"<<endl;
			if(vector[j]<vector[pos_min]){
				//cout<<vector[j]<<"j";
				pos_min=j;
				aux=vector[i];
				vector[i]=vector[pos_min];
				vector[pos_min]=aux;
			}
			
		}
	}
}
int main(){
	const int DIM_VECTOR =10;
	int  vector[DIM_VECTOR]={2,5,1,9,11,-31,7,8,71,9};
	int utiles_vector=10;
	ordenar_seleccion(vector,utiles_vector);
	for(int i=0;i<utiles_vector;i++){
		cout<<vector[i]<<",";
	}
	cout<<endl;
}
