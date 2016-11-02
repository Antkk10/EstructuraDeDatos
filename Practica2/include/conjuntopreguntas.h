
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
#include "pregunta.h"

using namespace std;


class ConjuntoPreguntas{
private:
	Pregunta *preguntas;
	int num_preg;
	int reservados;
	void Resize(int num_tam);
public:
	/**
	  * @brief Construye la clase ConjuntoPreguntas
	  * @param n: entero con el numero de posiciones de memoria
	  * que se tiene que reservar. Por defecto 20.
	  * @pre n > 0
	  * @exception Si n<= 0 entonces reservados=20
	*/
	ConjuntoPreguntas(int n=20);
	/**
	  * @brief Borra la memoria de la variable preguntas.
	  * @pre preguntas distinto de cero.
	*/	  
	~ConjuntoPreguntas();
	/**
	  * @brief Obtiene el numero de preguntas usadas
	  * @return Devuelve el numero de preguntas guardadas de la clase
	*/
	int Size() const{
		return num_preg;
	}
	/** 
	  * @brief Obtiene el numero de respuestas
	  * @param posicion Posicion del numero de respuestas a obtener
	  * @pre posicion >= 0 y posicion < numero de preguntas
	  * @return Devuelve el numero de respuestas de la pregunta
	*/

	int getNumRespuestas(int posicion) const{
		assert(posicion>=0 && posicion<num_preg);
		return preguntas[posicion].getNumRespuestas();
	}
	/**
	  * @brief Obtiene la respuesta concreta de una pregunta
	  * @param pregunta La posicion que ocupa la pregunta en el array pregutnas
	  * @param posicion La posicion de la respuesta en la pregunta.
	  * @pre que la posicion de la pregunta sea una posicion valida
	  * @return Devuelve un string con la respuesta buscada.
	*/
	string getRespuestaPregunta(int pregunta, int posicion) const{
		assert(pregunta>=0 && pregunta<num_preg);
		return preguntas[pregunta].getRespuesta(posicion);
	}
	/**
	  * @brief Obtener una pregunta concreta.
	  * @param posicion La posicion que ocupa la pregunta en el array
	  * @pre que la posicion sea valida dentro del array
	  * @return Devuelve un string con el contenido de la pregunta
	*/
	string getPregunta(int posicion) const{
		assert(posicion>=0 && posicion<num_preg);
		return preguntas[posicion].getPregunta();
	}
	/**
	  * @brief Funcion amiga que sirve para guardar el contenido de un archivo en un objeto de tipo ConjuntoPreguntas.
	  * @param archivo de tipo ifstream que contiene todas las preguntas y respuestas a obtener
	  * @param conjunto de tipo ConjuntoPreguntas y es donde se almacenaran las preguntas
	*/  
	friend ifstream& operator>>(ifstream& archivo, ConjuntoPreguntas& conjunto);


};

#endif
