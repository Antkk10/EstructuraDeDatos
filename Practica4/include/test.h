/**
  * @file test.h
  * @brief Fichero con la implementación de test.cpp
  *
  *
  */
#ifndef _TEST_H_
#define _TEST_H_

#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <map>
#include <set>
#include <utility>
#include "conjuntopreguntas.h"
#include "pregunta.h"

using namespace std;

/**
  * @brief TDA Test
  * 
  *	Clase que representa una prueba de tipo Test con sus preguntas y respuestas.
  * Para representar las preguntas utilizaremos la clase map de la stl para almacenar
  * las preguntas y respuestas. Un map está formado
  * por un conjunto de parejas clave, información asociada. Los datos están ordenados por la clave y no 
  * puede haber claves repetidas. En nuestro caso las preguntas y respuestas son representadas en la
  * clase Pregunta y el map almacena objetos de tipo Pregunta. Cada pregunta está asociada a una clave
  * de tipo entero.
  */
class Test{
private:

	map<int,Pregunta> preguntas;
public:
	/**
	  * @brief Constructor que inicializa el objeto con un conjunto de preguntas especificas.
	  * @param todas De tipo ConjuntoPreguntas que contiene un conjunto de preguntas
	  * @param num_test Entero con el numero de preguntas a almacenar en el objeto.
	  * @pre si num_test es <= 0 y > que el numero de preguntas en el conjunto, no guarda ninguna pregunta.
	*/
	Test(const ConjuntoPreguntas& todas, int num_test);
	/**
	  * @brief Constructor que inicializa el objeto con un conjunto de preguntas especificas.
	  * @param todas De tipo ConjuntoPreguntas que contiene un conjunto de preguntas
	  * @param num_test Entero con el numero de preguntas a almacenar en el objeto.
	  * @pre si num_test es <= 0 y > que el numero de preguntas en el conjunto, no guarda ninguna pregunta.
	  * @param escogidas de tipo set proporcionado por la stl. set guarda enteros y nos dice la cantidad de 
	  * un número concreto de enteros que hay almacenados dentro de set.
	*/
	Test(const ConjuntoPreguntas& todas, int num_test, set<int>& escogidas);

	/**
	  * @brief método que devuelve un objeto de tipo Pregunta asociado a una clave.
	  * @param i clave que contiene el obj a devolver.
	  * @pre una clave dentro del rango de claves almacenadas en map
	  */
	Pregunta getObjPregunta(const int i) const{
		return preguntas.at(i);
	}
	/**
	  * @brief cantidad de preguntas almacenadas.
	  */
	int size() const{
		return preguntas.size();
	}
	/**
	  * @brief class iterator que es utilizada dentro de la clase Solucion para iterar
	  * sobre el map y poder realizar operaciones de consulta con punteros. El atributo privado
	  * que utilizamos para hacer las operaciones propias de la clase es iterator de map.
	  */
	class iterator{
	private:
		map<int,Pregunta>::iterator it;///< const_iterator para realizar funciones propias de la clase
	public:
		/**
		  * @brief Constructor sin parámetros.
		  */
		iterator(){}

		/**
		  * @brief Devuelve el valor del iterador apuntando al siguiente campo de map
		  * @pre que haya un campo más al que apuntar.
		  */
		iterator& operator++(){
			++it;
			return *this;
		}
		/**
		  * @brief Devuelve el valor del iterador apuntando al anterior campo de map
		  * @pre que el campo anterior sea valido.
		  */
		iterator& operator--(){
			--it;
			return *this;
		}
		/**
		  * @brief Devuelve la pareja a la que apunta el iterador en ese momento.
		  */
		const pair<const int,Pregunta>& operator*(){
			return *it;
		}
		/**
		  * @brief Compara la dirección a la que apuntan dos iteradores. Si es la misma devuelven true
		  * @param i es un objeto de tipo const_iterator para comparlo con it de this.
		  */	
		bool operator==(const iterator& i)const{
			return i.it==it;
		}
		/**
		  * @brief Compara la dirección a la que apuntan dos iteradores. Si es la misma devuelven false
		  * @param i es un objeto de tipo const_iterator para comparlo con it de this.
		  */
		bool operator!=(const iterator& i)const{
			return i.it!=it;
		}
		/**
		  * @brief Para que el iterador pueda ser usado sobre Test debe declararse como amigo.
		  */
		friend class Test;
	};
	/**
	  * @brief devuelve un obj de tipo iterator apuntando al primer campo de map.
	  */
	iterator begin(){
		iterator i;
		i.it=preguntas.begin();
		return i;
	}
	/**
	  * @brief Devuelve un obj de tipo iterator apuntando a la útlima posición de map.
	  * Realmente no apunta a la última posición, apunta a la siguiente posición de la última posición.
	  */
	iterator end(){
		iterator i;
		i.it=preguntas.end();
		return i;
	}
	/**
	  * @brief Funcion amiga que escribe en un archivo las preguntas y respuestas contenidas en un objeto Test especifico.
	  * @param archivo El archivo donde se guardara las preguntas contenidas en test
	  * @param salida Objeto de la clase Test con preguntas y respuestas.
	  * @return se devuelve el parametro archivo para que se pueda seguir utilizando.
	*/
	friend ofstream& operator<<(ofstream& archivo, const Test& salida);
	/**
	  * @brief Funcion amiga que escribe en un pantalla las preguntas y respuestas contenidas en un objeto Test especifico.
	  * @param output De tipo ostream que se usa para sacar texto en pantalla
	  * @param salida Objeto de la clase Test con preguntas y respuestas.
	  * @return se devuelve el parametro output para que se pueda seguir utilizando.
	*/
	friend ostream& operator<<(ostream& output,const Test& salida);

};

#endif
