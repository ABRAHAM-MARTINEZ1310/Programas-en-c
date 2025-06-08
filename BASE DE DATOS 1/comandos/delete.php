<?php
include 'db.php';

if(isset($_GET['id'])){
    $id = $_GET['id'];
    $sql = "DELETE FROM autobus WHERE id_autobus = $id";

    if($conn->query($sql) === TRUE){
        echo "Autobus eliminado exitosamente.";
     } else{
            echo"Error: " . $sql . "<br>" . $conn->error;
        }
    header("Location: index.php");
    exit();
    }
?>