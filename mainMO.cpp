#include "MatrizO.cpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

void menu();


 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
}


void cuadro()
{	
	//lineas horizontales
	
	for(int i=1;i<78;i++){
		gotoxy(i,1); printf("%c",205); //lineas de arriba
		gotoxy(i,22); printf("%c",205); //lineas de abajo
	}
	
	//lineas verticales
	
		for(int i=2;i<22;i++){
		gotoxy(1,i); printf("%c",186); //lineas de izquierda
		gotoxy(78,i); printf("%c",186); //lineas de derecha
	}
	
	//esquinas 
		gotoxy(1,1); printf("%c",201);
		gotoxy(1,22); printf("%c",200);
		gotoxy(78,1); printf("%c",187);		
		gotoxy(78,22); printf("%c",188);
}

void portada(){
	
	char x;
	cuadro();
	gotoxy(4,2);	printf("U N I V E R S I D A D  M A R I A N O  G A L V E Z  D E  G U A T E M A L A");
	gotoxy(17,3);	printf("PROGRAMACION III   |   ING. JOAQUIN GUERRERO ");
	gotoxy(11,5);	printf("   .dMMMb  dMMMMMP .aMMMMP dMP dMP dMMMMb  dMMMMb  .aMMMb ");
	gotoxy(11,6);	printf("  dMP  VP dMP     dMP     dMP dMP dMP dMP dMP VMP dMP dMP ");
	gotoxy(11,7);	printf("  VMMMb  dMMMP   dMP MMP dMP dMP dMP dMP dMP dMP dMP dMP  ");
	gotoxy(11,8);	printf("dP .dMP dMP     dMP.dMP dMP.aMP dMP dMP dMP.aMP dMP.aMP   ");
	gotoxy(11,9);	printf("VMMMP  dMMMMMP  VMMMP   VMMMP  dMP dMP dMMMMP   VMMMP     ");
	gotoxy(11,10);	printf("    dMMMMb  .aMMMb  dMMMMb  .aMMMb  dMP .aMMMb  dMP ");
	gotoxy(11,11);	printf("   dMP.dMP dMP dMP dMP.dMP dMP VMP amr dMP dMP dMP  ");
	gotoxy(11,12);	printf("  dMMMMP  dMMMMMP dMMMMK  dMP     dMP dMMMMMP dMP   ");
	gotoxy(11,13);	printf(" dMP     dMP dMP dMP AMF dMP.aMP dMP dMP dMP dMP    ");
	gotoxy(11,14);	printf("dMP     dMP dMP dMP dMP  VMMMP  dMP dMP dMP dMMMMMP ");
	
	
	
	gotoxy(15,16);	printf("MATRIZ ORTOGONAL Y ARBOL BINARIO CON LISTA");
	gotoxy(23,17);	printf("PRESIONA [x] PARA CONTINUAR"); 
	gotoxy(51,17);	scanf("%c",&x);
	
	switch(x){
		
		case 'x': 	system("cls");
					cuadro();
					menu();
					break;
				
		default:	system("cls"); 
					system("color C0");
				 
					cuadro();
					gotoxy(8,10);			printf("P R E S I O N A S T E    U N A   T E C L A   I N C O R R E C T A");
					gotoxy(20,11);			printf("I N T E N T A   N U E V A M E N T E");
					gotoxy(15,20);			printf("P R E S I O N A   [ 1 ]  P A R A   C O N T I N U A R");
					gotoxy(68,20);			scanf("%d",&x);
	
					switch(x){
						case 1: 	system("cls");
									menu();
									break;
					}
					system("pause>null");
					break;				
}	
		
}

void menu(){
	
		int op;
		
		MatrizO mo;																					//instanciacion de clase
		Fila=NULL;																					//inicializacion de parametros
		Columna=NULL;
		

				int n;
				int x;
				int y;
				
				do{
					system("cls");
					system("color 79");
					cuadro();
					gotoxy(35,3);	printf("BIENVENIDO");
					gotoxy(6,4);	printf("Por favor indique la serie que desea evaluar. ");
					gotoxy(6,5);	printf("Indica el numero de seleccion, luego presiona [ENTER] para continuar.");
					gotoxy(20,8);	printf("[1] INGRESAR DATOS");
					gotoxy(20,9);	printf("[2] VISUALIZAR CON GRAPHVIZ");
					gotoxy(20,10); 	printf("[3] BUSCAR UN DATO EN LA MATRIZ");
					gotoxy(20,11); 	printf("[4] ELIMINAR UN DATO DE LA MATRIZ");
					gotoxy(68,21); 	printf("[5] SALIR");
					gotoxy(30,13); 	printf("QUE DESEAS HACER?");
					gotoxy(48,13);  scanf("%d",&op);
					
						switch(op){
							
							case 1:	system("cls");
									cuadro();
									gotoxy(6,2);	cout<<"INGRESO DE DATOS A LA MATRIZ."<<endl;
									gotoxy(6,4);	cout<<"Ingresa la columna"<<endl;
									gotoxy(6,5);	cin>>x;
									gotoxy(6,7);	cout<<"Ingresa la fila"<<endl;
									gotoxy(6,8);	cin>>y;
									gotoxy(6,10);	cout<<"Ingresa el numero a guardar"<<endl;
									gotoxy(6,11);	cin>>n;
									mo.insertarDato(n,x,y);
									getch();
									break;
								
							case 2: system("cls");
									gotoxy(6,2);	cout<<"CREACION DE GRAFICO POR MEDIO DE GRAPHVIZ"<<endl<<endl<<endl;
									mo.graficar();
									getch();
									break;
								
							case 3: system("cls");
									gotoxy(6,2);	cout<<"BUSQUEDA DE UN DATO DENTRO DE LA MATRIZ."<<endl;
									gotoxy(6,4);	cout<<"Que dato desea busca? "<<endl;
									gotoxy(6,5);	cin>>n;
													cout<<endl<<endl;
									mo.buscar(n);
									getch();
									break;
								
							case 4:	system("cls");
									gotoxy(6,2);	cout<<"ELIMINACION DE UN DATO DENTRO DE LA MATRIZ."<<endl;
									gotoxy(6,4);	cout<<"Que dato desea eliminar? "<<endl;
									gotoxy(6,5);	cin>>n;
													cout<<endl<<endl;
									mo.eliminar(n);
									getch();
									break;
						}
				}
				while(op!=5);

				system("cls");
				cuadro();
				gotoxy(12,2); printf("UNIVERSIDAD MARIANO GALVEZ DE GUATEMALA | PROGRAMACION III");
				gotoxy(32,4); printf(">>PROGRAMADORES<<");
				gotoxy(18,7); printf("%c Abner Noe Lopez Barahona - 6691-18-9759", 3);
				gotoxy(18,8); printf("%c Jason Jose Sosa Ralda    - 6691-19-10777", 3);
				gotoxy(12,18); printf("%c TODOS LOS DERECHOS RESERVADOS | %C ABNER BARAHONA 1991", 184, 169);
				
					
}






int main(){
	
	MatrizO mobPsycho100;
	system("color 79");
	portada();	
	system("pause>null");
	mobPsycho100.eliminarTodo();
	return 0;
}











