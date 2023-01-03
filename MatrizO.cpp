#include "MatrizO.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;


//---------------------------------------------------------//
//--------------METODOS DE INSERCION DE FILAS--------------//
//---------------------------------------------------------//

//caso 1: insercion de fila al inicio de todo. donde agregar es un nodo ortogonal nuevo 

void MatrizO::insertarFilaInicio(nodoO* agregar){
	
		nodoO*aux;
		
		if(Fila!=NULL){										//comprobamos que inicio no este vacio
			
		   	aux=Fila;										//aux es igual al inicio de la fila      						
			aux->izquierda=agregar;  						//luego su parte izquierda es igual al nuevo nodo
			agregar->derecha=aux;    						//ahora la derecha del nuevo nodo apunta a aux
			Fila=agregar;           						//depues aux deja de ser el inicio, porque inicio es igualado al nuevo	
		}
	
}

//caso 2: insercion de fila al final de todo. donde agregar es un nodo ortogonal nuevo 

void MatrizO::insertarFilaFinal(nodoO* agregar){

		nodoO* aux;
		
		if(Fila!=NULL){
			aux=Fila;                						//se iguala aux al punto de inicio
				while (aux->derecha!=NULL){   				//se recorre el lado derecho simpre que no este vacia
					aux=aux->derecha;   					//si se cumple que tiene datos, entonces todos los nodos apuntaran a la derecha hasta llegar a NULL
				}
			agregar->izquierda=aux; 						//ahora el nuevo nodo en su lado izquierdo, apuntara al ultimo
			aux->derecha=agregar;  							//el ultimo en su lado derecho apuntara al nuevo
		}
}

//caso 3: insercion de fila en punto medio.

void MatrizO::insertarFilaMedio(nodoO* agregar){
	
	nodoO*aux;
	nodoO*aux2;
	
	if(Fila!=NULL){
		aux=Fila;
			
			while(aux->numero < agregar->numero){   			//se recorre la fila comparando la parte numero de aux(numero) con agrega(numero)  
																//hasta identificar si es mayor
				aux=aux->derecha;								//este recorrido se hace a la derecha mientras se cumpla la condicion
			}
			aux2=aux->izquierda;   								//aux2 tomo el valor anterior de aux
			aux2->derecha=agregar;  							//ahora agregar de pone en el lado derecho de aux2
			aux->izquierda=agregar;  							//y agregar queda a la izquierda de aux
			
			agregar->derecha=aux;  								//se igual agrerar en su parte derecha a aux
			agregar->izquierda=aux2;  							//se igual agrerar en su parte izquierda a aux
	}

}

//Aqui se viene lo chido XD--> se crea la fila y se mandan a llamar los metodos anteriores
void MatrizO::insertarFila(int n){
	
	nodoO* fila;					
	fila=new nodoO;												//creacion de nuevo nodo
	
		//inicializamos valores
		fila->numero=n;       						
		fila->derecha=NULL;
		fila->izquierda=NULL;
		fila->abajo=NULL;
		fila->arriba=NULL;
		
		nodoO* aux;												//este aux nos ayudara a recorrer la fila
		aux=Fila;
		
		if (Fila==NULL){ 										//si la fila esta vacia
	
			Fila=fila;  										//fila sera el punto de inicio
		}
		else{													//sino hay datos
		
			if(n < Fila->numero)   							//CASO 1: si n es menor a inicio(numero) insertamos al inicio
				insertarFilaInicio(fila);  
			else  												
			{
				while (aux->derecha!=NULL) 						//en caso contrario, avanzara a la derecha
					aux=aux->derecha; 
				
			if(n > aux->numero)   								//CASO 2: si n en mayor lo insertara al fina
				insertarFilaFinal(fila);  					
			else 												//en caso contrario al ser mayor que el inicio pero menor que el final, cae enmedio	
				insertarFilaMedio(fila);  
			}
	}
}

bool MatrizO::fila_repetida(int n){
	
	nodoO*aux;
	aux=Fila;
	  
	bool encontrado=false;
	
		while(aux!=NULL && !encontrado){
		
			if(aux->numero==n)
				encontrado=true;
			else
				aux=aux->derecha;
		}
		
		if(encontrado==true)
			return true;
		
		else
		 	return false;
}

//---------------------------------------------------------//
//------------FIN METODOS DE INSERCION DE FILAS------------//
//---------------------------------------------------------//


//---------------------------------------------------------//
//------------METODOS DE INSERCION DE COLUMNAS-------------//
//---------------------------------------------------------//

//caso 1: insercion de columna al inicio de todo. donde agregar es un nodo ortogonal nuevo 

void MatrizO::insertarColumnaInicio(nodoO*agregar){
	
		nodoO*aux;
		
		if(Columna!=NULL){									//comprobamos que inicio no este vacio
			
		   	aux=Columna;									//aux es igual al inicio de la fila      						
			aux->arriba=agregar;  							//luego su parte arriba es igual al nuevo nodo
			agregar->abajo=aux;    							//ahora la abajo del nuevo nodo apunta a aux
			Columna=agregar;           						//depues aux deja de ser el inicio, porque inicio es igualado al nuevo	
		}
		else{												//si inicio esta vacio creara un punto inicio con todo en NULL
			agregar=nuevo();
			Columna=agregar;
			agregar->izquierda=NULL;
			agregar->derecha=NULL;
			agregar->arriba=NULL;
			agregar->abajo=NULL;
		}
	
}

//caso 2: insercion de columna al final de todo. donde agregar es un nodo ortogonal nuevo 

void MatrizO::insertarColumnaFinal(nodoO* agregar){

		nodoO* aux;
		
		if(Columna!=NULL){
			aux=Columna;                						//se iguala aux al punto de inicio
				while (aux->abajo!=NULL){   					//se recorre el lado abajo simpre que no este vacia
					aux=aux->abajo;   							//si se cumple que tiene datos, entonces todos los nodos apuntaran a la abajo hasta llegar a NULL
				}
			agregar->arriba=aux; 								//ahora el nuevo nodo en su lado arriba, apuntara al ultimo
			aux->abajo=agregar;  								//el ultimo en su lado abajo apuntara al nuevo
		}
}

//caso 3: insercion de fila en punto medio.

void MatrizO::insertarColumnaMedio(nodoO* agregar){
	
	nodoO*aux;
	nodoO*aux2;
	
	if(Columna!=NULL){
		aux=Columna;
			
			while(aux->numero < agregar->numero){   			//se recorre la fila comparando la parte numero de aux(numero) con agrega(numero)  
																//hasta identificar si es mayor
				aux=aux->abajo;									//este recorrido se hace a la derecha mientras se cumpla la condicion
			}
			aux2=aux->arriba;   								//aux2 tomo el valor anterior de aux
			aux2->abajo=agregar;  								//ahora agregar de pone en el lado derecho de aux2
			aux->arriba=agregar;  								//y agregar queda a la izquierda de aux
			
			agregar->abajo=aux;  								//se igual agrerar en su parte derecha a aux
			agregar->arriba=aux2;  								//se igual agrerar en su parte izquierda a aux
	}

}

//Aqui se viene lo chido XD--> se crea la columna y se mandan a llamar los metodos anteriores
void MatrizO::insertarColumna(int n){
	
	nodoO* columna;					
	columna=new nodoO;											//creacion de nuevo nodo
	
		//inicializamos valores
		columna->numero=n;       						
		columna->derecha=NULL;
		columna->izquierda=NULL;
		columna->abajo=NULL;
		columna->arriba=NULL;
		
		nodoO* aux;												//este aux nos ayudara a recorrer la columna
		aux=Columna;
		
		if (Columna==NULL){ 									//si la columna esta vacia
	
			Columna=columna;  									//columna sera el punto de inicio
		}
		else{													//sino hay datos
		
			if(n < Columna->numero)   							//CASO 1: si n es menor a inicio(numero) insertamos al inicio
				insertarColumnaInicio(columna);  
			else  												
			{
				while (aux->abajo!=NULL) 						//en caso contrario, avanzara a la derecha
					aux=aux->abajo; 
				
			if(n > aux->numero)   								//CASO 2: si n en mayor lo insertara al final
				insertarColumnaFinal(columna);  					
			else 												//en caso contrario al ser mayor que el inicio pero menor que el final, cae enmedio	
				insertarColumnaMedio(columna);  
			}
	}
}

bool MatrizO::columna_repetida(int n){
	
	nodoO*aux;
	aux=Columna;
	  
	bool encontrado=false;
	
		while(aux!=NULL && !encontrado){
		
			if(aux->numero==n)
				encontrado=true;
			else
				aux=aux->abajo;
		}
		
		if(encontrado==true)
			return true;
		
		else
		 	return false;
}


//---------------------------------------------------------//
//----------FIN METODOS DE INSERCION DE COLUMNAS-----------//
//---------------------------------------------------------//


//---------------------------------------------------------//
//--------------METODOS DE INSERCION DE DATOS--------------//
//---------------------------------------------------------//

//comprobacion de datos repetidos

bool MatrizO::dato_repetido(int f, int c){
			
	if(columna_repetida(c)==true && fila_repetida(f)==true){
		
		nodoO*fila=Fila;			
		nodoO*auxF;
		nodoO*auxF2;
		nodoO*aux2;
		
		bool encontrado=false;
		
		while(fila!=NULL && encontrado==false){
			
			if(fila->numero == f){
				aux2=fila;
				encontrado=true;
			}
			else{
				aux2=fila;
				fila=fila->derecha; 
			}
		}
		auxF=aux2->abajo;
			while(auxF!=NULL){
				auxF2=auxF->izquierda;
			
				while(auxF2->izquierda!=NULL)
					auxF2=auxF2->izquierda;

				if(encontrado ==true && auxF2->numero==c)
					return true;
				
				else
					auxF=auxF->abajo;	
			}
		}
		return false;	
}

//CASO 1: insercion de dato al inicio

void MatrizO::datoInicio(nodoO* f, nodoO* c, nodoO* d){
	
	f->abajo=d;											//el id de fila aputa abajo hacia dato
	c->derecha=d;										//el id de columna apunta a la derecha hacia dato							
	d->arriba=f;										// dato apunta hacia arriba al id fila
	d->izquierda=c;										//dato apunda a la izquierda al id de columna
	
	cout<<"Se agrego correctamente el dato."<<endl;
}

//CASO 2: si la fila esta vacia y la columna tiene datos
void MatrizO::dato_fila_NULL_columna_OK(nodoO* f, nodoO* c, nodoO* d){
	
	if(f->numero==1){  												//se inserta al inicio cuando el id de fila es 1
		
		nodoO*c1=c->derecha;
		
		d->izquierda=c;
		d->derecha=c1;
		d->arriba=f;
		c->derecha=d;
		c1->izquierda=d;
		f->abajo=d;
		cout<<"Se agrego correctamente el dato."<<endl;				//16:16
	}
	else{ 
		bool encontrado=false;
		
		nodoO*c4=c->derecha;
		nodoO*c3=c4->arriba;
		nodoO*c5;
		nodoO*c6;
		
		while(c4!=NULL && encontrado==false){
			
			while(c3->arriba!=NULL)	
				c3=c3->arriba;
			
			if(c3->numero > f->numero)
				encontrado=true;
			
				else{
					
				c5=c4; 												// toma el valor de c4 antes de volverse nulo;
				c4=c4->derecha;
					if(c4!=NULL)
						c3=c4;
					
				}	
		}
			if(c3->numero > f->numero){
				
				nodoO*c6=c5->derecha;	
				d->izquierda=c5;
				d->derecha=c6;
				d->arriba=f;
				c6->izquierda=d;
				c5->derecha=d;
				f->abajo=d;
				
				cout<<"Se agrego correctamente el dato."<<endl;				
			}
			else{ 
			
				if(c3->numero < f->numero){
				f->abajo=d;
				d->izquierda=c5;
				d->arriba=f;
				c5->derecha=d;
				cout<<"Se agrego correctamente el dato."<<endl;				
				}
			}
		}
}

//caso 3: el que costo un ovulo no fecundado de gallina
void MatrizO::dato_fila_OK_columna_NULL(nodoO* f, nodoO* c, nodoO* d){
	
	if(c->numero==1) 												//se insertara al inicio
	{  
		nodoO*f1=f->abajo;											//f1 se coloca abajo de id f
		d->arriba=f;												//d apunta hacia arriba indicando a f
		d->abajo=f1;												//d apunta hacia abajo indicando a f1
		d->izquierda=c;												//d apunta a la izq hacia el id c
		f->abajo=d;													//f en su parte baja apunta a d
		f1->arriba=d;												//fi en su parte arriba apunta a d
		c->derecha=d;												//id c apunta en su parte derecha a d
		cout<<"Se agrego correctamente el dato."<<endl;
	}
	else
	{  
		bool encontrado=false;
		nodoO*f4=f->abajo;
		nodoO*f3=f4->izquierda;
		nodoO*f5;
		nodoO*f6;
		
		while(f4!=NULL && encontrado==false)
		{
			while(f3->izquierda!=NULL)
			{	
				f3=f3->izquierda;
			}	
			if(f3->numero > c->numero)
			{
				encontrado=true;
			}
				else
				{
				f5=f4; 												// toma el valor de F4 antes de volverse nulo;
				f4=f4->abajo;
					if(f4!=NULL)
					{
					f3=f4;
					}
				}	
		}
			if(f3->numero > c->numero)
			{
				nodoO*f6=f5->abajo;
				d->arriba=f5;
				d->abajo=f6;
				d->izquierda=c;
				f6->arriba=d;
				f5->abajo=d;
				c->derecha=d;
				cout<<"Se agrego correctamente el dato."<<endl;			
			}
			else
			{ 
				if(f3->numero < c->numero)
				{	
				c->derecha=d;
				d->arriba=f5;
				d->izquierda=c;
				f5->abajo=d;
				cout<<"Se agrego correctamente el dato."<<endl;
				}
			}
	}
}

void MatrizO::dato_fila_OK_columna_OK(nodoO* f, nodoO* c, nodoO* d){
	
	if(c->abajo==NULL){ 																//si c en su parte inferior esta vacia
	
		if(f->numero==1){																//se inserta al inicio si la cabecera 1 en la parte baja es null
		
			nodoO*f1=f; 
				
				while(f1->abajo!=NULL)
		  			f1=f1->abajo;
		  
		  
			nodoO*c1=c->derecha;
			d->izquierda=c;
			d->derecha=c1;
			d->arriba=f1;
			c->derecha=d;
			c->izquierda=d;
			f1->abajo=d;
			cout<<"Se agrego correctamente el dato."<<endl;
		}
		else{ 
			bool encontrado=false;   													// inserta a la final si abajo esta vacio
		
			nodoO*c4=c->derecha;
			nodoO*c3=c4->arriba;
			nodoO*c5;
			nodoO*c6;
		
			while(c4!=NULL && encontrado==false){
				
				while(c3->arriba!=NULL)	
					c3=c3->arriba;
		

				if(c3->numero > f->numero)
					encontrado=true;
					
				else{
					c5=c4; 																// toma el valor de c4 antes de volverse nulo;
					c4=c4->derecha;
						if(c4!=NULL)
							c3=c4;
				}	
			}
			
			if(c3->numero > f->numero){
				nodoO*f1=f; 
			
				while(f1->abajo!=NULL)  												//recorre la fila hasta llegar a NULL;
		  			f1=f1->abajo;
   		   	
   		   	
				nodoO*c6=c5->derecha;
				d->izquierda=c5;
				d->derecha=c6;
				d->arriba=f1;
				c6->izquierda=d;
				c5->derecha=d;
				f1->abajo=d;
				cout<<"Se agrego correctamente el dato."<<endl;			
			}
			else{ 
				if(c3->numero < f->numero){
					nodoO*f1=f; 
		  			
					  while(f1->abajo!=NULL)  											//insereta en medio si esta vacio
	   	 	   			f1=f1->abajo;
   		  	
				f1->abajo=d;
				d->izquierda=c5;
				d->arriba=f1;
				c5->derecha=d;
				cout<<"Se agrego correctamente el dato."<<endl;				
				}
			}
		}
				
	}
	else{
		
			if(f->derecha==NULL){ 														//lo coloca a la derecha si esta vacio
			
				if(c->numero==1){ 														//se inserta al inicio
				  	nodoO*c1=c; 
				  	
						while(c1->derecha!=NULL) 										//recorre la fila hasta llegar a NULL
		  		  			c1=c1->derecha;
		  			
				nodoO*f1=f->abajo;
				d->arriba=f;
				d->abajo=f1;
				d->izquierda=c1;
				f->abajo=d;
				f1->arriba=d;
				c1->derecha=d;
				cout<<"Se agrego correctamente el dato."<<endl;	
				}
				
				else{
				  
					bool encontrado=false;
					nodoO*f4=f->abajo;
					nodoO*f3=f4->izquierda;
					nodoO*f5;
					nodoO*f6;
					
					while(f4!=NULL && encontrado==false){
						
						while(f3->izquierda!=NULL)
							f3=f3->izquierda;
						
						if(f3->numero>c->numero)
							encontrado=true;
						else{
		 					f5=f4; 															// toma el valor de F4 antes de volverse nulo
							f4=f4->abajo;
						if(f4!=NULL)
							f3=f4;
						}	
					}
					
					if(f3->numero > c->numero){  											//si abajo esta vacio, inserta enmedio
					
					nodoO*c1=c; 
					
					while(c1->derecha!=NULL)  												//recorre la columna hasta llegar a NULL
	   	  		 	 	c1=c1->derecha;
   		  			
						nodoO*f6=f5->abajo;
						d->arriba=f5;
						d->abajo=f6;
						d->izquierda=c1;
						f6->arriba=d;
						f5->abajo=d;
						c1->derecha=d;
						cout<<"Se agrego correctamente el dato."<<endl;			
					}
					else{ 
						if(f3->numero < c->numero){ 										//inserta al final si abajo es NULL
							nodoO*c1=c; 
						
							while(c1->derecha!=NULL)		  								//recorre la columna hasta llegar a NULL
	   	  			   			c1=c1->derecha;
   		  				 							
							c1->derecha=d;
							d->arriba=f5;
							d->izquierda=c1;
							f5->abajo=d;
							cout<<"Se agrego correctamente el dato."<<endl;	
						}
					}
				}
			}
			else{
			
				if(f->derecha!=NULL && c->abajo!=NULL){										//inserta el dato, si el dato tiene todas las direcciones 
							 																			
					if(f->numero==1){ 														//se agrega al inicio
				  
						bool encontrado=false;
						nodoO*f4=f->abajo;
						nodoO*f3=f4->izquierda;
						nodoO*f5;
						nodoO*f6;
						
						while(f4!=NULL && encontrado==false){
							
							while(f3->izquierda!=NULL)
								f3=f3->izquierda;
							
							if(f3->numero > c->numero)
								encontrado=true;
							
							else{
							
							f5=f4; 															// toma el valor de F4 antes de volverse nulo;
							f4=f4->abajo;
							
								if(f4!=NULL)
									f3=f4;
								
							}	
						}
						
						if(f3->numero > c->numero){
							f5=f4->arriba;
							
							nodoO*c1=c->derecha;	
							d->arriba=f5;
							d->abajo=f4;
							d->izquierda=c;
							d->derecha=c1;
							f4->arriba=d;
							f5->abajo=d;
							c->derecha=d;
							c1->izquierda=d;		
							cout<<"Se agrego correctamente el dato."<<endl;		
						}
		
					
					}	
					else{
						
						if(c->numero==1){ 														//se agrega al inicio
					  
							bool encontrado=false;
							
							nodoO*c4=c->derecha;
							nodoO*c3=c4->arriba;
							nodoO*c5;
							nodoO*c6;
							
							while(c4!=NULL && encontrado==false){
			
								while(c3->arriba!=NULL)	
								c3=c3->arriba;
			
								if(c3->numero > f->numero)
								encontrado=true;
			
								else{
								c5=c4; 														// toma el valor de c4 antes de volverse nulo;
								c4=c4->derecha;
									
									if(c4!=NULL)
										c3=c4;
								}	
							}
						
							if(c3->numero>f->numero){
			
								nodoO*f1=f->abajo;
								c5=c4->izquierda;	
								d->izquierda=c5;
								d->derecha=c4;
								d->arriba=f;
								d->abajo=f1;
								c4->izquierda=d;
								c5->derecha=d;
								f->abajo=d;
								f1->arriba=d;
								cout<<"Se agrego correctamente el dato."<<endl;				
							}
						}
						else{
								bool encontrado=false;
								nodoO*c4=c->derecha;
								nodoO*c3=c4->arriba;	
								nodoO*c5;
								nodoO*c6;
									
									while(c4!=NULL && encontrado==false){
										
										while(c3->arriba!=NULL)
											c3=c3->arriba;
								
										if(c3->numero>f->numero)
											encontrado=true;
										else{
											c5=c4; 											// toma el valor de c4 antes de volverse nulo;
											c4=c4->derecha;
												
												if(c4!=NULL)
													c3=c4;
										}	
									}
						
								bool encontrado2=false;
								nodoO*f4=f->abajo;
								nodoO*f3=f4->izquierda;
								nodoO*f5;
								nodoO*f6;
									
									while(f4!=NULL && encontrado2==false){
										
										while(f3->izquierda!=NULL)
											f3=f3->izquierda;
						
										if(f3->numero>c->numero)
											encontrado2=true;
		
										else{
											f5=f4; 											// toma el valor de f4 antes de volverse nulo;
											f4=f4->abajo;
										if(f4!=NULL)
											f3=f4;
					
										}	
									}
				
								nodoO*c7=c5->derecha;
								nodoO*f7=f5->abajo;
								d->izquierda=c5;
								d->derecha=c7;
								d->arriba=f5;
								d->abajo=f7;
								c5->derecha=d;
								c7->izquierda=d;
								f5->abajo=d;
								f7->arriba=d;		
								cout<<"Se agrego correctamente el dato."<<endl;			
						
						}
					}	
				}
			}
	}
}

//insercion de datos, utilizando los metodos anteriores
void MatrizO::insertarDato(int dato, int x, int y){
	
	nodoO *d=new nodoO;  																		//se crea un nuevo nodo y se inicia en NULL todos sus punteros
	d->dato=dato;
	d->derecha=NULL;
	d->izquierda=NULL;
	d->arriba=NULL;
	d->abajo=NULL;
	
	nodoO*f=Fila;  																				//se crean dos nodos con los valores iniciales de f y c
	nodoO*c=Columna;
			
	if(f!=NULL)
	{
		
		
	}	
		if(dato_repetido(x,y)==true) 															//se valida la existencia de un dato si ya existe no se insertara :(
			cout<<"La fila y la columna ya tienen datos"<<endl;
	
		else{
			if(fila_repetida(x)==false) 														//se crea la fila si esta no existe
				insertarFila(x);
			
			if(columna_repetida(y)==false) 									   					//se crea la columna si esta no existe
				insertarColumna(y);
		
			f=Fila;
			c=Columna;

			while(f!=NULL && f->numero!=x) 														//recorre la fila hasta encontrar el numero de fila
				f=f->derecha;
			
				while(c!=NULL && c->numero!=y) 													//lo mismo pero mas barato XD lo hace en las columnas
					c=c->abajo;
				
				
				if(f->abajo==NULL && c->derecha==NULL)  										//si f y c estan vacias el dato sera el punto de inicio
					datoInicio(f,c,d);
				
				else {
					if(f->abajo==NULL && c->derecha!=NULL)										//si la fila esta vacia pero la columna no, se insertara el dato
						dato_fila_NULL_columna_OK(f,c,d);
						
					else{
						if(f->abajo!=NULL && c->derecha==NULL)				    				//si la columna esta vacia pero la fila no, se insertara el dato
							dato_fila_OK_columna_NULL(f,c,d);
					
							else{
								if(f->abajo!=NULL && c->derecha!=NULL)							//aqui vale madre si estan llenas, lo inserta de todas formas :)
									dato_fila_OK_columna_OK(f,c,d);
					
							}	
					}
						
				
				}
			}
}

//---------------------------------------------------------//
//-----------METODOS DE GRAFICACION CON GRAPHVIZ-----------//
//---------------------------------------------------------//

void MatrizO::graficar(){
	
	ofstream grafica;											//se crea un objeto de la clase fstream llamado grafica
	grafica.open("matriz.dot",ios::out);
	
		if(grafica.fail()){	
			cout<<"Al parecer ocurrio un error.";
			exit(1);		
		}
		else{

			grafica<<"graph grid {"<<endl;
			grafica<<"layout=dot"<<endl;
			grafica<<"label=\"MATRIZ ORTOGONAL\""<<endl;
			grafica<<"labelloc=\"t\""<<endl;
			grafica<<"node[shape=circle]"<<endl;
			
			nodoO*c3=Columna;									//inicia a grafica las columna
				while(c3!=NULL){

					grafica<<"F"<<c3->numero;
				
					if(c3->abajo!=NULL)
						grafica<<" -- ";
					
					c3=c3->abajo;
				}

			grafica<<endl;
			
			nodoO*f3=Fila;										// inicia a graficar las filas
			grafica<<"rank=same {";

				while(f3!=NULL){
				
				grafica<<"C"<<f3->numero;
				
					if(f3->derecha!=NULL)
						grafica<<" -- ";
					
				f3=f3->derecha;
				}

			grafica<<"}"<<endl;
		
			grafica<<"edge [weight=1000 style=dashed color=dimgrey]"<<endl;
	
	
			nodoO*f=Fila;									// Datos en las filas
	
			nodoO*f2;
			
				while(f!=NULL){
					grafica<<"C"<<f->numero;
					
					if(f->abajo!=NULL)
						grafica<<" -- ";
			
					f2=f->abajo;

					while(f2!=NULL){ 
						grafica<<f2->dato;
				
					if(f2->abajo!=NULL)
						grafica<<" -- ";
				
					f2=f2->abajo;
					}
				grafica<<endl;	
				f=f->derecha;
				}	
		
		nodoO*c=Columna; 									//grafica los datos de las columnas
		nodoO*c2;

		while(c!=NULL){ 
			grafica<<"rank=same {F"<<c->numero;
			
				if(c->derecha!=NULL)
					grafica<<" -- ";
			
			c2=c->derecha;
			
			while(c2!=NULL){

				grafica<<c2->dato;
				
				if(c2->derecha!=NULL)
					grafica<<" -- ";
				
				c2=c2->derecha;	
			}
		    
			grafica<<"}"<<endl;	
			c=c->abajo;
		}
			
			grafica<<endl<<";"<<endl;
			grafica<<" } "<<endl;
			grafica.close();

			cout<<"La grafica ha sido generada con exito."<<endl;
			

			system("dot -Tpng matriz.dot > matriz.png");	
			system("matriz.png" );	
				
	}
}

//---------------------------------------------------------//
//-------------------METODO BUSQUEDA DE DATO---------------//
//---------------------------------------------------------//

void  MatrizO::buscar(int n){

	nodoO*c=Columna;
	nodoO*c1;
	nodoO*c2;
	nodoO*c3=c; 

	bool encontrado=false;

	while(c!=NULL && encontrado==false){
		c1=c->derecha;
			
			while(c1!=NULL&&encontrado==false){
				
				if(c1->dato == n){
					c2=c1->arriba;
					
					while(c2->arriba!=NULL)
						c2=c2->arriba;
					
					encontrado=true;
				}
				else
					c1=c1->derecha;
	  		}
	  	
	  	c3=c;
		c=c->abajo;	  
	}
	
	if(encontrado==true){
		cout<<"El numero: "<<n<<" esta ubicado en la"<<endl;
		cout<<"Columna: "<<c2->numero<<endl;
		cout<<"Fila: "<<c3->numero<<endl;
	}
	else
		cout<<"El numero que esta buscando no existe en la red nacional";
}

//---------------------------------------------------------//
//---------------------METODO ELIMINAR DATO----------------//
//---------------------------------------------------------//

void MatrizO::eliminar(int n){

	nodoO*c=Columna;
	nodoO*c1;
	nodoO*c2;
	bool encontrado=false;

	while(c!=NULL && encontrado==false){
		
		c1=c->derecha;
		
		while(c1!=NULL&&encontrado==false){
			
			if(c1->dato==n)
				encontrado=true;
			else
				c1=c1->derecha;
	  	}

	 	if(c->abajo!=NULL)
			c=c->abajo;	
	 }
	
	if(encontrado==true){
		
		if(c1->abajo==NULL && c1->derecha==NULL){

			nodoO*aux1=c1->izquierda;
			nodoO*aux2=c1->arriba;

			aux1->derecha=NULL;
			aux2->abajo=NULL;

			delete c1;

			cout<<"El dato ha sido eliminado con exito."<<endl;

		}
		else{
			
			if(c1->abajo!=NULL && c1->derecha==NULL){
				
				nodoO*aux1=c1->izquierda;
				nodoO*aux2=c1->arriba;
				nodoO*aux3=c1->abajo;
				
				aux1->derecha=c1->derecha;
				aux2->abajo=aux3;
				aux3->arriba=aux2;
				delete c1;
				cout<<"El dato ha sido eliminado con exito."<<endl;
		
			}
			else{

				if(c1->abajo==NULL && c1->derecha!=NULL){
					
					nodoO*aux1=c1->izquierda;
					nodoO*aux2=c1->arriba;
					nodoO*aux3=c1->derecha;
					
					aux1->derecha=aux3;
					aux3->izquierda=aux1;
					aux2->abajo=c1->abajo;
					delete c1;
					cout<<"El dato ha sido eliminado con exito."<<endl;
					
				}
				else{
				
					if(c1->abajo!=NULL && c1->derecha!=NULL){
					
						nodoO*aux1=c1->izquierda;
						nodoO*aux2=c1->arriba;
						nodoO*aux3=c1->derecha;
						nodoO*aux4=c1->abajo;
					
						aux1->derecha=aux3;
						aux3->izquierda=aux1;
						aux2->abajo=aux4;
						aux4->arriba=aux2;
						delete c1;
						cout<<"El dato ha sido eliminado con exito."<<endl;
					
					}
				}
			}
		}
	}
	else
		cout<<"El numero que ingreso no existe en la matriz.";
}

//---------------------------------------------------------//
//---------------------METODO ELIMINAR TODO----------------//
//---------------------------------------------------------//

void MatrizO::eliminarTodo(){

	nodoO*c=Columna;
	nodoO*c1;
	nodoO*aux1;
	nodoO*aux2;

	while(c->abajo!=NULL)
		c=c->abajo;
	
	while(c->arriba!=NULL)
	{
		c1=c->derecha; 
			while(c1->derecha!=NULL)
				c1=c1->derecha;
	

			while(c1!=c){

				aux1=c1->arriba;
				aux2=c1->izquierda;
				aux1->abajo=NULL;
				aux2->derecha=NULL;	
				c1=c1->izquierda;
				delete c1->derecha;
			}
		c=c->arriba;
		delete c->abajo;
	}
	delete c;
}