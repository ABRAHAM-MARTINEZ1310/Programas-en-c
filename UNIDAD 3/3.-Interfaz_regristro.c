#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void limpiar_pantalla() {
    printf("\033[2J\033[H");
}

// Función para establecer color
void setColor(int color) {
    printf("\033[%dm", color);
}

void mostrar_tabla(char nombres[][MAX], int edades[], char paises[][MAX], int cantidad) {
    limpiar_pantalla();
    

    setColor(36); 
    gotoxy(10, 3);
    printf("*************************************************");
    gotoxy(10, 4);
    printf("* No. *     NOMBRE      *   EDAD   *     PAIS    *");
    gotoxy(10, 5);
    printf("*************************************************");
    
  
    setColor(33); // Amarillo
    for(int i = 0; i < cantidad; i++) {
        gotoxy(10, 6 + (i*2));  
        printf("* %-2d * %-15s *    %-4d  * %-11s *", i+1, nombres[i], edades[i], paises[i]);
        
      
        setColor(36); 
        gotoxy(10, 7 + (i*2));
        printf("*************************************************");
    }
    
    setColor(0); 
    gotoxy(10, 8 + (cantidad*2));
    printf("Presione Enter para continuar...");
    getchar();
}

int main() {
    FILE *file;
    char nombres[MAX][MAX];
    int edades[MAX];
    char paises[MAX][MAX];
    char nombre_archivo[MAX];
    int cantidad, i;
    int opcion;

    limpiar_pantalla();
    

    gotoxy(10, 5);
    printf("¿Cuántas personas quieres registrar? ");
    scanf("%d", &cantidad);
    getchar();

    limpiar_pantalla();

    gotoxy(10, 5);
    printf("Nombre del archivo: ");
    fgets(nombre_archivo, MAX, stdin);
    nombre_archivo[strcspn(nombre_archivo, "\n")] = 0;
    strcat(nombre_archivo, ".csv");

    file = fopen(nombre_archivo, "w");
    if(file == NULL) {
        gotoxy(10, 7);
        printf("Error al crear el archivo");
        return 1;
    }
    fprintf(file, "Nombre,Edad,Pais\n");
    

    for(i = 0; i < cantidad; i++) {
        limpiar_pantalla();
        
        gotoxy(10, 5);
        printf("Registro de persona %d", i+1);
        

        setColor(32);
        gotoxy(10, 7);
        printf("Nombre: ");
        fgets(nombres[i], MAX, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;


        setColor(34);
        gotoxy(10, 8);
        printf("Edad: ");
        scanf("%d", &edades[i]);
        getchar();

        setColor(35);
        gotoxy(10, 9);
        printf("Pais: ");
        fgets(paises[i], MAX, stdin);
        paises[i][strcspn(paises[i], "\n")] = 0;

 
        setColor(0);

        fprintf(file, "%s,%d,%s\n", nombres[i], edades[i], paises[i]);
    }
    fclose(file);
   
    do {
        limpiar_pantalla();
        gotoxy(10, 5);
        printf("Datos guardados correctamente en '%s'", nombre_archivo);
        gotoxy(10, 7);
        printf("1. Mostrar tabla de personas");
        gotoxy(10, 8);
        printf("2. Salir");
        gotoxy(10, 10);
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();
        
        switch(opcion) {
            case 1:
                mostrar_tabla(nombres, edades, paises, cantidad);
                break;
            case 2:
                break;
            default:
                gotoxy(10, 12);
                printf("Opción no válida. Intente nuevamente.");
                getchar();
        }
    } while(opcion != 2);
    
    limpiar_pantalla();
    gotoxy(10, 5);
    getchar();
    
    return 0;
}