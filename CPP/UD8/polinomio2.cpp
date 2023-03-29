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
    
    
public:
    //MÉTODOS BÁSICOS
    Polinomio(); //constructor por defecto
    Polinomio(int max_grado, int grado); //constructor por parámetros
    Polinomio(const Polinomio &p); //constructo por copia
    ~Polinomio(); //destructor
    
    /**
     * @brief Introduce el coeficiente en el monomio de grado i, es decir en la posición i del vector de coeficientes interno del objeto. OJO!! NO REDIMENSIONA
     * @pre i >= 0 y <= MAX_GRADO
     */
    void setCoeficiente(int i, double coeficiente) {
    	if(i >= 0){
	    	if( i > this->max_grado){
	    		double* aux = 0;
	    		aux = new double[i+1]; //Reservamos memoria
	    		for (int j=0; j <= this->getGrado(); j++)
	    			aux[j] = this->coef[j];
	    		delete [] this->coef;
	    		this->coef = aux;
	    		delete [] aux;
	    		aux = 0;
	    		for (int j=this->getGrado()+1; j <= i ; j++) //Ponemos a 0 el resto de los nuevos coeficientes
	    			this->coef[j] = 0.0;
	    		this->max_grado = i;
	    	}
	    	this->coef[i] = coeficiente;

	    	//actualizar grado
	    	if (coeficiente!=0.0 && i > this->grado) //actualizamos el grado al valor de i si es mayor que el antiguo
	    		this->grado = i; 
	    	else if (coeficiente==0.0 && i==this->grado)  //si el coeficiente es 0 y el valor de i es igual al grado actualizamos al primer número que no sea 0
	    		while(this->coef[this->grado] == 0.0 && this->grado>0)
	    			grado--;
	    }
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
    
    /**
     * @brief Suma de Polinomios. El polinomio que se le pasa por referencia será sumado al polinomio que llama al método, acumulándose el resultado en dicho "objeto invocante".
     * @post SE PIERDEN LOS DATOS DEL POLINOMIO INICIAL QUE INVOCA AL MÉTODO
     */
    	void sumarV1(const Polinomio &p);
	Polinomio sumarV3(const Polinomio &p1,const Polinomio &p2);
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
/**
 * @brief Destructor de la Clase Polinomio. Por defecto reserva memoria para 10 coeficientes y lo inicializa a 0.
 */
Polinomio::~Polinomio(){
    for (int i=0; i <= max_grado; i++)
        coef[i]=0.0;
    delete [] coef;
    grado = 0;
    max_grado = 0;
    cout << "debug: Llamada al Destructor..." << endl;
}

void Polinomio::print(){
    cout << "p(x) = ";
    for(int i=this->getGrado(); i >=0 ; i--){
        if(this->getCoeficiente(i) != 0)
            cout << this->getCoeficiente(i) << "x^" << i <<" " ;
    }
    cout << endl;
}

Polinomio::Polinomio(const Polinomio &p){
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
        for (int j=0; j <= this->getGrado(); j++)
            aux[j] = this->coef[j];
        for (int j = this->getGrado(); j <= tamanio ; j++)
            aux[j] = 0.0;
    }
    delete[] this->coef;
    this->coef = aux;
    delete [] aux;
    aux = 0;
    this->max_grado = tamanio;
}
 
/**
 * @brief Suma de Polinomios. El polinomio que se le pasa por referencia será sumado al polinomio que llama al método, acumulándose el resultado en dicho "objeto invocante".
 * @post SE PIERDEN LOS DATOS DEL POLINOMIO INICIAL QUE INVOCA AL MÉTODO
 */
void Polinomio::sumarV1(const Polinomio &p){
int grado_inical=this->getGrado();//el grado del polinomioactual
    if (p.getGrado() > this->grado){ //se necesita redimensión
        this->redimensionarVectorCoeficientes(p.getGrado() + 1);
        for (int i=0; i <= p.getGrado(); i++)
            this->coef[i] = this->coef[i] + p.getCoeficiente(i);
        this->grado= p.getGrado();
    }else{ //no se necesita redimensión
        for (int i=0; i <= p.getGrado(); i++)
            this->coef[i] = this->coef[i] + p.getCoeficiente(i);
        
        // hacer el for para comprobar el primer coeficiente que no es 0 (yo lo he hecho con la funcion d3e arriba)
	if (this->coef[grado_inical]==0){ //no entra en el do while si el primero no es 0
		do{
			grado_inical--;
			this->grado=grado_inical;
			cout<<"debug:0 detectado grado --"<<endl;
		}while(this->coef[grado_inical]==0);
	}
    }
}
Polinomio Polinomio::sumarV3(const Polinomio &p1,const Polinomio &p2){
Polinomio p3;
p3.setGrado(10);
cout<<"debug:creado corectamente"<<endl;
int grado_inical=p3.getGrado();//el grado del polinomioactual
int max_grado=0;

    if (p1.getGrado() > p3.getGrado() || p2.getGrado()> p3.getGrado()){ //se necesita redimensión
	cout<<"debug:entro en el primer if"<<endl;
	if(p1.getGrado() >= p2.getGrado()){
		max_grado=p1.getGrado();
	}
	else{
		max_grado=p2.getGrado();
	}
        p3.redimensionarVectorCoeficientes(max_grado+ 1);
        for (int i=0; i <= max_grado; i++)
            p3.coef[i] = p2.getCoeficiente(i) + p1.getCoeficiente(i);
        p3.grado=max_grado;
    }else{ //no se necesita redimensión
	cout<<"debug:entro en el else"<<endl;
	if(p1.getGrado() >= p2.getGrado()){
		max_grado=p1.getGrado();
	}
	else{
		max_grado=p2.getGrado();
	}
        for (int i=0; i <= max_grado; i++){
		cout<<"la i va por"<<i<<"de "<<max_grado<<endl;
 		p3.coef[i] = p2.getCoeficiente(i) + p1.getCoeficiente(i);
        }
        // hacer el for para comprobar el primer coeficiente que no es 0 (yo lo he hecho con la funcion d3e arriba)
	if (p3.coef[grado_inical]==0){ //no entra en el do while si el primero no es 0
		do{
			grado_inical--;
			p3.grado=grado_inical;
			cout<<grado_inical<<"debug:0 detectado grado --"<<endl;
		}while(p3.coef[grado_inical]==0);
	}
    }
	return p3;
}

int main(){
    Polinomio p2,p3,p4; //llama/invoca automáticamente al constructor
    double coeficiente;
    int grado;
    
    cout << "Bienvenido a mi primer programa orientado a objetos..." << endl;
    cout << "Introduzca el grado que tendrá el polinomio [0,n]: ";
    cin >> grado;
    //aquí irían los filtros para que grado esté comprendido entre 0 y max_grado...
    p2.setGrado(grado); //aquí establecemos el grado del polinomio.
    
    cout << "Introduzca los coeficientes del polinomio..." << endl;
    for(int i=0; i <= p2.getGrado(); i++){
        cout << "Monomio de grado (" << i <<  "): ";
        cin >> coeficiente;
        p2.setCoeficiente(i, coeficiente);
    }
    
    cout << "CHA CHAN... Su polinomio es: "; p2.print();
    
 	 Polinomio porcopia(p2);
    
    cout << "CHA CHAN... Su polinomio creado con el constructor por copia: ";
    porcopia.print();
    //sumar v1
	cout<<"vamos a sumar"<<endl;
	p2.sumarV1(porcopia);
	p2.print();
	// ahora vamos a probar que se comporta bien cuando la suma del primer monomio da o por ejemplo 1 +(-1)
   	cout << "Introduzca el grado que tendrá el polinomio [0,n]: ";
    	cin >> grado;
    	//aquí irían los filtros para que grado esté comprendido entre 0 y max_grado...
    	p3.setGrado(grado); //aquí establecemos el grado del polinomio.
    
   	 cout << "Introduzca los coeficientes del polinomio..." << endl;
    	for(int i=0; i <= p3.getGrado(); i++){
      	  cout << "Monomio de grado (" << i <<  "): ";
       	 cin >> coeficiente;
       	 p3.setCoeficiente(i, coeficiente);
    	}
	p2.sumarV1(p3);
	p2.print();
	p4=p4.sumarV3(porcopia,p2);
	p4.print();
    //antes de terminar se invoca automáticamente al destructor
}
