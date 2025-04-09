create table empleados(
    numero int not null,
    nombre varchar (50),
    salario float (6,2) zerofill, //rellena ceros a la izquierda
    categoria char (30),
    sexo enum ("M","F"),
    departamento char(2),
    primary key (numero))
    ENGINE=innoDB; 

    create table departamentos(
        codigo char(2) not null,
        nombre varchar(50) not null,
        primary key (codigo)
    )
    ENGINE= innoDB;