#include "torneo.h"

using namespace std;

int main(){	
	
	system("color F0");
	int opcion2;
	int idTorneo,num;
	stringstream s1;
	MYSQL_RES *res;
	MYSQL_ROW row;
	string consultaRonda, validarTotalEquipos;
	int ronda,totalInscriptos;
	
	string consultaJugar;	
	do{
	system("cls");
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
			s1.str("");
			s1.clear();
			idTorneo=pedirTorneo();
			s1<<idTorneo;
			
			consultaRonda="select cant_participantes from torneo where id_torneos="+s1.str();
			if(mysql_query(obj,consultaRonda.c_str())==0){
    		res=mysql_store_result(obj);
			}			
			row=mysql_fetch_row(res);
			ronda=atoi(row[0]);
			
			validarTotalEquipos = "select count(*) from equipos where id_torneo="+s1.str();
    		if (mysql_query(obj, validarTotalEquipos.c_str())==0){
        		res=mysql_store_result(obj);
    		}
    			row=mysql_fetch_row(res);
    			totalInscriptos=atoi(row[0]);
    	
    		if(ronda==totalInscriptos){
			consultaJugar="select count(*) from partidos where id_torneo="+s1.str()+ " and estado='Finalizado'";
			if(mysql_query(obj,consultaJugar.c_str())==0){
    		res=mysql_store_result(obj);
			}			
			row=mysql_fetch_row(res);
			num=atoi(row[0]);
			
			cout<< ronda <<" Ronda"<<endl;
			cout<<num<<" numero"<<endl;
			getch();
			if(ronda==16){
    			if(num<8){
        			partidoOctavos(idTorneo);
    			}else if(num<12){
        			partidoCuartos(idTorneo, "octavos");
    			}else if(num<14){
        			partidoSemis(idTorneo, "octavos");
    			}else{
        			partidoFinal(idTorneo, "octavos");
    			}
			}
			else if(ronda==8){
    			if(num<4){
        			partidoCuartos(idTorneo, "cuartos");
		    	}else if(num<6){
        			partidoSemis(idTorneo, "cuartos");
    			}else{
        		partidoFinal(idTorneo, "cuartos");
	    		}
			}
			else if(ronda==4){
    			if(num<2){
        			partidoSemis(idTorneo, "semis");
    			}else{
        			partidoFinal(idTorneo, "semis");
			    }	
			}
			else{
    			cout<<"ERROR: error inesperado.";
			}
		}else{
			cout<<"ERROR: complete la inscripcion de los equipos.";
			getch();
		}
			break;
			
			
		case 6:
			
   	 		s1.str(""); s1.clear();

		    idTorneo=pedirTorneo();
    		s1<<idTorneo;

    		consultaRonda="select cant_participantes from torneo where id_torneos="+s1.str();

    		if(mysql_query(obj,consultaRonda.c_str())==0){
        		res=mysql_store_result(obj);
 		   }
    		row=mysql_fetch_row(res);
    		ronda=atoi(row[0]);

    		if(ronda==16){
        		visualizarTorneo(idTorneo,"octavos");
    		}else if(ronda==8){
        		visualizarTorneo(idTorneo,"cuartos");
    		}else if(ronda==4){
        		visualizarTorneo(idTorneo,"semis");
    		}else{
        		cout<<"ERROR: error inesperado.";
		    }
		
			break;
		case 7:
			estadisticas();	
			getch();
			break;
		case 0:
			abort();
			break;		
		
}
}
while(1);
	getch();
}


  
  
