#include "torneo.h"

using namespace std;

int main(){	

	fstream archivo;
	
	system("color F0");
	int opcion2;
	
	do{
	cuadro(40,0,115,24);
	cuadro(41,1,114,3); 
	gotoxy(74,2); cout<<"Menu"<<endl;
	gotoxy(41,5);cout<<"[1]: Crear Torneo"<<endl;
	gotoxy(41,6);cout<<"[2]: Inscripciones de equipos"<<endl;
	gotoxy(41,7);cout<<"[3]: Inscripciones de jugadores"<<endl;
	gotoxy(41,8);cout<<"[4]: Sorteo"<<endl;
	gotoxy(41,9);cout<<"[5]: Jugar"<<endl;
	gotoxy(41,10);cout<<"[6]: Base de datos"<<endl;
	gotoxy(41,11);cout<<"[0]: Salir"<<endl;
	gotoxy(41,13);
	cout<<"Elije una opcion: "; cin>>opcion2;
	limpiarBuffer();
	system("cls");
	
	switch(opcion2){
		case 1:
			system("cls");
			crearTorneo();
			break;
			
		case 2:
			//Se incriben los equipos
			inscribirEquipos();	
			system("cls");
			break;	
					
		case 3:
		inscribirJug();
		system("cls");
		break;
			
		case 4:	
	  	sorteo();
	  	system("cls");
		break;
		
		case 5:			
			partidoSemis();
			system("cls");
			break;
		case 0:
			abort();
			break;		
			
		case 6:
			cout<<"hola";
		}
		
		

}while(1);
	getch();
}


  
