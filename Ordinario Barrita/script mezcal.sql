CREATE DATABASE mezcal;
USE mezcal;

-- Tabla productor
CREATE TABLE productor (
    idProductor INT AUTO_INCREMENT PRIMARY KEY, 
    nombre VARCHAR(30),
    direccion VARCHAR(150),
    año_fundacion YEAR,
    grupo_dueño VARCHAR(30)
);

-- Tabla mezcal
CREATE TABLE mezcal (
    idMezcal INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(30),
    tipo_agave VARCHAR(30),
    grado_alcohol DECIMAL(5,2),
    idProductor INT,
    FOREIGN KEY(idProductor) REFERENCES productor(idProductor)
);

-- Tabla certificado
CREATE TABLE certificado (
    idCertificado INT AUTO_INCREMENT PRIMARY KEY,
    nombre_certificado VARCHAR(45),
    entidad_emisora VARCHAR(45),
    fecha_expedido DATE    
);

-- Tabla puente productor_certificado
CREATE TABLE productor_certificado (
    idProductor_certificados INT AUTO_INCREMENT PRIMARY KEY,
    idProductor INT,
    idCertificado INT,
    FOREIGN KEY(idProductor) REFERENCES productor(idProductor),
    FOREIGN KEY(idCertificado) REFERENCES certificado(idCertificado)
);

-- INSERTS para tabla productor
INSERT INTO productor (nombre, direccion, año_fundacion, grupo_dueño) VALUES
('Mezcal Los Magueyes', 'Carretera Internacional 190, Santiago Matatlán, Oaxaca', 1995, 'Grupo Maguey'),
('Casa del Agave', 'Camino Real s/n, San Dionisio Ocotepec, Oaxaca', 2002, 'AgaveCorp'),
('Espíritu del Valle', 'Calle Independencia 43, Tlacolula de Matamoros, Oaxaca', 1980, 'Mezcaleros Unidos'),
('Don Benito', 'Barrio La Mina, Santa Catarina Minas, Ocotlán, Oaxaca', 1975, 'Independiente'),
('Mezcal Real', 'Calle Benito Juárez 17, Miahuatlán de Porfirio Díaz, Oaxaca', 2005, 'Grupo Real'),
('Monte Sagrado', 'Carretera a San Juan del Río km 3, Oaxaca', 1990, 'Sierra Alta'),
('Palenque Aurora', 'Camino a El Progreso, Ejutla de Crespo, Oaxaca', 1987, 'Familia Aurora'),
('Flor de Agave', 'Calle 5 de Mayo 12, San Pablo Villa de Mitla, Oaxaca', 2010, 'FlorAgave Inc.'),
('Sabores de Oaxaca', 'Centro, Ocotlán de Morelos, Oaxaca', 2008, 'Consorcio Oaxaca'),
('Agave Dorado', 'Av. Hidalgo 100, San Pedro Totolápam, Oaxaca', 1998, 'Grupo Dorado');

-- INSERTS para tabla mezcal
INSERT INTO mezcal (nombre, tipo_agave, grado_alcohol, idProductor) VALUES
('Espadín Clásico', 'Espadín', 40.00, 1),
('Tobalá Premium', 'Tobalá', 42.50, 2),
('Cuishe Artesanal', 'Cuishe', 43.00, 3),
('Mezcal Joven', 'Espadín', 38.00, 4),
('Reposado de Oro', 'Espadín', 39.00, 5),
('Añejo Místico', 'Tobalá', 44.00, 6),
('Flor de Espadín', 'Espadín', 40.50, 7),
('Silvestre Selecto', 'Cuishe', 41.00, 8),
('Blanco Suave', 'Espadín', 37.50, 9),
('Cristalino', 'Tobalá', 43.50, 10);

-- INSERTS para tabla certificado
INSERT INTO certificado (nombre_certificado, entidad_emisora, fecha_expedido) VALUES
('Norma Oficial Mexicana NOM-070-SCFI-2016', 'Consejo Regulador del Mezcal', '2017-05-01'),
('Certificación Orgánica', 'Certimex', '2019-07-15'),
('Fair Trade', 'Fair Trade USA', '2020-03-20'),
('Kosher', 'KMD Latinoamérica', '2021-01-10'),
('ISO 9001', 'Organismo Internacional de Normalización', '2018-10-01'),
('Certificación Artesanal', 'Secretaría de Economía', '2022-04-12'),
('Denominación de Origen', 'IMPI', '2016-08-23'),
('Distintivo "Hecho en Oaxaca"', 'Gobierno de Oaxaca', '2023-02-28'),
('Sello Mujer Productora', 'INMUJERES', '2021-11-11'),
('Calidad Suprema', 'SAGARPA', '2018-06-30');

-- INSERTS para tabla productor_certificado
INSERT INTO productor_certificado (idProductor, idCertificado) VALUES
(1, 1),
(1, 2),
(2, 3),
(3, 4),
(4, 5),
(5, 6),
(6, 7),
(7, 8),
(8, 9),
(9, 10);
