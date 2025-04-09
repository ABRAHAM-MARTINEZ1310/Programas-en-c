#include <stdio.h>
#include <string.h>

#define FILAS 2
#define COLUMNAS 2

typedef struct {
    char nombre[50];
    int edad;
} Persona;

typedef struct {
    char nombre[50];
    float precio;
} Producto;

typedef union {
    Persona persona;
    Producto producto;
} Dato;

typedef struct {
    Dato valor;
    int tipo; // 1 para Persona, 2 para Producto
} Celda;

int main() {
    Celda matriz[FILAS][COLUMNAS];

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Ingresa 1 para Persona y 2 para Producto): ", i, j);
            scanf("%d", &matriz[i][j].tipo);

         

            switch (matriz[i][j].tipo) {
                case 1:
                    printf("Ingresando datos para Persona:\n");
                    printf("Nombre: ");
                    scanf(" %49[^\n]", matriz[i][j].valor.persona.nombre);
                    printf("Edad: ");
                    scanf("%d", &matriz[i][j].valor.persona.edad);
                    break;
                
                case 2: 
                    printf("Ingresando datos para Producto:\n");
                    printf("Nombre: ");
                    scanf(" %49[^\n]", matriz[i][j].valor.producto.nombre);
                    printf("Precio: ");
                    scanf("%f", &matriz[i][j].valor.producto.precio);
                    break;

            }
    
        }
    }

    printf("\nRecorriendo la matriz de uniones con estructuras:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Celda [%d][%d]: ", i, j);
            switch (matriz[i][j].tipo) {
                case 1: 
                    printf("Persona - Nombre: %s, Edad: %d\n",
                        matriz[i][j].valor.persona.nombre,
                        matriz[i][j].valor.persona.edad);
                    break;
                
                case 2:
                    printf("Producto - Nombre: %s, Precio: %.2f\n",
                        matriz[i][j].valor.producto.nombre,
                        matriz[i][j].valor.producto.precio);
                    break;
                
                default:
                    printf("Tipo no válido\n");
                    break;
            }
        }
    }

    return 0;
}