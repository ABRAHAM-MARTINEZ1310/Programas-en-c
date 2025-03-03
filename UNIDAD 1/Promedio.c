#include <stdio.h>
int main(){

    char nombre[50];
    printf("%s\n", "Ingrese su nombre: ");
    scanf("%s", &nombre);

    int cal1;
    printf("%s", "Ingresa la calificacion 1: ");
    scanf("%d", &cal1);

    int cal2;
    printf("%s", "Ingresa la calificacion 2: ");
    scanf("%d", &cal2);

    int cal3;
    printf("%s", "Ingresa la calificacion 3: ");
    scanf("%d", &cal3);

    float promedio=(cal1 + cal2 + cal3)/3;
    printf("%s%s", "Nombre:", nombre);
    printf("\n");
    printf("%s%2f", "El promedio es:\n", promedio);
    printf("\n");
    
    if(promedio>=6){
        printf("%s\n","APROBADO!");
    } else { 
        printf("%s\n","REPROBADO ");
    }

    return 0;

}