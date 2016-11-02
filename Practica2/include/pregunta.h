
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

using namespace std;

class Pregunta{
private:
	string pregunta;
	string *respuestas;
	int n;  // Numero de respuestas
	/**
	  * @brief Metodo privado que borra la memoria de respuestas y pone el
	  *         resto de contenido a 0.
	*/
	void Borrar();
public:
	/**
	  * @brief Constructor para iniciar los atributos del objeto
	  * @param pregunta de tipo string que contiene el texto de la pregunta a guardar.
	  * @param respuestas puntero de tipo string con el contenido de las respuestas
	  * @param n cantidad de respuestas.
	*/
	Pregunta(string pregunta, string *respuestas, int n);
	/**
	  * @brief Constructor por defecto para inicializar los atributos.
	*/
	Pregunta();
	/**
	  * @brief Borra la memoria reservada en respuestas.
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
	string getPregunta(){
		return pregunta;
	}
	/**
	  * @brief Obtiene el numero de respuestas.
	  * @return devuelve el numero de respuestas de la pregunta.
	*/
	int getNumRespuestas(){
		return n;
	}
	/** 
	  * @brief Obtiene una respuesta concreta.
	  * @param num La posicion que ocupa la respuesta en el array.
	  * @pre La varibla num debe ser una posicion valida.
	  * @return contenido de la respuesta buscada.
	*/
	string getRespuesta(int num);
};

#endif 
