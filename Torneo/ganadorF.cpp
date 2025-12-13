
#include "torneo.h"
/*
void ganador() {
    for (size_t i = 0; i < equipos.size(); i++) {
        gotoxy(68.5,18.5); cout << equipos[i] ;
        getch();
        system("cls");
    }
}
*/

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

void estadisticas(){
    int idTorneo;
    stringstream s1,salida;
    string consulta1;
    MYSQL_RES *res;
    MYSQL_ROW row;

    int opcion;
    int i=0;
    bool ingresoInvalido=false;
    string col1,col2,col3,col4;
    cuadro(20,0,130,30);
    cuadro(21,1,129,3);

    gotoxy(65,2); cout<<"Estadisticas";

    gotoxy(21,5); cout<<"[1] Maximos Goleadores Por Torneo";
    gotoxy(21,6); cout<<"[2] Maximos Asistidores Por Torneo";
    gotoxy(21,7); cout<<"[3] Jugadores con mas Rojas por Torneo";
    gotoxy(21,8); cout<<"[4] Jugadores con mas Amarillas por Torneo";
    gotoxy(21,9); cout<<"[5] Equipos con mas Goles Por Torneo";
    gotoxy(21,10); cout<<"[6] Informacion de torneos";
    gotoxy(21,11); cout<<"[7] Campeones por Torneo";
    gotoxy(21,12); cout<<"[0] Salir";
    gotoxy(21,13); cout<<"Opcion: ";
    cin>>opcion;

    limpiarBuffer();
    s1.str("");
    s1.clear();
 
 	if (opcion>0 && opcion<8){
    gotoxy(21,14); idTorneo=pedirTorneo();
    s1<<idTorneo;
}

switch (opcion){
    case 1:
        consulta1="select j.nombre,j.apellido , e.nombre,j.goles from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo="+ s1.str()+ " order by j.goles desc limit 10;";
        col1="Nombre";
        col2="Apellido";
        col3="Equipo";
        col4="Goles";
        break;
    case 2:
        consulta1="select j.nombre,j.apellido , e.nombre,j.asistencias from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo="+s1.str()+" order by j.asistencias desc limit 10;";
        col1="Nombre";
        col2="Apellido";
        col3="Equipo";
        col4="Asistencias";
        break;
    case 3:
        consulta1= "select j.nombre,j.apellido , e.nombre,j.rojas from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo="+s1.str() +" order by j.rojas desc limit 10;";
        col1="Nombre";
		col2="Apellido";
        col3="Equipo";
        col4="Rojas";
        break;
    case 4:
        consulta1="select j.nombre,j.apellido , e.nombre,j.amarillas from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo="+s1.str()+" order by j.amarillas desc limit 10;";
        col1="Nombre";
        col2="Apellido";
        col3="Equipo";
        col4="Amarillas";
        break;
    case 5:
        consulta1="select e.nombre, sum(goles) as 'golesTotales' from equipos e inner join torneo t on e.id_torneo=t.id_torneos inner join jugadores j on e.id_equipos=j.id_equipo where e.id_torneo="+s1.str()+" group by e.nombre order by golesTotales desc limit 10;";
        col1="Equipo";
        col2="Goles totales";
        break;
    case 6:
        consulta1="select nombre, cant_participantes, fecha_inicio, fecha_fin from torneo where id_torneos="+s1.str();
        col1="Torneo";
        col2="Cantidad De Equipos";
        col3="Fecha Inicio";
        col4="Fecha Fin";
        break;
    case 7:
        consulta1="select e.nombre, j.nombre, j.apellido, j.num_camiseta from equipos e inner join jugadores j on e.id_equipos=j.id_equipo where e.final='C' and e.id_torneo="+s1.str()+" order by j.goles desc , j.asistencias desc limit 1;";
        col1="Equipo";
        col2="Nombre";
        col3="Apellido";
        col4="Numero Camiseta";
        break;
    case 0:
		ingresoInvalido=true;    
    default:
		ingresoInvalido=true;
		break;    
	}
	getch();
	system("cls");
	
	if(ingresoInvalido==false){
    if(mysql_query(obj,consulta1.c_str())==0){
        res=mysql_store_result(obj);
    }

    if(opcion==5){
        cuadro(1,1,50,33);
        gotoxy(2,2); cout<<col1;
        gotoxy(2,3.1); cout<<"________________________________________________";
        gotoxy(21,2); cout<<col2;

        while((row = mysql_fetch_row(res))){

            gotoxy(2,5+i); cout<<row[0];
            gotoxy(21,5+i); cout<<row[1];
            gotoxy(2,6.2+i); cout<<"________________________________________________";
            i=i+3;
        }
    }
    else{
        cuadro(1,1,81,33);
        gotoxy(2,2); cout<<col1;
        gotoxy(2,3.1); cout<<"_______________________________________________________________________________";
        gotoxy(21,2); cout<<col2;
        gotoxy(41,2); cout<<col3;
        gotoxy(61,2); cout<<col4;

        while((row = mysql_fetch_row(res))){
            gotoxy(2,5+i); cout<<row[0];
            gotoxy(21,5+i); cout<<row[1];
            gotoxy(41,5+i); cout<<row[2];
            gotoxy(61,5+i); cout<<row[3];
            gotoxy(2,6.2+i); cout<<"_______________________________________________________________________________";
            i=i+3;
        }
}
}
}
		   

