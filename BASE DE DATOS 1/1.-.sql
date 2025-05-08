CREATE DATABASE tienda;
USE tienda;

CREATE TABLE fabricante (
id INT UNSIGNED auto_increment PRIMARY KEY,
nombre VARCHAR(100) NOT NULL
);

CREATE TABLE producto (
id INT UNSIGNED auto_increment PRIMARY KEY,
nombre VARCHAR(100) NOT NULL,
precio DECIMAL (10,2),
id_fabricante INT UNSIGNED NOT NULL,
FOREIGN KEY (id_fabricante ) REFERENCES fabricante(id)
);


INSERT INTO fabricante (nombre) VALUES 
('Samsung'),
('Apple'),
('Sony'),
('LG'),
('Huawei'),
('Nokia'),
('Xiaomi'),
('Microsoft'),
('Dell'),
('Lenovo');


INSERT INTO producto (nombre, precio, id_fabricante) VALUES
('Galaxy S21', 799.99, 1),  -- Samsung
('iPhone 13', 999.99, 2),   -- Apple
('PlayStation 5', 499.99, 3),  -- Sony
('LG OLED TV', 1999.99, 4),  -- LG
('Huawei P40', 699.99, 5),  -- Huawei
('Nokia 8.3', 449.99, 6),  -- Nokia
('Xiaomi Mi 11', 749.99, 7),  -- Xiaomi
('Microsoft Surface Laptop', 1299.99, 8),  -- Microsoft
('Dell XPS 13', 1399.99, 9),  -- Dell
('Lenovo ThinkPad', 1199.99, 10);  -- Lenovo



 select nombre FROM producto WHERE precio > 1000;


 select p.nombre AS producto, f.nombre AS fabricante from producto p
    join fabricante f ON p.id_fabricante  = f.id
    order by nombre.precio DESC;

 select p.nombre AS producto, f.nombre AS fabricante, p.precio  from producto p
    join fabricante f ON p.id_fabricante  = f.id
     where p.precio between 800 and 1000;


     mysql> select count(*)AS total_productos FROM producto;


 select avg(precio) as precio_promedio from producto;

     select count(*)AS total_productos FROM producto where precio > 800 ;


     select f.nombre AS fabricante, count(p.id) AS total_producto from fabricante f
    LEFT JOIN producto p ON f.id = p.id_fabricante
    GROUP BY f.id;

    INSERT INTO producto (nombre, precio, id_fabricante) VALUES
('Galaxy S21', 799.99, 1),

INSERt INTO producto (nombre,precio,id_fabricante)VALUES
    ('Samsumg Galaxy A55',7000,1);
      --limit dice el numero de resultados que quieres ver 
    select p.nombre as producto , p.precio from producto p order by precio asc limit 1;


    select * from producto where nombre like'i%';    --para el incio poner el porcentaje al final 

     select * from producto where nombre like'%1';  --para el final  poner el porcentaje al incio


     select * from producto where nombre like'%a%';  --al inicio y al final muesttra en cualquier posicion


     UPdate producto set nombre= 'Ip x' where id = 2 ;

     delete from producto where id=2;


      AlTER TABLE fabricante CHANGE COLUMN nombre name VARCHAR(100) NOT NULL;