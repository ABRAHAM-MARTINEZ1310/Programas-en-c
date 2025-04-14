create database Ismael;
create table ESTUDIANTES (
id INT PRIMARY KEY,
nombre VARCHAR(50),
edad INT
);
insert into ESTUDIANTES(id,nombre,edad)
values (1,'Ana',20);

insert into ESTUDIANTES(id,nombre,edad)
values (2,'Pedro',40);

select *FROM ESTUDIANTES;

SELECT nombre FROM ESTUDIANTES WHERE edad=20;

insert into ESTUDIANTES(id,nombre,edad)
values (1,'Abraham',18),
		(2,'Sergio',19),
        (3,'Kevin',20),
        (4,'Cesar',18),
        (5,'David',21)
;
SELECT nombre,edad FROM ESTUDIANTES WHERE edad>=17 & edad<=19;
