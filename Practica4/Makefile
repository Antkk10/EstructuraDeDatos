SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c



all: $(BIN)/pruebagen_test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebagen_test: $(OBJ)/pruebagen_test.o $(LIB)/libarchivos.a
	g++ -g $< -o $@ -L$(LIB) -larchivos

$(OBJ)/pruebagen_test.o: $(SRC)/pruebagen_test.cpp $(INC)/conjuntopreguntas.h $(INC)/test.h 
	g++ -c $(SRC)/pruebagen_test.cpp -o $(OBJ)/pruebagen_test.o -I$(INC)/

#$(OBJ)/repasa.o: $(SRC)/repasa.cpp $(INC)/solucion.h $(INC)/test.h $(INC)/conjuntopreguntas.h 
#	g++ -c $(SRC)/repasa.cpp -o $(OBJ)/repasa.o -I$(INC)/

#$(OBJ)/pasa_test.o: $(SRC)/pasa_test.cpp $(INC)/solucion.h $(INC)/test.h $(INC)/conjuntopreguntas.h
#	g++ -c $(SRC)/pasa_test.cpp -o $(OBJ)/pasa_test.o -I$(INC)/

$(LIB)/libarchivos.a: $(OBJ)/conjuntopreguntas.o $(OBJ)/test.o $(OBJ)/pregunta.o $(OBJ)/solucion.o
	ar rvs $(LIB)/libarchivos.a $(OBJ)/conjuntopreguntas.o $(OBJ)/test.o $(OBJ)/pregunta.o $(OBJ)/solucion.o

$(OBJ)/solucion.o: $(SRC)/solucion.cpp $(INC)/solucion.h
	g++ -c $(SRC)/solucion.cpp -o $(OBJ)/solucion.o -I$(INC)/

$(OBJ)/conjuntopreguntas.o: $(SRC)/conjuntopreguntas.cpp $(INC)/conjuntopreguntas.h $(INC)/test.h
	g++ -c $(SRC)/conjuntopreguntas.cpp -o $(OBJ)/conjuntopreguntas.o -I$(INC)/


$(OBJ)/test.o: $(SRC)/test.cpp $(INC)/test.h $(INC)/conjuntopreguntas.h
	g++ -c $(SRC)/test.cpp -o $(OBJ)/test.o -I$(INC)/

$(OBJ)/pregunta.o: $(SRC)/pregunta.cpp $(INC)/pregunta.h
	g++ -c $(SRC)/pregunta.cpp -o $(OBJ)/pregunta.o -I$(INC)/




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
