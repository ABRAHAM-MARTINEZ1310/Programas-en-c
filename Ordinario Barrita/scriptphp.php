
//db.php
<?php
$servername = "localhost";
$username = "root";
$password = "Casagato123#";
$dbname = "mezcal";

// Crear conexión
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificar conexión
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>

//delete.php
<?php
include 'db.php';

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql = "DELETE FROM productor WHERE idProductor = $id";

    if ($conn->query($sql) === TRUE) {
        header("Location: index.php");
        exit();
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
?>



//index.php
<?php
include 'db.php';
$result = $conn->query("SELECT * FROM productor");
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Productores de Mezcal</title>
</head>
<body>
    <h1>CRUD Productores de Mezcal</h1>

    <form action="insert.php" method="POST">
        <h2>Agregar Productor</h2>
        <label>Nombre:</label>
        <input type="text" name="nombre" required><br>

        <label>Dirección:</label>
        <input type="text" name="direccion" required><br>

        <label>Año de fundación:</label>
        <input type="number" name="año_fundacion" required><br>

        <label>Grupo dueño:</label>
        <input type="text" name="grupo_dueño" required><br>

        <input type="submit" value="Agregar Productor">
    </form>

    <hr>

    <h2>Lista de Productores</h2>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Nombre</th>
            <th>Dirección</th>
            <th>Año</th>
            <th>Grupo</th>
            <th>Acciones</th>
        </tr>
        <?php while($row = $result->fetch_assoc()): ?>
        <tr>
            <td><?= $row['idProductor'] ?></td>
            <td><?= $row['nombre'] ?></td>
            <td><?= $row['direccion'] ?></td>
            <td><?= $row['año_fundacion'] ?></td>
            <td><?= $row['grupo_dueño'] ?></td>
            <td>
                <a href="update.php?id=<?= $row['idProductor'] ?>">Editar</a>
                <a href="delete.php?id=<?= $row['idProductor'] ?>" onclick="return confirm('¿Eliminar este productor?')">Eliminar</a>
            </td>
        </tr>
        <?php endwhile; ?>
    </table>
</body>
</html>

//insert.php 

<?php
include 'db.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nombre = $_POST['nombre'];
    $direccion = $_POST['direccion'];
    $año = $_POST['año_fundacion'];
    $grupo = $_POST['grupo_dueño'];

    $sql = "INSERT INTO productor (nombre, direccion, año_fundacion, grupo_dueño)
            VALUES ('$nombre', '$direccion', '$año', '$grupo')";

    if ($conn->query($sql) === TRUE) {
        header("Location: index.php");
        exit();
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
?>


//update.php


<?php
include 'db.php';

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $res = $conn->query("SELECT * FROM productor WHERE idProductor = $id");
    $row = $res->fetch_assoc();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST['id'];
    $nombre = $_POST['nombre'];
    $direccion = $_POST['direccion'];
    $año = $_POST['año_fundacion'];
    $grupo = $_POST['grupo_dueño'];

    $sql = "UPDATE productor SET nombre='$nombre', direccion='$direccion', año_fundacion='$año', grupo_dueño='$grupo' WHERE idProductor=$id";

    if ($conn->query($sql) === TRUE) {
        header("Location: index.php");
        exit();
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Editar Productor</title>
</head>
<body>
    <h1>Editar Productor</h1>
    <form action="update.php" method="POST">
        <input type="hidden" name="id" value="<?= $row['idProductor'] ?>">
        <label>Nombre:</label>
        <input type="text" name="nombre" value="<?= $row['nombre'] ?>" required><br>

        <label>Dirección:</label>
        <input type="text" name="direccion" value="<?= $row['direccion'] ?>" required><br>

        <label>Año de fundación:</label>
        <input type="number" name="año_fundacion" value="<?= $row['año_fundacion'] ?>" required><br>

        <label>Grupo dueño:</label>
        <input type="text" name="grupo_dueño" value="<?= $row['grupo_dueño'] ?>" required><br>

        <input type="submit" value="Actualizar Productor">
    </form>
</body>
</html>
