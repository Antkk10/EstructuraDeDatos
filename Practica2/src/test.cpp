

#include "test.h"


Test::Test(const ConjuntoPreguntas& todas, int num_test){
	if(num_test >= todas.Size() || num_test <= 0){
		num_preg=0;
		preguntas=0;
	}
	else{
		this->num_preg=num_test;
		preguntas= new Pregunta[this->num_preg];

		int total_conjunto = todas.Size();

		int vec[this->num_preg];

		for(int i=0;i<this->num_preg;i++)
			vec[i]=-1;

		int i=0;
		int preg;
		while(i<this->num_preg){
			static bool primera_vez = true ;
   			if ( primera_vez )
   			{primera_vez = false ;
      		srand( time(NULL) );    
   			}

			preg = rand()%total_conjunto;
			bool contenida=false;
			for(int j=0;j<this->num_preg && !contenida;j++){
				if(preg==vec[j])
					contenida=true;
			}
			if(!contenida){
				string *respuestas = new string[todas.getNumRespuestas(preg)];
				for(int j=0;j<todas.getNumRespuestas(preg);j++)
					respuestas[j]=todas.getRespuestaPregunta(preg,j);
				Pregunta p(todas.getPregunta(preg),respuestas,todas.getNumRespuestas(preg));
				preguntas[i]=p;
				delete[] respuestas;
				i++;
			}

		}
	}
		
}
Test::~Test(){
	if(preguntas!=0)
		delete[] preguntas;
}

ofstream& operator<<(ofstream& archivo, const Test& salida){
	for(int i=0;i<salida.num_preg;i++){
		archivo << salida.preguntas[i].getPregunta() << endl;
		for(int j=0;j<salida.preguntas[i].getNumRespuestas();j++){
			archivo << salida.preguntas[i].getRespuesta(j) << endl;
		}

	}
	return archivo;

}

ostream& operator<<(ostream& output, const Test& salida){
	for(int i=0;i<salida.num_preg;i++){
		output << salida.preguntas[i].getPregunta() << endl;
		for(int j=0;j<salida.preguntas[i].getNumRespuestas();j++){
			output << salida.preguntas[i].getRespuesta(j) << endl;
		}

	}
	return output;
}