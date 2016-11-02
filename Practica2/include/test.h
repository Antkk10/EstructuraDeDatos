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
#include "conjuntopreguntas.h"
#include "pregunta.h"

using namespace std;


class Test{
private:
	Pregunta *preguntas;
	int num_preg;
public:
	/**
	  * @brief Constructor que inicializa el objeto con un conjunto de preguntas especificas.
	  * @param todas De tipo ConjuntoPreguntas que contiene un conjunto de preguntas
	  * @param num_test Entero con el numero de preguntas a almacenar en el objeto.
	  * @pre si num_test es <= 0 y > que el numero de preguntas en el conjunto, no guarda ninguna pregunta.
	*/
	Test(const ConjuntoPreguntas& todas, int num_test);
	/**
	  * @brief Borra la memoria del atributo preguntas.
	*/
	~Test();
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
