#include <stdio.h>
struct Usuario usuario1; { 
    char nombre [50];
    int edad;
    char correo [50];
};

int main (){
    struct Usuario usuario1;
    printf("ingrese su nombre: ");
    scanf("%s",&usuario1.nombre);

    printf("ingrese su edad: ");
    scanf("%d",&usuario1.edad);

    printf("ingrese su correo: ");
    scanf("%s",&usuario1.correo);

    printf("\n Datos del usuario:\n");
    printf("Nombre: %s\n", usuario1.nombre);
    printf("Edad: %d\n", usuario1.edad);
    printf("Correo: %s\n", usuario1.correo);

    return 0;
 }
