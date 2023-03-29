#include<iostream>
using namespace std;

const int  MAX_MUM_PALABRAS=10000;
const int DIM_PALABRA=40;

struct Entrada{
	char palabra[DIM_PALABRA]; 
	int traduccion;
};

struct Diccionario{
	Entrada ingles[MAX_MUM_PALABRAS];
	Entrada espanol[MAX_MUM_PALABRAS];
	int num_palabras;
};
/***********************************************
 * declaracion de los set y los get ************
 ***********************************************/
char getpalabra(Entrada unaentrada,int pos){
	return unaentrada.palabra[pos];
}
int gettraduccion(Entrada unaentrada){
	return unaentrada.traduccion;
}
char getinglespalabra(Diccionario unaentrada,int pos,int pos2){
	return unaentrada.ingles[pos].palabra[pos2];
}
int  getinglestraduccion(Diccionario unaentrada,int pos){
	return unaentrada.ingles[pos].traduccion;
}
char getespanolpalabra(Diccionario unaentrada,int pos,int pos2){
	return unaentrada.espanol[pos].palabra[pos2];
}
int  getespanoltraduccion(Diccionario unaentrada,int pos){
	return unaentrada.ingles[pos].traduccion;
}
int getnum_palabras(Diccionario entrada){
	return entrada.num_palabras;
}
void setingles(Diccionario &unaentrada ,int pos ,string palabra_nueva,int traduccion_nueva){//V
	char aux[DIM_PALABRA];
	int dim=0;
	for (int i =0;palabra_nueva[i]!='\0';i++){
		aux[i]=palabra_nueva[i];
		dim++;
	}
	for(int i=0;i<dim;i++){
		unaentrada.ingles[pos].palabra[i]=aux[i];
	}
	unaentrada.ingles[pos].traduccion=traduccion_nueva;
}
void setespanol(Diccionario &unaentrada ,int pos ,string palabra_nueva,int traduccion_nueva){//V
	char aux[DIM_PALABRA];
	int dim=0;
	for (int i =0;palabra_nueva[i]!='\0';i++){
		aux[i]=palabra_nueva[i];
		dim++;
	}
	for(int i=0;i<dim;i++){
		unaentrada.espanol[pos].palabra[i]=aux[i];
	}
	unaentrada.espanol[pos].traduccion=traduccion_nueva;	
}
void setnum_palabras(Diccionario &unaentrada ,int numero_nuevo){
	unaentrada.num_palabras=numero_nuevo;

}
//fin de declaracion de los set y los get
void imprimir(Diccionario &diccionarioX){
	int n_palabras=getnum_palabras(diccionarioX);
	int pos=0;
	for(int i =0;i<n_palabras;i++){
		for(int j=0;diccionarioX.ingles[pos].palabra[j] !='\0';j++){
			cout<<diccionarioX.ingles[pos].palabra[j];	
		}
		cout<<endl;
		for(int k=0;diccionarioX.espanol[pos].palabra[k] !='\0';k++){
			cout<<diccionarioX.espanol[pos].palabra[k];	
		}
		cout<<endl;
		pos++;
	}
	
	cout<<"en total "<<getnum_palabras(diccionarioX)<<" palabras"<<endl; 	
}
void traduccir(Diccionario diccionarioX,string palabrae){
char aux[DIM_PALABRA];
	int dim=0;
	bool encontrado=false;
	bool entro_else=false;
	int pos_encontrado=-1;
	int dicc_encontrado=-1;
	for (int i =0;palabrae[i]!='\0';i++){
		aux[i]=palabrae[i];
		dim++;
	}
	//buscando en el diccionario de ingles
	cout<<dim<<" es la dimesion"<<endl;
	for(int i=0;i<getnum_palabras(diccionarioX) && encontrado==false;i++){
		for(int j=0;j<dim && entro_else==false;j++){
			if(diccionarioX.ingles[i].palabra[j]==aux[j]){
				cout<<"entro en el if del ingles"<<endl;
				pos_encontrado=i;
				encontrado=true;
				dicc_encontrado=0;		
			}
			else{
				cout<<"entro en el else del ingles"<<endl;
				encontrado=false;
				pos_encontrado=-1;
				dicc_encontrado=-1;
				entro_else=true;
			}
		}
		entro_else=false;
		for(int k=0;k<dim && dicc_encontrado != 0 && entro_else==false;k++){
			if(diccionarioX.espanol[i].palabra[k]==aux[k]){
				cout<<"entro en el if del español"<<endl;
				pos_encontrado=i;
				encontrado=true;
				dicc_encontrado=1;		
			}
			else{
					cout<<"entro en el else del español"<<endl;
					encontrado=false;
					pos_encontrado=-1;
					dicc_encontrado=-1;
					entro_else=true;
				}
			}
		}
	if(encontrado==true){
		cout<<"la traduccion es: ";
		if(dicc_encontrado==1){
			for(int x=0;diccionarioX.ingles[pos_encontrado].palabra[x] !='\0';x++){
				cout<<diccionarioX.ingles[pos_encontrado].palabra[x];	
			}
		}
		else if (dicc_encontrado==0){
			for(int y=0;diccionarioX.espanol[pos_encontrado].palabra[y] !='\0';y++){
				cout<<diccionarioX.espanol[pos_encontrado].palabra[y];	
			}
		}
		cout<<endl;
	}
	else {
		cout<<"no se ha encontrado su palabra :("<<endl;
	}
}

int main(){
	Diccionario diccionario1;
	int seleccion=0;
	bool ee=false;
	int c=0;
	string palabra;
	int num_palabras=0;
	/*
	1)crear diccionario
	2) imprimir diccionario
	3)añadir palabra al Diccionario
	4) traducir palabra
	5) ordenar diccionario
	6) eliminar palabra
	*/
	do{
		cout<<"****hola bienvenido al menu le dejo las opciones que usted puede seleccionar****"<<endl;
		cout<<"********************************************************************************"<<endl;
		cout<<"* 1)crear diccionario                                                          *"<<endl;
		cout<<"* 2)imprimir diccionario                                                       *"<<endl;
		cout<<"* 3)añadir palabra al diccionario                                              *"<<endl;
		cout<<"* 4)traducir palabra                                                           *"<<endl;
		cout<<"* 5)ordenar diccionario                                                        *"<<endl;
		cout<<"* 6)eliminar palabra                                                           *"<<endl;
		cout<<"* otra tecla)salir                                                             *"<<endl;
		cout<<"********************************************************************************"<<endl;
		cin>>seleccion;
	
		switch(seleccion){
			case 1:
				cout<<"creando diccionario"<<endl;
				setingles(diccionario1 ,0 ,"dog",0);
				c++;
				setingles(diccionario1 ,1,"cat",1);
				c++;
				setespanol(diccionario1 ,0 ,"perro",0);
				setespanol(diccionario1 ,1 ,"gato",1);
				setnum_palabras(diccionario1,2);
				break;
			case 2:
				cout<<"imprimiendo diccionario"<<endl;
				imprimir(diccionario1);
				break;
			case 3:
				cout<<"añadiendo palabras al diccionario"<<endl;
				cout<<"digame la palabra que quiere añadir al diccionario en español"<<endl;
				cin.clear();
				cin>>palabra;
				cin.clear();
				setespanol(diccionario1,c,palabra,c);
				cout<<"digame la palabra que quiere añadir al diccionario ingles"<<endl;
				cin.clear();
				cin>>palabra;
				cin.clear();
				setingles(diccionario1,c,palabra,c);
				c++;
				num_palabras=getnum_palabras(diccionario1);
				num_palabras++;
				setnum_palabras(diccionario1,num_palabras);
				break;
			case 4:
				cout<<"traduciendo palabra"<<endl;
				cout<<"digame la palabra que quire traduccir"<<endl;
				cin>>palabra;
				traduccir(diccionario1,palabra);
				break;
			case 5:
				cout<<"ordenado diccionario"<<endl;
				break;
			case 6:
				cout<<"eliminar palabra"<<endl;
				break;
			default:
				cout<<"adios..."<<endl;
				ee=true;
		}
	}while(ee==false);
}
