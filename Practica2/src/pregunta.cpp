

#include "pregunta.h"


	
Pregunta::Pregunta(string pregunta, string *respuestas, int n){
	this->pregunta=pregunta;
	this->n=n;
	this->respuestas = new string[n];
	for(int i=0;i<this->n;i++)
		this->respuestas[i]=respuestas[i];
}

Pregunta::Pregunta(){
	n=0;
	respuestas=0;
	pregunta="";
}

void Pregunta::Borrar(){
	if(respuestas!=0){
		delete[] respuestas;
		pregunta="";
		n=0;
	}
}

Pregunta::~Pregunta(){
	Borrar();
}

string Pregunta::getRespuesta(int num){
	assert(num>=0 && num <n);
	return respuestas[num];	
}

Pregunta & Pregunta::operator=(const Pregunta& copia){
	if(this!=&copia){
		Borrar();
		this->n=copia.n;
		this->pregunta=copia.pregunta;
		respuestas= new string[copia.n];
		for(int i=0;i<this->n;i++)
			this->respuestas[i]=copia.respuestas[i];

	}
	return *this;
}