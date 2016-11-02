
/**
  * @author Antonio Manuel Fernández Cantos
  * @file Pila_min_vd.h
  * @brief Cabecera que utiliza una plantilla vector dinámico para implementar la funcionalidad
  * de una pila. El tipo de dato introducido en el vector es Pares en el cual esta estructura
  * contiene un elemento de tipo entero y el mínimo actual de la pila.
  */
#ifndef _PILA_MIN_VD_H_
#define _PILA_MIN_VD_H_

#include "vd.h"
#include <cassert>
#include "Pares.h"

/**
  * @brief Pila
  *
  * La pila utiliza la plantilla vector dinámico pasandole el tipo Pares (explicada anteriormente).
  * Usa la funcionalidad del vector dinámico para implementar la propia funcionalidad de la pila.
  * La pila está vacia cuando la función size del vector dinámico nos devuelve 0.
  *
  * Una pila es una sucesión de elemento con un funcionamiento LIFO (Last in first out) el último
  * elemento que entra es el primero en salir. Si introducimos una sucesión de elementos :
  * {a0, a1, a2, ..., an} al sacarlos de la pila obtendremos la siguiente sucesión :
  * {aN, aN-2, ..., a2, a1, a0}
  *
  */
class Pila_min{
private:
	VD<Pares> datos; ///< variable de tipo VD que internamiente utiliza Pares.
public:
	/**
	  * @brief Devuelve el último elemento introducido en la pila
	  * @pre La pila debe contener almenos un elemento.
	  */
	Pares tope()const{
		assert(datos.size() > 0);
		return datos[datos.size()-1];
	}

	/**
	  * @brief Devuelve true cuando la pila está vacia.
	  */
	bool vacia()const{
		return datos.size()==0;
	}

	/**
	  * @brief quita el último elemento introducido en la pila.
	  * @pre la pila debe contener almenos un elemento.
	  */
	void quitar(){
		assert(datos.size()>0);
		datos.Borrar(datos.size()-1);
	}
	
	/**
	  * @brief Método que introduce un elemento en la pila.
	  */
	void poner(int elemento);

	/**
	  * @brief Devuelve el número de elementos introducidos en la pila.
	  */
	int size()const{
		return datos.size();
	}
};

#endif
