
#include "conjuntopreguntas.h"




void ConjuntoPreguntas::Resize(int num_tam){
	Pregunta *aux;
	aux = new Pregunta[num_tam];
	int minimo=(this->num_preg < num_tam)?num_preg:num_tam;

	for(int i=0;i<minimo;i++)
		aux[i]=preguntas[i];
	reservados=num_tam;
	delete[] preguntas;
	preguntas=aux;
	num_preg=minimo;
}

ConjuntoPreguntas::ConjuntoPreguntas(int n){
	if (n<=0){
		this->reservados=20;
		this->num_preg=0;
		this->preguntas= new Pregunta[this->reservados];
	}
	else{
		this->reservados=n;
		this->num_preg=0;
		this->preguntas= new Pregunta[this->reservados];
	}
}

ConjuntoPreguntas::~ConjuntoPreguntas(){
	if(preguntas!=0){

		delete[] preguntas;
	}

}
	
ifstream& operator>>(ifstream& archivo, ConjuntoPreguntas& conjunto){

	string pregunta;
	int numero_res;
	string *respuestas;

	while(!archivo.eof()){
		if(conjunto.num_preg==conjunto.reservados)
			conjunto.Resize(2*conjunto.reservados);

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

				Pregunta p(pregunta, respuestas, numero_res);

				conjunto.preguntas[conjunto.num_preg]=p;
				conjunto.num_preg++;
				delete[] respuestas;
			}
		
	}

	return archivo;
}