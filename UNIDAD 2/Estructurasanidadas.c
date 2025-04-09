#include <stdio.h>
main () {
    struct direccion {
        char calle [50];
        int numero;
    };
    struct Persona {
        char nombre [50];
        struct direccion domicilio;
        };
    int main (){
        struct Persona personal = ("Abraham Martinez" , ("Camino al tequio" , 120));
        printf("Nombre: $s\n", personal.nombre );
        printf("Domicilio: %s #%d\n",
        
    }
        
    }
    {
        
    };
    