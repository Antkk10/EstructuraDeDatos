
/**
  * @author Antonio Manuel Fernández Cantos
  * @file vd.h
  * @brief fichero de cabecera de TDA vector dinámico.
  */
#ifndef _VD_
#define _VD_

#include <cassert>

/**
 *  @brief T.D.A. VD
 *
 *
 * Una instancia @e vd del tipo de dato abstracto VD sobre un dominio @e T es
 * una sucesión finita de elementos. En una vector dinámico, las operaciones de inserción 
 * se van introduciendo en una posición pasada como parámetro y dentro del rango de númer
 * espacio reservado. El borrado y consulta también se hace recibiendo un parámetro entero (posición)
 * dentro del rango de posiciones utilizadas.
 * En este vector, tendremos acceso a cualquier posición siempre y cuando esté dentro del rango de 
 * posiciones ocupadas.
 *
 * Si n=0 diremos que el vector está vacio.
 *
 */
template <class T>
class VD{
private:
	T *datos; ///< array con los datos de tipo T almacenados.
	int n; ///< Numero de elementos almacenados
	int reservados; ///< Numero de posiciones reservadas
	/**
	  * @brief método para aumentar o disminuir la memória reservada.
	  * @param num_tam para hacer la reserva de memoria.
	  */
	void Resize(int num_tam);
public:
	/**
	  * @brief Constructor para reservar memoría en la variable de instancia datos.
	  * @param n la cantidad de reserva de memoria, por defecto es 10.
	  * @pre el parámetro n debe recibir un entero mayor estricto que 0
	  */
	VD(int n=10);
	/**
	  * @brief Constructor de copia.
	  * @param Recibe un vector dinámico a copiar.
	  */
	VD(const VD<T>& original);
	/**
	  * @brief Destructor que elmina la memoria reservada.
	  */
	~VD();
	/**
	  * @brief devuelve la cantidad de posiciones del vector utilizadas.
	  */
	int size()const{return this->n;}
	/**
	  * @brief operator que devuelve el elemento de una determinada posición.
	  * @param i la posición del dato que ocupa en el vector a devolver.
	  * @pre que el parámetro i esté entre 0 <= i < n
	  */
	T& operator[](int i){ return datos[i];}
	/**
	  * @brief operator que devuelve el elemento de una determinada posición.
	  * Este método se invoca cuando el vector es de tipo const.
	  *
	  * @param i la posición del dato que ocupa en el vector a devolver.
	  * @pre que el parámetro i esté entre 0 <= i < n
	  */
	const T& operator[](int i) const{
		return datos[i];
	}
	/**
	  * @brief Inserta un dato en una posición concreta del vector.
	  * @param dato es el dato de tipo T a introducir.
	  * @param pos la posición a introducir el dato en el vector.
	  * @pre la posición debe estar comprendida : 0 <= posición < n
	  */	
	void Insertar(const T& dato, int pos);
	/**
	  * @brief Método que borra el elemento de una posición concreta.
	  * @param pos posición a borrar del vector.
	  * @pre que la posición sea un entero entre 0 <= pos < n
	  */
	void Borrar(int pos);
	/**
	  * @brief Operator que sirve para copiar el contenido de un objeto vector dinámico
	  * en la instancia actual (this).
	  * @param vd es el vector dinámico a copiar.
	  */
	VD<T>& operator=(const VD<T>& vd);
};

#include "vd.cpp"

#endif

