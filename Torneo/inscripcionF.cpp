#include "torneo.h"

string entradaDeEquipos;

MYSQL *obj=0;

//FUNCIONA
void crearTorneo(){
	
	char nombre[30];
	int cant_participantes;
	char fecha_inicio[11];
	char fecha_fin[11];
	
	
	char* consulta;
	char* insertar;
	string insertar_aux;
	
	conectar_base();
	
	 cuadro(20,0,130,30);
     cuadro(21,1,129,3); 
	 gotoxy(65,2); cout<<"Crear Torneo";

	 cin.ignore(100,'\n');
	 
	 gotoxy(21,6);cout<<"Nombre del torneo: ";
	 cin.getline(nombre,30,'\n');
	 
	 gotoxy(21,7);cout<<"Ingrese la cantidad de equipos (permitido unicamente 2,4,8,16): ";
	 cin>>cant_participantes;
	 cin.ignore(100,'\n');
	 
	 if(cant_participantes!=2&&cant_participantes!=4&&cant_participantes!=8&&cant_participantes!=16){
	 	abort();
	 }
	 		 
	 gotoxy(21,8);cout<<"Fecha de inicio: ";
	 cin.getline(fecha_inicio,11,'\n');
	 
	 gotoxy(21,9);cout<<"Fecha de final: ";
	 cin.getline(fecha_fin,11,'\n');
	 
	 insertar_aux="insert into torneo(nombre,cant_participantes,fecha_inicio,fecha_fin) values ('%s',%d,'%s','%s')";
	 
	 int tamanio_consulta= snprintf(NULL,0,insertar_aux.c_str(),nombre,cant_participantes,fecha_inicio,fecha_fin)+1;
	 
    consulta = new char[tamanio_consulta];

    snprintf(consulta, tamanio_consulta, insertar_aux.c_str(), nombre,cant_participantes, fecha_inicio, fecha_fin);
	
	if (mysql_query(obj,consulta)) {
   gotoxy(21,10); cout<<"ERROR: no se pudo insertar el torneo. "<< mysql_error(obj)<<endl;
} else {
   gotoxy(21,10); cout<<"Torneo insertado correctamente."<<endl;
}	
	mysql_close(obj);
	getch();
	system("cls");
}

//FUNCIONA
void inscribirEquipos() {

 int id_torneo;
 int id_equipos;
 char nombre[30];
 int Posicion_sorteo=0;
 char* consulta;
 
 	 conectar_base();
 	 
     cuadro(20,0,130,30);
     cuadro(21,1,129,3); 
	 gotoxy(65,2); cout<<"Inscripcion";
	 gotoxy(21,5); cout<<"Nombre del torneo: ";   
	 cin.getline(nombre,30,'\n');
	 cin.ignore();
		MYSQL_RES *res;
	    MYSQL_ROW row;
			
		 string query1 = "select id_torneos,cant_participantes FROM torneo where nombre='"+string (nombre)+"'";
        if (mysql_query(obj, query1.c_str()) == 0) {
            res= mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	id_torneo= atoi(row[0]);
	numEquipos= atoi(row[1]);
	
	stringstream ss,s2;
	ss<<id_torneo;
	
	string query2= "select count(*) from equipos where id_torneo="+ss.str();
	  if (mysql_query(obj, query2.c_str()) == 0) {
            res= mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	int contador= atoi(row[0]);
	
	 for (int i = 1+contador; i <= numEquipos; i++) {
        gotoxy(21,7+i-contador); 
        s2.str(""); s2.clear();
        s2<<i;
		cout << "Ingrese el nombre del equipo N " << i << ": ";
        cin.getline(nombre,30,'\n');
        
       string consulta = "INSERT INTO equipos(num_equipo,id_torneo,nombre, Posicion_sorteo, octavos) VALUES ("+s2.str() +","+ ss.str() + ", '" + string(nombre) + "', 0, 'S')";
        
        if (mysql_query(obj, consulta.c_str())!=0){
        	cout<<"ERROR: no se pudo insertar."<<mysql_error(obj) <<endl;
		} 
    }
	
	getch();
}
//FUNCIONA
void inscribirJug(){
int id_jug;
int id_equipo;
char nombre [25];
char nombre2 [25];
char apellido[25];
char apellido2[25];
int num_camiseta;
int asistencias=0;
int goles=0;
int rojas=0;
int amarillas=0;

char equipo [30];
MYSQL_RES *res;
MYSQL_ROW row;


conectar_base();

	cout<<"Ingrese el nombre del equipo al que pertence: ";
	cin.getline(equipo,30,'\n');
	
	string consulta1="select e.nombre, t.nombre, e.id_equipos from equipos e  join torneo t on e.id_torneo=t.id_torneos where e.nombre='"+ string(equipo)+"'";
	
	if(mysql_query(obj,consulta1.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	
	string nombreEquipo= row[0];
	string nombretorneo=row[1];
	id_equipo=atoi(row[2]);
	string opcion;
	
	cout<<"El torneo en el que partcipas es "<<nombretorneo<<"? (Si=S // No=N)"<<endl;
	cout<<"opcion: ";  
	getline(cin,opcion);
	
	while (opcion=="N"||opcion=="n"){
		row=mysql_fetch_row(res);
		string nombretorneo=row[1];	
		cout<<"El torneo en el que partcipas es "<<nombretorneo<<"? (Si=S // No=N)"<<endl;
		cout<<"opcion: ";  
		getline(cin,opcion);
	}
	
	mysql_free_result(res); //Limpia el resultado de la consulta :)
	stringstream ss;
	ss<<id_equipo;
	
	string consulta2="select count(*) from jugadores where id_equipo="+ss.str(); 
	
	if(mysql_query(obj,consulta2.c_str())==0){
		res=mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	int cantidad_jug =atoi(row[0]);
	
	for(int i=1+cantidad_jug;i<=12;i++){
	cout<<"Jugador Nº"<<i<<endl;
	cout<<"Ingrese primer nombre: ";
	cin.getline(nombre,25,'\n');
	cout<<"Ingrese segundo nombre: ";
	cin.getline(nombre2,25,'\n');
	cout<<"Ingrese primer apellido: ";
	cin.getline(apellido,25,'\n');
	cout<<"Ingrese segundo apellido: ";
	cin.getline(apellido2,25,'\n');
	cout<<"Ingrese el numero de camiseta:";
	cin>>num_camiseta;
	cin.ignore(100,'\n');
	
	char* ins_consulta3;
	
	if(strcmp(nombre2, "null") == 0 && strcmp(apellido2, "null")==0){
	string consulta3= "insert into jugadores(id_jug,id_equipo,nombre,apellido,num_camiseta,asistencias,goles,rojas,amarillas)values(%d,%d,'%s','%s',%d,%d,%d,%d,%d)";
	int tam_consulta=snprintf(NULL,0,consulta3.c_str(),id_jug,id_equipo,nombre,apellido,num_camiseta,asistencias,goles,rojas,amarillas)+1;
	ins_consulta3=new char[tam_consulta];
	snprintf(ins_consulta3,tam_consulta,consulta3.c_str(),id_jug,id_equipo,nombre,apellido,num_camiseta,asistencias,goles,rojas,amarillas);		
} if(strcmp(nombre2,"null")==0 && strcmp(apellido2,"null")!=0){
	string consulta3= "insert into jugadores(id_jug,id_equipo,nombre,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas)values(%d,%d,'%s','%s','%s',%d,%d,%d,%d,%d)";
	int tam_consulta=snprintf(NULL,0,consulta3.c_str(),id_jug,id_equipo,nombre,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas)+1;
	ins_consulta3=new char[tam_consulta];
	snprintf(ins_consulta3,tam_consulta,consulta3.c_str(),id_jug,id_equipo,nombre,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas);	
}if(strcmp(nombre2,"null")!=0 && strcmp(apellido2,"null")==0){
	string consulta3= "insert into jugadores(id_jug,id_equipo,nombre,nombre2,apellido,num_camiseta,asistencias,goles,rojas,amarillas)values(%d,%d,'%s','%s','%s',%d,%d,%d,%d,%d)";
	int tam_consulta=snprintf(NULL,0,consulta3.c_str(),id_jug,id_equipo,nombre,nombre2,apellido,num_camiseta,asistencias,goles,rojas,amarillas)+1;
	ins_consulta3=new char[tam_consulta];
	snprintf(ins_consulta3,tam_consulta,consulta3.c_str(),id_jug,id_equipo,nombre,nombre2,apellido,num_camiseta,asistencias,goles,rojas,amarillas);	
}
if(strcmp(nombre2,"null")!=0 && strcmp(apellido2,"null")!=0){
	string consulta3= "insert into jugadores(id_jug,id_equipo,nombre,nombre2,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas)values(%d,%d,'%s','%s','%s','%s',%d,%d,%d,%d,%d)";
	int tam_consulta=snprintf(NULL,0,consulta3.c_str(),id_jug,id_equipo,nombre,nombre2,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas)+1;
 	ins_consulta3=new char[tam_consulta];
	snprintf(ins_consulta3,tam_consulta,consulta3.c_str(),id_jug,id_equipo,nombre,nombre2,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas);	
}
	if(mysql_query(obj,ins_consulta3)){
		cout<<"ERROR: no se pudo insertar el jugador"<<mysql_error(obj)<<endl;
	}
	delete[] ins_consulta3;
	}
	
	getch();
}
//FUNCIONA
void sorteo(){
	char nombreTorneo[30];
	
	int id_torneo, idEquipo;
	int Posicion_Sorteo;
	int numPartido=1;
	vector<int> PosEquipos;
	string equipoAux;
	string consulta1,consulta2,consulta3,consulta4,consulta5,consulta6;
	MYSQL_RES* res;
	MYSQL_ROW row;
	
	
	conectar_base();

	cout<<"Ingrese el nombre del torneo: "<<endl;
	cin.getline(nombreTorneo,30,'\n');
	
	consulta1 = "select id_torneos from torneo where nombre='"+string (nombreTorneo)+"'";
        if (mysql_query(obj, consulta1.c_str()) == 0) {
            res= mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	id_torneo= atoi(row[0]);
	
	stringstream s1,s2,s3,s4,s5;
	s1<<id_torneo;
	
	consulta2= "select Posicion_sorteo from equipos where id_torneo= "+s1.str();
	
		if (mysql_query(obj, consulta2.c_str())==0){
			res= mysql_store_result(obj);
		}
		
	row= mysql_fetch_row(res);
	Posicion_Sorteo=atoi(row[0]);
	
	if (Posicion_Sorteo>0){
		cout<<"Los equipos ya estan mezclados.";	
		getch();
	}else{

	for (int i=1; i<=16; i++) {
    	PosEquipos.push_back(i);
	}
		
	mezclar(PosEquipos);
	
	for (int i=1; i<=16; i++){
		
		s2.str(""); s2.clear();
		s3.str(""); s3.clear();
		
		s2<<PosEquipos[i-1];
		s3<<i;
		consulta3= " update equipos set Posicion_sorteo= "+s2.str() +" where id_torneo= "+s1.str()+" and num_equipo= "+s3.str();
		
		mysql_query(obj,consulta3.c_str());
		}	
	for (int i=1;i<=16;i++){
		s3.str(""); s3.clear();
		s4.str(""); s4.clear();
		s5.str(""); s5.clear();
		
		s3<<i;
		s4<<numPartido; 
		consulta4= "select nombre,id_equipos from equipos where id_torneo="+s1.str()+ " and Posicion_Sorteo= "+s3.str();
			if(mysql_query(obj,consulta4.c_str())==0){
			res=mysql_store_result(obj);
		}
		row= mysql_fetch_row(res);
		equipoAux=row[0];
		idEquipo=atoi(row[1]);
		s5<<idEquipo;

		if (i%2==1){			
			consulta6= "insert into partidos (id_torneo,num_partido,id_equipo1,estado,goles_equipo1,goles_equipo2) values ("+s1.str()+","+s4.str()+","+s5.str()+",'activo',0,0)";
			if (mysql_query(obj, consulta6.c_str()) != 0) {
         
		    cout << "Error insertando partido: " << mysql_error(obj) << endl;
        }
			
			cout<<equipoAux<<" VS ";
		}else{
			consulta6= "update partidos set id_equipo2="+s5.str()+" where id_torneo= "+s1.str()+" and num_partido="+s4.str();
			
			if (mysql_query(obj, consulta6.c_str()) != 0) {
            cout << "Error insertando partido: " << mysql_error(obj) << endl;
        }
			cout<<equipoAux<<endl;
			numPartido=numPartido+1;
		}
	}
	cout<<"Se realizo el sorteo.";
	}
	getch();
	 } 

void instrucciones(){
			cuadro(20,0,130,30);
			cuadro(21,1,129,3); 
			gotoxy(65,2); cout<<"Instrucciones";
			gotoxy(21,6); cout<< "1. Crear Torneo:";
			gotoxy(21,7); cout<< "   - Selecciona la opcion 1.";
			gotoxy(21,8); cout<< "   - Ingresa un nombre para el torneo (sin .txt).";
			gotoxy(21,9); cout<< "   - El torneo se creara automaticamente.";
			gotoxy(21,11); cout<< "2. Inscripcion:";
			gotoxy(21,12); cout<< "   - Ingresa el nombre del torneo (sin .txt).";
			gotoxy(21,13); cout<< "   - Registra los equipos participantes.";
			gotoxy(21,14); cout<< "   - Puedes agregar equipos mas tarde.";
			gotoxy(21,15); cout<< "   - Posible Error: Si el nombre no coincide, el programa se cerrara.";
			gotoxy(21,17); cout<< "3. Mezclar Equipos:";
			gotoxy(21,18); cout<< "   - Es recomendable realizar esta accion una vez.";
			gotoxy(21,19); cout<< "   - No mezcles los equipos despues de iniciar el torneo.";
			gotoxy(21,21); cout<< "4. Jugar Torneo:";
			gotoxy(21,22); cout<< "   - Cuando te pida ingresas la cantidad de equipos:";
			gotoxy(21,23); cout<< "   - Ingresa la cantidad original de equipos.";
			gotoxy(21,24); cout<< "   - Ejemplo: Si comenzo con 16 y quedan 4, ingresa 16.";		
}
//funciona
void conectar_base(){
 
		char HOST[]="localhost";
		char USER[]="root";
		char PASS[]="1234";
		
		obj=mysql_init(0);
		
		if(!obj){
			cout<<"ERROR: no se pudo crear el objeto mysql";
		}else{
			if(!mysql_real_connect(obj,HOST,USER,PASS,"torneos",3306,NULL,0)){
			 	cout<<"ERROR: la informacion de la base de datos son incorrectos o no existen.";
			 	cout<<mysql_error(obj)<<endl;
			}else{
				cout<<"EXITO: se pudo conectar a la base de datos."<<endl;
			}
}
}

void mezclar(vector<int> &v) {
    for (int i = 16 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(v[i], v[j]);
    }
}
