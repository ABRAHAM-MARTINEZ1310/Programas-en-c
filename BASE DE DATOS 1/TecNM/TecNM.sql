
CREATE DATABASE TecNM;
USE TecNM;

CREATE TABLE Director (
	idDirector INT AUTO_INCREMENT PRIMARY KEY,
    Nombre VARCHAR(45),
    Edad INT,
    Profesion VARCHAR(45),
    Email VARCHAR(45),
    Telefono VARCHAR(45),
    Fecha_inicio_cargo DATE
);

CREATE TABLE Carrera (
	idCarrera INT AUTO_INCREMENT PRIMARY KEY,
    Nombre VARCHAR(100),
    Semestres_cursar INT,
    Num_materias_acreditar INT,
    Año_planestudio DATE
);

CREATE TABLE Institucion (
	idInstitucion INT AUTO_INCREMENT PRIMARY KEY,
    Nombre_del_campus VARCHAR(100),
	Direccion_plantel VARCHAR(100),
    Ubicacion_latitud FLOAT,
    Ubicacion_longitud FLOAT,
    idDirector INT,
    FOREIGN KEY(idDirector) REFERENCES Director(idDirector)
);

CREATE TABLE Carreras_institucion (
	idInstitucion INT,
    idCarrera INT,
    PRIMARY KEY (idInstitucion, idCarrera),
    FOREIGN KEY(idInstitucion) REFERENCES Institucion(idInstitucion),
    FOREIGN KEY(idCarrera) REFERENCES Carrera(idCarrera)
);
INSERT INTO Director (Nombre, Edad, Profesion, Email, Telefono, Fecha_inicio_cargo) VALUES
('Dr. Juan Cruz Nieto', 52, 'Ingeniero Industrial', 'juan.cruz@itoaxaca.edu.mx', '9515015016', '2018-04-18'),
('M.C. Sergio Fernando Garibay Armenta', 48, 'Ingeniero Agrónomo', 'sergio.garibay@itvoaxaca.edu.mx', '9515170444', '2019-06-14'),
('Ing. María López Hernández', 45, 'Ingeniera Civil', 'maria.lopez@itistmo.edu.mx', '9711234567', '2020-01-15'),
('Dr. Carlos Pérez Ramírez', 50, 'Ingeniero Electrónico', 'carlos.perez@ittux.edu.mx', '2871234567', '2017-09-01'),
('Mtra. Ana Gómez Sánchez', 47, 'Administradora', 'ana.gomez@itpinotepa.edu.mx', '9541234567', '2016-03-10'),
('Ing. Luis Martínez Díaz', 49, 'Ingeniero Mecánico', 'luis.martinez@itputla.edu.mx', '9531234567', '2015-05-20'),
('M.C. Patricia Torres Ruiz', 46, 'Ingeniera Química', 'patricia.torres@itmixteca.edu.mx', '9511234567', '2014-11-30'),
('Dr. Jorge Hernández Silva', 51, 'Ingeniero en Sistemas', 'jorge.hernandez@itcuicatlan.edu.mx', '9517654321', '2013-08-25'),
('Ing. Rosa María Jiménez', 44, 'Ingeniera Ambiental', 'rosa.jimenez@itocotlan.edu.mx', '9512345678', '2012-07-12'),
('Mtra. Elena Rodríguez Vázquez', 48, 'Contadora Pública', 'elena.rodriguez@itmatias.edu.mx', '9518765432', '2011-02-18');


INSERT INTO Institucion (Nombre_del_campus, Direccion_plantel, Ubicacion_latitud, Ubicacion_longitud, idDirector) VALUES
('Instituto Tecnológico de Oaxaca', 'Av. Ing. Víctor Bravo Ahuja No. 125, Oaxaca de Juárez, Oaxaca', 17.073184, -96.726588, 1),
('Instituto Tecnológico del Valle de Oaxaca', 'Carretera Oaxaca - Puerto Ángel km. 11.5, San Pablo Huixtepec, Oaxaca', 16.883333, -96.75, 2),
('Instituto Tecnológico del Istmo', 'Carretera Panamericana km. 2.5, Juchitán de Zaragoza, Oaxaca', 16.437778, -95.016667, 3),
('Instituto Tecnológico de Tuxtepec', 'Av. Tecnológico s/n, Col. La Esperanza, Tuxtepec, Oaxaca', 18.088611, -96.125, 4),
('Instituto Tecnológico de Pinotepa', 'Carretera Pinotepa - Acapulco km. 2, Pinotepa Nacional, Oaxaca', 16.341111, -98.059444, 5),
('Instituto Tecnológico de Putla', 'Carretera Putla - Tlaxiaco km. 1, Putla Villa de Guerrero, Oaxaca', 17.033333, -97.933333, 6),
('Instituto Tecnológico de la Mixteca', 'Cerro de las Flores s/n, Huajuapan de León, Oaxaca', 17.8, -97.783333, 7),
('Instituto Tecnológico de Cuicatlán', 'Carretera Cuicatlán - Teotitlán km. 1, Cuicatlán, Oaxaca', 17.8, -96.9, 8),
('Instituto Tecnológico de Ocotlán', 'Carretera Ocotlán - Ejutla km. 1, Ocotlán de Morelos, Oaxaca', 16.8, -96.7, 9),
('Instituto Tecnológico de San Juan Bautista Tuxtepec', 'Av. Tecnológico s/n, Col. La Esperanza, Tuxtepec, Oaxaca', 18.088611, -96.125, 10);


INSERT INTO Carrera (Nombre, Semestres_cursar, Num_materias_acreditar, Año_planestudio) VALUES
('Ingeniería Civil', 9, 54, '2020-08-01'),
('Ingeniería en Gestión Empresarial', 9, 50, '2021-08-01'),
('Ingeniería Electrónica', 9, 52, '2019-08-01'),
('Ingeniería Eléctrica', 9, 51, '2018-08-01'),
('Ingeniería Mecánica', 9, 53, '2020-08-01'),
('Ingeniería Industrial', 9, 55, '2021-08-01'),
('Ingeniería Química', 9, 52, '2019-08-01'),
('Ingeniería en Sistemas Computacionales', 9, 56, '2020-08-01'),
('Licenciatura en Administración', 8, 48, '2018-08-01'),
('Ingeniería en Agronomía', 9, 50, '2021-08-01'),
('Ingeniería en Informática', 9, 54, '2020-08-01'),
('Ingeniería en Tecnologías de la Información y Comunicaciones', 9, 55, '2021-08-01');

INSERT INTO Carreras_institucion (idInstitucion, idCarrera) VALUES
(11, 13),
(11, 14),
(11, 15),
(12, 22),
(12, 21),
(12, 14),
(13, 13),
(13, 16),
(13, 18),
(14, 13),
(14, 17),
(14, 19),
(15, 22),
(15, 21),
(15, 14),
(16, 13),
(16, 16),
(16, 18),
(17, 15),
(17, 20),
(17, 23),
(18, 22),
(18, 21),
(18, 14),
(19, 13),
(19, 16),
(19, 18),
(20, 13),
(20, 17),
(20, 19);
