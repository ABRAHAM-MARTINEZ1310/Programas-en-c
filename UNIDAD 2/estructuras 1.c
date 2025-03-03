#include <stdio.h>
struct Estudiante {
    char nombre[50];
    int edad;               // tipo global, significa que cualquier parte del codigo funcviona 
    float promedio;
};

int main() {
    struct Estudiante estudiante1 = {"Abraham Ismael",18,7,6};
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %f\n", estudiante1.promedio);
    return 0;
}