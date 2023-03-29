#include<iostream>
using namespace std;
void ordenar_burbuja(int vector[],int utiles_vector){
	bool entrada=true;
	int aux=0;
	for(int izq=0;entrada==true && izq<utiles_vector;izq++){
		entrada=false;
		for(int i=utiles_vector-1;i>izq;i--){
			if(vector[i]< vector[i-1]){
				entrada=true;
				aux=vector[i];
				vector[i]=vector[i-1];
				vector[i-1]=aux;
			}
		}
	}
}
void ordenar_insercion(int vector[],int utiles_vector){
	int izq=0;
	int i=0;
	int valor=0;
	for(izq=1;izq<utiles_vector;izq++){
		valor=vector[izq];
		for(i=izq; valor<vector[i-1] && i>0; i--){
			vector[i]=vector[i-1];
		}
		vector[i]=valor;	
	}
}
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
int desordenar_vector (int vector[]){
	vector[0]=11;
	vector[1]=70;
	vector[2]=-15;
	vector[3]=77;
	vector[4]=5;
	vector[5]=-77;
	vector[6]=100;
	vector[7]=7;
	vector[8]=9;
	vector[9]=10;
}
void imprime_vector(int vector[],int utiles_vector){
	for(int i=0;i<utiles_vector;i++){
		cout<<vector[i];
		if(i<utiles_vector){
		cout<<",";
		}
	}
	cout<<endl;
}
int main(){
	const int DIM_VECTOR=10;
	int vector[DIM_VECTOR]={11,70,-15,77,5,-77,100,7,9,10};
	int utiles_vector=10;
	int contar=0;
	imprime_vector(vector,utiles_vector);
	ordenar_burbuja(vector,utiles_vector);
	imprime_vector(vector,utiles_vector);
	desordenar_vector (vector);
	imprime_vector(vector,utiles_vector);
	ordenar_insercion(vector,utiles_vector);
	imprime_vector(vector,utiles_vector);
	desordenar_vector (vector);
	imprime_vector(vector,utiles_vector);
	ordenar_seleccion(vector,utiles_vector);
	imprime_vector(vector,utiles_vector);

}
