#include <stdio.h>
#include <string.h>
#include <strings.h> // Para strcasecmp

int main() {
    char nombre1[50] = "Abraham";
    char apellido1[50] = "Martinez";
    char completo1[100];

    // Copiar nombre
    strcpy(completo1, nombre1);
    // Agregar espacio y apellido
    strcat(completo1, " ");
    strcat(completo1, apellido1);

    printf("Nombre completo: %s\n", completo1);

    // Usar strncpy para copiar solo parte
    char nombre_corto[10];
    strncpy(nombre_corto, nombre1, 3);
    nombre_corto[3] = '\0';
    printf("Primeras 3 letras del nombre: %s\n", nombre_corto);

    // Comparar dos nombres
    char nombre2[50] = "    Ismael";
    printf("Comparando '%s' y '%s':\n", nombre1, nombre2);
    printf("strcmp: %d\n", strcmp(nombre1, nombre2));
    printf("strcasecmp: %d\n", strcasecmp(nombre1, nombre2));

    // Usar memcpy para copiar lista de nombres
    char lista1[3][20] = {"Ana", "Luis", "Maria"};
    char lista2[3][20];
    memcpy(lista2, lista1, sizeof(lista1));

    printf("\nLista copiada con memcpy:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", lista2[i]);
    }

    return 0;
}
