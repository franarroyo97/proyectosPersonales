#include<iostream>

using namespace std;

int  factorial (int numero) {// esta funcion cacula el factorial de un numero 

int solucion=1, i=0; 

for ( i=1 ; i<=numero ; i++ ){
	solucion = solucion *i;
	}

return solucion;
	
}

double combinatoria (int n,int m){//esta funcion cacula la combinatoria de un numero con la siguente formula : m!/n!(n-m)!

double combinatoria;

combinatoria=factorial(m)/(factorial(n)*factorial((m-n)));

return combinatoria ;
}
int main(){
int n=0,m=0;
do{
	cout<<"dime el primer numero (m)"<<endl;
	cin>>m;
	cout<<"dime el primer numero (n)"<<endl;
	cin>>n;
	if(m<n){
		cout<<m<<"es mas pequeño que "<<n<<" dime los numeros otra vez"<<endl;
	}
	if(n<=0){
		cout<<n<<"es mas pequeño que 0 dime los numeros otra vez "<<endl;
	}
}
while (m < n || n<=0);
cout<<combinatoria(n,m)<<"es el resultado"<<endl;

}
