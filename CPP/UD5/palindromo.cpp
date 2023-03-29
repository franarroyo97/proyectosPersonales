#include<iostream>
using namespace std;
int  contar_cadena(char cadena[]){
	int contador=0;
	while(cadena[contador] != '\0'){
		contador++;
	}
	return contador;
}
void  quitar_espacios_blanco(char cadena[]){
	for(int i=0;cadena[i]!='\0';i++){
		if(cadena[i]==' '){
			for(int j=i;cadena[j]!='\0';j++)
			cadena[j]=cadena[j+1];
		}
	}
	cout<<endl;
}
bool es_palindromo(char vector[],int longitud_cadena){
	int contador_tope=longitud_cadena;
	bool palindromo=false; 
	bool fallo=false ;
	//cout<<"la cadena miede "<<longitud_cadena<<endl<<endl;
	for(int i=0;i<contador_tope && fallo==false;i++){
		if(vector[i]==vector[contador_tope-1]){
			//cout<<"entro"<<endl;
			contador_tope--;
			palindromo=true;
		}
		else{
			//cout<<"salgo"<<endl;
			palindromo=false;
			fallo=true;
		}
	}
	return palindromo;
}
void imprimir_cadena(char cadena[]){
	cout<<cadena;
	cout<<endl;
}
int main(){
	int DIM_VECTOR=10000;
	char vector[DIM_VECTOR];
	int longitud_vector=0;
	char original[DIM_VECTOR];
	bool palindromo=false;
	cout<<"digame una palabra o frase y yo le dire si es un palidiromo o no"<<endl;
	cin.getline(vector,DIM_VECTOR);
	for(int i=0;vector[i]!='\0';i++){
	original[i]=vector[i];
	}
	quitar_espacios_blanco(vector);
	longitud_vector=contar_cadena(vector);
	palindromo=es_palindromo(vector,longitud_vector);
	imprimir_cadena(original);
	if (palindromo==true){
		cout<<" es un palindromo"<<endl;
	}
	else{
		cout<<"no es un palindromo"<<endl;
	}
}
