#include <iostream>
using namespace std;
void cambia_vector(int vector1[],int util_vector1,int vector2[],int util_vector2){
	const int DIM_VECTOR_LOCAL=10;
	int vector_local[DIM_VECTOR_LOCAL]={0};
	for (int i=0;i<DIM_VECTOR_LOCAL;i++){
		vector_local[i]=vector1[i];
	}
	for (int i=0;i<util_vector2;i++){
		vector1[i]=vector2[i];
	}
	for (int i=0;i<util_vector1;i++){
		vector2[i]=vector_local[i];
	}
}
void imprime_vector(int vector1[],int util_vector1,int vector2[],int util_vector2){
	cout<<"este es el resultado del vector1: ";
	for(int i=0;i<util_vector1;i++){
		cout<<vector1[i]<<" ";
	}
	cout<<"\neste es el resultado del vector2 ";
	for(int i=0;i<util_vector2;i++){
		cout<<vector2[i]<<" ";
	}
	cout<<endl;
}
int main(){
	const int DIM_VECTOR1=10;
	int vector1[DIM_VECTOR1]={1,2,3,4,5,6,7,8,9,10};
	int util_vector1=10;
	const int DIM_VECTOR2=10;
	int vector2[DIM_VECTOR2]={12,6,9,4,7,7,6,7,1,9};
	int util_vector2=10;
	cout<<"antes: "<<endl;
	imprime_vector(vector1,util_vector1,vector2,util_vector2);
	cambia_vector(vector1,util_vector1,vector2,util_vector2);
	cout<<"despues: "<<endl;
	imprime_vector(vector1,util_vector1,vector2,util_vector2);

}
