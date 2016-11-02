SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


$(BIN)/usopilas_min: $(OBJ)/usopilas_min.o $(LIB)/libarchivos.a
	g++ -g $< -o $@ -L$(LIB) -larchivos

$(OBJ)/usopilas_min.o: $(SRC)/usopilas_min.cpp $(INC)/Pila_min.h
	g++ -c $(SRC)/usopilas_min.cpp -o $(OBJ)/usopilas_min.o -I$(INC)/
 
$(LIB)/libarchivos.a: $(OBJ)/Pila_min.o $(OBJ)/Pares.o  
	ar rvs $(LIB)/libarchivos.a $(OBJ)/Pila_min.o $(OBJ)/Pares.o

#$(OBJ)/Pila_min_cola.o: $(SRC)/Pila_min_cola.cpp $(INC)/Pila_min_cola.h
#	g++ -c $(SRC)/Pila_min_cola.cpp -o $(OBJ)/Pila_min_cola.o -I$(INC)/

#$(OBJ)/Pila_min_lista.o: $(SRC)/Pila_min_lista.cpp $(INC)/Pila_min_lista.h
#	g++ -c $(SRC)/Pila_min_lista.cpp -o $(OBJ)/Pila_min_lista.o -I$(INC)/

#$(OBJ)/Pila_min_vd.o: $(SRC)/Pila_min_vd.cpp $(INC)/Pila_min_vd.h
#	g++ -c $(SRC)/Pila_min_vd.cpp -o $(OBJ)/Pila_min_vd.o -I$(INC)/

$(OBJ)/Pila_min.o: $(SRC)/Pila_min.cpp $(INC)/Pila_min.h $(SRC)/Pila_min_vd.cpp $(INC)/Pila_min_vd.h $(SRC)/Pila_min_lista.cpp $(INC)/Pila_min_lista.h $(SRC)/Pila_min_cola.cpp $(INC)/Pila_min_cola.h
	g++ -c $(SRC)/Pila_min.cpp -o $(OBJ)/Pila_min.o -I$(INC)/

$(OBJ)/Pares.o: $(SRC)/Pares.cpp $(INC)/Pares.h
	g++ -c $(SRC)/Pares.cpp -o $(OBJ)/Pares.o -I$(INC)/

   

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
