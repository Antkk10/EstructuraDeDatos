
/**
  * @author Antonio Manuel Fernández Cantos
  * @file Pila_min_lista.h
  * @brief Fichero de cabecera Pila que utiliza la plantilla lista para implementar
  * la funcionalidad de la pila.
  */
#ifndef _PILA_MIN_LISTA_H_
#define _PILA_MIN_LISTA_H_

#include "lista.h"
#include <cassert>
#include "Pares.h"

/**
  * @brief clase llamada Pila_min que tiene implementación de pila y que realiza
  * operaciones propias de una pila sobre una clase plantilla lista.
  * La pila es una sucesión finita de elementos con un funcionamiento
  * LIFO (last input first out), esto quiere decir que el último elemento que entra es
  * el primero en salir. Si introducimos la siguiente sucesión de elementos:
  * {a0, a1, a2, ..., an} al sacar todos esos elementos introducidos tendremos la 
  * siguiente sucesión: {an, an-1, ..., a2, a1, a0}
  *
  * La plantilla lista está implementada como forma de lista con cabecera, su funcionamiento interno
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
	
	Lista<Pares> milista; ///< Variable que almacena internamente celdas enlazadas y en cada celda un objeto Pares
public:
	/**
	  * @brief Constructor sin parámetros.
	  */
	Pila_min(){

	}

	/**
	  * @brief Método que el último dato introducido en la pila
	  * @pre Que la pila no esté vacia.
	  */
	Pares tope()const{
		return milista.Get(milista.begin());
	}
	
	/**
	  * @brief Método que devuelve true cuando la pila está vacia.
	  */
	bool vacia()const{
		return milista.size()==0;
	}

	/**
	  * @brief Método que quita el último elemento introducido en la pila
	  * @pre que la pila no esté vacia.
	  */
	void quitar(){
		assert(milista.size()>0);
		milista.Borrar(milista.begin());
	}

	/**
	  * @brief introduce un elemento con el mínimo de la pila.
	  */
	void poner(int elemento);

	/**
	  * @brief Devuelve la cantidad de elementos que contiene la pila.
	  */
	int size()const{
		return milista.size();
	}
};

#endif
