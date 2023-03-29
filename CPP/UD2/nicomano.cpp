#include<iostream>

using namespace std;

int main(){
	long int contador=1,solucion=0,i=0,res=0;
	bool primero=false

	for (i=1;i<=100;i++){
		while( contador <=i ){
			if (primero=false){ 
			solucion=1;
			cout<<contador<<"al cubo es :"<<solucion<<end;
			primero=true
			}
			solucion=solucion+2;
			contador=contador+2;
			cout<<contador<<"al cubo es :"<<solucion<<endl;
		}
		
		
	}
}

