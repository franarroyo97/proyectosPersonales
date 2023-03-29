#include <iostream>

using namespace std;

int main (){
	int i=0,b;
	
	for (i=1;i<=10;i++){
		for (b=1;b<=10;b++){
			cout<<i<<" * "<<b<<" = "<<i*b<<endl;
		}
		cout <<"------------------------------------"<<endl;
	}
}
