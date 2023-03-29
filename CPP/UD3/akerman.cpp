#include <iostream>
using namespace std; 

#define AZUL "\033[1;34m"
#define MORADO "\033[1;35m"
#define ROJO "\033[1;31m"
#define VERDE "\033[1;32m"
#define NORMAL "\033[0m"
#define CIAN_F "\33[1;46m"

int akerman(int m,int n){
	int resultado=0;
	if (m==0){
		resultado=n+1;
	}
	else if (m > 0 && n==0){
		resultado=akerman(m-1,1);
	}
	else if (m > 0 && n >0){
		resultado=akerman(m-1,akerman(m,n-1));
	}
	return resultado;
}

int main(){
	int m,n;
	
	cout <<"vamos a calcular la funcion de akerman"<<endl;
	cout<<"digame m:  ";
	do{
		cin>>m;
		if(m<0){
			cout<<"\n m no puede ser negativa"<<endl;
		}
	}
	while (m<0);
	cout<<"digame n:  ";
	do{
		cin>>n;
		if(n<0){
			cout<<"\n n no puede ser negativa"<<endl;
		}
	}
	while (n<0);
	cout<<"el resultado es: "<<akerman(m,n);
}
