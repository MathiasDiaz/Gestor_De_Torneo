#include "torneo.h"

using namespace std;

int main(){	
	
	system("color F0");
	int opcion2;
	int idTorneo,num;
	stringstream s1;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	string consultaJugar;	
	do{
	cuadro(40,0,115,24);
	cuadro(41,1,114,3); 
	gotoxy(74,2); cout<<"Menu"<<endl;
	gotoxy(41,5);cout<<"[1]: Crear Torneo"<<endl;
	gotoxy(41,6);cout<<"[2]: Inscripciones de equipos"<<endl;
	gotoxy(41,7);cout<<"[3]: Inscripciones de jugadores"<<endl;
	gotoxy(41,8);cout<<"[4]: Sorteo"<<endl;
	gotoxy(41,9);cout<<"[5]: Jugar"<<endl;
	gotoxy(41,10);cout<<"[6]: Visualizacion De Torneo"<<endl;
	gotoxy(41,11);cout<<"[7]: Estadisticas"<<endl;
	gotoxy(41,12);cout<<"[0]: Salir"<<endl;
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
			idTorneo=pedirTorneo();
			s1<<idTorneo;
			
			
			    
			consultaJugar="select count(*) from partidos where id_torneo="+s1.str()+ " and estado='finalizado'";
			
			if(mysql_query(obj,consultaJugar.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			num=atoi(row[0]);
			
			if(num<=8){
				partidoOctavos(idTorneo);
			}else if(num<=12){
				partidoCuartos(idTorneo);
			}else if(num<=14){
				partidoSemis(idTorneo);
			}else{
				partidoFinal(idTorneo);
			}
			system("cls");
			break;
		case 0:
			abort();
			break;		
			
		case 6:
			visualizarTorneo();
		}
}while(1);
	getch();
}


  
