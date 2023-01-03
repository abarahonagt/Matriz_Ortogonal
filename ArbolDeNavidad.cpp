#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>


using namespace std;
int op, contador=0; 
ofstream arbi;

struct nodo{
	int numero;
	nodo *derecha;
	nodo *izquierda;
	nodo *abajo;
	char l;	
};

nodo *arbol =NULL;

//Metodos
void insertar(nodo *&arbol,int n) //insertar numero
{
	
	nodo *aux2=new nodo();   //reservacion de espacio para insertar el numero
	aux2->numero=n;
	aux2->derecha=NULL;
	aux2->izquierda=NULL;
	aux2->abajo=NULL;

	if(arbol == NULL)//Si se encuentra vacio
	{
		aux2->abajo = NULL;
		arbol=aux2;
	}
	else//Si ya hay algo 
	{
		int raiz = arbol->numero;
		if(n < raiz) //comparacion para enviar a la izq
		{
		insertar(arbol->izquierda,n);
			
		}
		else
		{
			insertar(arbol->derecha,n); //comparacion para enviar a la der
		}
	}
}

void InsertarLetra(nodo *&arbol,int n, char letra) //insertar letra
{
if(arbol == NULL)  //Si se encuentra vacio
	{
		cout<<"el arbol esta vacio"<<endl;

	}
		else 
		{
		if(arbol->numero == n)//compara si es igual al numero
		{
			nodo *auxL=new nodo();
			auxL->l=letra;
			auxL->derecha=NULL;
			auxL->izquierda=NULL;
			auxL->abajo=NULL;
			nodo*aux2=arbol;
				while(aux2->abajo!=NULL)
				{
					aux2=aux2->abajo;
				} 

				aux2->abajo=auxL;
				cout<<aux2->abajo->l;
		}
		else 
		{
			if(n < arbol->numero)
			{
		 	InsertarLetra(arbol->izquierda,n,letra);
			}
			else{
				if(n>arbol->numero)
				{
			 InsertarLetra(arbol->derecha,n,letra);
				}
				}
			
		}
		
	}
}

void mostrar(nodo *arbol,int cont) //muestra el arbol en la pantalla
{
	
	if(arbol == NULL)
	{
		return;
	}
	else
	{
		mostrar(arbol->derecha, cont+1);
		for(int i=0;i< cont;i++) 
		{
			cout<<"   ";
		}
		cout<<arbol->numero;
		cout<<"--->";
		
		nodo *aux;
		aux=arbol->abajo;
		while(aux !=NULL)
		{
		cout<<aux->l;
		
		if(aux->abajo !=NULL)
		{
			cout<<"--->";
		}
			aux=aux->abajo;
		}
		cout<<endl;
		mostrar(arbol->izquierda,cont+1);
	}
}

void mostrarX(nodo *arbol) //Sirve para graficar el arbol con graphviz
{
	if(arbol == NULL)
	{
		return;
	}
	else
	{
		
		if(arbol->izquierda!=NULL)
		{
			arbi<<arbol->numero;
			arbi<<" -> ";
			mostrarX(arbol->izquierda);
		}
		
		arbi<<arbol->numero;
		arbi<<" -> ";
		nodo *aux;
		aux = arbol->abajo;
		
		while(aux != NULL)
		{
			arbi<<aux->l;
			if(aux->abajo !=NULL)
			{
				arbi<<" -> ";
			}
			aux=aux->abajo;
		}
		arbi<<endl;
		
		if(arbol->derecha!=NULL)
		{
			arbi<<arbol->numero;
			arbi<<" -> ";
			mostrarX(arbol->derecha);
		}
		
	}
	
}

void Graficar() //grafica y crea
{
	arbi.open("arbollista.dot", ios::out);
	
	if(arbi.fail())
	{
		cout<<"ERROR AL CREAR ARCHIVO";
	}
	arbi<<"digraph G {"<<endl;

	mostrarX(arbol);
	
	arbi<<endl;
	arbi<<"}";
	
	arbi.close();
	system("dot -Tpng arbollista.dot > arbollista.png");
	system("arbollista.png");

}


void Orden(nodo *arbol) //Orden
{
	if(arbol == NULL)
	{
		return;
	}
	else
	{
		
		Orden(arbol->izquierda);
		cout<<arbol->numero<<" -> ";
		
		nodo*aux;
		aux=arbol->abajo;
		while(aux !=NULL)
		{
		cout<<aux->l<<" - ";
		
			aux=aux->abajo;
		}
		
		Orden(arbol->derecha);
	}
	
}

void PreOrden(nodo *arbol) //Pre-orden
{
		if(arbol ==NULL)
	{
		return;
	}
	else
	{
		
		cout<<arbol->numero<<" ---> ";
		
		nodo*aux;
		aux=arbol->abajo;
		while(aux !=NULL)
		{
		cout<<aux->l<<" -- ";
		
			aux=aux->abajo; 
		}
		
		PreOrden(arbol->izquierda);
		PreOrden(arbol->derecha);
	}
}

void PostOrden(nodo *arbol) //Post-orden
{
		if(arbol ==NULL)
	{
		return;
	}
	else
	{
		PostOrden(arbol->izquierda);
		PostOrden(arbol->derecha);
		cout<<arbol->numero<<" ---> ";
		
		nodo*aux;
		aux=arbol->abajo;
		while(aux !=NULL)
		{
		cout<<aux->l<<" -- ";
		
			aux=aux->abajo;
		}
		
	}
}

bool buscar(nodo *arbol,int n) 
{
	if(arbol == NULL)    //Si se encuentra vacio
	{
		return false;
	}
	else if(arbol->numero == n) //compara si es igual al numero
	{
		
	}
	else if(n < arbol->numero)
	{
		return buscar(arbol->izquierda,n);
	}
	else{
		return buscar(arbol->derecha,n);
	}

}

void Tiempo()
{
	int segundos=5;
    for(int i=0; i<=21; i++)
        cout << "\n";
    cout << "\n CARGANDO...\n";
    for(int i=0; i<=79; i++)
        cout << " ";
    for(int i=0; i<=79; i++)
    {
        cout<<char(219);
        Sleep(segundos*1000/80);
    }
    cout<<"\n Abriendo archivo";

}

void BuscarLetra(nodo *arbol,char letra)
{
	
	if(arbol == NULL)
	{
	}
	else
	{
		BuscarLetra(arbol->derecha,letra);
	
		nodo *aux;
		aux=arbol->abajo;
		while(aux !=NULL)
		{
			if(aux->l==letra)
			{
				cout<<"LA LETRA "<<aux->l<<" ESTA EN EL NUMERO "<<arbol->numero<<endl;

			}
		if(aux->abajo !=NULL)
		{
	
		}
			aux=aux->abajo;
		}

		BuscarLetra(arbol->izquierda,letra);
	}
	
}

void Menu(){
	system("cls");
	cout<<" >> ARBOL BINARIO - LISTAS ENLAZADAS << "<<endl;
	cout<<"   "<<endl;
	cout<<" 1) Ingresar un numero: "<<endl;
	cout<<" 2) Ingresar una letra bajo un numero: "<<endl;
	cout<<" 3) Ver el arbol: "<<endl;
	cout<<" 4) Buscar un numero: "<<endl;
	cout<<" 5) Buscar una letra: "<<endl;
	cout<<" 6) Ver en orden:  "<<endl;
	cout<<" 7) Ver en pre-orden: "<<endl;
	cout<<" 8) Ver en post-orden: "<<endl;
	cout<<" 9) Graficar: "<<endl;
	cout<<" 10) Exit: "<<endl;
	cout<<"   "<<endl;
	cout<<" >> Diguite el numero de la opcion que desea utilizar: ";
	cin>>op;	

}

main()
{	
	arbol=NULL;
	
	do{
		Menu();
		char letra;
		int numero;
		switch(op)
		{
			case 1:
				system("cls");
				cout<<endl;
				cout<<"Ingrese el numero: ";
				cin>>numero;
				if(buscar(arbol,numero) == true)
				{
					cout<<"ERROR!! EL NUMERO YA FUE INGRESADO ANTERIORMENTE!! "<<endl;
					cout<<endl;
				}
				else
				{
				insertar(arbol,numero); //Nuevo nodo
				cout<<endl<<endl;
				cout<<"Ingresado con exito: "<<endl<<endl;
				}
				system("pause");		
				break;
					
			case 2:
				system("cls");
				cout<<endl;
				cout<<"Ingrese el numero en el que desea ingresar la letra: ";
				cin>>numero;
				cout<<"Ingrese la letra: ";
				cin>>letra;
				InsertarLetra(arbol,numero,letra);
				cout<<endl<<endl;
				cout<<"Ingresada con exito: "<<endl<<endl;
				system("pause");		
				break;
					
					
			case 3:
				system("cls");
				cout<<"Visualizacion del arbol: "<<endl;
			    mostrar(arbol,contador);
			    cout<<endl;
			    system("pause");
				break;
				
			case 4:
				system("cls");
				cout<<"Ingrese el numero que desea buscar: ";
				cin>>numero;
				if(buscar(arbol,numero) == true)
				{
					cout<<"El numero "<<numero<<"existe";
					cout<<endl;
				}
				else{
					cout<<"ERROR!! EL NUMERO A BUSCAR NO EXISTE!!";
					cout<<endl;
				}
				cout<<endl;
				system("pause");
				break;
				
				
			case 5:
				system("cls");
				cout<<"Ingrese la letra que desea busca: "<<endl;
				cin>>letra;
				BuscarLetra(arbol,letra);
				cout<<endl;
				system("pause");
				break;
				
			case 6:
				system("cls");
				mostrar(arbol,contador);
			    cout<<endl<<endl;
				Orden(arbol);
				cout<<endl;
				system("pause");
				break;
			
			case 7:
				system("cls");
				mostrar(arbol,contador);
			    cout<<endl<<endl;
				PreOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			
			case 8:
				system("cls");
				mostrar(arbol,contador);
			    cout<<endl<<endl;
				PostOrden(arbol);
				cout<<endl;
				system("pause");
				break;
			case 9:
				system("cls");
				cout<<"GENERANDO LA IMAGEN...";
				cout<<endl<<endl;
				PostOrden(arbol);
				Tiempo();
				Graficar();
				cout<<endl;
				system("pause");
				break;
		}	
	} while (op!=10);

		system("cls");
	
}
