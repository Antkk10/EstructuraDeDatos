
/**
  * @author Antonio Manuel Fernández Cantos
  * @file lista.h
  * @brief fichero de cabecera del TDA lista
  */

#ifndef LISTAS_H
#define LISTAS_H

#include <cassert>
#include "Pares.h"

/**
  * @brief Estructura que guarda un puntero y el puntero a la celda siguiente
  */
template <class T>
struct Celda{
	T elemento; ///< elemento de información
	Celda<T> *sig; ///< puntero al siguiente nodo
};


template <class T>
class Lista;
/**
  * @brief T.D.A Posición
  * 
  * Una instancia @e p sobre el tipo de dato abstracto Posición sobre @e T sirve
  * para iterar sobre un conjunto de celdas enlazadas. Así pues el comienzo será en la primera
  * celda de la lista y y otro puntero que apunta a una celda concreta. En esta clase usaremos
  * los métodos para movernos sobre un conjunto de celdas inicializadas previamente. Para saber sobre el
  * funcionamiento de las celdas lo haremos en la clase lista.
  */
template <class T>
class Posicion{
private:
	Celda<T> *punt; ///< puntero que apunta a una celda concreta
	Celda<T> *primera; ///< puntero que apunta a la celda inicial de un conjunto de celdas
public:
	/**
  	  * @brief Constructor por defecto.
	  */
	Posicion():punt(0),primera(0){}
	/**
	  * @brief método para que el atributo privado punt apunte a la celda siguiente.
	  * @pre el atributo punt sea distinto de 0
	  * @ret Devuelve this.
	  */
	Posicion<T>& operator++(){
		assert(punt!=0);
		punt=punt->sig;
		return *this;
	}
	/**
	  * @brief Devuelve el elemento de la celda apuntada.
	  */
	T& operator*(){
		return punt->sig->elemento;
	}
	/**
	  * @brief método para que el atributo privado punt apunte a la celda anterior.
	  * Si punt apunta a la primera celda, devuelve un 0
	  */
	Posicion<T>& operator--();
	/**
	  * @brief Devuelve true si las dos posiciones apuntan a la misma celda.
	  * @param p Es un objeto que contiene un puntero apuntando al inicio de un conjunto de celdas enlazadas
	  * y otro puntero apuntando a una celda concreta.
	  */
	bool operator==(const Posicion &p){
		return p.punt==punt;
	}
	/**
	  * @brief Devuelve true si las dos posiciones apuntan a distintas celdas.
	  * @param p Es un objeto que contiene un puntero apuntando al inicio de un conjunto de celdas enlazadas
	  * y otro puntero apuntando a una celda concreta.
	  */
	bool operator!=(const Posicion& p){
		return p.punt!=punt;
	}
	/**
	  * @brief Clase amiga para poder usar las celdas almacenadas en una lista.
	  */
	friend class Lista<T>;
};

/**
  * @brief T.D.A Lista
  * una instancia @e l sobre el tipo de dato abstracto Lista sobre @e T sirve para crear un conjunto de celdas enlazadas.
  * La lista es con cabecera con lo cual la cabecera apuntará al inicio de la primera celda creada y a partir de ahí se irán añadiendo
  * celdas. El objeto de instancia cab (cabecera) es de tipo Celda, como hemos mencionado anteriormente contiene dos atributos privados,
  * T elemento y un puntero Celda apuntando a la celda siguiente. La funcion de la cabecera es apuntar a la celda siguiente y no contener
  * ningún tipo de dato (elemento). Si la celda a la que apunta cab es 0 (cab->sig == 0) entonces no hay ninguna celda creada en la lista.
  * La lista no contiene ninguna celda cuando.
  */
template <class T>
class Lista{
private:
	Celda<T> *cab; ///< Puntero que apunta al principio de un conjunto de celdas.
	/**
	  * @brief método para copiar una lista en this.
	  * @param L que contiene la lista a copiar.
	  */
	void Copiar(const Lista& L);
	/**
	  * @brief 
	  * método que borrar toda la lista.
	  */
	void BorrarAll();
public:
	/**
	  * @brief Constructor sin parámetros. No crea ninguna celda.
	  */
	Lista();
	/**
	  * @brief Constructor con parámetros en el que copia una lista ya creada.
	  * @param L contiene la lista a copiar.
	  */
	Lista(const Lista<T>& L);
	/**
	  * @brief Destructor
	  */
	~Lista();
	/**
	  * @brief Operador de asignación en el cual copia una lista en this.
	  * @param L contiene la lista a copiar.
	  */
	Lista<T>& operator=(const Lista<T>& L);
	/**
	  * @brief Devuelve la cantidad de celdas inicializadas.
	  */
	int size() const;
	/**
	  * @brief método para insertar una celda en una posición y con valores concretas.
	  * @param p con la posición a insertar en el conjunto de celdas.
	  * @pre que p sea una posición válida dentro del conjunto de celdas.
	  * @param v con el contenido a guardar en la celda.
	  */
	void Insertar(Posicion<T> p, const T& v);
	/**
	  * @brief método para borrar una celda concreta dentro de un conjunto de celdas.
	  * @param p La posición a borrar.
	  * @pre que la posición sea una posición válida dentro del conjunto de celdas.
	  */
	void Borrar(Posicion<T> p);
	/**
	  * @brief Método que devuelve una posición apuntando a la primera celda.
	  */
	Posicion<T> begin()const;
	/**
	  * @brief Método que devuelve un objeto de tipo Posición con la posición de la primera y la última celda
	  * dentro de un conjunto de celdas.
	  */
	Posicion<T> end()const;
	/**
	  * @brief método que devuelve una copia del contenido de una celda concreta.
	  * @param p contiene la posición donde se encuentra la celda a copiar.
	  */
	T Get(Posicion<T> p)const;
	/**
	  * @brief método que modifica el elemento almacenado en una celda concreta
	  * @param p es la posición de la celda que se tiene que modificar.
	  * @pre que la posición exista dentro de un conjunto de celdas.
	  * @param v actualiza el contenido de la celda indicada.
	  */
	void Set(Posicion<T> p, const T& v);
};

#include "lista.cpp"

#endif
