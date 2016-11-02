
#include <iostream>
#include "Pares.h"

using namespace std;

	ostream& operator<<(ostream& output, Pares pareja){
		output << "Valor: " << pareja.valor;
		output << " Minimo: " << pareja.minimo;

		return output;
	}
