


#include "Pila_min.h"

#if CUAL_COMPILA==1
#include "Pila_min_vd.cpp"
#elif CUAL_COMPILA==2
#include "Pila_min_lista.cpp"
#else
#include "Pila_min_cola.cpp"
#endif