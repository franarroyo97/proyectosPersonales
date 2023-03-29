/* 
 * File:   Vendedor.h
 * Author: neozizou
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 * 			  SOBRECARGAS PERTINENTES e IMPLEMENTAR LOS MÉTODOS QUE FALTAN.
 * Created on 24 de abril de 2012, 9:23
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include <string>
#include "Cliente.h" //ojo que usa la Clase Cliente!!!
using namespace std;

class Vendedor : public Cliente{
    private:
        string DNI;
        string nombre;
        int edad;
        Cliente* clientes_asignados;
        int dim_actual;
        int utiles;
	Cliente* vector_clientes;

    public:
        //Funcionalidad Mínima
        Vendedor();
        Vendedor(const Vendedor& v);
        ~Vendedor();
        //Los SETS
        inline void setDNI(string DNI) { this->DNI = DNI; }
        inline void setNombre(string nombre) { this->nombre = nombre; }
        inline void setEdad(int edad) { this->edad = edad; }
        //Los GETS
        inline string getDNI() const { return this->DNI; }
        inline string getNombre() const { return this->nombre; }
        inline int getEdad() const { return this->edad; }
        inline int getUtiles() const { return this->utiles; }
        inline int getDim_Actual() const { return this->dim_actual; }
        //SOBRECARGA DE OPERADOR =
        Vendedor& operator=(const Vendedor &v);
        //PRINT
        void print() const;

        //Funcionalidad Avanzada
        /**
         *@brief Añade un cliente al vector de clientes del objeto
         */
        void vender(const Cliente &c);
         
        /**
         *@brief Me devuelve el cliente que está en la posición "pos"
          * del vector de clientes del objeto
         */
        Cliente getCliente(int pos) const;
};

#endif	/* VENDEDOR_H */

