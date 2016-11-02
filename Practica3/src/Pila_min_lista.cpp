
#include "Pila_min_lista.h"
#include <iostream>

using namespace std;

void Pila_min::poner(int elemento){
		
		Pares par;
		par.valor=elemento;
		if(milista.size()==0){
			par.minimo=elemento;
		}
		else{
			Pares aux = tope();
			if(aux.minimo>par.valor){
				par.minimo=par.valor;
			}
			else
				par.minimo=aux.minimo;
		}
		milista.Insertar(milista.begin(),par);	
}