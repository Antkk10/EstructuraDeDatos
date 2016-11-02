

#include <cassert>
#include "Pila_min_cola.h"

#include <iostream>

using namespace std;

Pares Pila_min::tope()const{
	assert(size()>0);

	Cola<Pares> aux(micola);
	int i=size();

	while(i>1){
		aux.quitar();
		i--;
	}

	return aux.frente();
}

void Pila_min::quitar(){
	assert(size()>0);

	Cola<Pares> aux;

	int i=size();

	while(i>1){
		aux.poner(micola.frente());
		micola.quitar();
		i--;
	}

	micola.quitar();
	micola=aux;
}

void Pila_min::poner(int elemento){
	
	Pares par;

	par.valor=elemento;
	if(micola.num_elementos()==0)
		par.minimo=elemento;
	else{
		Pares aux = tope();
		if(par.valor < aux.minimo)
			par.minimo=par.valor;
		else
			par.minimo=aux.minimo;
	}
	micola.poner(par);	
}