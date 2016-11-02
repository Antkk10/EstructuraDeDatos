
/** 
  * @author Antonio Manuel Fernández Cantos
  * @file Pares.h
  * @brief Fichero para guardar dos pares.
  * 
  */
#ifndef _ESTRUCTURA_PARES_H_
#define _ESTRUCTURA_PARES_H_

/**
  * @brief Estructura llamada Pares para guardar dos valores. 
  */
#include <iostream>
using namespace std;

struct Pares{
	int valor; ///< Valor entero
	int minimo; ///< Almacena el mínimo entre dos valores.
	/**
	  * @brief Función amiga para mostrar una pareja por pantalla.
	  * @param output permite mostrar datos por pantalla
	  * @param pareja objeto para mostrar los dos valores.
          */
	friend ostream& operator<<(ostream& output,Pares pareja);
};

#endif
