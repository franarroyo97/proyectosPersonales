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
void imprimir_cadena(char cadena[]){
	cout<<cadena;
	cout<<endl;
}

int main(){
	const int DIM_CADENA=1000;
	char cadena[DIM_CADENA]={""};
	cout<<"digame una cadena de texto como maximo 999 caracteres"<<endl;
	cin.getline(cadena,1000);
	cout<<contar_cadena(cadena)<<" es la longutid de la cadena"<<endl;
	quitar_espacios_blanco(cadena);
	cout<<"este esta es la cadena sin espacios: "<<endl;
	imprimir_cadena(cadena);
	

}
