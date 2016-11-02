
#include "conjuntopreguntas.h"





ConjuntoPreguntas::ConjuntoPreguntas(){

}


ifstream& operator>>(ifstream& archivo, ConjuntoPreguntas& conjunto){

	string pregunta;
	int numero_res;
	string *respuestas;
	list<string> mis_respuestas;

	int num_preg=1;

	while(!archivo.eof()){


		getline(archivo,pregunta);
		bool continuar=false;
		for(int i=0;i<pregunta.size() && !continuar;i++){
			char comparar;
			comparar=pregunta[i];
			if(comparar!=' ')
				continuar=true;
		}
			if(continuar){

				
				archivo >> numero_res;
				archivo.ignore();
				respuestas = new string[numero_res];
				
				for(int i=0;i<numero_res;i++){
					getline(archivo,respuestas[i]);
				}

				
				for(int i=0;i<numero_res;i++)
					mis_respuestas.push_back(respuestas[i]);


				Pregunta p(pregunta, mis_respuestas/*respuestas, numero_res*/);
				
				/* preguntas es de tipo map, queremos insertar su llave que lo identifica con el contenido asociado a esa llave
				que es un objeto de tipo pregunta con su pregunta y respuestas. Para eso tenemos que usar pair de la stl.
				En primer lugar lo ocupa un entero con el número de pregunta que es.
				*/
				conjunto.preguntas.insert(pair<int,Pregunta>(num_preg,p));
				

				mis_respuestas.clear();
				delete[] respuestas;
				num_preg++;
			}
		
	}

	return archivo;
}