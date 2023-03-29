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
    
    //Métodos de la Clase
public:
    //MÉTODOS BÁSICOS
    Polinomio(); //constructor por defecto
    Polinomio(int max_grado); //constructor por parámetros
    //Polinomio(Polinomio &p); //constructo por copia
    ~Polinomio(); //destructor
    void setCoeficiente(int i, double coeficiente);
    inline void setGrado(int gradonuevo) { this->grado = gradonuevo;}
    inline void setMaxGrado(int grado) { this->max_grado = grado;}
    inline double getCoeficiente (int i) {return coef[i];}
    inline int getGrado() {return grado;}
    inline int getMaxGrado() {return max_grado;}
    void print() const; //imprime
    
    //MÉTODOS AVANZADO
    //Polinomio sumar_v1 (Polinomio &p); //res = p1.sumar(p2)
    //void sumar_v2 (const Polinomio &p1, const Polinomio &p2); //res.sumar(p1,p2)
    //void sumar_v3 (const Polinomio &p); //p1.sumar(p2) en p1 se almacena tb el resultado
};

//Programación de los Métodos de las Clases
/**
 * @brief Constructor de la Clase Polinomio. Por defecto reserva memoria para 10 coeficientes y lo inicializa a 0.
 */
Polinomio::Polinomio(){
    grado = 0;
    max_grado = 0;
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
    delete [] coef;
    grado = 0;
    max_grado = 0;
    cout << "debug: Llamada al Destructor..." << endl;
}


void Polinomio::print() const{
	for(int i=grado;i>=0;i--){
		if(i==0){
			cout<<this->coef[i];
		}
		else {
			cout<<this->coef[i]<<"X"<<"^"<<i<<" ";
		}
		
	}
	cout<<endl;
	

}
void Polinomio::setCoeficiente(int i, double coeficiente){
	double * ptrd=0;
	int control=i;
	//esto es para poder hacer un test de funcionamiento
	if (i>=0){
		if (this->max_grado>i){
			this->coef[i]=coeficiente;
		}
		else{
			cout<<"bebug:entro en la redimesion"<<endl;
			ptrd=new double[i+1];
			if (ptrd==0){
				cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
	       			 exit(-1);
			}
			for (int l=0; l <= max_grado; l++)
      				  ptrd[l] = 0.0;
			 for (int j=0; j <= max_grado;j++){
				cout<<ptrd[j]<<" = "<<coef[j];
				 ptrd[j]=coef[j];
			 }
			delete [] coef;
			coef=ptrd;
			this->coef[i]=coeficiente;
			this->max_grado=i;
			cout<<i<<"sera en nuevo grado"<<endl;
			this->setGrado(i);
		}
		if(coeficiente!=0 && control>this->grado){
			this->setGrado(i);
		}
		else if(coeficiente==0 ){
			while(coef[this->grado]==0 && this->grado>0){
				grado--;
				cout<<"el grado se esta disminuñendo"<<grado<<endl;
			}
		}
	}
	else 
		cout<<"el grado no puede ser negativo"<<endl;
}
Polinomio::setCoeficienteExacto(int i, double coeficiente){
	if (this->max_grado>i){
			cout<<"bebug:entro en la redimesion"<<endl;
			ptrd=new double[i+1];
			if (ptrd==0){
				cerr << "Error en la reserva de memoria del Polinomio. Se abortará la ejecución!" << endl;
	       			 exit(-1);
			}
			for (int l=0; l <= max_grado; l++)
      				  ptrd[l] = 0.0;
			 for (int j=0; j <= max_grado;j++){
				cout<<ptrd[j]<<" = "<<coef[j];
				 ptrd[j]=coef[j];
			 }
			delete [] coef;
			coef=ptrd;
			this->coef[i]=coeficiente;
			this->max_grado=i;
			cout<<i<<"sera en nuevo grado"<<endl;
			this->setGrado(i);
		}
		else{
			
		}
}
int main(){
    Polinomio pn; //llama/invoca automáticamente al constructor
	pn.setCoeficiente(0,7);
	pn.setCoeficiente(1,8);
	pn.print();
	pn.setCoeficiente(13,9);
	pn.print();
	pn.setCoeficiente(14,0);
    pn.print();
    //antes de terminar se invoca automáticamente al destructor
}


