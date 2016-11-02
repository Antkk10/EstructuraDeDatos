
/**
  * @file conjuntopreguntas.h
  * @brief Fichero con la implementación de conjuntopreguntas.cpp
  *
  *
  */
#ifndef _CONJUNTOPREGUNTAS_H_
#define _CONJUNTOPREGUNTAS_H_

#include <string>
#include <fstream>
#include <list>
#include <map>
#include "pregunta.h"

using namespace std;

/**
  * @brief TDA ConjuntoPreguntas
  *
  * Conjunto preguntas como su propio nombre indica es un conjunto de preguntas. Las preguntas vienen representadas
  * por un map en la cual el primer campo del map representa la clave que debe de ser única y el segundo campo
  * viene es de tipo Pregunta. Un map (diccionario) es un conjunto de parejas clve (de tipo int en este caso),
  * información (de tipo Pregunta) asociada. Los datos están ordenados por la clave y no puede haber claves repetidas.
  *
  * Esta TDA la usaremos como Base de datos para almacenar un conjunto finito de preguntas y que posteriormente podemos
  * llamar a los métodos de consulta para poder obtener las preguntas y sus respectivas respuestas.
  */
class ConjuntoPreguntas{
private:

	map<int,Pregunta> preguntas; ///< map que representa la clave con su información
	
public:
	/**
	  * @brief Constructor sin parámetros, no necesitamos inicializar el map preguntas.
	*/
	ConjuntoPreguntas();

	/**
	  * @brief Devuelve el número de preguntas almacenadas.
	*/
	int Size() const{
		//return num_preg;
		return preguntas.size();
	}
	/** 
	  * @brief Obtiene el numero de respuestas
	  * @param posicion Posicion del numero de respuestas a obtener
	  * @pre posicion > 0 y posicion <= numero de preguntas
	  * @return Devuelve el número de respuestas de la pregunta
	*/

	int getNumRespuestas(int posicion) const{
		assert(posicion>0 && posicion<=preguntas.size());
		return preguntas.at(posicion).getNumRespuestas();
	}
	/**
	  * @brief Obtiene la respuesta concreta de una pregunta
	  * @param pregunta La posición que ocupa la pregunta en el array pregutnas
	  * @param posicion La posición de la respuesta en la pregunta.
	  * @pre que la posicion de la pregunta sea una posicion valida
	  * @return Devuelve un string con la respuesta buscada.
	*/
	string getRespuestaPregunta(int pregunta, int posicion) const{
		assert(pregunta>0 && pregunta<=preguntas.size());
		return preguntas.at(pregunta).GetAnswer(posicion);
	}
	/**
	  * @brief Obtener una pregunta concreta.
	  * @param posicion La posición que ocupa la pregunta en el array
	  * @pre que la posicion sea valida dentro del array
	  * @return Devuelve un string con el contenido de la pregunta
	*/
	const string getPregunta(int posicion) const{
		assert(posicion>0 && posicion<=preguntas.size());
		return preguntas.at(posicion).getPregunta();
	}

	/**
	  * @brief class const_iterator que es utilizada dentro de la clase ConjuntoPreguntas para iterar
	  * sobre el map y poder realizar operaciones de consulta con punteros. El atributo privado
	  * que utilizamos para hacer las operaciones propias de la clase es const_iterator de map.
	  */
	class const_iterator{
	private:
		map<int,Pregunta>::const_iterator it;  ///< const_iterator para realizar funciones propias de la clase
	public:
		/**
		  * @brief Constructor sin parámetros.
		  */
		const_iterator(){}

		/**
		  * @brief Devuelve el valor del iterador apuntando al siguiente campo de map
		  * @pre que haya un campo más al que apuntar.
		  */
		const const_iterator& operator++(){
			++it;
			return *this;
		}
		/**
		  * @brief Devuelve el valor del iterador apuntando al anterior campo de map
		  * @pre que el campo anterior sea valido.
		  */
		const const_iterator& operator--(){
			--it;
			return *this;
		}
		/**
		  * @brief Devuelve la pareja a la que apunta el iterador en ese momento.
		  */
		const pair<const int, Pregunta>& operator*() const{
			return *it;
		}
		/**
		  * @brief Compara la dirección a la que apuntan dos iteradores. Si es la misma devuelven true
		  * @param i es un objeto de tipo const_iterator para comparlo con it de this.
		  */
		bool operator==(const const_iterator &i) const{
			return i.it==it;
		}
		/**
		  * @brief Compara la dirección a la que apuntan dos iteradores. Si es la misma devuelven false
		  * @param i es un objeto de tipo const_iterator para comparlo con it de this.
		  */
		bool operator!=(const const_iterator& i)const{
			return i.it!=it;
		}

		/**
		  * @brief Para que el iterador pueda ser usado sobre ConjuntoPreguntas debe declararse como amigo.
		  */
		friend class ConjuntoPreguntas;
	};

	/**
	  * @brief devuelve un obj de tipo const_iterator apuntando al primer campo de map.
	  */
	const_iterator begin() const{
		const_iterator i;
		i.it=preguntas.begin();
		return i;
	}
	/**
	  * @brief Devuelve un obj de tipo const_iterator apuntando a la útlima posición de map.
	  * Realmente no apunta a la última posición, apunta a la siguiente posición de la última posición.
	  */
	const_iterator end() const{
		const_iterator i;
		i.it=preguntas.end();
		return i;
	}


	/**
	  * @brief Funcion amiga que sirve para guardar el contenido de un archivo en un objeto de tipo ConjuntoPreguntas.
	  * @param archivo de tipo ifstream que contiene todas las preguntas y respuestas a obtener
	  * @param conjunto de tipo ConjuntoPreguntas y es donde se almacenaran las preguntas
	*/  
	friend ifstream& operator>>(ifstream& archivo, ConjuntoPreguntas& conjunto);


};

#endif
