#include "torneo.h"

using namespace std;


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void cuadro(int x1,int y1,int x2,int y2){
	for(int i=x1;i<x2;i++){
		gotoxy(i,y1); cout<<"\304"; //Linea horizontal arriba
		gotoxy(i,y2); cout<<"\304"; //Linea horizontal abajo
	}
	for(int i=y1;i<y2;i++){
		gotoxy(x1,i); cout<<"\263"; //Linea vertical izquierda
		gotoxy(x2,i); cout<<"\263"; //Linea vertical derecha
	}
	gotoxy(x1,y1); cout<<"\332"; 
	gotoxy(x1,y2); cout<<"\300"; 
	gotoxy(x2,y1); cout<<"\277"; 
	gotoxy(x2,y2); cout<<"\331";	
}

void octavosFinal(){
	
	//OCTAVOS
	cuadro(0,0,20,3);
	flechas(21,1.7,23,3,25);
	
	cuadro(0,5,20,8);
	flechas(21,6.7,23,4,25);
	
	cuadro(0,10,20,13);
	flechas(21,11.7,23,13,25);
	
	cuadro(0,15,20,18);
	flechas(21,16.7,23,14,25);
	
	cuadro(0,20,20,23);
	flechas(21,21.7,23,23,25);
	
	cuadro(0,25,20,28);
	flechas(21,26.7,23,24,25);
	
	cuadro(0,30,20,33);
	flechas(21,31.7,23,33,25);
	
	cuadro(0,35,20,38);
	flechas(21,36.7,23,34,25);
	
	cuadro(130,0,150,3);
	flechasInversa(129,1.7,127,3,124);
	
	cuadro(130,5,150,8);
	flechasInversa(129,6.7,127,4,124);
	
	cuadro(130,10,150,13);
	flechasInversa(129,11.7,127,13,124);
	
	cuadro(130,15,150,18);
	flechasInversa(129,16.7,127,14,124);
	
	cuadro(130,20,150,23);
	flechasInversa(129,21.7,127,23,124);
	
	cuadro(130,25,150,28);
	flechasInversa(129,26.7,127,24,124);
	
	cuadro(130,30,150,33);
	flechasInversa(129,31.7,127,33,124);
	
	cuadro(130,35,150,38);		
	flechasInversa(129,36.7,127,34,124);
}
void cuartosFinal(){
	//CUARTOS
	
	cuadro(25,2.5,45,5.5);
	cuadro(25,12.5,45,15.5);
	cuadro(25,22.5,45,25.5);
	cuadro(25,32.5,45,35.5);
	
	cuadro(105,2.5,125,5.5);
	cuadro(105,12.5,125,15.5);
	cuadro(105,22.5,125,25.5);
	cuadro(105,32.5,125,35.5);
}
void semiFinal(){
	//SEMIS
	cuadro(5,7.5,25,10.5);
	cuadro(5,27.5,25,30.5);
	cuadro(130,7.5,150,10.5);
	cuadro(130,27.5,150,30.5);
	
	flechas(26,8.75,30,18.5,34);
	flechas(26,28.75,30,19.5,34);
	
	flechasInversa(129,8.75,125,18.5,121);
	flechasInversa(129,28.75,125,19.5,121);
}
void Final(){
	//Final
	cuadro(35,17.5,55,20.5);
	cuadro(100,17.5,120,20.5);
	
	flechas(56,18.75,66.5,18.75,66.5);
	flechas(88.5,18.75,99,18.75,99);
	
	gotoxy(66.5,18.75); cout<<"\304";
	gotoxy(99,18.75); cout<<"\304";
	
	cuadro(67.5,17.5,87.5,20.5);
}

void semiFinal2(){
	/*SemiFinal: Tuve un problema con que no me alcanza
	la pantalla para todas las llaves juntas y tuve que hacerla
	otra vez, esta vez dejando mas espacio para las siguientes rondas*/
	cuadro(50,7.5,70,10.5);
	cuadro(50,27.5,70,30.5);
	cuadro(80,7.5,100,10.5);
	cuadro(80,27.5,100,30.5);
		
	flechas(46.5,3,47,8.5,49);
	flechas(46.5,14,47,9.5,49);
	
	flechas(46.5,23.5,47,28.5,49);
	flechas(46.5,33.5,47,29.5,49);
	
	flechasInversa(104,3,102,8.5,100);
	flechasInversa(104,14,102,9.5,100);

	flechasInversa(104,23.5,102,28.5,100);
	flechasInversa(104,33.5,102,29.5,100);	
}

void flechas (int Fx1,int Fy1,int Fx2,int Fy2,int Fx3){
	for(int i=Fx1;i<Fx2;i++){
		gotoxy(i,Fy1); cout<<"\304";
	}
	for(int i=Fx2; i<Fx3;i++){
		gotoxy(i,Fy2); cout<<"\304";
	}
	if(Fy1<Fy2){	
	for(int i=Fy1;i<Fy2;i++){
		gotoxy(Fx2,i); cout<<"\263";
	}
	gotoxy(Fx2,Fy2); cout<<"\300";
	gotoxy(Fx2,Fy1); cout<<"\277";
	} else {
		for (int i=Fy1;i>Fy2;i--){
			gotoxy(Fx2,i); cout<<"\263";
		}	
	gotoxy(Fx2,Fy2); cout<<"\332";
	gotoxy(Fx2,Fy1); cout<<"\331";	
	}
}


void flechasInversa (int Fx1,int Fy1,int Fx2,int Fy2,int Fx3){
	for(int i=Fx1;i>Fx2;i--){
		gotoxy(i,Fy1); cout<<"\304";
	}
	for(int i=Fx2; i>Fx3;i--){
		gotoxy(i,Fy2); cout<<"\304";
	}
	if(Fy1<Fy2){	
	for(int i=Fy1;i<Fy2;i++){
		gotoxy(Fx2,i); cout<<"\263";
	}
	gotoxy(Fx2,Fy1); cout<<"\332";
	gotoxy(Fx2,Fy2); cout<<"\331";
	} else {
		for (int i=Fy1;i>Fy2;i--){
			gotoxy(Fx2,i); cout<<"\263";
		}	
	gotoxy(Fx2,Fy2); cout<<"\277";
	gotoxy(Fx2,Fy1); cout<<"\300";	
	}
}

void visualizarTorneo(){
	int idTorneo;
	stringstream s1,s2;
	string consulta1,validacion;
	int X=1,Y=1,X2=1,Y2=6,GX=26,GY=3.5;
	MYSQL_RES *res;
	MYSQL_ROW row;
	string equipoLocal,equipoVisitante;
	int gol1,gol2;
	int i=1;
	int fin;
	bool val=true;
		
	idTorneo=pedirTorneo();
	s1<<idTorneo;
	
	system("cls");
	octavosFinal();
	cuartosFinal();
	validacion= "select count(*) from partidos where id_torneo="+s1.str()+ " and estado='finalizado'";
	if(mysql_query(obj,validacion.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	fin=atoi(row[0]);
	
	while (i<fin) {
	s2.str(""); s2.clear();	
	s2<<i;
	
	consulta1= "select e.nombre,goles_equipo1 from equipos e inner join partidos p on e.id_equipos=p.id_equipo1 where p.num_partido="+ s2.str()+" and e.id_torneo="+s1.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoLocal=row[0];
	gol1=atoi(row[1]);
	
	mysql_free_result(res);
	
	consulta1= "select e.nombre, goles_equipo2 from equipos e inner join partidos p on e.id_equipos=p.id_equipo2 where p.num_partido="+ s2.str()+" and e.id_torneo="+s1.str();
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	equipoVisitante=row[0];
	gol2=atoi(row[1]);
	
  	gotoxy(X,Y);
	cout << equipoLocal << " " <<gol1;
	gotoxy(X2,Y2);
	cout << equipoVisitante << " "<<gol2;
	
	
	if(gol1>gol2){
		gotoxy(GX,GY);
		cout<<equipoLocal;
	}else{
		gotoxy(GX,GY);
		cout<<equipoVisitante;
	}
	
	if(i<=8){
		Y=Y+10;
		Y2=Y2+10;
		GY=GY+10;
		i=i+1;
	}else if(i<=13){
		Y=Y+20;
		Y2=Y2+20;
		GY=GY+20;
		i=i+1;
	}else{
		cout<<"Holi";
		i=i+1;
	}
	
    if(i==5){
        X=131;
        Y=1;
        X2=131;
        Y2=6;
        GX=106;
        GY=3.5;
		}
	if(i==9){
		getch();
		system("cls");
		cuartosFinal();
		semiFinal2();
        X=26;
        Y=3.5;
        X2=26;
        Y2=13.5;
        GX=51;
        GY=8.5;
		}
	if(i==11){
        X=106;
        X2=106; 
        Y=3.5;
        Y2=13.5;
        GX=81;
        GY=8.5;
		}	
		
	if(i==13){
		getch();
		system("cls");
	}
		
	}

	getch();
	system("cls");
	
}
