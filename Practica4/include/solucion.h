
/**
  * @file solucion.h
  * @brief Fichero cabecera de solucion.cpp
  *
  *
  */

#ifndef _SOLUCION_H_
#define _SOLUCION_H_
#include <cassert>
#include <map>
#include <cctype>

#include <fstream>

using namespace std;

/**
  * @brief TDA Solucion
  * 
  * Clase que representa las soluciones de un conjunto de preguntas almacenadas en otro archivo.
  * Las soluciones están almacenadas en la clase map proporcionadas por la stl. Un map está formado
  * por un conjunto de parejas clave, información asociada. Los datos están ordenados por la clave y no 
  * puede haber claves repetidas.
  */

class Solucion{
private:
	map<int,char> soluciones; ///< soluciones de tipo map, int es la clave y la información asociada es un char
public:
	/**
	  * @brief constructor sin parámetros
	  */
	Solucion(){}

	/**
	  * @brief Devuelve un char asociado a una clave.
	  * @param i es un entero que es donde está almacenado el char buscado.
	  * @exception assert cuando se recibe una clave no válida.
	  */
	char GetSolucion(int i) const{
		assert(i>0 && i <=soluciones.size());
		return soluciones.at(i);
	}
	/**
	  * @brief Devuelve la cantidad de soluciones almacenadas.
	  */
	int Size() const{
		return soluciones.size();
	}

	/**
	  * @brief class const_iterator que es utilizada dentro de la clase Solucion para iterar
	  * sobre el map y poder realizar operaciones de consulta con punteros. El atributo privado
	  * que utilizamos para hacer las operaciones propias de la clase es const_iterator de map.
	  */
	class const_iterator{
	private:
		map<int,char>::const_iterator it; ///< const_iterator para realizar funciones propias de la clase
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
		const pair<const int, char>& operator*()const {
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
		  * @brief Para que el iterador pueda ser usado sobre Solucion debe declararse como amigo.
		  */
		friend class Solucion;
	};
	/**
	  * @brief devuelve un obj de tipo const_iterator apuntando al primer campo de map.
	  */
	const_iterator begin() const{
		const_iterator i;
		i.it=soluciones.begin();
		return i;
	}
	/**
	  * @brief Devuelve un obj de tipo const_iterator apuntando a la útlima posición de map.
	  * Realmente no apunta a la última posición, apunta a la siguiente posición de la última posición.
	  */
	const_iterator end() const{
		const_iterator i;
		i.it=soluciones.end();
		return i;
	}

	/**
	  * @brief Funcion amiga que sirve para guardar el contenido de un archivo en un objeto de tipo Solucion
	  * @param archivo de tipo ifstream que contiene todas las preguntas y respuestas a obtener
	  * @param conjunto de tipo solucion y es donde se almacenaran las soluciones
	*/  
	friend ifstream& operator>>(ifstream& archivo, Solucion& conjunto);

};

#endif
