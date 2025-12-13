create database torneos;
use torneos;

create table torneo(
id_torneos int primary key not null auto_increment,
nombre varchar(30) not null,
cant_participantes int not null, 
fecha_inicio date not null,
fecha_fin date not null
);

create table equipos(
id_equipos int primary key not null AUTO_INCREMENT,
id_torneo int not null,
num_equipo int not null,
nombre varchar(100) not null,
Posicion_sorteo int,
octavos varchar(5),
cuartos varchar(5),
semi varchar(5),
final varchar(5),
foreign key (id_torneo) references torneo(id_torneos)
);

create table jugadores(
id_equipo int not null,
nombre varchar(25) not null,
nombre2 varchar(25),
apellido varchar(25) not null,
apellido2 varchar(25),
num_camiseta int not null,
asistencias int,
goles int,
rojas int,
amarillas int,
primary key (num_camiseta,id_equipo),
foreign key (id_equipo) references equipos(id_equipos)
);

create table partidos(
id_partidos int primary key not null auto_increment,
id_torneo int not null,
num_partido int not null,
id_equipo1 int,
id_equipo2 int,
goles_equipo1 int,
goles_equipo2 int,
resultado varchar(10),
estado varchar(20),
foreign key (id_torneo) references torneo(id_torneos),
foreign key(id_equipo1) references equipos(id_equipos),
foreign key (id_equipo2) references equipos(id_equipos)
);



use torneos;
INSERT INTO torneo (id_torneos,nombre, cant_participantes,fecha_inicio,fecha_fin) values 
(1,'Liga Argentina',16,'2025-01-01','2025-12-31');

INSERT INTO equipos (num_equipo, id_torneo, nombre, Posicion_sorteo, octavos) VALUES
(1, 1, 'Boca Juniors', 0, 'S'),
(2, 1, 'River Plate', 0, 'S'),
(3, 1, 'Independiente', 0, 'S'),
(4, 1, 'Racing Club', 0, 'S'),
(5, 1, 'San Lorenzo', 0, 'S'),
(6, 1, 'Vélez Sarsfield', 0, 'S'),
(7, 1, 'Estudiantes LP', 0, 'S'),
(8, 1, 'Gimnasia LP', 0, 'S'),
(9, 1, 'Rosario Central', 0, 'S'),
(10, 1, 'Newell''s Old Boys', 0, 'S'),
(11, 1, 'Huracán', 0, 'S'),
(12, 1, 'Argentinos Juniors', 0, 'S'),
(13, 1, 'Tigre', 0, 'S'),
(14, 1, 'Lanús', 0, 'S'),
(15, 1, 'Defensa y Justicia', 0, 'S'),
(16, 1, 'Banfield', 0, 'S');

INSERT INTO torneo (id_torneos,nombre, cant_participantes,fecha_inicio,fecha_fin) values 
(2,'Premier League',16,'2025-01-01','2025-12-31');

INSERT INTO equipos
(id_torneo, num_equipo, nombre, Posicion_sorteo, octavos, cuartos, semi, final)
VALUES
(2, 29, 'Manchester United', 0, 'S', NULL, NULL, NULL),
(2, 30, 'Manchester City', 0, 'S', NULL, NULL, NULL),
(2, 31, 'Arsenal', 0, 'S', NULL, NULL, NULL),
(2, 32, 'Chelsea', 0, 'S', NULL, NULL, NULL),
(2, 33, 'Liverpool', 0, 'S', NULL, NULL, NULL),
(2, 34, 'Tottenham Hotspur', 0, 'S', NULL, NULL, NULL),
(2, 35, 'Aston Villa', 0, 'S', NULL, NULL, NULL),
(2, 36, 'Brighton & Hove Albion', 0, 'S', NULL, NULL, NULL),
(2, 37, 'Burnley', 0, 'S', NULL, NULL, NULL),
(2, 38, 'Nottingham Forest', 0, 'S', NULL, NULL, NULL),
(2, 39, 'West Ham United', 0, 'S', NULL, NULL, NULL),
(2, 40, 'Fulham', 0, 'S', NULL, NULL, NULL),
(2, 41, 'Crystal Palace', 0, 'S', NULL, NULL, NULL),
(2, 42, 'Nottingham Forest', 0, 'S', NULL, NULL, NULL),
(2, 43, 'Brentford', 0, 'S', NULL, NULL, NULL),
(2, 44, 'Newcastle United', 0, 'S', NULL, NULL, NULL);

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES
(1, 'Miguel', NULL, 'Merentiel', NULL, 16, 0, 0, 0, 0),          -- Boca Juniors
(2, 'Miguel', NULL, 'Borja', NULL, 9, 0, 0, 0, 0),               -- River Plate
(3, 'Gabriel', NULL, 'Ávalos', NULL, 9, 0, 0, 0, 0),             -- Independiente
(4, 'Roger', NULL, 'Martínez', NULL, 9, 0, 0, 0, 0),             -- Racing Club
(5, 'Adam', NULL, 'Bareiro', NULL, 9, 0, 0, 0, 0),               -- San Lorenzo
(6, 'Thiago', NULL, 'Almada', NULL, 23, 0, 0, 0, 0),             -- Vélez Sarsfield
(7, 'Guido', NULL, 'Carrillo', NULL, 19, 0, 0, 0, 0),            -- Estudiantes LP
(8, 'Benjamín', NULL, 'Domínguez', NULL, 7, 0, 0, 0, 0),         -- Gimnasia LP
(9, 'Ignacio', NULL, 'Malcorra', NULL, 10, 0, 0, 0, 0),          -- Rosario Central
(10, 'Juan', NULL, 'Sforza', NULL, 5, 0, 0, 0, 0),               -- Newell's Old Boys
(11, 'Ignacio', NULL, 'Pussetto', NULL, 7, 0, 0, 0, 0),          -- Huracán
(12, 'Gabriel', NULL, 'Ávalos', NULL, 9, 0, 0, 0, 0),            -- Argentinos Juniors
(13, 'Mateo', NULL, 'Retegui', NULL, 32, 0, 0, 0, 0),            -- Tigre
(14, 'José', 'Gustavo', 'Sand', NULL, 9, 0, 0, 0, 0),            -- Lanús
(15, 'Nicolás', NULL, 'Fernández', NULL, 29, 0, 0, 0, 0),        -- Defensa y Justicia
(16, 'Milton', NULL, 'Giménez', NULL, 9, 0, 0, 0, 0);            -- Banfield

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES
(1, 'Kevin', NULL, 'Zenón', NULL, 22, 0, 0, 0, 0),            -- Boca Juniors
(2, 'Esequiel', NULL, 'Barco', NULL, 21, 0, 0, 0, 0),        -- River Plate
(3, 'Mauricio', NULL, 'Isla', NULL, 3, 0, 0, 0, 0),          -- Independiente
(4, 'Juan', NULL, 'Quintero', NULL, 8, 0, 0, 0, 0),          -- Racing Club
(5, 'Yeison', NULL, 'Córdoba', NULL, 7, 0, 0, 0, 0),         -- San Lorenzo
(6, 'Lautaro', NULL, 'Gianetti', NULL, 6, 0, 0, 0, 0),       -- Vélez Sarsfield
(7, 'Carlos', NULL, 'Auzqui', NULL, 28, 0, 0, 0, 0),         -- Estudiantes LP
(8, 'Rodrigo', NULL, 'Saravia', NULL, 5, 0, 0, 0, 0),        -- Gimnasia LP
(9, 'Agustín', NULL, 'Maldonado', NULL, 2, 0, 0, 0, 0),      -- Rosario Central
(10, 'Pablo', NULL, 'Pérez', NULL, 8, 0, 0, 0, 0),           -- Newell''s Old Boys
(11, 'William', NULL, 'Alarcón', NULL, 14, 0, 0, 0, 0),      -- Huracán
(12, 'Alan', NULL, 'Rodríguez', NULL, 4, 0, 0, 0, 0),        -- Argentinos Juniors
(13, 'Facundo', NULL, 'Colidio', NULL, 9, 0, 0, 0, 0),       -- Tigre
(14, 'Lautaro', NULL, 'Acuña', NULL, 22, 0, 0, 0, 0),        -- Lanús
(15, 'Santiago', NULL, 'Ramos', 'Mingo', 25, 0, 0, 0, 0),    -- Defensa y Justicia
(16, 'Agustín', NULL, 'Urruti', NULL, 11, 0, 0, 0, 0);       -- Banfield


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(29, 'André', NULL, 'Onana', NULL, 1, 0, 0, 0, 0),
(29, 'Victor', NULL, 'Lindelöf', NULL, 2, 0, 0, 0, 0),
(29, 'Luke', NULL, 'Shaw', NULL, 3, 0, 0, 0, 0),
(29, 'Raphaël', NULL, 'Varane', NULL, 4, 0, 0, 0, 0),
(29, 'Lisandro', NULL, 'Martínez', NULL, 6, 0, 0, 0, 0),
(29, 'Mason', 'Tony', 'Mount', NULL, 7, 0, 0, 0, 0),
(29, 'Bruno', NULL, 'Fernandes', NULL, 8, 0, 0, 0, 0),
(29, 'Anthony', NULL, 'Martial', NULL, 9, 0, 0, 0, 0),
(29, 'Marcus', NULL, 'Rashford', NULL, 10, 0, 0, 0, 0),
(29, 'Rasmus', NULL, 'Højlund', NULL, 11, 0, 0, 0, 0),
(29, 'Diogo', NULL, 'Dalot', NULL, 5, 0, 0, 0, 0);



INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(30, 'Ederson', 'Santana', 'de Moraes', NULL, 1, 0, 0, 0, 0),
(30, 'Kyle', NULL, 'Walker', NULL, 2, 0, 0, 0, 0),
(30, 'Rúben', 'Santos', 'Dias', NULL, 3, 0, 0, 0, 0),
(30, 'John', NULL, 'Stones', NULL, 4, 0, 0, 0, 0),
(30, 'Nathan', 'Benjamin', 'Aké', NULL, 6, 0, 0, 0, 0),
(30, 'Matheus', 'Luís', 'Nunes', NULL, 5, 0, 0, 0, 0), 
(30, 'Mateo', NULL, 'Kovačić', NULL, 8, 0, 0, 0, 0),
(30, 'Erling', 'Braut', 'Haaland', NULL, 9, 0, 0, 0, 0),
(30, 'Jack', NULL, 'Grealish', NULL, 10, 0, 0, 0, 0),
(30, 'Jérémy', NULL, 'Doku', NULL, 11, 0, 0, 0, 0),
(30, 'Bernardo', 'Mota', 'Veiga de Carvalho e Silva', NULL, 7, 0, 0, 0, 0);



INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(31, 'Aaron', NULL, 'Ramsdale', NULL, 1, 0, 0, 0, 0),
(31, 'William', 'Alain André', 'Saliba', NULL, 2, 0, 0, 0, 0),
(31, 'Kieran', NULL, 'Tierney', NULL, 3, 0, 0, 0, 0),
(31, 'Ben', NULL, 'White', NULL, 4, 0, 0, 0, 0),
(31, 'Thomas', NULL, 'Partey', NULL, 5, 0, 0, 0, 0),
(31, 'Gabriel', 'dos Santos', 'Magalhães', NULL, 6, 0, 0, 0, 0),
(31, 'Bukayo', 'Ayoyinka Temidayo', 'Saka', NULL, 7, 0, 0, 0, 0),
(31, 'Martin', NULL, 'Ødegaard', NULL, 8, 0, 0, 0, 0),
(31, 'Gabriel', 'Fernando de Jesus', 'Silva', NULL, 9, 0, 0, 0, 0),
(31, 'Emile', 'Smith', 'Rowe', NULL, 10, 0, 0, 0, 0),
(31, 'Gabriel', NULL, 'Martinelli', NULL, 11, 0, 0, 0, 0);



INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(32, 'Robert', NULL, 'Sánchez', NULL, 1, 0, 0, 0, 0),
(32, 'Axel', 'Laurent Angel', 'Disasi', NULL, 2, 0, 0, 0, 0),
(32, 'Marc', NULL, 'Cucurella', NULL, 3, 0, 0, 0, 0),
(32, 'Benoît', NULL, 'Badiashile', NULL, 4, 0, 0, 0, 0),
(32, 'Benoît', NULL, 'Chilwell', NULL, 5, 0, 0, 0, 0),
(32, 'Thiago', 'Emiliano da Silva', 'Mendes', NULL, 6, 0, 0, 0, 0),
(32, 'Raheem', 'Shaquille', 'Sterling', NULL, 7, 0, 0, 0, 0),
(32, 'Enzo', 'Jeremías', 'Fernández', NULL, 8, 0, 0, 0, 0),
(32, 'Nicolas', NULL, 'Jackson', NULL, 9, 0, 0, 0, 0),
(32, 'Mykhailo', NULL, 'Mudryk', NULL, 10, 0, 0, 0, 0),
(32, 'Noni', null, 'Madueke', NULL, 11, 0, 0, 0, 0);


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(37, 'Arijanet', NULL, 'Murić', NULL, 1, 0, 0, 0, 0),
(37, 'Dara', NULL, 'O\'Shea', NULL, 2, 0, 0, 0, 0),
(37, 'Charlie', NULL, 'Taylor', NULL, 3, 0, 0, 0, 0),
(37, 'Jack', NULL, 'Cork', NULL, 4, 0, 0, 0, 0),
(37, 'Jordan', NULL, 'Beyer', NULL, 5, 0, 0, 0, 0),
(37, 'Lorenz', 'Zebulon', 'Assignon', NULL, 6, 0, 0, 0, 0),
(37, 'Jóhann', 'Berg', 'Guðmundsson', NULL, 7, 0, 0, 0, 0),
(37, 'Josh', NULL, 'Brownhill', NULL, 8, 0, 0, 0, 0),
(37, 'Jay', NULL, 'Rodríguez', NULL, 9, 0, 0, 0, 0),
(37, 'Manuel', NULL, 'Benson', NULL, 10, 0, 0, 0, 0),
(37, 'Zeki', NULL, 'Amdouni', NULL, 11, 0, 0, 0, 0);


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(33, 'Alisson', 'Ramses', 'Becker', NULL, 1, 0, 0, 0, 0),
(33, 'Joe', NULL, 'Gomez', NULL, 2, 0, 0, 0, 0),
(33, 'Wataru', NULL, 'Endo', NULL, 3, 0, 0, 0, 0),
(33, 'Virgil', NULL, 'van Dijk', NULL, 4, 0, 0, 0, 0),
(33, 'Ibrahima', NULL, 'Konaté', NULL, 5, 0, 0, 0, 0),
(33, 'Thiago', 'Alcántara', 'do Nascimento', NULL, 6, 0, 0, 0, 0),
(33, 'Luis', 'Fernando', 'Díaz', NULL, 7, 0, 0, 0, 0),
(33, 'Dominik', NULL, 'Szoboszlai', NULL, 8, 0, 0, 0, 0),
(33, 'Darwin', 'Gabriel', 'Núñez', NULL, 9, 0, 0, 0, 0),
(33, 'Alexis', 'Mac', 'Allister', NULL, 10, 0, 0, 0, 0),
(33, 'Mohamed', NULL, 'Salah', NULL, 11, 0, 0, 0, 0);


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(34, 'Guglielmo', NULL, 'Vicario', NULL, 1, 0, 0, 0, 0),
(34, 'Cristian', 'Gabriel', 'Romero', NULL, 2, 0, 0, 0, 0),
(34, 'Sergio', NULL, 'Reguilón', NULL, 3, 0, 0, 0, 0),
(34, 'Oliver', NULL, 'Skipp', NULL, 4, 0, 0, 0, 0),
(34, 'Pierre-Emile', 'Kordt', 'Højbjerg', NULL, 5, 0, 0, 0, 0),
(34, 'Davinson', 'Sánchez', 'Mina', NULL, 6, 0, 0, 0, 0),
(34, 'Son', null , 'Heung-min', NULL, 7, 0, 0, 0, 0),
(34, 'Yves', null, 'Bissouma', NULL, 8, 0, 0, 0, 0),
(34, 'Richarlison', null, 'de Andrade', NULL, 9, 0, 0, 0, 0),
(34, 'James', NULL, 'Maddison', NULL, 10, 0, 0, 0, 0),
(34, 'Bryan', 'Gil', 'Salvadores', NULL, 11, 0, 0, 0, 0);

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(35, 'Emiliano', 'Damián', 'Martínez', NULL, 1, 0, 0, 0, 0),
(35, 'Matty', NULL, 'Cash', NULL, 2, 0, 0, 0, 0),
(35, 'Diego', 'Carlos', 'Santos Silva', NULL, 3, 0, 0, 0, 0),
(35, 'Ezri', NULL, 'Konsa', NULL, 4, 0, 0, 0, 0),
(35, 'Tyrone', NULL, 'Mings', NULL, 5, 0, 0, 0, 0),
(35, 'Douglas', 'Luiz', 'Soares de Paulo', NULL, 6, 0, 0, 0, 0),
(35, 'John', NULL, 'McGinn', NULL, 7, 0, 0, 0, 0),
(35, 'Youri', NULL, 'Tielemans', NULL, 8, 0, 0, 0, 0),
(35, 'Bertrand', 'Isidore', 'Traoré', NULL, 9, 0, 0, 0, 0),
(35, 'Emiliano', 'Ramiro', 'Buendía', NULL, 10, 0, 0, 0, 0),
(35, 'Ollie', NULL, 'Watkins', NULL, 11, 0, 0, 0, 0);


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(36, 'Bart', NULL, 'Verbruggen', NULL, 1, 0, 0, 0, 0),
(36, 'Tariq', 'Kwadwo', 'Lamptey', NULL, 2, 0, 0, 0, 0),
(36, 'Igor', 'Julio', 'dos Santos de Paulo', NULL, 3, 0, 0, 0, 0),
(36, 'Adam', 'David', 'Webster', NULL, 4, 0, 0, 0, 0),
(36, 'Lewis', 'Carl', 'Dunk', NULL, 5, 0, 0, 0, 0),
(36, 'James', NULL, 'Milner', NULL, 6, 0, 0, 0, 0),
(36, 'Solly', 'Shaun', 'March', NULL, 7, 0, 0, 0, 0),
(36, 'Mahmoud', NULL, 'Dahoud', NULL, 8, 0, 0, 0, 0),
(36, 'João', 'Pedro', 'Junqueira de Jesus', NULL, 9, 0, 0, 0, 0),
(36, 'Julio', 'César', 'Enciso', NULL, 10, 0, 0, 0, 0),
(36, 'Billy', 'Clifford', 'Gilmour', NULL, 11, 0, 0, 0, 0);


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(38, 'Matt', NULL, 'Turner', NULL, 1, 0, 0, 0, 0),
(38, 'Ola', null, 'Aina', NULL, 2, 0, 0, 0, 0),
(38, 'Nuno', 'Tavares', 'Oliveira', NULL, 3, 0, 0, 0, 0),
(38, 'Joe', null, 'Worrell', NULL, 4, 0, 0, 0, 0),
(38, 'Orel', NULL, 'Mangala', NULL, 5, 0, 0, 0, 0),
(38, 'Ibrahim', null, 'Sangare', NULL, 6, 0, 0, 0, 0),
(38, 'Neco', NULL, 'Williams', NULL, 7, 0, 0, 0, 0),
(38, 'Cheikhou', NULL, 'Kouyaté', NULL, 8, 0, 0, 0, 0),
(38, 'Taiwo', 'Michael', 'Awoniyi', NULL, 9, 0, 0, 0, 0),
(38, 'Morgan', NULL, 'Gibbs-White', NULL, 10, 0, 0, 0, 0),
(38, 'Chris', NULL, 'Wood', NULL, 11, 0, 0, 0, 0);



INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(39, 'Łukasz', NULL, 'Fabiański', NULL, 1, 0, 0, 0, 0),
(39, 'Ben', NULL, 'Johnson', NULL, 2, 0, 0, 0, 0),
(39, 'Aaron', NULL, 'Cresswell', NULL, 3, 0, 0, 0, 0),
(39, 'Kurt', 'Happy', 'Zouma', NULL, 4, 0, 0, 0, 0),
(39, 'Vladimír', NULL, 'Coufal', NULL, 5, 0, 0, 0, 0),
(39, 'Tomáš', NULL, 'Souček', NULL, 6, 0, 0, 0, 0),
(39, 'Saïd',null , 'Benrahma', NULL, 7, 0, 0, 0, 0),
(39, 'James', NULL, 'Ward-Prowse', NULL, 8, 0, 0, 0, 0),
(39, 'Michail', 'Gregory', 'Antonio', NULL, 9, 0, 0, 0, 0),
(39, 'Lucas', 'Tolentino Coelho', 'de Lima', NULL, 10, 0, 0, 0, 0),
(39, 'Danny', 'Owen', 'Ings', NULL, 11, 0, 0, 0, 0);


INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(40, 'Marek', NULL, 'Rodák', NULL, 1, 0, 0, 0, 0),
(40, 'Kenny', 'Jack', 'Tete', NULL, 2, 0, 0, 0, 0),
(40, 'Calvin', NULL, 'Bassey', NULL, 3, 0, 0, 0, 0),
(40, 'Tosin',null,  'Adarabioyo', NULL, 4, 0, 0, 0, 0),
(40, 'Harrison', NULL, 'Reed', NULL, 5, 0, 0, 0, 0),
(40, 'João', 'Palhinha', 'Gonçalves', NULL, 6, 0, 0, 0, 0),
(40, 'Raúl', 'Alonso', 'Jiménez', NULL, 7, 0, 0, 0, 0),
(40, 'Harry', 'Billy', 'Wilson', NULL, 8, 0, 0, 0, 0),
(40, 'Armando', null, 'Broja', NULL, 9, 0, 0, 0, 0),
(40, 'Tom', null, 'Cairney', NULL, 10, 0, 0, 0, 0),
(40, 'Adama', NULL, 'Traoré', NULL, 11, 0, 0, 0, 0);

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(41, 'Dean', NULL, 'Henderson', NULL, 1, 0, 0, 0, 0),
(41, 'Joel', 'Alan', 'Ward', NULL, 2, 0, 0, 0, 0),
(41, 'Tyrick', 'Samuel', 'Mitchell', NULL, 3, 0, 0, 0, 0),
(41, 'Rob', 'Dickie', 'Holding', NULL, 4, 0, 0, 0, 0),
(41, 'James', NULL, 'Tomkins', NULL, 5, 0, 0, 0, 0),
(41, 'Marc', NULL, 'Guéhi', NULL, 6, 0, 0, 0, 0),
(41, 'Michael', NULL, 'Olise', NULL, 7, 0, 0, 0, 0),
(41, 'Jefferson', 'Andrés', 'Lerma', NULL, 8, 0, 0, 0, 0),
(41, 'Jordan', NULL, 'Ayew', NULL, 9, 0, 0, 0, 0),
(41, 'Eberechi', 'Oluchi', 'Eze', NULL, 10, 0, 0, 0, 0),
(41, 'Matheus', 'França', 'de Oliveira', NULL, 11, 0, 0, 0, 0);

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(42, 'Matt', NULL, 'Turner', NULL, 1, 0, 0, 0, 0),
(42, 'Ola',null , 'Aina', NULL, 2, 0, 0, 0, 0),
(42, 'Nuno', 'Tavares', 'Oliveira', NULL, 3, 0, 0, 0, 0),
(42, 'Joe', null, 'Worrell', NULL, 4, 0, 0, 0, 0),
(42, 'Orel', NULL, 'Mangala', NULL, 5, 0, 0, 0, 0),
(42, 'Ibrahim', null, 'Sangare', NULL, 6, 0, 0, 0, 0),
(42, 'Neco', NULL, 'Williams', NULL, 7, 0, 0, 0, 0),
(42, 'Cheikhou', NULL, 'Kouyaté', NULL, 8, 0, 0, 0, 0),
(42, 'Taiwo', 'Michael', 'Awoniyi', NULL, 9, 0, 0, 0, 0),
(42, 'Morgan', NULL, 'Gibbs-White', NULL, 10, 0, 0, 0, 0),
(42, 'Chris', NULL, 'Wood', NULL, 11, 0, 0, 0, 0);

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
(43, 'Mark', NULL, 'Flekken', NULL, 1, 0, 0, 0, 0),
(43, 'Aaron', 'James', 'Hickey', NULL, 2, 0, 0, 0, 0),
(43, 'Rico', NULL, 'Henry', NULL, 3, 0, 0, 0, 0),
(43, 'Seán', NULL, 'Tarkowski', NULL, 4, 0, 0, 0, 0),
(43, 'Ethan', 'Rupert', 'Pinnock', NULL, 5, 0, 0, 0, 0),
(43, 'Christian', null, 'Nørgaard', NULL, 6, 0, 0, 0, 0),
(43, 'Neal', null, 'Maupay', NULL, 7, 0, 0, 0, 0),
(43, 'Mathias', null , 'Jensen', NULL, 8, 0, 0, 0, 0),
(43, 'Bryan',null , 'Mbeumo', NULL, 9, 0, 0, 0, 0),
(43, 'Josh', NULL, 'Dasilva', NULL, 10, 0, 0, 0, 0),
(43, 'Yoane', null, 'Wissa', NULL, 11, 0, 0, 0, 0);

INSERT INTO jugadores (id_equipo, nombre, nombre2, apellido, apellido2, num_camiseta, asistencias, goles, rojas, amarillas) VALUES 
 (44, 'Martin', NULL, 'Dúbravka', NULL, 1, 0, 0, 0, 0),
 (44, 'Kieran', NULL, 'Trippier', NULL, 2, 0, 0, 0, 0),
 (44, 'Paul', NULL, 'Dummett', NULL, 3, 0, 0, 0, 0),
 (44, 'Sven', NULL, 'Botman', NULL, 4, 0, 0, 0, 0),
 (44, 'Fabian', NULL, 'Schär', NULL, 5, 0, 0, 0, 0),
 (44, 'Jamaal',NULL, 'Lascelles', NULL, 6, 0, 0, 0, 0),
 (44, 'Joelinton', 'Cássio', 'Apolinário de Lira', NULL, 7, 0, 0, 0, 0),
(44, 'Sandro', NULL, 'Tonali', NULL, 8, 0, 0, 0, 0),
(44, 'Callum', NULL, 'Wilson', NULL, 9, 0, 0, 0, 0),
(44, 'Anthony', NULL, 'Gordon', NULL, 10, 0, 0, 0, 0),
(44, 'Matt', NULL, 'Ritchie', NULL, 11, 0, 0, 0, 0);


select * from jugadores where id_equipo=44;
select * from equipos where id_torneo=3;
select * from partidos where (id_torneo=5) and id_equipo1=34 or id_equipo2=34;
select * from torneo;

select j.nombre,j.apellido , e.nombre,j.goles from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo=1 order by j.goles desc limit 10;






select * from jugadores;
select * from equipos;

select j.nombre,j.apellido , e.nombre,j.goles from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo=1 order by j.goles desc limit 10;
select j.nombre,j.apellido , e.nombre,j.asistencias from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo=5 order by j.asistencias desc limit 10;
select j.nombre,j.apellido , e.nombre,j.rojas from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo=5 order by j.rojas desc limit 10;
select j.nombre,j.apellido , e.nombre,j.amarillas from jugadores j inner join equipos e on e.id_equipos=j.id_equipo where e.id_torneo=5 order by j.amarillas desc limit 10;
select e.nombre, sum(goles) as 'golesTotales' from equipos e inner join torneo t on e.id_torneo=t.id_torneos inner join jugadores j on e.id_equipos=j.id_equipo where e.id_torneo=1 group by e.nombre order by golesTotales desc;
select nombre, cant_participantes, fecha_inicio, fecha_fin from torneo where id_torneos=1;
select e.nombre, j.nombre, j.apellido, j.num_camiseta from equipos e inner join jugadores j on e.id_equipos=j.id_equipo where e.final='C' and e.id_torneo=1 order by j.goles desc , j.asistencias desc limit 1;



select e.nombre, t.nombre, e.id_equipos from equipos e  join torneo t on e.id_torneo=t.id_torneos where e.nombre='Boca Juniors';

use torneos;
select * from torneo;
select * from equipos;
select * from jugadores;
select * from partidos;
select j.nombre,j.num_camiseta,e.nombre,e.id_equipos from equipos e inner join jugadores j on e.id_equipos=j.id_equipo;

delete from jugadores where id_equipo>0;

update partidos set resultado='0-1' where id_partidos=65;


SELECT * FROM equipos where id_torneo=5;
SELECT * FROM jugadores WHERE id_equipo =1;

delete from torneo where id_torneos=4;
select * from torneo;
select e.nombre, j.nombre, j.apellido, j.num_camiseta from equipos e inner join jugadores j on e.id_equipos=j.id_equipo where e.final='C' order by j.goles desc , j.asistencias desc limit 1;

select * from partidos where id_torneo=5;
update partidos  set resultado=null where id_partidos=80;



select count(*) from torneo where id_torneos=1;
select * from partidos where id_equipo1=1 or id_equipo2=1;

select * from partidos where id_torneo=2;

update partidos set num_partido=5 where id_partidos=100;

select count(*) from partidos where id_torneo=4 and estado='Finalizado';


