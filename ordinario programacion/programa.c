#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Conexión global
MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

// ============================
// Prototipos de funciones
// ============================

void conectar();
void menu_fabricante();
void menu_distribuidor();
void menu_cliente();
void menu_mueble();
void menu_cocina();
void menu_montador();
void menu_fabricante_distribuidor();

// ============================
// Función de conexión
// ============================

void conectar() {
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Error al inicializar MySQL\n");
        exit(1);
    }

    // Ruta de socket específica para XAMPP
    if (mysql_real_connect(conn, "localhost", "root", "", "venta_cocinas", 0, "/opt/lampp/var/mysql/mysql.sock", 0) == NULL) {
        fprintf(stderr, "Error de conexión: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }
}

// ============================
// CRUD de fabricante
// ============================

void insertar_fabricante() {
    char nombre[50], direccion[150], telefono[50];
    printf("Nombre: "); fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");
    printf("Dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");

    char query[512];
    sprintf(query,
        "INSERT INTO fabricante (nombre, direccion, telefono) VALUES ('%s', '%s', '%s')",
        nombre, direccion, telefono);

    if (mysql_query(conn, query) == 0)
        printf("✔ Fabricante insertado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}

void ver_fabricantes() {
    if (mysql_query(conn, "SELECT * FROM fabricante") != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-20s %-40s %-15s\n", "ID", "Nombre", "Dirección", "Teléfono");
    printf("--------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-20s %-40s %-15s\n", row[0], row[1], row[2], row[3]);
    }
    mysql_free_result(res);
}

void actualizar_fabricante() {
    char id[10];
    printf("ID del fabricante a actualizar: ");
    fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char nombre[50], direccion[150], telefono[50];
    printf("Nuevo nombre: "); fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");
    printf("Nueva dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Nuevo teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");

    char query[512];
    sprintf(query,
        "UPDATE fabricante SET nombre='%s', direccion='%s', telefono='%s' WHERE idfabricante=%s",
        nombre, direccion, telefono, id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Fabricante actualizado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al actualizar: %s\n", mysql_error(conn));
}

void eliminar_fabricante() {
    char id[10];
    printf("ID del fabricante a eliminar: ");
    fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM fabricante WHERE idfabricante=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Fabricante eliminado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}

void menu_fabricante() {
    int opcion;
    do {
        printf("\n--- MENÚ FABRICANTE ---\n");
        printf("1. Insertar fabricante\n");
        printf("2. Ver fabricantes\n");
        printf("3. Actualizar fabricante\n");
        printf("4. Eliminar fabricante\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_fabricante(); break;
            case 2: ver_fabricantes(); break;
            case 3: actualizar_fabricante(); break;
            case 4: eliminar_fabricante(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}



void insertar_distribuidor() {
    char nombre[50], direccion[150], telefono[50];
    printf("Nombre: "); fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");
    printf("Dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");

    char query[512];
    sprintf(query,
        "INSERT INTO distribuidor (nombre, direccion, telefono) VALUES ('%s', '%s', '%s')",
        nombre, direccion, telefono);

    if (mysql_query(conn, query) == 0)
        printf("✔ Distribuidor insertado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}

void ver_distribuidores() {
    if (mysql_query(conn, "SELECT * FROM distribuidor") != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-20s %-40s %-15s\n", "ID", "Nombre", "Dirección", "Teléfono");
    printf("--------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-20s %-40s %-15s\n", row[0], row[1], row[2], row[3]);
    }
    mysql_free_result(res);
}

void actualizar_distribuidor() {
    char id[10];
    printf("ID del distribuidor a actualizar: ");
    fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char nombre[50], direccion[150], telefono[50];
    printf("Nuevo nombre: "); fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");
    printf("Nueva dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Nuevo teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");

    char query[512];
    sprintf(query,
        "UPDATE distribuidor SET nombre='%s', direccion='%s', telefono='%s' WHERE iddistribuidor=%s",
        nombre, direccion, telefono, id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Distribuidor actualizado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al actualizar: %s\n", mysql_error(conn));
}

void eliminar_distribuidor() {
    char id[10];
    printf("ID del distribuidor a eliminar: ");
    fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM distribuidor WHERE iddistribuidor=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Distribuidor eliminado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}
void insertar_cliente() {
    char nif[14], direccion[150], telefono[50];
    printf("NIF: "); fgets(nif, sizeof(nif), stdin); strtok(nif, "\n");
    printf("Dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");

    char query[512];
    sprintf(query,
        "INSERT INTO cliente (nif, direccion, telefono) VALUES ('%s', '%s', '%s')",
        nif, direccion, telefono);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cliente insertado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}

void ver_clientes() {
    if (mysql_query(conn, "SELECT * FROM cliente") != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-15s %-40s %-15s\n", "ID", "NIF", "Dirección", "Teléfono");
    printf("--------------------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-15s %-40s %-15s\n", row[0], row[1], row[2], row[3]);
    }
    mysql_free_result(res);
}

void actualizar_cliente() {
    char id[10];
    printf("ID del cliente a actualizar: ");
    fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char nif[14], direccion[150], telefono[50];
    printf("Nuevo NIF: "); fgets(nif, sizeof(nif), stdin); strtok(nif, "\n");
    printf("Nueva dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Nuevo teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");

    char query[512];
    sprintf(query,
        "UPDATE cliente SET nif='%s', direccion='%s', telefono='%s' WHERE idcliente=%s",
        nif, direccion, telefono, id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cliente actualizado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al actualizar: %s\n", mysql_error(conn));
}

void eliminar_cliente() {
    char id[10];
    printf("ID del cliente a eliminar: ");
    fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM cliente WHERE idcliente=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cliente eliminado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}

void insertar_cocina() {
    char num_total[10], num_tipo[10], iddistribuidor[10], fecha[20];

    printf("Número total de muebles: "); fgets(num_total, sizeof(num_total), stdin); strtok(num_total, "\n");
    printf("Número de muebles de un tipo: "); fgets(num_tipo, sizeof(num_tipo), stdin); strtok(num_tipo, "\n");
    printf("ID del distribuidor (debe existir): "); fgets(iddistribuidor, sizeof(iddistribuidor), stdin); strtok(iddistribuidor, "\n");
    printf("Fecha de venta (YYYY-MM-DD): "); fgets(fecha, sizeof(fecha), stdin); strtok(fecha, "\n");

    char query[512];
    sprintf(query,
        "INSERT INTO cocina (num_muebles_total, num_muebles_tipo, iddistribuidor, fecha_venta) "
        "VALUES (%s, %s, %s, '%s')",
        num_total, num_tipo, iddistribuidor, fecha);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cocina insertada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}

void ver_cocinas() {
    const char* query =
        "SELECT c.idcocina, c.num_muebles_total, c.num_muebles_tipo, c.fecha_venta, d.nombre "
        "FROM cocina c LEFT JOIN distribuidor d ON c.iddistribuidor = d.iddistribuidor";

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-10s %-10s %-12s %-20s\n", "ID", "Total", "Tipo", "Fecha", "Distribuidor");
    printf("-------------------------------------------------------------\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-10s %-10s %-12s %-20s\n",
               row[0], row[1], row[2], row[3], row[4] ? row[4] : "N/A");
    }
    mysql_free_result(res);
}

void actualizar_cocina() {
    char id[10], num_total[10], num_tipo[10], iddistribuidor[10], fecha[20];

    printf("ID de la cocina a actualizar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");
    printf("Nuevo número total de muebles: "); fgets(num_total, sizeof(num_total), stdin); strtok(num_total, "\n");
    printf("Nuevo número de muebles de un tipo: "); fgets(num_tipo, sizeof(num_tipo), stdin); strtok(num_tipo, "\n");
    printf("Nuevo ID del distribuidor: "); fgets(iddistribuidor, sizeof(iddistribuidor), stdin); strtok(iddistribuidor, "\n");
    printf("Nueva fecha de venta (YYYY-MM-DD): "); fgets(fecha, sizeof(fecha), stdin); strtok(fecha, "\n");

    char query[512];
    sprintf(query,
        "UPDATE cocina SET num_muebles_total=%s, num_muebles_tipo=%s, iddistribuidor=%s, fecha_venta='%s' WHERE idcocina=%s",
        num_total, num_tipo, iddistribuidor, fecha, id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cocina actualizada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al actualizar: %s\n", mysql_error(conn));
}

void eliminar_cocina() {
    char id[10];
    printf("ID de la cocina a eliminar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM cocina WHERE idcocina=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cocina eliminada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}
void insertar_mueble_de_cocina() {
    char idfabricante[10], idcocina[10], linea[50], color[50], tipo_encimera[50], categoria[50];
    char ancho[15], largo[15], alto[15], altura_suelo[15];

    printf("ID del fabricante: "); fgets(idfabricante, sizeof(idfabricante), stdin); strtok(idfabricante, "\n");
    printf("ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");
    printf("Línea: "); fgets(linea, sizeof(linea), stdin); strtok(linea, "\n");
    printf("Color: "); fgets(color, sizeof(color), stdin); strtok(color, "\n");
    printf("Ancho (decimal): "); fgets(ancho, sizeof(ancho), stdin); strtok(ancho, "\n");
    printf("Largo (decimal): "); fgets(largo, sizeof(largo), stdin); strtok(largo, "\n");
    printf("Alto (decimal): "); fgets(alto, sizeof(alto), stdin); strtok(alto, "\n");
    printf("Altura desde el suelo (decimal): "); fgets(altura_suelo, sizeof(altura_suelo), stdin); strtok(altura_suelo, "\n");
    printf("Tipo de encimera: "); fgets(tipo_encimera, sizeof(tipo_encimera), stdin); strtok(tipo_encimera, "\n");
    printf("Categoría: "); fgets(categoria, sizeof(categoria), stdin); strtok(categoria, "\n");

    char query[800];
    sprintf(query,
        "INSERT INTO mueble_de_cocina (idfabricante, idcocina, linea, color, ancho, largo, alto, altura_suelo, tipo_encimera, categoria) "
        "VALUES (%s, %s, '%s', '%s', %s, %s, %s, %s, '%s', '%s')",
        idfabricante, idcocina, linea, color, ancho, largo, alto, altura_suelo, tipo_encimera, categoria);

    if (mysql_query(conn, query) == 0)
        printf("✔ Mueble de cocina insertado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}
void ver_muebles_de_cocina() {
    const char* query =
        "SELECT m.idmueble_de_cocina, f.nombre, c.idcocina, m.linea, m.color, m.ancho, m.largo, m.alto, m.altura_suelo, m.tipo_encimera, m.categoria "
        "FROM mueble_de_cocina m "
        "LEFT JOIN fabricante f ON m.idfabricante = f.idfabricante "
        "LEFT JOIN cocina c ON m.idcocina = c.idcocina";

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-20s %-8s %-10s %-10s %-7s %-7s %-7s %-10s %-15s %-10s\n", 
           "ID", "Fabricante", "Cocina", "Línea", "Color", "Ancho", "Largo", "Alto", "Alt. Suelo", "Encimera", "Categoría");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-20s %-8s %-10s %-10s %-7s %-7s %-7s %-10s %-15s %-10s\n",
               row[0], row[1] ? row[1] : "N/A", row[2], row[3], row[4], row[5], row[6],
               row[7], row[8], row[9], row[10]);
    }
    mysql_free_result(res);
}
void actualizar_mueble_de_cocina() {
    char id[10], idfabricante[10], idcocina[10], linea[50], color[50], tipo_encimera[50], categoria[50];
    char ancho[15], largo[15], alto[15], altura_suelo[15];

    printf("ID del mueble a actualizar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");
    printf("Nuevo ID del fabricante: "); fgets(idfabricante, sizeof(idfabricante), stdin); strtok(idfabricante, "\n");
    printf("Nuevo ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");
    printf("Nueva línea: "); fgets(linea, sizeof(linea), stdin); strtok(linea, "\n");
    printf("Nuevo color: "); fgets(color, sizeof(color), stdin); strtok(color, "\n");
    printf("Nuevo ancho: "); fgets(ancho, sizeof(ancho), stdin); strtok(ancho, "\n");
    printf("Nuevo largo: "); fgets(largo, sizeof(largo), stdin); strtok(largo, "\n");
    printf("Nuevo alto: "); fgets(alto, sizeof(alto), stdin); strtok(alto, "\n");
    printf("Nueva altura desde el suelo: "); fgets(altura_suelo, sizeof(altura_suelo), stdin); strtok(altura_suelo, "\n");
    printf("Nuevo tipo de encimera: "); fgets(tipo_encimera, sizeof(tipo_encimera), stdin); strtok(tipo_encimera, "\n");
    printf("Nueva categoría: "); fgets(categoria, sizeof(categoria), stdin); strtok(categoria, "\n");

    char query[800];
    sprintf(query,
        "UPDATE mueble_de_cocina SET idfabricante=%s, idcocina=%s, linea='%s', color='%s', ancho=%s, largo=%s, alto=%s, altura_suelo=%s, tipo_encimera='%s', categoria='%s' "
        "WHERE idmueble_de_cocina=%s",
        idfabricante, idcocina, linea, color, ancho, largo, alto, altura_suelo, tipo_encimera, categoria, id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Mueble actualizado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al actualizar: %s\n", mysql_error(conn));
}
void eliminar_mueble_de_cocina() {
    char id[10];
    printf("ID del mueble de cocina a eliminar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM mueble_de_cocina WHERE idmueble_de_cocina=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Mueble eliminado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}

void insertar_montador() {
    char nif[14], nombre[50], direccion[150], telefono[50], num_cocinas[10];
    printf("NIF: "); fgets(nif, sizeof(nif), stdin); strtok(nif, "\n");
    printf("Nombre: "); fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");
    printf("Dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");
    printf("Número de cocinas montadas: "); fgets(num_cocinas, sizeof(num_cocinas), stdin); strtok(num_cocinas, "\n");

    char query[512];
    sprintf(query,
        "INSERT INTO montador (nif, nombre, direccion, telefono, num_cocinas_montadas) "
        "VALUES ('%s', '%s', '%s', '%s', %s)",
        nif, nombre, direccion, telefono, num_cocinas);

    if (mysql_query(conn, query) == 0)
        printf("✔ Montador insertado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}
void ver_montadores() {
    if (mysql_query(conn, "SELECT * FROM montador") != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-15s %-20s %-30s %-15s %-10s\n", "ID", "NIF", "Nombre", "Dirección", "Teléfono", "Cocinas");
    printf("----------------------------------------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-15s %-20s %-30s %-15s %-10s\n",
               row[0], row[1], row[2], row[3], row[4], row[5]);
    }
    mysql_free_result(res);
}
void actualizar_montador() {
    char id[10], nif[14], nombre[50], direccion[150], telefono[50], num_cocinas[10];
    printf("ID del montador a actualizar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");
    printf("Nuevo NIF: "); fgets(nif, sizeof(nif), stdin); strtok(nif, "\n");
    printf("Nuevo nombre: "); fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");
    printf("Nueva dirección: "); fgets(direccion, sizeof(direccion), stdin); strtok(direccion, "\n");
    printf("Nuevo teléfono: "); fgets(telefono, sizeof(telefono), stdin); strtok(telefono, "\n");
    printf("Nuevo número de cocinas montadas: "); fgets(num_cocinas, sizeof(num_cocinas), stdin); strtok(num_cocinas, "\n");

    char query[512];
    sprintf(query,
        "UPDATE montador SET nif='%s', nombre='%s', direccion='%s', telefono='%s', num_cocinas_montadas=%s "
        "WHERE idmontador=%s",
        nif, nombre, direccion, telefono, num_cocinas, id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Montador actualizado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al actualizar: %s\n", mysql_error(conn));
}
void eliminar_montador() {
    char id[10];
    printf("ID del montador a eliminar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM montador WHERE idmontador=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Montador eliminado correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}

void insertar_fabricante_distribuidor() {
    char idfabricante[10], iddistribuidor[10];
    printf("ID del fabricante: "); fgets(idfabricante, sizeof(idfabricante), stdin); strtok(idfabricante, "\n");
    printf("ID del distribuidor: "); fgets(iddistribuidor, sizeof(iddistribuidor), stdin); strtok(iddistribuidor, "\n");

    char query[256];
    sprintf(query,
        "INSERT INTO fabricante_distribuidor (idfabricante, iddistribuidor) VALUES (%s, %s)",
        idfabricante, iddistribuidor);

    if (mysql_query(conn, query) == 0)
        printf("✔ Relación insertada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}
void ver_fabricantes_distribuidores() {
    const char* query =
        "SELECT f.nombre, d.nombre "
        "FROM fabricante_distribuidor fd "
        "JOIN fabricante f ON fd.idfabricante = f.idfabricante "
        "JOIN distribuidor d ON fd.iddistribuidor = d.iddistribuidor";

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-30s %-30s\n", "Fabricante", "Distribuidor");
    printf("--------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-30s %-30s\n", row[0], row[1]);
    }
    mysql_free_result(res);
}
void eliminar_fabricante_distribuidor() {
    char idfabricante[10], iddistribuidor[10];
    printf("ID del fabricante: "); fgets(idfabricante, sizeof(idfabricante), stdin); strtok(idfabricante, "\n");
    printf("ID del distribuidor: "); fgets(iddistribuidor, sizeof(iddistribuidor), stdin); strtok(iddistribuidor, "\n");

    char query[256];
    sprintf(query,
        "DELETE FROM fabricante_distribuidor WHERE idfabricante=%s AND iddistribuidor=%s",
        idfabricante, iddistribuidor);

    if (mysql_query(conn, query) == 0)
        printf("✔ Relación eliminada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}
void insertar_montador_cocina() {
    char idcocina[10], idmontador[10];
    printf("ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");
    printf("ID del montador: "); fgets(idmontador, sizeof(idmontador), stdin); strtok(idmontador, "\n");

    char query[256];
    sprintf(query,
        "INSERT INTO montador_cocina (idcocina, idmontador) VALUES (%s, %s)",
        idcocina, idmontador);

    if (mysql_query(conn, query) == 0)
        printf("✔ Relación montador-cocina insertada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}
void ver_montadores_cocinas() {
    const char* query =
        "SELECT m.nombre, c.idcocina "
        "FROM montador_cocina mc "
        "JOIN montador m ON mc.idmontador = m.idmontador "
        "JOIN cocina c ON mc.idcocina = c.idcocina";

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-30s %-10s\n", "Montador", "Cocina");
    printf("----------------------------------------------\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-30s %-10s\n", row[0], row[1]);
    }
    mysql_free_result(res);
}
void eliminar_montador_cocina() {
    char idcocina[10], idmontador[10];
    printf("ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");
    printf("ID del montador: "); fgets(idmontador, sizeof(idmontador), stdin); strtok(idmontador, "\n");

    char query[256];
    sprintf(query,
        "DELETE FROM montador_cocina WHERE idcocina=%s AND idmontador=%s",
        idcocina, idmontador);

    if (mysql_query(conn, query) == 0)
        printf("✔ Relación eliminada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}
void insertar_cliente_cocina() {
    char idcliente[10], idcocina[10];
    printf("ID del cliente: "); fgets(idcliente, sizeof(idcliente), stdin); strtok(idcliente, "\n");
    printf("ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");

    char query[256];
    sprintf(query,
        "INSERT INTO cliente_cocina (idcliente, idcocina) VALUES (%s, %s)",
        idcliente, idcocina);

    if (mysql_query(conn, query) == 0)
        printf("✔ Relación cliente-cocina insertada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}
void ver_clientes_cocinas() {
    const char* query =
        "SELECT cl.nif, cl.direccion, c.idcocina "
        "FROM cliente_cocina cc "
        "JOIN cliente cl ON cc.idcliente = cl.idcliente "
        "JOIN cocina c ON cc.idcocina = c.idcocina";

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-15s %-30s %-10s\n", "NIF Cliente", "Dirección", "Cocina");
    printf("--------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-15s %-30s %-10s\n", row[0], row[1], row[2]);
    }
    mysql_free_result(res);
}
void eliminar_cliente_cocina() {
    char idcliente[10], idcocina[10];
    printf("ID del cliente: "); fgets(idcliente, sizeof(idcliente), stdin); strtok(idcliente, "\n");
    printf("ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");

    char query[256];
    sprintf(query,
        "DELETE FROM cliente_cocina WHERE idcliente=%s AND idcocina=%s",
        idcliente, idcocina);

    if (mysql_query(conn, query) == 0)
        printf("✔ Relación eliminada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}
void insertar_cesion() {
    char idcede[10], idrecibe[10], idcocina[10], fecha[20];
    printf("ID del distribuidor que cede: "); fgets(idcede, sizeof(idcede), stdin); strtok(idcede, "\n");
    printf("ID del distribuidor que recibe: "); fgets(idrecibe, sizeof(idrecibe), stdin); strtok(idrecibe, "\n");
    printf("ID de la cocina: "); fgets(idcocina, sizeof(idcocina), stdin); strtok(idcocina, "\n");
    printf("Fecha de cesión (YYYY-MM-DD): "); fgets(fecha, sizeof(fecha), stdin); strtok(fecha, "\n");

    char query[512];
    sprintf(query,
        "INSERT INTO cesion_de_cocina (iddistribuidor_cede, iddistribuidor_recibe, idcocina, fecha_cesion) "
        "VALUES (%s, %s, %s, '%s')",
        idcede, idrecibe, idcocina, fecha);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cesión registrada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al insertar: %s\n", mysql_error(conn));
}
void ver_cesiones() {
    const char* query =
        "SELECT c.idcesion_de_cocina, dc.nombre, dr.nombre, co.idcocina, c.fecha_cesion "
        "FROM cesion_de_cocina c "
        "JOIN distribuidor dc ON c.iddistribuidor_cede = dc.iddistribuidor "
        "JOIN distribuidor dr ON c.iddistribuidor_recibe = dr.iddistribuidor "
        "JOIN cocina co ON c.idcocina = co.idcocina";

    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Error al consultar: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    printf("\n%-5s %-25s %-25s %-8s %-12s\n", "ID", "Cede", "Recibe", "Cocina", "Fecha");
    printf("--------------------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%-5s %-25s %-25s %-8s %-12s\n", row[0], row[1], row[2], row[3], row[4]);
    }
    mysql_free_result(res);
}
void eliminar_cesion() {
    char id[10];
    printf("ID de la cesión a eliminar: "); fgets(id, sizeof(id), stdin); strtok(id, "\n");

    char query[128];
    sprintf(query, "DELETE FROM cesion_de_cocina WHERE idcesion_de_cocina=%s", id);

    if (mysql_query(conn, query) == 0)
        printf("✔ Cesión eliminada correctamente.\n");
    else
        fprintf(stderr, "✘ Error al eliminar: %s\n", mysql_error(conn));
}

// ============================
// Menús vacíos de otras tablas
// ============================

void menu_distribuidor() {
    int opcion;
    do {
        printf("\n--- MENÚ DISTRIBUIDOR ---\n");
        printf("1. Insertar distribuidor\n");
        printf("2. Ver distribuidores\n");
        printf("3. Actualizar distribuidor\n");
        printf("4. Eliminar distribuidor\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_distribuidor(); break;
            case 2: ver_distribuidores(); break;
            case 3: actualizar_distribuidor(); break;
            case 4: eliminar_distribuidor(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}


void menu_cliente() {
    int opcion;
    do {
        printf("\n--- MENÚ CLIENTE ---\n");
        printf("1. Insertar cliente\n");
        printf("2. Ver clientes\n");
        printf("3. Actualizar cliente\n");
        printf("4. Eliminar cliente\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_cliente(); break;
            case 2: ver_clientes(); break;
            case 3: actualizar_cliente(); break;
            case 4: eliminar_cliente(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}




void menu_cocina() {
    int opcion;
    do {
        printf("\n--- MENÚ COCINA ---\n");
        printf("1. Insertar cocina\n");
        printf("2. Ver cocinas\n");
        printf("3. Actualizar cocina\n");
        printf("4. Eliminar cocina\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_cocina(); break;
            case 2: ver_cocinas(); break;
            case 3: actualizar_cocina(); break;
            case 4: eliminar_cocina(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}

void menu_mueble_de_cocina() {
    int opcion;
    do {
        printf("\n--- MENÚ MUEBLE DE COCINA ---\n");
        printf("1. Insertar mueble de cocina\n");
        printf("2. Ver muebles de cocina\n");
        printf("3. Actualizar mueble de cocina\n");
        printf("4. Eliminar mueble de cocina\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_mueble_de_cocina(); break;
            case 2: ver_muebles_de_cocina(); break;
            case 3: actualizar_mueble_de_cocina(); break;
            case 4: eliminar_mueble_de_cocina(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}
void menu_montador() {
    int opcion;
    do {
        printf("\n--- MENÚ MONTADOR ---\n");
        printf("1. Insertar montador\n");
        printf("2. Ver montadores\n");
        printf("3. Actualizar montador\n");
        printf("4. Eliminar montador\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_montador(); break;
            case 2: ver_montadores(); break;
            case 3: actualizar_montador(); break;
            case 4: eliminar_montador(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}


void menu_fabricante_distribuidor() {
    int opcion;
    do {
        printf("\n--- MENÚ FABRICANTE - DISTRIBUIDOR ---\n");
        printf("1. Insertar relación\n");
        printf("2. Ver relaciones\n");
        printf("3. Eliminar relación\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_fabricante_distribuidor(); break;
            case 2: ver_fabricantes_distribuidores(); break;
            case 3: eliminar_fabricante_distribuidor(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}
void menu_montador_cocina() {
    int opcion;
    do {
        printf("\n--- MENÚ MONTADOR - COCINA ---\n");
        printf("1. Insertar relación\n");
        printf("2. Ver relaciones\n");
        printf("3. Eliminar relación\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_montador_cocina(); break;
            case 2: ver_montadores_cocinas(); break;
            case 3: eliminar_montador_cocina(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}

void menu_cliente_cocina() {
    int opcion;
    do {
        printf("\n--- MENÚ CLIENTE - COCINA ---\n");
        printf("1. Insertar relación\n");
        printf("2. Ver relaciones\n");
        printf("3. Eliminar relación\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_cliente_cocina(); break;
            case 2: ver_clientes_cocinas(); break;
            case 3: eliminar_cliente_cocina(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}
void menu_cesion_de_cocina() {
    int opcion;
    do {
        printf("\n--- MENÚ CESIÓN DE COCINA ---\n");
        printf("1. Registrar cesión\n");
        printf("2. Ver cesiones\n");
        printf("3. Eliminar cesión\n");
        printf("0. Volver\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: insertar_cesion(); break;
            case 2: ver_cesiones(); break;
            case 3: eliminar_cesion(); break;
            case 0: break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);
}

// ============================
// Menú principal
// ============================

int main() {
    conectar();
    int opcion;

    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. CRUD de Fabricante\n");
        printf("2. CRUD de Distribuidor\n");
        printf("3. CRUD de Cliente\n");
        printf("4. CRUD de Mueble de mueble de cocina\n");
        printf("5. CRUD de Cocina\n");
        printf("6. CRUD de Montador\n");
        printf("7. CRUD de Relación Fabricante-Distribuidor\n");
        printf("9. Relación Montador - Cocina\n");
        printf("10. Relación Cliente - Cocina\n");
        printf("11. Cesión de Cocina (1:1)\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion); getchar();

        switch (opcion) {
            case 1: menu_fabricante(); break;
            case 2: menu_distribuidor(); break;
            case 3: menu_cliente(); break;
            case 4: menu_mueble_de_cocina(); break;
            case 5: menu_cocina(); break;
            case 6: menu_montador(); break;
            case 7: menu_fabricante_distribuidor(); break;
            case 9: menu_montador_cocina(); break;
            case 10: menu_cliente_cocina(); break;
            case 11: menu_cesion_de_cocina(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    mysql_close(conn);
    return 0;
}
