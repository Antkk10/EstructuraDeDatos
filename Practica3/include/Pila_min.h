

#define CUAL_COMPILA 0
/**
  * @author Antonio Manuel Fernández Cantos
  * @brief Incluimos uno de los tres ficheros a usar por el main.
  * Con la opci´on usamos el vector de la pila, la opci´on dos usamos la lista y
  * opci´on 3 usamos la cola.
*/

#if CUAL_COMPILA==1
#include <Pila_min_vd.h>
#elif CUAL_COMPILA==2
#include <Pila_min_lista.h>
#else
#include <Pila_min_cola.h>
#endif
