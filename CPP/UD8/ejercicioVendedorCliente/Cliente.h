/* 
 * File:   Cliente.h
 * Author: neozizou
 * Version: 1.0
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 * 			  SOBRECARGAS PERTINENTES.
 *
 * Created on 24 de abril de 2012, 8:49
 */

#ifndef CLIENTE_H
#define	CLIENTE_H
#include <string>
using namespace std;

class Cliente {
    private:
        string DNI;
        string nombre;
        int edad;

    public:
        //Constructores
        Cliente();
        Cliente(const Cliente &c);
        Cliente(string DNI, string nombre, int edad);
        //Destructor
        ~Cliente();
        //Los SETS
        inline void setDNI(string DNI) { this->DNI = DNI; }
        inline void setNombre(string nombre) { this->nombre = nombre; }
        inline void setEdad(int edad) { this->edad = edad; }
        //Los GETS
        inline string getDNI() const { return this->DNI; }
        inline string getNombre() const { return this->nombre; }
        inline int getEdad() const { return this->edad; }
        //SOBRECARGA DE OPERADOR =
        /* No hace falta porque sólo tenemos variables estáticas */
        //PRINT
        void print() const;
};


#endif	/* CLIENTE_H */

