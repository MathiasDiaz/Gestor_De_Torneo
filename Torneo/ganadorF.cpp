#include "torneo.h"

void ganador() {
    for (size_t i = 0; i < equipos.size(); i++) {
        gotoxy(68.5,18.5); cout << equipos[i] ;
        getch();
        system("cls");
    }
}

void limpiarBuffer(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void barraDeCarga(int x, int y){
	 
	int i=0;
	int porcentajeMax=100;
	string consejo [10];
	
	srand((unsigned)time(0)); 
	int num= rand()%(10);
	
	consejo[0]="Consejo: Tu compilador no te odia, solo quiere que pongas el ;";
	consejo[1]="Consejo: Todo el mundo escucha el arbol caer, pero nadie escucha cuando crece.";
	consejo[2]="Consejo: Si puedes imaginarlo, puedes programarlo.";
	consejo[3]="Consejo: El futbol es simple, pero es dificil jugar simple.";
	consejo[4]="Consejo: La adrenalina sube, el juego esta por comenzar.";
	consejo[5]="Consejo: Un gol puede cambiar el destino de un partido.";
	consejo[6]="Consejo: El futbol siempre da revancha.";
	consejo[7]="Consejo: Algunas veces es mejor hacer un cambio de frente.";
	consejo[8]="Consejo: Las estrellas brillan mas fuerte antes de apagarse.";
	consejo[9]="Consejo: Un ganador es un perdedor que lo volvio a intentar.";
	
	static HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE ); 	
	
		gotoxy(x+45,y-1); cout<<"Cargando...\n";
		
		//Deja el espacio en blanco de la barra
		for(int j=0;j<porcentajeMax;j++){
		gotoxy(x+j,y); cout<<" ";
		}
		
		//Escribe un consejo debajo de la barra
		gotoxy(x,y+2);cout<<consejo[num];
		
		//Aqui se carga la barra    
		for (i=0; i<=porcentajeMax;i++){
			 SetConsoleTextAttribute(hConsole, 0xF0);
			 gotoxy(i+x,y); printf("%c",219);		
			 SetConsoleTextAttribute(hConsole, 0xF0);
			 gotoxy(porcentajeMax+x+1,y);
			 cout<<(i*100/100)<<"%"; 
			 Sleep(100);	
		}
}
