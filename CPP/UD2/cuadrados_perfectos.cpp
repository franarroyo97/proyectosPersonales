#include<iostream>


using namespace std;

int main(){
	int numero=0,i=0,cuadrados_perfectos=0;
	bool parada = false , numero_es_cuadrado_perfecto=false ;
	
	cout<<"digame el numero el cual desa saber si es un cuadrado perfecto"<<endl;
	cin>>numero;

	for (i=1;i<=numero  && parada == false ;i++){
		cuadrados_perfectos=i*i;
	
	if (cuadrados_perfectos  == numero){
		cout<<numero<<" es un cuadrado perfecto"<<endl;
		parada = true;
		numero_es_cuadrado_perfecto= true;
		
	}
	
	}
	if(numero_es_cuadrado_perfecto  == false ){ 
		cout<<numero<<" no es un cuadrado perfecto"<<endl;
	}
	
}
