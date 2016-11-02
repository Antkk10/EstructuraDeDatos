
/**
  * @file pregunta.h
  * @brief Fichero con la implementación de pregunta.cpp
  *
  *
  */
#ifndef _PREGUNTA_H_
#define _PREGUNTA_H_

#include <cstring>
#include <iostream>
#include <cassert>
#include <list>

using namespace std;

/**
  * @brief TDA Pregunta
  *
  * La clase pregunta representa una pregunta y sus respectivas respuestas.
  * Las preguntas son representadas por un string y las respuestas vienen representadas por una list de string
  * La clase list nos la proporciona la stl y la utilizamos para almacenar un conjunto de respuestas asociadas 
  * a la pregunta.
  */
class Pregunta{
private:
	string pregunta;
	list<string> respuestas;
	/**
	  * @brief Método que borra la lista de respuestas.
	*/
	void Borrar();
public:
	/**
	  * @brief Constructor para iniciar los atributos del objeto
	  * @param pregunta de tipo string que contiene el texto de la pregunta a guardar.
	  * @param unas_respuestas contiene las respuestas a almacenar en el atributo respuestas de tipo list.
	*/
	Pregunta(string pregunta, list<string> unas_respuestas);
	/**
	  * @brief Constructor sin parámetros
	*/
	Pregunta();
	/**
	  * @brief Llama al método privado Borrar para limpiar la lista.
	*/
	~Pregunta();
	/**
	  * @brief operador de asignacion para asignar el contenido
	  *        de un objeto de tipo Pregunta a otro objeto.
	  * @param copia objeto de tipo Pregunta con el contenido a copiar
	  *              en el objeto que llama al operador de asignacion.
	  * @pre que this y copia sean objetos diferentes.
	  * @return devuelve el contenido de this.
	*/
	Pregunta& operator=(const Pregunta& copia);
	/**
	  * @brief Llama al contenido del atributo pregunta.
	  * @return Devuelve el contenido del string pregunta.
	*/
	const string getPregunta()const{
		return pregunta;
	}
	/**
	  * @brief Obtiene el numero de respuestas.
	  * @return devuelve el numero de respuestas de la pregunta.
	*/
	int getNumRespuestas() const{
		return respuestas.size();
	}
	/** 
	  * @brief Obtiene una respuesta concreta.
	  * @param num La posicion que ocupa la respuesta en el array.
	  * @pre La varibla num debe ser una posicion valida.
	  * @return contenido de la respuesta buscada.
	*/
	string GetAnswer(int num)const;

	/**
	  * @brief Funcion amiga que sirve para mostrar por pantalla el contenido del objeto.
	  * @param archivo de tipo ifstream que contiene todas las preguntas y respuestas a obtener
	  * @param una_pregunta de tipo Pregunta y contiene el contenido a mostrar por pantalla.
	*/ 
	friend ostream& operator<<(ostream& output, const Pregunta& una_pregunta);
};

#endif 
