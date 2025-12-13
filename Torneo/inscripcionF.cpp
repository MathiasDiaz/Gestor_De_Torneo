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

    cuadro(20, 0, 130, 30);
    cuadro(21, 1, 129, 3);
    gotoxy(65, 2);
    cout << "Crear Torneo";

    gotoxy(21, 6);
    cout << "Nombre del torneo: ";
    cin.getline(nombre, 30, '\n');

    while (cant_participantes != 2 && cant_participantes != 4 && cant_participantes != 8 && cant_participantes != 16) {
        system("color F7");
        gotoxy(21, 7);
        cout << "____________________________________________________________________";
        system("color F0");
        gotoxy(21, 7);
        cout << "Ingrese la cantidad de equipos (permitido unicamente 2,4,8,16): ";
        cin >> cant_participantes;
        cin.ignore(100, '\n');
        }

    gotoxy(21, 8);
    cout << "Fecha de inicio: ";
    cin.getline(fecha_inicio, 11, '\n');

    gotoxy(21, 9);
    cout << "Fecha de final: ";
    cin.getline(fecha_fin, 11, '\n');
	
	if (nombre[0] != '\0'){
    insertar_aux = "insert into torneo(nombre,cant_participantes,fecha_inicio,fecha_fin) values ('%s','%d','%s','%s')";

    int tamanio_consulta = snprintf(NULL, 0, insertar_aux.c_str(), nombre, cant_participantes, fecha_inicio, fecha_fin) + 1;
    consulta = new char[tamanio_consulta];

    snprintf(consulta, tamanio_consulta, insertar_aux.c_str(), nombre, cant_participantes, fecha_inicio, fecha_fin);

    if (mysql_query(obj, consulta)) {
        gotoxy(21, 10);
        cout << "ERROR: no se pudo insertar el torneo." << mysql_error(obj) << endl;
    } else {
        gotoxy(21, 10);
        cout << "Torneo insertado correctamente." << endl;
    }

    mysql_close(obj);
    getch();
    system("cls");
	}else{
		gotoxy(21,10); cout<<"ERROR: Llene el campo de nombre de torneo";
		getch();
	}
}
        

//FUNCIONA
void inscribirEquipos() {

 int id_torneo;
 int id_equipos;
 char nombre[30];
 int Posicion_sorteo=0;

 
 	 conectar_base();
 	 
     cuadro(20,0,130,30);
     cuadro(21,1,129,3); 
	 gotoxy(65,2); cout<<"Inscripcion";
	 gotoxy(21,5); cout<<"Nombre del torneo: ";   
	 cin.getline(nombre,30,'\n');
	 cin.ignore();
	 
		MYSQL_RES *res;
	    MYSQL_ROW row;
			
		 string consulta = "select id_torneos,cant_participantes FROM torneo where nombre='"+string (nombre)+"'";
        if (mysql_query(obj, consulta.c_str()) == 0) {
            res= mysql_store_result(obj);
	}
	row=mysql_fetch_row(res);
	id_torneo= atoi(row[0]);
	numEquipos= atoi(row[1]);
	
	stringstream ss,s2;
	ss<<id_torneo;
	
	string consulta2= "select count(*) from equipos where id_torneo="+ss.str();
	  if (mysql_query(obj, consulta2.c_str()) == 0) {
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
        
       if (nombre[0] == '\0') {
            i = i - 1;
        } else {
             string consulta3 = "INSERT INTO equipos(num_equipo,id_torneo,nombre, Posicion_sorteo, octavos) VALUES ("+s2.str() +","+ ss.str() + ", '" + string(nombre) + "', 0, 'S')";
            if (mysql_query(obj, consulta3.c_str()) != 0) {
                cout << "ERROR: no se pudo insertar." << mysql_error(obj);
            }
        }
    }
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
    string consulta3="";
    stringstream ss,sIdEquipo,sNombre1,sNombre2,sApellido1,sApellido2,sCamiseta,sEstadisticas;
	
	sEstadisticas<<0;
	
    char equipo [30],torneo[30];
    MYSQL_RES *res;
    MYSQL_ROW row;

    conectar_base();
    cuadro(20,0,130,30);
    cuadro(21,1,129,3);

    gotoxy(65,2);
    cout<<"Inscribir Jugadores";

    gotoxy(21,6);
    cout<<"Ingrese el nombre del equipo al que pertence: ";
    cin.getline(equipo,30,'\n');
    gotoxy(21,7);
    cout<<"El nombre del torneo al que pertenece: ";
    cin.getline(torneo,30,'\n');
    
    string consulta1="select e.nombre, t.nombre, e.id_equipos from equipos e join torneo t on e.id_torneo=t.id_torneos where e.nombre='"+string(equipo)+"' and t.nombre='"+string(torneo)+"'";

    if(mysql_query(obj,consulta1.c_str())==0){
        res=mysql_store_result(obj);
    }
    
    row=mysql_fetch_row(res);


    id_equipo=atoi(row[2]);
    string opcion;
    
    ss<<id_equipo;
    
	string consulta2="select count(*) from jugadores where id_equipo="+ss.str();
    if(mysql_query(obj,consulta2.c_str())==0){
        res=mysql_store_result(obj);
    }
    
    row=mysql_fetch_row(res);
    int cantidad_jug = atoi(row[0]);

    int y=8;

    for(int i=1+cantidad_jug;i<=12;i++){

        gotoxy(21,y);
        cout<<"Jugador N "<<i;
        gotoxy(21,y+1);
        cout<<"Ingrese primer nombre: ";
        cin.getline(nombre,25,'\n');
        
        gotoxy(21,y+2);
        cout<<"Ingrese segundo nombre: ";
        cin.getline(nombre2,25,'\n');
        
        gotoxy(21,y+3);
        cout<<"Ingrese primer apellido: ";
        cin.getline(apellido,25,'\n');
        
        gotoxy(21,y+4);
        cout<<"Ingrese segundo apellido: ";
        cin.getline(apellido2,25,'\n');
        
        gotoxy(21,y+5);
        cout<<"Ingrese el numero de camiseta: ";
        cin>>num_camiseta;
        cin.ignore(100,'\n');
        
        sNombre1.clear(); sNombre1.str("");
        sNombre2.clear(); sNombre2.str("");
        sApellido1.clear(); sApellido1.str("");
        sApellido2.clear(); sApellido2.str("");
        sCamiseta.clear(); sCamiseta.str("");
        
        sNombre1<<nombre;
        sNombre2<<nombre2;
        sApellido1<<apellido;
        sApellido2<<apellido2;
        sCamiseta<<num_camiseta;
	
	if(strcmp(nombre2,"")==0 && strcmp(apellido2,"")==0){
        consulta3="insert into jugadores(id_equipo,nombre,apellido,num_camiseta,asistencias,goles,rojas,amarillas)values("+ss.str()+",'"+sNombre1.str()+"','"+sApellido1.str()+"',"+sCamiseta.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+")";
    }
	if(strcmp(nombre2,"")==0 && strcmp(apellido2,"")!=0){
        consulta3="insert into jugadores(id_equipo,nombre,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas)values("+ss.str()+",'"+sNombre1.str()+"','"+sApellido1.str()+"','"+sApellido2.str()+"',"+sCamiseta.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+")";
    }
	if(strcmp(nombre2,"")!=0 && strcmp(apellido2,"")==0){
        consulta3="insert into jugadores(id_equipo,nombre,nombre2,apellido,num_camiseta,asistencias,goles,rojas,amarillas)values("+ss.str()+",'"+sNombre1.str()+"','"+sNombre2.str()+"','"+sApellido1.str()+"',"+sCamiseta.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+")";
    }
    if(strcmp(nombre2,"")!=0 && strcmp(apellido2,"")!=0){
        consulta3="insert into jugadores(id_equipo,nombre,nombre2,apellido,apellido2,num_camiseta,asistencias,goles,rojas,amarillas)values("+ss.str()+",'"+sNombre1.str()+"','"+sNombre2.str()+"','"+sApellido1.str()+"','"+sApellido2.str()+"',"+sCamiseta.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+","+sEstadisticas.str()+")";
    }

    if(mysql_query(obj, consulta3.c_str())){
        cout<<"ERROR: no se pudo insertar el jugador"<<mysql_error(obj)<<endl;
    }
    y=y+6;
}
	getch();
}

//FUNCIONA
void sorteo(){
	
	char nombreTorneo[30];
    int id_torneo, idEquipo, cantParticipantes, totalInscriptos;
    int Posicion_Sorteo;
    int numPartido = 1;
    vector <int> PosEquipos;
    string equipoAux;
    string consulta1, consulta2, consulta3, consulta4, consulta5, consulta6;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conectar_base();
    cuadro(20, 0, 130, 30);
    cuadro(21, 1, 129, 3);

    gotoxy(65, 2);
    cout << "Sorteo";

    gotoxy(21, 6);
    cout << "Ingrese el nombre del torneo: ";
    cin.getline(nombreTorneo, 30, '\n');

    consulta1 = "select id_torneos,cant_participantes from torneo where nombre='" + string(nombreTorneo) + "'";
    if (mysql_query(obj, consulta1.c_str()) == 0) {
        res = mysql_store_result(obj);
    }
    row = mysql_fetch_row(res);
    id_torneo = atoi(row[0]);
    cantParticipantes = atoi(row[1]);

    stringstream s1,s2,s3,s4,s5;
    s1 << id_torneo; 
	
	string validarTotalEquipos = "select count(*) from equipos where id_torneo="+s1.str();
    if (mysql_query(obj, validarTotalEquipos.c_str())==0){
        res=mysql_store_result(obj);
    }
    row=mysql_fetch_row(res);
    totalInscriptos=atoi(row[0]);
    
    if(totalInscriptos==cantParticipantes){
        
        consulta2 = "select Posicion_sorteo from equipos where id_torneo=" + s1.str();

        if (mysql_query(obj, consulta2.c_str())==0){
            res = mysql_store_result(obj);
        }

        row = mysql_fetch_row(res);
        Posicion_Sorteo=atoi(row[0]);

        if (Posicion_Sorteo>0){
            gotoxy (21,7);
            cout<<"Los equipos ya estan mezclados.";
            getch();
    	}else{
    		for (int i=1; i<=cantParticipantes; i++) {
    			PosEquipos.push_back(i);
			}
			
			mezclar(PosEquipos,cantParticipantes);
			for (int i=1; i<=cantParticipantes; i++){
		
				s2.str(""); s2.clear();
				s3.str(""); s3.clear();
		
				s2<<PosEquipos[i-1];
				s3<<i;
				consulta3= " update equipos set Posicion_sorteo= "+s2.str() +" where id_torneo= "+s1.str()+" and num_equipo= "+s3.str();
		
				mysql_query(obj,consulta3.c_str());
			}
			
			for (int i=1;i<=cantParticipantes;i++){
            s3.str(""); s3.clear();
			s4.str(""); s4.clear();
            s5.str(""); s5.clear();

            s3<<i;
            s4<<numPartido;
            
            consulta4 = "select nombre,id_equipos from equipos where id_torneo="+s1.str()+" and Posicion_Sorteo="+s3.str();
            
			if (mysql_query(obj, consulta4.c_str())==0){
                res=mysql_store_result(obj);
            }
            row = mysql_fetch_row(res);
            equipoAux=row[0];
            idEquipo=atoi(row[1]);
            s5<<idEquipo;

            if (i%2==1){
                consulta6= "insert into partidos (id_torneo,num_partido,id_equipo1,estado,goles_equipo1,goles_equipo2) values ("+s1.str()+","+s4.str()+","+s5.str()+",'activo',0,0)";
                if (mysql_query(obj, consulta6.c_str()) != 0) {
                    cout << "Error insertando partido: " << mysql_error(obj) << endl;
                }

                gotoxy(21,6+numPartido); cout<<equipoAux;
                gotoxy(38,6+numPartido); cout<<" VS ";
            }else{
                consulta6= "update partidos set id_equipo2="+s5.str()+" where id_torneo= "+s1.str()+" and num_partido="+s4.str();
                if (mysql_query(obj, consulta6.c_str()) != 0) {
                    cout << "Error insertando partido: " << mysql_error(obj) << endl;
                }
                gotoxy(43,6+numPartido); cout<<equipoAux;
                numPartido=numPartido+1;
            }
	}
				gotoxy(21,7+ numPartido); cout<<"Se realizo el sorteo.";
	}
	getch();
	 }else{
	 	gotoxy(21,7); cout<<"ERROR: Complete la inscrpicon de todos los equipos.";
	 	getch();
	 }
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
				//cout<<"EXITO: se pudo conectar a la base de datos."<<endl;
			}
}
}

void mezclar(vector<int> &v, int limite) {
    for (int i = limite - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(v[i], v[j]);
    }
}
