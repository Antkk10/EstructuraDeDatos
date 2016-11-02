

#include "test.h"
Test::Test(const ConjuntoPreguntas& todas, int num_test,set<int>& escogidas){
		
		list<string> mis_respuestas;
		int pregunta_test=1;
		int total_conjunto = todas.Size();

		int i=0;
		int preg;
		while(i<num_test){
			static bool primera_vez = true ;
   			if ( primera_vez )
   			{primera_vez = false ;
      		srand( time(NULL) );    
   			}

			preg = (rand()%total_conjunto)+1;
			
			if(escogidas.count(preg)==0){
				escogidas.insert(preg);
				string *respuestas = new string[todas.getNumRespuestas(preg)];
				for(int j=0;j<todas.getNumRespuestas(preg);j++)
					respuestas[j]=todas.getRespuestaPregunta(preg,j);
				// Nueva linea 
				// Copia el contenido del vector tipo c de respuestas en el vector tipo c++ en mis_respuestas
				for(int j=0;j<todas.getNumRespuestas(preg);j++)
					mis_respuestas.push_back(respuestas[j]);
				Pregunta p(todas.getPregunta(preg),mis_respuestas);
		
				preguntas.insert(pair<int,Pregunta>(pregunta_test,p));
				delete[] respuestas;
				mis_respuestas.clear();
				pregunta_test++;
				i++;
			}

		}
}

Test::Test(const ConjuntoPreguntas& todas, int num_test){
	if(num_test >= todas.Size() || num_test <= 0){

	}
	else{

		list<string> mis_respuestas;
		int pregunta_test=1;
		int total_conjunto = todas.Size();

		
		int vec[num_test];
		
		for(int i=0;i<num_test;i++)
			vec[i]=-1;

		int i=0;
		int preg;

		while(i<num_test){
			static bool primera_vez = true ;
   			if ( primera_vez )
   			{primera_vez = false ;
      		srand( time(NULL) );    
   			}

			preg = rand()%total_conjunto;
			bool contenida=false;
	
			for(int j=0;j<num_test && !contenida;j++){
				if(preg==vec[j])
					contenida=true;
			}
			if(!contenida){
				string *respuestas = new string[todas.getNumRespuestas(preg)];
				for(int j=0;j<todas.getNumRespuestas(preg);j++)
					respuestas[j]=todas.getRespuestaPregunta(preg,j);
				// Nueva linea 
				// Copia el contenido del vector tipo c de respuestas en el vector tipo c++ en mis_respuestas
				for(int j=0;j<todas.getNumRespuestas(preg);j++)
					mis_respuestas.push_back(respuestas[j]);
				Pregunta p(todas.getPregunta(preg),mis_respuestas);
			
				preguntas.insert(pair<int,Pregunta>(pregunta_test,p));
				delete[] respuestas;
				mis_respuestas.clear();
				pregunta_test++;
				i++;
			}

		}
	}
		
}


ofstream& operator<<(ofstream& archivo, const Test& salida){
	for(int i=1;i<=salida.size();i++){
		archivo << salida.getObjPregunta(i).getPregunta() << endl;
		for(int j=0;j<salida.getObjPregunta(i).getNumRespuestas();j++){
			archivo << salida.getObjPregunta(i).GetAnswer(j) << endl;
		}

	}
	return archivo;

}

ostream& operator<<(ostream& output, const Test& salida){
	for(int i=1;i<=salida.size();i++){
		output << salida.getObjPregunta(i).getPregunta() << endl;
		for(int j=0;j<salida.getObjPregunta(i).getNumRespuestas();j++){
			output << salida.getObjPregunta(i).GetAnswer(j) << endl;
		}

	}

	return output;
}