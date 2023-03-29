
#include <iostream>
using namespace std;


int MCD(int a, int b){
int modulo=0;
while(a%b==0){	
	a=b;
	b=modulo;
	modulo=a%b;
	}
	return b;
	}

int main(){
int a ,b;
cout<<"digame a"<<endl;
cin>>a;
cout<<"digame b"<<endl;
cin>>b;
cout << MCD(a,b)<<"es el MCD";
}
