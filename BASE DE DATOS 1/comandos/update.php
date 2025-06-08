<?php
include 'db.php';
 
if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $result = $conn->query("SELECT * FROM autobus WHERE id_autobus = $id");
    $row = $result->fetch_assoc();
}
 
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $placa = $_POST['placa'];
    $modelo = $_POST['modelo'];
    $capacidad = $_POST['capacidad'];
 
    $sql = "UPDATE autobus SET placa='$placa', modelo='$modelo', capacidad='$capacidad' WHERE id_autobus=$id";
 
    if ($conn->query($sql) === TRUE) {
        echo "Autobús actualizado exitosamente.";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
 
    header("Location: index.php");  // Redirigir a la página principal después de actualizar.
    exit();
}
?>
 
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Actualizar Autobús</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <h1>Actualizar Autobús</h1>
    <form action="update.php?id=<?php echo $id; ?>" method="POST" id="formUpdate">
        <label for="placa">Placa:</label>
        <input type="text" name="placa" value="<?php echo $row['placa']; ?>" required>
        <br>
        <label for="modelo">Modelo:</label>
        <input type="text" name="modelo" value="<?php echo $row['modelo']; ?>" required>
        <br>
        <label for="capacidad">Capacidad:</label>
        <input type="number" name="capacidad" value="<?php echo $row['capacidad']; ?>" required>
        <br>
        <input type="submit" value="Actualizar Autobús">
    </form>
</body>
</html> 