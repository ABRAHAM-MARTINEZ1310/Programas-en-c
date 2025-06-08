<?php
$servername ="localhost";
$username = "root";
$password = "Casagato123#";
$dbname = "zachila";

//crear la conexion
$conn = new mysqli($servername, $username, $password, $dbname);

//verificar la conexion
if ($conn->connect_error){
    die("Connection failed: ") . $conn->connect_error;
}
?>
