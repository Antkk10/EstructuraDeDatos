
/**
  * @author Antonio Manuel Fernández Cantos
  * @file Pila_min_cola.h
  * @brief Fichero de cabecera Pila que usa una plantilla Cola para implementar la
  * la función de una pila
  */
#ifndef _PILA_MIN_COLA_H_
#define _PILA_MIN_COLA_H_


#include "cola.h"
#include "Pares.h"

/**
  * @brief clase llamada Pila_min que tiene implementación de pila y que realiza
  * operaciones propias de una pila sobre una clase plantilla con las funciones
  * propias de una cola. La pila es una sucesión finita de elementos con un funcionamiento
  * LIFO (last input first out), esto quiere decir que el último elemento que entra es
  * el primero en salir. Si introducimos la siguiente sucesión de elementos:
  * {a0, a1, a2, ..., an} al sacar todos esos elementos introducidos tendremos la 
  * siguiente sucesión: {an, an-1, ..., a2, a1, a0}
  *
  * La plantilla cola está implementada como forma de cola, su funcionamiento interno
  * ha sido implementado y explicado en su propio fichero.
  * Se almacenarán los datos en la cola y la pila usará esos datos y
  * la forma que están implementados para adaptarlos y usarlos como forma de pila.
  *
  * El tipo de dato que usaremos será un struct de pares que almacena un elemento entero
  * y el mínimo introducido en la pila que también es de tipo entero.
  *
  * La pila no tendrá elementos cuando la función size = 0.
  */
class Pila_min{
private:
	Cola<Pares> micola; ///< plantilla que usará la pila para implementar su funcionalidad.
public:
	/**
	  * @brief Constructor sin parámetros.
          */
	Pila_min(){}

	/**
	  * @brief Método que devuelve el último dato insertado de tipo Pares.
	  * @pre la pila debe contener almenos un elemento.
	  */
	Pares tope() const;
	
	/**
	  * Devuelve true si la pila está vacia.
	  */
	bool vacia()const{
		return micola.vacia();
	}

	/**
	  * @brief quita el último elemento introducido en la pila.
	  * @pre la pila debe contener almenos un elemento.
	  */
	void quitar();

	/**
	  * @brief Introduce un elemento en la pila
	  * @param elemento que es un entero a introducir en la pila.
	  * @post puede ser que el mínimo de la pila se actualice ya que el elemento
	  * puede ser menor que el mínimo actual de la pila.
	  */
	void poner(int elemento);
	/**
	  * @brief Devuelve el número de elementos de la pila.
	  */
	int size()const{
		return micola.num_elementos();
	}

};

#endif
