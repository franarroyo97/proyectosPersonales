#include <iostream>
#include <stdlib.h>

using namespace std;

//Definición de las Clases
class Polinomio{
    //Atributos de la Clase
private:
    double* coef;
    int grado; //el grado actual del polinomio (GRADO + 1 = UTILES DEL VECTOR)
    int max_grado; //el grado máximo que vamos a permitir en ese polinomio (MAX_GRADO + 1 = DIMENSIÓN DEL VECTOR, es decir la memoria reservada y disponible para meter coeficientes).
    
    //grado <= max_grado SE DEBE CUMPLIR ESTA RESTRICCIÓN!!!!!!!! SI NO VIOLAMOS SEGMENTO DE COEF!!!!
    
    //Métodos de la Clase PRIVADOS
    void redimensionarVectorCoeficientes(int tamanio);
    void sumarVectorCoeficientes(const Polinomio &p1, const Polinomio &p2);
    
public:
    //MÉTODOS BÁSICOS
    Polinomio(); //constructor por defecto
    Polinomio(int max_grado, int grado); //constructor por parámetros
    Polinomio(const Polinomio &p); //constructor por copia
    ~Polinomio(); //destructor
    
    /**
     * @brief Introduce el coeficiente en el monomio de grado i, es decir en la posición i del vector de coeficientes interno del objeto. OJO!! NO REDIMENSIONA
     * @pre i >= 0 y <= MAX_GRADO
     */
    void setCoeficiente(int i, double coeficiente) {
        if(i >= 0){
            if( i > 0){
                double* aux = new double[i+1]; //Reservamos memoria
            if (aux == 0){
                cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
                exit(-1);
            }
                for (int j=0; j <= this->grado; j++)
                    aux[j] = this->coef[j];
                delete [] this->coef;
                this->coef = aux;
                aux = 0;
                for (int j=this->grado+1; j <= i ; j++) //Ponemos a 0 el resto de los nuevos coeficientes
                    this->coef[j] = 0.0;
                this->max_grado = i;
            }
            this->coef[i] = coeficiente;
            //actualizar grado
            if (coeficiente!=0.0 && i > this->grado){ //actualizamos el grado al valor de i si es mayor que el antiguo
                this->grado = i;
        }
            else if (coeficiente==0.0 && i==this->grado)  //si el coeficiente es 0 y el valor de i es igual al grado actualizamos al primer número que no sea 0
                while(this->coef[this->grado] == 0.0 && this->grado > 0)
                    this->grado--;
        
        }
        else
            cout << "ERROR" << endl;
    }
    
    /**
     * @brief
     * @param
     * @pre SUPONEMOS QUE EL GRADO ES >= 0 y <= QUE MAX_GRADO
     */
    inline void setGrado(int grado) { this->grado = grado;}
    inline void setMaxGrado(int grado) { this->max_grado = grado;}
    inline double getCoeficiente (int i) const {return this->coef[i];}
    inline int getGrado() const {return this->grado;}
    inline int getMaxGrado() const {return this->max_grado;}
    void print(); //imprime
    inline void asignarCoef(double *p){this->coef=p;}
    /**
     * @brief Suma de Polinomios. El polinomio que se le pasa por referencia será sumado al polinomio que llama al método, acumulándose el resultado en dicho "objeto invocante".
     * @post SE PIERDEN LOS DATOS DEL POLINOMIO INICIAL QUE INVOCA AL MÉTODO
     */
        void sumarV1(const Polinomio &p);
    void sumarV2(const Polinomio &p1,const Polinomio &p2);
    Polinomio sumarV3(const Polinomio &p);
	  Polinomio& operator=(const Polinomio &p);
	Polinomio operator+(Polinomio &p);	
};

//Programación de los Métodos de las Clases
/**
 * @brief Constructor de la Clase Polinomio. Por defecto reserva memoria para 10 coeficientes y lo inicializa a 0.
 */
Polinomio::Polinomio(){
    grado = 0;
    max_grado = 10;
    coef = new double[max_grado+1];
    if (coef == 0){
        cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
        exit(-1);
    }
    //inicializamos
    for (int i=0; i <= max_grado; i++)
        coef[i] = 0.0;
    
    cout << "debug: Llamada al Constructor..." << endl;
}



Polinomio::Polinomio(const Polinomio &p){//Constructor por copia
        cout << "debug: LLamamos al Constructor por copia" << endl;
        this->max_grado = p.getMaxGrado();
        this->grado = p.getGrado();
        this->coef = new double[this->max_grado+1];
        if (coef == 0){
            cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
            exit(-1);
        }
        for(int i=0; i <= this->max_grado; i++)
            this->coef[i] = p.getCoeficiente(i);




}


//Programación de los Métodos de las Clases
/**
 * @brief Constructor de la Clase Polinomio. Por parametro, reserva memoria para 10 coeficientes y lo inicializa a 0.
 */
Polinomio::Polinomio(int max_grado, int grado){
    this->grado = grado;
    this->max_grado = max_grado;
    coef = new double[max_grado+1];
    if (coef == 0){
        cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
        exit(-1);
    }
    //inicializamos
    for (int i=0; i <= max_grado; i++)
        coef[i] = 0.0;
    
    cout << "debug: Llamada al Constructor..." << endl;
}


void Polinomio::print(){
    cout << "P(x) = ";
    for(int i=this->getGrado(); i >=0 ; i--){
        if(this->getCoeficiente(i) != 0 && i != 0)
            cout << this->getCoeficiente(i) << "x^" << i <<" " ;
    else if ( i == 0)
        cout << this->getCoeficiente(i) <<" " ;
    }
    cout << endl;
}

/**
 * @brief Destructor de la Clase Polinomio. Por defecto reserva memoria para 10 coeficientes y lo inicializa a 0.
 */
Polinomio::~Polinomio(){
    //for (int i=0; i <= this->max_grado; i++)
       // this->coef[i]=0.0;
    delete [] this->coef;
    //this->grado = 0;
    //this->max_grado = 0;
    cout << "debug: Llamada al Destructor del polinomio...";
    this->print();
}




Polinomio& Polinomio::operator=(const Polinomio &p){//Sobrecarga del operador =
 	cout << "debug: Sobrecarga del operador ="<<endl;
	if(&p != this){	
		delete[] this->coef;
		cout << "debug: LLamamos al Constructor por copia" << endl;
		this->max_grado = p.getMaxGrado();
		this->grado = p.getGrado();
		this->coef = new double[this->max_grado+1];
		if (coef == 0){
		    cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
		    exit(-1);
		}
		for(int i=0; i <= this->max_grado; i++)
		    this->coef[i] = p.getCoeficiente(i);
	}
	return *this;
}






Polinomio Polinomio::operator+(Polinomio &p){//por copia
	int maxGrado=0;
        cout << "debug: Sobrecarga del operador +"<<endl;
	if(this -> getGrado() > p.getGrado()){
		maxGrado= this -> getGrado();

	}
		
	else{
		maxGrado=p.getGrado();
	}
	Polinomio resultado;
       	resultado.setGrado(maxGrado);
	 for (int i=0; i <= resultado.grado; i++){   
                    resultado.coef[i] = this->coef[i] + p.getCoeficiente(i);
        }
        while(resultado.coef[resultado.grado] == 0.0 && resultado.grado > 0)
            resultado.grado--;

    return resultado;
}
/**
 * @brief Redimensiona el vector de coeficientes al tamaño indicado por el parámetro. Y LE DA IGUAL TODO. OJO QUE PUEDES PERDER INFORMACIÓN. Habrá que hacer fuera las comprobaciones necesarias.
 */
void Polinomio::redimensionarVectorCoeficientes(int tamanio){
    double* aux = new double[tamanio]; //Reservamos memoria
    if (aux == 0){
        cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
        exit(-1);
    }
    if (tamanio <= this->getGrado()){ //se hace, pero se pierde información
        for (int j=0; j <= tamanio; j++)
            aux[j] = this->coef[j];
    }else{
        this->grado = tamanio;
        for (int j=0; j <= this->getGrado(); j++)
            aux[j] = this->coef[j];
        for (int j = this->getGrado(); j <= tamanio ; j++)
            aux[j] = 0.0;
    }
    delete[] this->coef;
    this->coef = aux;
    aux = 0;
    this->grado = tamanio;
    }

/**
 * @brief Suma de Polinomios. El polinomio que se le pasa por referencia será sumado al polinomio que llama al método, acumulándose el resultado en dicho "objeto invocante".
 * @post SE PIERDEN LOS DATOS DEL POLINOMIO INICIAL QUE INVOCA AL MÉTODO

void Polinomio::sumarV1(const Polinomio &p){
    if (p.getGrado() > this->grado_actual){ //se necesita redimensión
        this->redimensionarVectorCoeficientes(p.getGrado() + 1);
        for (int i=0; i <= p.getGrado(); i++)
            this->coef[i] = this->coef[i] + p.getCoeficiente(i);
        this->grado_actual = p.getGrado();
    }else{ //no se necesita redimensión
        for (int i=0; i <= p.getGrado(); i++)
            this->coef[i] = this->coef[i] + p.getCoeficiente(i);
        
        // hacer el for para comprobar el primer coeficiente que no es 0
        while(this->coef[this->grado] == 0.0 && this->grado > 0)
            grado--;
    }
}
*/
void Polinomio::sumarV1(const Polinomio &p){
        if (p.getGrado() > this->grado){ //se necesita redimensión
            this->redimensionarVectorCoeficientes(p.getGrado() + 1);
        this->grado = p.getGrado();
        }
        for (int i=0; i <= this->grado; i++)    
                this->coef[i] = this->coef[i] + p.getCoeficiente(i);
    
        while(this->coef[this->grado] == 0.0 && this->grado > 0)
            this->grado--;  
}

void Polinomio::sumarV2(const Polinomio &p1,const Polinomio &p2){
        if (p2.getGrado() >= p1.getGrado()){ //se necesita redimensión
            this->redimensionarVectorCoeficientes(p2.getGrado() + 1);
        for (int i=0; i <= this->grado; i++)    
                    this->coef[i] = p2.getCoeficiente(i) + p1.getCoeficiente(i);
        }
    else{
        this->redimensionarVectorCoeficientes(p1.getGrado() + 1);
        for (int i=0; i <= this->grado; i++)    
                    this->coef[i] = p1.getCoeficiente(i) + p2.getCoeficiente(i);
        }
    
        while(this->coef[this->grado] == 0.0 && this->grado > 0)
            this->grado--;
}

Polinomio Polinomio::sumarV3(const Polinomio &p){
    Polinomio resultado;

        if (p.getGrado() >= this->grado){ //se necesita redimensión
            resultado.redimensionarVectorCoeficientes(p.getGrado() + 1);
        for (int i=0; i <= resultado.grado; i++)    
                    resultado.coef[i] = this->coef[i] + p.getCoeficiente(i);
        }
    else{
        resultado.redimensionarVectorCoeficientes(this->getGrado() + 1);
        for (int i=0; i <= resultado.grado; i++)    
                    resultado.coef[i] = this->coef[i] + p.getCoeficiente(i);
    }
    
        while(resultado.coef[resultado.grado] == 0.0 && resultado.grado > 0)
            resultado.grado--;

    return resultado;
}

ostream& operator<<(ostream &salida, const Polinomio p){
	 salida << "debug: Sobrecarga del operador <<"<<endl;
	salida << "P(x) = ";
    for(int i=p.getGrado(); i >=0 ; i--){
        if(p.getCoeficiente(i) != 0 && i != 0)
            salida << p.getCoeficiente(i) << "x^" << i <<" " ;
    else if ( i == 0)
        salida << p.getCoeficiente(i) <<" " ;
    }
    salida << endl;
}



int main(){
    Polinomio p1, p2, p3, p4, p5, resultado; //llama/invoca automáticamente al constructor
        
    cout << "Bienvenido a mi primer programa orientado a objetos..." << endl;
    cout << "Caso 1: Insertar un monomio de grado menor que el grado actual" << endl;
    p1.setCoeficiente(0,3);
    p1.setCoeficiente(1,0);
    p1.setCoeficiente(2,2);
    p1.print();
        
    cout << "Caso 2: Insertar un monomio de grado negativo" << endl;
    p2.setCoeficiente(0,3);
    p2.setCoeficiente(1,1);
    //p2.setCoeficiente(-2,2);
    p2.print();

    cout << "Caso 3: Insertar un monomio de grado mayor al grado actual, pero que sea menor que max_grado" << endl;
    p3.setCoeficiente(0,3);
    p3.setCoeficiente(1,1);
    p3.setCoeficiente(2,2);
    p3.setCoeficiente(3,2);
    p3.print();

    cout << "Caso 4: Insertar un monomio de grado mayor al grado actual, y que sea mayor que max_grado" << endl;
    p4.setCoeficiente(0,3);
    p4.setCoeficiente(1,1);
    p4.setCoeficiente(2,2);
    p4.setCoeficiente(3,2);
    p4.setCoeficiente(4,2);
    p4.setCoeficiente(5,2);
    p4.setCoeficiente(6,2);
    p4.setCoeficiente(7,2);
    p4.setCoeficiente(8,2);
    p4.setCoeficiente(9,2);
    p4.setCoeficiente(10,2);
    p4.setCoeficiente(11,2);
    p4.setCoeficiente(12,4);
    p4.print();
        
    cout << "Caso 5: insertar un monomio de grado igual que el grado actual, y cuyo coeficiente sea cero" << endl;
    p5.setCoeficiente(0,3);
    p5.setCoeficiente(1,1);
    p5.setCoeficiente(1,0);
    p5.setCoeficiente(2,1);
    p5.print();
    cout << "***** Polinomio DINÁMICO *****" << endl;
    Polinomio* unpolinomiodinamico;
    unpolinomiodinamico = new Polinomio (p5);
    unpolinomiodinamico->print();
    delete unpolinomiodinamico;
    
    cout << "***** Vector ESTÁTICO DE POLINOMIOS ESTÁTICOS *****" << endl;
    Polinomio vector_pol[100];
    
    cout << "***** Vector DINÁMICO DE POLINOMIOS ESTÁTICOS *****" << endl;
    Polinomio *vectordinpol = new Polinomio[10];
    for(int i=0; i < 10; i++)
        vectordinpol[i].print();
    delete [] vectordinpol;
    
    cout << "***** Vector DINÁMICO DE POLINOMIOS DINÁMICOS*****" << endl;
    Polinomio **vectordinpoldin = new Polinomio*[10];
    for(int i=0; i < 10; i++){
        vectordinpoldin[i] = new Polinomio();
        vectordinpoldin[i]->setCoeficiente(2,2);
        vectordinpoldin[i]->print();
    }
    //1)Borro las burbujas una por una
    for(int i=0; i < 10; i++)
        delete vectordinpoldin[i];
    //2) Borro el vector dinámico de punteros
    delete [] vectordinpoldin;
    
	Polinomio p11,p10,p12,p13;
	p13=p12=p11=p10=p1+p2+p1+p3;
	cout<<"print........................."<<endl;
	cout<<p10<<"\n"<<p11<<"\n"<<p12<<"\n"<<p13<<endl;

}
