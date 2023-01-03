#ifndef MATRIZO_H
#define MATRIZO_H

#include <iostream>

using namespace std;

class nodoO{
	
public:
	nodoO* derecha;
	nodoO*izquierda;
	nodoO*arriba;
	nodoO* abajo;
	int dato;	//dato a agregar
	int numero; //identificador
	
		friend class MatrizO;
};


	
nodoO* nuevo(){

nodoO* p;
p= new nodoO;
return p;
}

	nodoO*Fila;				//inicio filas
	nodoO*Columna;			//inicio columnas

class MatrizO{
	

public:	
	//filas
		void insertarFilaInicio(nodoO* agregar);
		void insertarFilaFinal(nodoO* agregar);
		void insertarFilaMedio(nodoO* agregar);
		void insertarFila(int n);
		bool fila_repetida(int n);
		
	//columnas
		void insertarColumnaInicio(nodoO* agregar);
		void insertarColumnaFinal(nodoO* agregar);
		void insertarColumnaMedio(nodoO* agregar);
		void insertarColumna(int n);
		bool columna_repetida(int n);
		
	//datos
		bool dato_repetido(int f, int c);
		void datoInicio(nodoO* f, nodoO* c, nodoO* d);
		void dato_fila_NULL_columna_OK(nodoO* f, nodoO* c, nodoO* d);	//este metodo agrega el dato si la fila esta vacia pero la columna no
		void dato_fila_OK_columna_NULL(nodoO* f, nodoO* c, nodoO* d);	//este metodo agrega el dato si la columna esta vacia pero la fila no
		void dato_fila_OK_columna_OK(nodoO* f, nodoO* c, nodoO* d);		//este agrega el numero si la fila y la columna ya tienen datos
		void insertarDato(int dato,int x,int y);
		
	//graphviz
		void graficar();
		
	//buscar un dato
		void buscar(int n);
	
	//eliminar un dato
		void eliminar(int n);
		
	// eliminar todo
		void eliminarTodo();
		
};

#endif 
