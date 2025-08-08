#include "torneo.h"

using namespace std;

int numEquipos;  
vector<string> equipos;
int golA, golB;  
string nombreArchivo;
string ruta;

void reescribirOctavos(int pX1,int pY1,string equipo);
void reescribirCuartos(int pX1,int pY1, int pX2,int pY2);
void reescribirSemi(int pX1,int pY1, int pX2,int pY2);
void reescribirFinal(int pX1,int pY1, int pX2,int pY2);
 
 	//reescribirOctavos(1,1,1,6);
  		//int posicionX1=1;
    	//int posicionY1=1;
    	//int posicionX2=1;
    	//int posicionY2=6;
    	//int ganadorX=26;
   	 	//int ganadorY=3.5; 	
   	 	
void partidoOctavos() {	
	int opcion;
	char hayAsistencia;	
	string tarjeta;	
	MYSQL_RES *res;
	MYSQL_ROW row;
	int idTorneo,idLocal,idVisitante;	
	stringstream s1,s2,s3,s4,s5,s6,s7,sResultado,s8;
	string consulta1,consulta2,consulta3,consulta4,consulta5,consulta6,consulta7,consulta8,consulta9,consultaVal;
	string equipo,equipoLocal,equipoVisitante;
	string resultado;
	int numPartido,proxPartido;
	int camiseta1,camiseta2;
	int golesLocal,golesVisitante;
	int X=1;
	int Y=1;	
	
	idTorneo=pedirTorneo();
	s1<<idTorneo;
	
	system("cls");
	octavosFinal();
	cuartosFinal();
	
	for (int i=1; i<=16;i=i +1 ){
	s2.str(""); s2.clear();	
	s2<<i;
	consulta1= "select nombre from equipos where Posicion_sorteo="+ s2.str()+" and id_torneo="+s1.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipo=row[0];
	
  	gotoxy(X,Y);
	cout << equipo << " ";
	Y=Y+5;
    if(i==8){
        X=131;
        Y=1;
		}
	}
	getch();
	system("cls");
	
	cout<<"Ingrese que partido quiere gestionar: ";
	cin>>numPartido;
	s3<<numPartido;
	
	consulta2="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	consulta3="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	
	if(mysql_query(obj,consulta2.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	idLocal=atoi(row[1]);
	
	if(mysql_query(obj,consulta3.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	idVisitante=atoi(row[1]);
	getch();
	system("cls");
	
	s6<<idLocal;
	s7<<idVisitante;
	do{
	cout<<equipoLocal<<" VS "<< equipoVisitante<<endl;
	menuDeJuego();
	cin>>opcion;	
	
	s4.str(""); s4.clear();
	s5.str(""); s5.clear();
	switch(opcion){
		case 1:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
				
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 2:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
			    mysql_query(obj,consulta6.c_str());
				cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 3:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 4:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 5:
			consulta4= "select goles_equipo1 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo1="+s6.str();
			consulta5= "select goles_equipo2 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo2="+s7.str();
			
			if(mysql_query(obj,consulta4.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesLocal=atoi(row[0]);
			
			if(mysql_query(obj,consulta5.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesVisitante=atoi(row[0]);
			
			sResultado<< golesLocal<< "-" << golesVisitante;
			cout<<"El resultado final es: "<<sResultado.str()<<endl;
			
			consulta9="update partidos set resultado='"+sResultado.str()+ "' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			consulta9="update partidos set estado= 'finalizado' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			s8.str(""); s8.clear();
			proxPartido=((numPartido-1)/2)+9;
			s8<<proxPartido;
			int validacion;
			
			if(golesLocal>golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s6.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
					
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}	
				}else{
					if (numPartido%2==0){
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}else{
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
							
			}else if(golesLocal<golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s7.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();
					}	
			    }else{
					if (numPartido%2==0){
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
					}else{
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
				}
				else{
				cout<<"ERROR: el resultado no puede ser empate";
				break;
			}
			cout<<"Partido finalizado.";
			getch();
			opcion=0;
			break;
		case 0:
			break;	
		default:
			cout<<"Ingreso de caracter incorrecto.";	
			getch();
			break;
	}						
}while(opcion!=0);
}

void partidoCuartos() {
		int opcion;
	char hayAsistencia;	
	string tarjeta;	
	MYSQL_RES *res;
	MYSQL_ROW row;
	int idTorneo,idLocal,idVisitante;	
	stringstream s1,s2,s3,s4,s5,s6,s7,sResultado,s8;
	string consulta1,consulta2,consulta3,consulta4,consulta5,consulta6,consulta7,consulta8,consulta9,consultaVal;
	string equipo,equipoLocal,equipoVisitante;
	string resultado;
	int numPartido,proxPartido;
	int camiseta1,camiseta2;
	int golesLocal,golesVisitante;
	int X=26;
	int Y=3.5;
	int X2=26;
	int Y2=13.5;
	
	idTorneo=pedirTorneo();
	s1<<idTorneo;
	
	system("cls");
	cuartosFinal();
	semiFinal2();
	for (int i=9; i<=12;i=i +1 ){
	s2.str(""); s2.clear();	
	s2<<i;
	consulta1="select e.nombre from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido="+s2.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	
	consulta1="select e.nombre from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido="+s2.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	
 	gotoxy(X,Y);
	cout << equipoLocal << " ";
	gotoxy(X2,Y2);
	cout << equipoVisitante << " ";
	Y=Y+20;
    Y2= Y2+20;
    if(i==10){
        X=106;
        X2=106; 
        Y=3.5;
        Y2=13.5;
	}
	}
	getch();
	system("cls");

	cout<<"Ingrese que partido quiere gestionar: ";
	cin>>numPartido;
	s3<<numPartido;
	
	consulta2="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	consulta3="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	
	if(mysql_query(obj,consulta2.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	idLocal=atoi(row[1]);
	
	if(mysql_query(obj,consulta3.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	idVisitante=atoi(row[1]);
	getch();
	system("cls");
	
	s6<<idLocal;
	s7<<idVisitante;
	do{
	cout<<equipoLocal<<" VS "<< equipoVisitante<<endl;
	menuDeJuego();
	cin>>opcion;	
	
	s4.str(""); s4.clear();
	s5.str(""); s5.clear();
	switch(opcion){
		case 1:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
				
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 2:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
			    mysql_query(obj,consulta6.c_str());
				cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 3:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 4:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 5:
			consulta4= "select goles_equipo1 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo1="+s6.str();
			consulta5= "select goles_equipo2 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo2="+s7.str();
			
			if(mysql_query(obj,consulta4.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesLocal=atoi(row[0]);
			
			if(mysql_query(obj,consulta5.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesVisitante=atoi(row[0]);
			
			sResultado<< golesLocal<< "-" << golesVisitante;
			cout<<"El resultado final es: "<<sResultado.str()<<endl;
			
			consulta9="update partidos set resultado='"+sResultado.str()+ "' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			consulta9="update partidos set estado= 'finalizado' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			s8.str(""); s8.clear();
			proxPartido=((numPartido-9)/2)+13;
			s8<<proxPartido;
			int validacion;
			
			if(golesLocal>golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s6.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
					
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}	
				}else{
					if (numPartido%2==0){
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}else{
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
							
			}else if(golesLocal<golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s7.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();
					}	
			    }else{
					if (numPartido%2==0){
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
					}else{
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
				}
				else{
				cout<<"ERROR: el resultado no puede ser empate";
				break;
			}
			cout<<"Partido finalizado.";
			getch();
			opcion=0;
			break;
		case 0:
			break;	
		default:
			cout<<"Ingreso de caracter incorrecto.";	
			getch();
			break;
	}						
}while(opcion!=0);
}

void partidoSemis() {
	int opcion;
	char hayAsistencia;	
	string tarjeta;	
	MYSQL_RES *res;
	MYSQL_ROW row;
	int idTorneo,idLocal,idVisitante;	
	stringstream s1,s2,s3,s4,s5,s6,s7,sResultado,s8;
	string consulta1,consulta2,consulta3,consulta4,consulta5,consulta6,consulta7,consulta8,consulta9,consultaVal;
	string equipo,equipoLocal,equipoVisitante;
	string resultado;
	int numPartido,proxPartido;
	int camiseta1,camiseta2;
	int golesLocal,golesVisitante;
		
	int X=6;
    int Y=8.5;
    int X2=6;
    int Y2=28.5;
    
	idTorneo=pedirTorneo();
	s1<<idTorneo;
	
	system("cls");
	semiFinal();
	Final();
	for (int i=13; i<=14;i=i +1 ){
	s2.str(""); s2.clear();	
	s2<<i;
	consulta1="select e.nombre from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido="+s2.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	
	consulta1="select e.nombre from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido="+s2.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	
 	gotoxy(X,Y);
	cout << equipoLocal << " ";
	gotoxy(X2,Y2);
	cout << equipoVisitante << " ";
	Y=Y+20;
    Y2= Y2+20;
    if(i==13){
        X=131;
        X2=131; 
        Y=8.5;
        Y2=28.5;
	}
	}
	getch();
	system("cls");

	cout<<"Ingrese que partido quiere gestionar: ";
	cin>>numPartido;
	s3<<numPartido;
	
	consulta2="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	consulta3="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	
	if(mysql_query(obj,consulta2.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	idLocal=atoi(row[1]);
	
	if(mysql_query(obj,consulta3.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	idVisitante=atoi(row[1]);
	getch();
	system("cls");
	
	s6<<idLocal;
	s7<<idVisitante;
	do{
	cout<<equipoLocal<<" VS "<< equipoVisitante<<endl;
	menuDeJuego();
	cin>>opcion;	
	
	s4.str(""); s4.clear();
	s5.str(""); s5.clear();
	switch(opcion){
		case 1:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
				
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 2:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
			    mysql_query(obj,consulta6.c_str());
				cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 3:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 4:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 5:
			consulta4= "select goles_equipo1 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo1="+s6.str();
			consulta5= "select goles_equipo2 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo2="+s7.str();
			
			if(mysql_query(obj,consulta4.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesLocal=atoi(row[0]);
			
			if(mysql_query(obj,consulta5.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesVisitante=atoi(row[0]);
			
			sResultado<< golesLocal<< "-" << golesVisitante;
			cout<<"El resultado final es: "<<sResultado.str()<<endl;
			
			consulta9="update partidos set resultado='"+sResultado.str()+ "' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			consulta9="update partidos set estado= 'finalizado' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			s8.str(""); s8.clear();
			proxPartido=15;
			s8<<proxPartido;
			int validacion;
			
			if(golesLocal>golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s6.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
					
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}	
				}else{
					if (numPartido%2==0){
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}else{
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
							
			}else if(golesLocal<golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s7.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();
					}	
			    }else{
					if (numPartido%2==0){
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
					}else{
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
				}
				else{
				cout<<"ERROR: el resultado no puede ser empate";
				break;
			}
			cout<<"Partido finalizado.";
			getch();
			opcion=0;
			break;
		case 0:
			break;	
		default:
			cout<<"Ingreso de caracter incorrecto.";	
			getch();
			break;
	}						
}while(opcion!=0);
}   

void partidoFinal() {
/*
	int posicionX1=36;
    int posicionY1=18.5;
    int posicionX2=101;
    int posicionY2=18.5;
    
    int opcion;
	char hayAsistencia;	
	string tarjeta;	
	MYSQL_RES *res;
	MYSQL_ROW row;
	int idTorneo,idLocal,idVisitante;	
	stringstream s1,s2,s3,s4,s5,s6,s7,sResultado,s8;
	string consulta1,consulta2,consulta3,consulta4,consulta5,consulta6,consulta7,consulta8,consulta9,consultaVal;
	string equipo,equipoLocal,equipoVisitante;
	string resultado;
	int numPartido,proxPartido;
	int camiseta1,camiseta2;
	int golesLocal,golesVisitante;
		
	int X=6;
    int Y=8.5;
    int X2=6;
    int Y2=28.5;
    
	idTorneo=pedirTorneo();
	s1<<idTorneo;
	
	system("cls");
	semiFinal();
	Final();
	
	consulta1="select e.nombre from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido=15";
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	
	consulta1="select e.nombre from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido=16";
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	
 	gotoxy(X,Y);
	cout << equipoLocal << " ";
	gotoxy(X2,Y2);
	cout << equipoVisitante << " ";
	Y=Y+20;
    Y2= Y2+20;
    if(i==13){
        X=131;
        X2=131; 
        Y=8.5;
        Y2=28.5;
	}
	}
	getch();
	system("cls");

	cout<<"Ingrese que partido quiere gestionar: ";
	cin>>numPartido;
	s3<<numPartido;
	
	consulta2="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	consulta3="select e.nombre ,e.id_equipos  from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where e.id_torneo="+s1.str()+" and p.num_partido="+s3.str();
	
	if(mysql_query(obj,consulta2.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	idLocal=atoi(row[1]);
	
	if(mysql_query(obj,consulta3.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	idVisitante=atoi(row[1]);
	getch();
	system("cls");
	
	s6<<idLocal;
	s7<<idVisitante;
	do{
	cout<<equipoLocal<<" VS "<< equipoVisitante<<endl;
	menuDeJuego();
	cin>>opcion;	
	
	s4.str(""); s4.clear();
	s5.str(""); s5.clear();
	switch(opcion){
		case 1:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
				
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo1=goles_equipo1+1 where id_equipo1="+s6.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 2:
			cout<<"En el gol hubo asistencia (S/N): ";
			cin>>hayAsistencia;
			if (hayAsistencia == 'S' || hayAsistencia == 's') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				cout<<"Ingrese el numero de camiseta del que asistio: ";
				cin>>camiseta2;
				
				s4<<camiseta1;
				s5<<camiseta2;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta5= "update jugadores set asistencias=asistencias+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s5.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
				mysql_query(obj,consulta5.c_str());
				mysql_query(obj,consulta6.c_str());
			    cout << "Se registró correctamente.";
			} else if (hayAsistencia == 'N' || hayAsistencia == 'n') {
				cout<<"Ingrese el numero de camiseta del que hizo el gol: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set goles=goles+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				consulta6= "update partidos set goles_equipo2=goles_equipo2+1 where id_equipo2="+s7.str()+ " and id_torneo= "+s1.str();
				
				mysql_query(obj,consulta4.c_str());
			    mysql_query(obj,consulta6.c_str());
				cout << "Se registró el goleador.";
			} else {
			    cout << "No existe lo que ingresó.";
			}
			break;
		case 3:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s6.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 4:
			cout<<"La infraccion es amarilla o roja (Amarilla/Roja):";
			cin>>tarjeta;
			
			if (tarjeta== "roja" || tarjeta== "Roja"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set rojas=rojas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else if (tarjeta== "Amarilla" || tarjeta== "amarilla"){
				cout<<"Ingrese el numero de camiseta del que cometio la falta: ";
				cin>>camiseta1;
				
				s4<<camiseta1;
						
				consulta4= "update jugadores set amarillas=amarillas+1 where id_equipo="+s7.str()+ " and num_camiseta= "+s4.str();
				
				mysql_query(obj,consulta4.c_str());
				cout<<"Se registro correctamente";
			}else{
				cout<<"Ingreso de caracteres incorrectos.";
			}
			break;
		case 5:
			consulta4= "select goles_equipo1 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo1="+s6.str();
			consulta5= "select goles_equipo2 from partidos where id_torneo="+s1.str()+" and num_partido="+s3.str() +" and id_equipo2="+s7.str();
			
			if(mysql_query(obj,consulta4.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesLocal=atoi(row[0]);
			
			if(mysql_query(obj,consulta5.c_str())==0){
				res=mysql_store_result(obj);
			}
			row=mysql_fetch_row(res);
			golesVisitante=atoi(row[0]);
			
			sResultado<< golesLocal<< "-" << golesVisitante;
			cout<<"El resultado final es: "<<sResultado.str()<<endl;
			
			consulta9="update partidos set resultado='"+sResultado.str()+ "' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			consulta9="update partidos set estado= 'finalizado' where id_torneo="+s1.str()+ " and num_partido= "+s3.str();
			mysql_query(obj,consulta9.c_str());
			
			s8.str(""); s8.clear();
			proxPartido=(numPartido+2);
			s8<<proxPartido;
			int validacion;
			
			if(golesLocal>golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s6.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
					
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s6.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}	
				}else{
					if (numPartido%2==0){
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}else{
					consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s6.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
							
			}else if(golesLocal<golesVisitante){
				consulta7="update equipos set cuartos='S' where id_equipos="+s7.str();
				mysql_query(obj,consulta7.c_str());
				
				consultaVal="select count(*) from partidos where id_torneo="+s1.str()+" and num_partido="+s8.str();
				
				if (mysql_query(obj,consultaVal.c_str())==0){
					res=mysql_store_result(obj);	
				}
				row=mysql_fetch_row(res);
				validacion=atoi(row[0]);
				
				if (validacion==1){
					if (numPartido%2==0){
						consulta8="update partidos set id_equipo2="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();	
					}else{
						consulta8="update partidos set id_equipo1="+s7.str()+ " where id_torneo="+s1.str()+ " and num_partido="+s8.str();
					}	
			    }else{
					if (numPartido%2==0){
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo2,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
					}else{
						consulta8="insert into partidos (id_torneo,num_partido,id_equipo1,goles_equipo1,goles_equipo2,estado) values("+s1.str()+","+s8.str()+","+s7.str()+",0,0,'activo' )";
				}
				}
				mysql_query(obj,consulta8.c_str());
				}
				else{
				cout<<"ERROR: el resultado no puede ser empate";
				break;
			}
			cout<<"Partido finalizado.";
			getch();
			opcion=0;
			break;
		case 0:
			break;	
		default:
			cout<<"Ingreso de caracter incorrecto.";	
			getch();
			break;
	}						
}while(opcion!=0);
}   
*/
    
  }
  
  
  
  void reescribirOctavos(int X1,int Y1,string equipo) {
   for (int i=0; i<16;i=i +1 ){
	  
  	gotoxy(X1,Y1);
	cout << equipo << " ";
	Y1=Y1+5;
    if(i==7){
        X1=131;
        Y1=1;
		}
  }     
}/*
  void reescribirCuartos(int pX1,int pY1, int pX2,int pY2) {
	  
  	gotoxy(pX1,pY1);
	cout << "equipos" << " ";
	gotoxy(pX2,pY2);
	cout << "equipos" << " ";
	pY1=pY1+20;
    pY2= pY2+20;
    if(i==2){
        pX1=106;
        pX2=106; 
        pY1=3.5;
        pY2=13.5;
		}
  }     
}*/
  void reescribirSemi(int pX1,int pY1, int pX2,int pY2) {
   for (int i=0; i<equipos.size();i += 2){
	  
  	gotoxy(pX1,pY1);
	cout << equipos[i] << " ";
	gotoxy(pX2,pY2);
	cout << equipos[i+1] << " ";
        pX1=131;
        pX2=131; 
        pY1=8.5;
        pY2=28.5;
		}
  }     

  void reescribirFinal(int pX1,int pY1, int pX2,int pY2) {
  	
  	gotoxy(pX1,pY1);
	cout << equipos[0] << " ";
	gotoxy(pX2,pY2);
	cout << equipos[1] << " ";
}

  int pedirTorneo(){
  	char nombre[30];
  	int id_torneo;
  	MYSQL_RES *res;
	MYSQL_ROW row;
  	
  	conectar_base();
  	
  	cout<<"Ingrese el nombre del torneo: ";
  	cin.getline(nombre,30,'\n');
  	
  	string consulta = "select id_torneos from torneo where nombre='"+string (nombre)+"'";
        if (mysql_query(obj, consulta.c_str()) == 0) {
            res= mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	id_torneo= atoi(row[0]);
  	
  	return id_torneo;
  }
  
void menuDeJuego(){
	cout<<"[1] Gol Local"<<endl;
	cout<<"[2] Gol Visitante"<<endl;
	cout<<"[3] Tarjeta Local"<<endl;
	cout<<"[4] Tarjeta Visitante"<<endl;
	cout<<"[5] Finalizar Partido"<<endl;
	cout<<"[0] Salir"<<endl;
	cout<<"Ingrese una opcion: ";
}
