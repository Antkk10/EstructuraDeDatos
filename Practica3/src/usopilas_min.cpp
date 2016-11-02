
#include <iostream>
#include "Pila_min.h"

using namespace std;

int main(){

  Pila_min p;
  int i;
 for ( i=10; i>=0 ; i--){
   
    p.poner(i);
    

  }

   for ( i=-4; i<=0 ; i++){
   
    p.poner(i);
    

  }

  p.poner(8);
  p.poner(2);
  p.poner(-15);
  p.poner(3);

  while (!p.vacia() ){
    Pares x = p.tope();
    cout << x <<  endl;
    p.quitar();
  }     
  
  return 0;
}
