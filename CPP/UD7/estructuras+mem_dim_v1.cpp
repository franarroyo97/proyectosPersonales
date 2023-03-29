/* 
 * File:   estructuras.cpp
 * Author: neozizou
 *
 * Created on 15 de febrero de 2012, 9:10
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Fecha{
    int dia;
    string mes;
    int anio;
};

struct Alumno{
    string cod_alumno;
    string dni;
    string nombre;
    string apellido1;
    string apellido2;
    int edad;
    Fecha fecha_nacimiento;
    string nombres_asignaturas[6];
    int util_nombres;
    float notas[6];
    int util_notas;
};

void inicializarAlumno(Alumno *ptralumno, string cod_alumno, string dni, string nombre, string apellido1,
                   string apellido2, int edad, Fecha fecha_nacimiento, string nombres_asignaturas[], int util_nombres,
                   float notas[], int util_notas){

    //Inicialización de las variables simples
    (*ptralumno).cod_alumno = cod_alumno;
    (*ptralumno).dni = dni;
   (*ptralumno).nombre = nombre;
   (*ptralumno).apellido1 = apellido1;
   (*ptralumno).apellido2 = apellido2;
   (*ptralumno).edad = edad;
   (*ptralumno).fecha_nacimiento.dia = fecha_nacimiento.dia;
   (*ptralumno).fecha_nacimiento.mes = fecha_nacimiento.mes;
   (*ptralumno).fecha_nacimiento.anio = fecha_nacimiento.anio;
   (*ptralumno).util_notas = util_notas;
   (*ptralumno).util_nombres = util_nombres;

    //Inicialización del vector nombre de las asignaturas
    for(int i=0; i < util_nombres; i++)
        (*ptralumno).nombres_asignaturas[i]=nombres_asignaturas[i];

    //Inicialización del vector nombre de las asignaturas
    for(int i=0; i < util_notas; i++)
        (*ptralumno).notas[i]=notas[i];
}

void imprimirAlumno(const Alumno &a){

    //Imprimimos los datos básicos
    cout << "Alumn@: " << a.nombre << " " << a.apellido1 << " " << a.apellido2 << endl;
    cout << "DNI: " << a.dni << " Código de Identificación: " << a.cod_alumno << endl;
    cout << "Edad: " << a.edad << endl;
    cout << "Fecha Nacimiento: " << a.fecha_nacimiento.dia << " de "
            << a.fecha_nacimiento.mes << " de " << a.fecha_nacimiento.anio << endl;

    //Imprimimos las asignaturas que cursa y sus calificaciones actuales
    cout << "Calificaciones del Alumn@:" << endl;
    for(int i=0; i < a.util_nombres; i++){
        cout << a.nombres_asignaturas[i] << ": "
                << a.notas [i] << endl;
    }
}

//asignamos el contenido del alumno b al alumno a
void asignarAlumno(Alumno *a, Alumno &b){
    //asigación de los datos básicos de "b" a "a"
    (*a).cod_alumno = b.cod_alumno;
    (*a).dni = b.dni;
    (*a).nombre = b.nombre;
	(*a).apellido1 = b.apellido1;
    (*a).apellido2 = b.apellido2;
    (*a).edad = b.edad;
    (*a).fecha_nacimiento.dia = b.fecha_nacimiento.dia;
    (*a).fecha_nacimiento.mes = b.fecha_nacimiento.mes;
    (*a).fecha_nacimiento.anio = b.fecha_nacimiento.anio;
    (*a).util_notas = b.util_notas;
    (*a).util_nombres = b.util_nombres;

    //asigación del vector nombre de las asignaturas
    for(int i=0; i < b.util_nombres; i++)
        (*a).nombres_asignaturas[i]=b.nombres_asignaturas[i];

    //asigación del vector nombre de las asignaturas
    for(int i=0; i < b.util_notas; i++)
        (*a).notas[i]=b.notas[i];
}

//intercambiamos el contenido del alumno a y el alumno b
void intercambiarAlumnos(Alumno a, Alumno b){
    Alumno aux;
	Alumno *prtaux=&aux;
	Alumno *prta=&a;
	Alumno *ptrb=&b;
	
    asignarAlumno(prtaux,a);
    asignarAlumno(prta,b);
    asignarAlumno(ptrb,aux);
}

float calcularMediaCalificacionesAlumno(Alumno a){

    float media = 0.0;

    for(int i=0; i < a.util_notas; i++)
        media += a.notas[i];

    media = media / a.util_notas;

    return media;
}

int incluirAlumnoenVectorAlumnos(Alumno v_alumnos[], const int DIM_v_alumnos,
                                    int &util_v_alumnos, Alumno &a){
	Alumno **v;
	v=&v_alumnos;

    if((util_v_alumnos + 1) > DIM_v_alumnos)
        return -1; //No hay espacio
    else{ //HAY ESPACIO
        asignarAlumno(v[util_v_alumnos], a);
        util_v_alumnos++;
        return 0;
    }
}

void imprimirVectorAlumnos(const Alumno v_alumnos[], int &util_v_alumnos){
    for(int i = 0; i < util_v_alumnos; i++)
       imprimirAlumno(v_alumnos[i]);
}


/* NOTA DE VERSIÓN: NO ES NECESARIO MODIFICAR LOS MÓDULOS, PORQUE AL LLAMARLOS PASAMOS
 * EL CONTENIDO DEL PUNTERO (QUE ES UNA DIRECCIÓN CON MEMORIA DINÁMICA). */
int main() {
    
    /* MEMORIA ESTÁTICA */
    Alumno paquito_estatico; //aquí ya está el burbujón creado y gastado la memoria
	Alumno *prtalumno;
    /*MEMORIA DINÁMICA*/

    //Declaramos el puntero de tipo alumno
    Alumno *paquito_dinamico;

    //Reserva de memoria dinámica
    paquito_dinamico = new Alumno;

    //... Trabajos con el alumno dinámico
    //inicializamos el alumno
    //OBSERVAR LA DIFERENCIA ENTRE PASAR UN PUNTERO (PASO POR REFERENCIA) Y
    //EL PASO POR VALOR. LA VARIABLE QUE SE PASA POR VALOR DEBE ESTAR CREADA
    //FUERA DEL MÓDULO, MIENTRAS QUE EN EL PASO POR REFERENCIA, LO ÚNICO QUE
    //NECESITAMOS ES EL PUNTERO.
    Fecha fecha_nacimiento_paquito = {19, "Junio", 1991};
    string asignaturas_paquito[6] = {"PROG", "BD", "ED", "SI", "LM", "FOL"};
    float notas_paquito[6] = {0.0, 8.0, 0.0, 0.0, 0.0, 1.0};
    inicializarAlumno(paquito_dinamico,"A3","X1111111","Paquito","Dinámico","Chocolatero",
                19,fecha_nacimiento_paquito,asignaturas_paquito,6,notas_paquito,6);
    cout << "Este es Paquito DINÁMICO Chocolatero:"<< endl;
    imprimirAlumno(*paquito_dinamico);
    //Liberar la memoria dinamica
    delete paquito_dinamico;
    paquito_dinamico = 0; //antihacking
    
    
    //ESTÁTICO
	prtalumno=&paquito_estatico;
    inicializarAlumno(prtalumno,"A1","X1111111","Paquito","Estático","Chocolatero",
                      19,fecha_nacimiento_paquito,asignaturas_paquito,6,notas_paquito,6);
    cout << "Este es Paquito ESTÁTICO Chocolatero:"<< endl;
    imprimirAlumno(paquito_estatico);

    return 0;
}




