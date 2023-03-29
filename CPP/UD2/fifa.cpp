#include <iostream>

using namespace std;

int main (){
	int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0;
	int tiro_x=0,tiro_y=0;
	
	cout<<"le voy a pedir las cordenadas de la porteria recuerde que no deben de ser negativas (si vale que valgan 0) ";
	do{//tenemos en cuenta a -x como un espacio inexistente 
		cout<<"digame x1"<<endl;
		cin>>x1;
		cout<<"dime y1"<<endl;
		cin>>y1;
		cout<<"digame x4"<<endl;
		cin>>x4;
		cout<<"digame y4"<<endl;
		cin>>y4;
		if (x1<0||y1<0||x4<0||y4<0){//si queremos contar x- como un espacio posible solo debemos de quitar todas las x de esta condicion 
		cout<<"cordenada negativa debera de introducir todas las cordenas otra vez"<<endl;
		}
	}
	while (x1<0||y1<0||x4<0||y4<0);
	
	//cacluado porteria cuadrada ...
	x2=x1;
	y3=y1;
	x3=x4;
	y2=y4;
	cout<<"test de cordenadas "<<x1<<","<<y1<<","<<x2<<","<<y2<<","<<x3<<","<<y3<<","<<x4<<","<<y4<<endl;
	//pidiendo tiro
	cout<<"digame x de la  cordenada del tiro"<<endl;
	cin>>tiro_x;
	cout<<"digame y de la cordenada del tiro"<<endl;
	cin>>tiro_y;
	//caculando tiro
	if (tiro_y < 0){
		cout <<"tiro bajo"<<endl;
	}
	if (tiro_x<0){
		cout<<"no existe una en el plano un punto x negativo "<<endl;
	}
	if(tiro_x <x1 && tiro_x < x2){
			cout<<"fuera por la izquierda "<<endl;
	}
	if(tiro_x>x2 && tiro_x>x4){
		cout<<"fuera por la derecha"<<endl;
	}
	if(tiro_x>x1 && tiro_x<x4 && tiro_y<y3 && tiro_y<y4){
		cout<<"fuera por abajo"<<endl;
	}
	if(tiro_y>y1 && tiro_y>y2){
		cout<<"fuera tiro alto"<<endl;
	}
	if(tiro_x<x4 &&tiro_y==y1){
		cout<<"largero"<<endl;
	}
	if(tiro_x==x4 && tiro_y==y1){
		cout<<"escuadra"<<endl;
	}
	if ((tiro_x==x1 && tiro_x<x4 )||(tiro_x==x4 && tiro_x<x1)){
		cout<<"palo"<<endl;
	}
	if(tiro_x>x1 && tiro_x<x4 && tiro_y<y1 && tiro_y>y4 ){
		cout<<"¡gol!"<<endl;
	}
}

