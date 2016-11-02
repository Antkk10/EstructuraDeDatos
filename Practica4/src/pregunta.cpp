

#include "pregunta.h"


	
Pregunta::Pregunta(string pregunta, list<string> unas_respuestas){
	this->pregunta=pregunta;

	respuestas.assign(unas_respuestas.begin(),unas_respuestas.end());
}

Pregunta::Pregunta(){
	pregunta="";
	// La lista se inicializa con 0 respuestas por defecto.
}

void Pregunta::Borrar(){
	if(respuestas.size()!=0){
		respuestas.clear();
		pregunta="";
		
	}
}

Pregunta::~Pregunta(){
	Borrar();
}

string Pregunta::GetAnswer(int num)const{
	assert(num>=0 && num <respuestas.size());
	list<string>::const_iterator it=respuestas.begin();
	for(int i=0;i<num;i++)
		++it;
	return (*it);
}

Pregunta & Pregunta::operator=(const Pregunta& copia){
	if(this!=&copia){
		Borrar();
		this->pregunta=copia.pregunta;

		respuestas.assign(copia.respuestas.begin(),copia.respuestas.end());

	}
	return *this;
}

ostream& operator<<(ostream& output, const Pregunta& una_pregunta){
	output << una_pregunta.pregunta << endl;
	list<string>::const_iterator it;
	for(it = una_pregunta.respuestas.begin();it!=una_pregunta.respuestas.end();++it)
		output << (*it) << endl;


	return output;
}