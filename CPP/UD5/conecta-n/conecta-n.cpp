#include<iostream>
using namespace std;

const int DIM_FIL = 500;
const int DIM_COL = 500;

void inicializarTablero(char tablero[][DIM_COL], int util_col, int util_fil){
    char caracter_inicializador = '-';
    for (int f = 0; f < util_fil; f++)
        for (int c = 0; c < util_col; c++)
            tablero[f][c] = caracter_inicializador;
}
void imprimirTablero(int mapa_tiradas[][DIM_COL], int util_col, int util_fil, char nombreJ1[], char nombreJ2[]){
    
    cout << "               TABLERO TRES EN RAYA" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Jugador 1: " << nombreJ1 << endl;
    cout << "| Jugador 2: " << nombreJ2 << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "*********" << endl;
    for (int f = 0; f < util_fil; f++){
        cout << "* ";
        for (int c = 0; c < util_col; c++){
            if (mapa_tiradas[f][c]==0 ){
			cout<<"-";
		}
	    else if(mapa_tiradas[f][c]==1){
			cout<<"O";
		}
	    else if(mapa_tiradas[f][c]==2){
			cout<<"X";
		}
	    cout<< " ";
	}
        cout << "*" << endl;
    }
    cout <<"*********" << endl;
}
void inicilizarMapa(int mapa_tiradas[][DIM_COL],int util_col,int util_fil){
		for (int f = 0; f < util_fil; f++)
			for (int c = 0; c < util_col; c++){
				mapa_tiradas[f][c] = 0;
			}
}
void realizarTriada(int &turno,int mapa_tiradas[][DIM_COL],int util_col,int util_fil){
	int tirada_fil=-1;
	int tirada_col=-1;
	if(turno==1){
		do{
			cout<<"digame las cordenas de su tirda PRIMERO LA FILA y SEGUNDO LA COLUNA se cuenta la poscion 0"<<endl;
			cin>>tirada_fil;
			cin>>tirada_col;
			if ( mapa_tiradas[tirada_fil][tirada_col] != 0 || tirada_fil<0 || tirada_col<0||tirada_fil>util_col || tirada_col>util_fil ){
				cout<<"error en la tirada tire otora vez "<<endl;
				}
		}while(mapa_tiradas[tirada_fil][tirada_col] != 0 || tirada_fil<0 || tirada_col<0 ||tirada_fil>util_col || tirada_col>util_fil);
		mapa_tiradas[tirada_fil][tirada_col]=1;
		turno=2;
	}
	else if (turno==2){
		do{
			cout<<"digame las cordenas de su tirda PRIMERO LA FILA y SEGUNDO LA COLUNA se cuenta la poscion 0"<<endl;
			cin>>tirada_fil;
			cin>>tirada_col;
			 if ( mapa_tiradas[tirada_fil][tirada_col] != 0 ||tirada_fil<0 || tirada_col<0 ||tirada_fil>util_col || tirada_col>util_fil ){
				cout<<"error en la tirada tire otora vez "<<endl;
				}
		}while(mapa_tiradas[tirada_fil][tirada_col] != 0 || tirada_fil<0 || tirada_col<0 ||tirada_fil>util_col || tirada_col>util_fil);
		mapa_tiradas[tirada_fil][tirada_col]=2;
		turno=1;
	}
}
int comprobar_tablero(int mapa_tiradas[][DIM_COL],int condicion_ganar,int util_fil,int util_col){
	int actJ1=0;
	int actJ2=0;
	bool ganaJ1=false;
	bool ganaJ2=false;
	int ganador=-1;
	for (int f = 0; f < util_fil &&( ganaJ1==false || ganaJ2==false) ; f++)
		for (int c = 0; c < util_col; c++){
			if (mapa_tiradas[f][c]==1){
				if(mapa_tiradas[f+1][c]==1||mapa_tiradas[f+1][c+1]==1 || mapa_tiradas[f-1][c]==1|| mapa_tiradas[f-1][c-1]==1 || mapa_tiradas[f][c+1]==1 || mapa_tiradas[f][c-1]==1){
				actJ1++;
				cout<<"entro en el for de conectadas J1"<<endl;
				if(actJ1==condicion_ganar){
					cout<<"entro en ganar de j1"<<endl;
					ganaJ1=true;
				}
				}
				else 
					actJ1=0;
				
				
			}
			if (mapa_tiradas[f][c]==2){
				if(mapa_tiradas[f+1][c]==2||mapa_tiradas[f+1][c+1]==2 || mapa_tiradas[f-1][c]==2|| mapa_tiradas[f-1][c-1 ]==2 || mapa_tiradas[f][c+1]==2 || mapa_tiradas[f][c-1]==2){
				actJ2++;
				cout<<"entro en el for de conectadas J2"<<endl;
				if(actJ2==condicion_ganar){
					cout<<"entro en ganar de j2"<<endl;
					ganaJ2=true;
				}
				}
				else 
					actJ2=0;
				
				
			}
	}
	if (ganaJ1==true){
		ganador=1;
	}
	else if(ganaJ2==true){
		ganador=2;	
	}
	else {
		ganador=-1;
	}
	return ganador;
}
int main(){
	char tablero[DIM_FIL][DIM_COL] = {'-'};
   	char nombreJ1[50], nombreJ2[50];
  	int util_fil = 0;
 	int util_col = 0;
	int mapa_tiradas[DIM_FIL][DIM_COL];
	int turno=1;
	int  ganador=-1;
	int condicion_ganar=0;

    
	cout << "*** Bienvenido al 3-enRaya ***" << endl;
	cout << "Introduzca el nombre del Jugador 1 (Máx.50 caracteres):";
    	cin.getline(nombreJ1,50);
    	cout << "Introduzca el nombre del Jugador 2 (Máx.50 caracteres): ";
    	cin.getline(nombreJ2,50);
	cout <<"digame la dimension del del tablero"<<endl;
	do{	
		cout <<"¿filas? "<<endl;
 		cin>>util_fil;
			if(util_fil<=0){
				cout<<"MENOR QUE 0"<<endl;
			}
			if (util_fil>DIM_FIL){
				cout<<"tiene que se menor que "<<DIM_FIL<<endl;
			}
	while(util_fil<=0 || util_fil>DIM_FIL);
	do{
		cout <<"¿colunas?"<<endl;
   		cin>>util_col;
		if(util_fil<=0){
				cout<<"MENOR QUE 0"<<endl;
			}
		if (util_fil>DIM_COl){
				cout<<"tiene que se menor que "<<DIM_FIL<<endl;
			}
	}while(util_col<=0 || util_fil>DIM_COL);
	cout<<"cuantas hay que juntar para ganar"<<endl;
	cin>>condicion_ganar;
    	

    	inicilizarMapa(mapa_tiradas,util_col,util_fil);
    	//inicializarTablero(mapa_tiradas, util_col, util_fil);
	do{
    		imprimirTablero(mapa_tiradas,util_col,util_fil,nombreJ1,nombreJ2);
		if(turno==1){
			cout<<"su turno "<<nombreJ1<<endl;
		}
		else if (turno==2){
			cout<<"su turno "<<nombreJ2<<endl;
		}
		realizarTriada(turno,mapa_tiradas,util_col,util_fil);
		ganador=comprobar_tablero(mapa_tiradas,condicion_ganar,util_fil,util_col);
	}while (ganador==-1);
	imprimirTablero(mapa_tiradas,util_col,util_fil,nombreJ1,nombreJ2);
	cout<<"ganador vale "<<ganador<<endl;
	if (ganador==1){
		cout<<"gana "<<nombreJ1<<endl;
	}
	else if (ganador==2){
		cout<<"gana "<<nombreJ2<<endl;
 	}
}
