
#include "solucion.h"

ifstream& operator>>(ifstream& archivo, Solucion& conjunto){
	// Guardaremos la linea de lectura de un archivo
	string solucion;
	//char caracter;
	// Identificador del map
	int num_respuesta=1;
	char caracter;
	char comparador[]={'a','b','c','d','e','f','g','h','i','j','k'};

	// Lectura del fichero.
	// eof devuelve true cuando llegamos al final del fichero.
	while(!archivo.eof()){
		// Lectura de una linea del fichero y la guardamos en un string
		getline(archivo,solucion);
		bool obt_caracter=false;
		for(int i=0;i<solucion.size() && !obt_caracter;i++){
			for(int j=0;j<10 && !obt_caracter;j++){
				if(tolower(solucion[i])==comparador[j]){
					obt_caracter=true;
					caracter=solucion[i];
				}

			}
		}


		// Insertamos en el map soluciones una pareja asociada
		// al número de pregunta y un string con la solución.
		conjunto.soluciones.insert( pair<int,char>(num_respuesta,caracter));

		// Aumentamos el identificador del map.
		num_respuesta++;

	}

	return archivo;



}
