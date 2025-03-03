#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;
int main() {
    Estudiante estudiante1 = {"Abraham Ismael",18,7.6};
    printf("Nombre: %s\n", estudiante1.nombre);
    return 0;
}