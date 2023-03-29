#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/**************************************
 * Definición de la Estructura Alumno
 **************************************/
struct Alumno{
    string nombre;
    int notas[6];
    string asignaturas[6];
    int util;
};

/********************************************
 * Módulos SET y GET de la Estructura Alumno
 ********************************************/

string getNombre(const Alumno &unalumno){
    return unalumno.nombre;
}

int getNota(const Alumno &unalumno,int posicion){
    return unalumno.notas[posicion];
}

string getAsignatura(const Alumno &unalumno, int posicion){
    return unalumno.asignaturas[posicion];
}

int getUtiles(const Alumno &unalumno){
    return unalumno.util;
}

void setNombre(Alumno &unalumno, string nuevo_nombre){
    unalumno.nombre = nuevo_nombre;
}

void setNota(Alumno &unalumno, int posicion, int nueva_nota){
    unalumno.notas[posicion] = nueva_nota;
}

void setAsignatura(Alumno &unalumno, int posicion, string nueva_asignatura){
    unalumno.asignaturas[posicion] = nueva_asignatura;
}

void setUtil(Alumno &unalumno, int nueva_util){
    unalumno.util = nueva_util;
}

void imprimirAlumno(const Alumno &unalumno){
    cout << endl;
    cout << "Boletín de Calificaciones de " << getNombre(unalumno) << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i=0; i < getUtiles(unalumno); i++){
        cout << "\t\t" << getAsignatura(unalumno, i) << ": " << getNota(unalumno, i) << endl;
    }
    cout << endl;
}

void pedirAlumnoPantalla(Alumno &unalumno){
    string nuevo_nombre;
    int nueva_nota;
    string nueva_asignatura;
    int nueva_util;
    
    //1)Rellenar el nombre del alumno
    cout << "Introduzca el nombre del alumno: " << endl;
    cin >> nuevo_nombre;
    setNombre(unalumno, nuevo_nombre);
    
    //2º) Rellenar las asignaturas
    do{
        cout << "¿Cuántas asignaturas tiene el alumno? [1-6]: " << endl;
        cin >> nueva_util;
    } while ((nueva_util < 0) || (nueva_util > 6));
    setUtil (unalumno, nueva_util);
    
    for(int i=0; i < getUtiles(unalumno); i++){
        cout << "Introduzca el nombre de la asignatura (" << i+1 << "): ";
        cin >> nueva_asignatura;
        setAsignatura(unalumno, i, nueva_asignatura);
        
        cout << "Introduzca la calificación de la asignatura " << getAsignatura(unalumno, i) << ": ";
        cin >> nueva_nota;
        setNota(unalumno, i, nueva_nota);
    }
}

/*********************************************************************
 * Módulos que nos permiten manejar Vectores de la Estructura Alumno *
 *********************************************************************/
void imprimirVectorAlumno(const Alumno unvectordealumnos[], int util_unvectordealumnos, string nombre_clase){
    
    cout << "************** Clase de " << nombre_clase << " *************" << endl;
    for(int i=0; i < util_unvectordealumnos; i++)
        imprimirAlumno(unvectordealumnos[i]);
    cout << "***********************************************" << endl;
}

void insertarAlumnoenVectorAlumno(Alumno cursoX[],int &utiles){
	const int DIM=24;
	char tecla='p';
	Alumno nuevo;
	do{
		 pedirAlumnoPantalla(nuevo);
		cursoX[utiles]=nuevo;
		cout<<"si quire parar de introducir alumnos nuevos pulse la tecla s (en minusclula) en caso contrario pulse cualquir otra "<<endl;
		cin>>tecla;
		utiles++;
	}
	while(utiles < 24 && tecla !='s' );
}

//buscarAlumnoporNombreenVectorAlumno
void busca(Alumno cursoX[],string nombre_buscado,int utiles,int &pos){
	bool encontrado=false;
	string nombre;
	int i=0;
	for(i=0;i<=utiles && encontrado==false;i++){
	nombre=getNombre(cursoX[i]);
		if(nombre == nombre_buscado){
			encontrado=true;
			pos=i-1;
		}
	}
	cout<<"debug i vale "<<i<<endl;
	if (encontrado==false){
		cout<<"IMPOSIBLE ENCONTRAR INFORMARCION: "<<nombre_buscado<<"no esta dado de alta "<<endl;
	}
	else{
		cout<<"EXITO se procede a mostar los datos del alumno"<<endl;
		imprimirAlumno( cursoX[pos]);
	}
}

//eliminarAlumnoenVectorAlumno
void elimina(Alumno cursoX[],string nombre_buscado,int &utiles,int pos){
	Alumno aux;
	busca(cursoX,nombre_buscado,utiles,pos);
	if (pos!=-1){
		setNombre(cursoX[pos]," ");
		for(int i=0;i<utiles;i++){
			setNota(cursoX[pos],i,0);
			setAsignatura(cursoX[pos],i,0);
		}
		setUtil(cursoX[pos],0);
	}/*
	while(pos+1!=utiles){
		aux
		curso[pos]
		
	}
	*/	
	
}




int main(){
    //Declaración de Variables de Tipo Estructura
    Alumno david = {"David",{10,9,8,7,6,5},{"PROG","BD","ED","SI","LM","FOL"}, 6};
    Alumno musgo = {"Musgo",{9,7,8,5,7,10},{"PROG","BD","ED","SI","LM","FOL"}, 6};
    Alumno fran;
    Alumno clon_fran;
/*
    imprimirAlumno(david);
    pedirAlumnoPantalla(fran);
    imprimirAlumno(fran);
    
    cout << "¿Se puede copiar directamente con la asignación dos variables de tipo Alumno?" << endl;
    clon_fran = fran; //LA COPIA ESTÁTICA DE ESTRUCTURAS FUNCIONA CORRECTAMENTE
    imprimirAlumno(clon_fran);
    */
    //VECTORES DE ESTRUCTURAS
    Alumno dam1[24]; //vector de Alumno dimensión 24
    Alumno dam2[24];
    cout<<"parte 2..........................."<<endl;
	
    int util_dam1 = 0, util_dam2=0;
	string nombre;
   	insertarAlumnoenVectorAlumno(dam1,util_dam1);
	int pos =-1;
   // imprimirVectorAlumno(dam1, util_dam1, "DAM1");
	//insertarAlumnoenVectorAlumno(dam2,util_dam2);
   // imprimirVectorAlumno(dam2, util_dam2, "DAM2");
	cout<<"digame el nombre del alumno que quire buscar: "<<endl;
	cin>>nombre;
	busca(dam1,nombre,util_dam1,pos);
    
   
    
    //COPIA DE ALUMNOS
    //copiaAlumno(alumno, alumno_aux);
    //imprimirAlumno(alumno_aux);
}
