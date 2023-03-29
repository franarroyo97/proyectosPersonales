/**
 * File:   Vendedor.cpp
 * Author: neozizou
 * Version: 1.0
 * 
 * Created on 24 de abril de 2012, 9:23
 */

#include "Vendedor.h"
#include <iostream>

Vendedor::Vendedor(){
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
    this->dim_actual = 10;
    this->utiles = 0;
    this->vector_clientes = new Cliente[10];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        //    exit(-1); //no funciona???
    }
}

Vendedor::Vendedor(const Vendedor &v){
    this->DNI = v.getDNI();
    this->nombre = v.getNombre();
    this->edad = v.getEdad();
    //ASIGNACIÓN DEL ARRAY CLIENTES
    //Borro
    //delete [] this->vector_clientes; //SOBRA PORQUE ESTÁS CONSTRUYENDO EL OBJETO Y NO HAY NADA RESERVADO!!
    //Reservo con el tamaño del array del vendedor que me pasan
    this->vector_clientes = new Cliente[v.getDim_Actual()];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
       //    exit(-1); //no funciona???
    }
    //Asigno las útiles y la dimensión
    this->dim_actual = v.getDim_Actual();
    this->utiles = v.getUtiles();
    //Copio los valores
    for (int i=0; i < this->dim_actual; i++)
        this->vector_clientes[i] = v.getCliente(i);
}

Vendedor::~Vendedor(){
    this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;
    //Ahora hay que liberar la memoria reservada del vector clientes
}

Vendedor& Vendedor::operator=(const Vendedor &v){
    this->DNI = v.getDNI();
    this->nombre = v.getNombre();
    this->edad = v.getEdad();

    if (v.getDim_Actual() > this->dim_actual){ //redimensiono el vector_clientes




    }else{//borro y reservo el nuevo espacio y copio los valores
        //Primero borro
        delete [] this->vector_clientes;
        //Reservo con el tamaño del array del vendedor que me pasar
        this->vector_clientes = new Cliente[v.getDim_Actual()];
        if (!this->vector_clientes){
            cerr << "Error en la creación del vector de clientes" << endl;
        //    exit(-1); //no funciona???
        }
        //Asigno las útiles y la dimensión
        this->dim_actual = v.getDim_Actual();
        this->utiles = v.getUtiles();
        //Copio los valores
        for (int i=0; i < this->dim_actual; i++)
            this->vector_clientes[i] = v.getCliente(i);
    }
}

void Vendedor::print() const{
    cout << "Impresión de Vendedor: " << endl;
    cout << "DNI: " << this->DNI << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
}


//Funcionalidad Avanzada
/**
 *@brief Añade un cliente al vector de clientes del objeto
 */
void Vendedor::vender(const Cliente &c){

}

/**
 *@brief Me devuelve el cliente que está en la posición "pos"
  * del vector de clientes del objeto
 */
Cliente Vendedor::getCliente(int pos) const{
}
int main(){
Cliente c1("77448308","pepe",36);
c1.print();
}

