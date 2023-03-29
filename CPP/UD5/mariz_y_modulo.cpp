#include<iostream>
using namespace std;
const int DIM_FIL_MATRIZ=5;
const int DIM_COL_MATRIZ=5;
void imprimir_matriz(int matriz[][DIM_COL_MATRIZ],int utiles_col_matriz,int utiles_fil_matriz){
	int j=0;
	int i=0;
	for(i=0;i<utiles_fil_matriz;i++){
		for(j=0;j<utiles_col_matriz;j++){
			cout<<matriz[j][i]<<" ";
		}
	}
}
int main(){
	int matriz[DIM_FIL_MATRIZ][DIM_COL_MATRIZ]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int utiles_col_matriz=5;
	int utiles_fil_matriz=5;
	imprimir_matriz(matriz,utiles_col_matriz,utiles_fil_matriz);
}
