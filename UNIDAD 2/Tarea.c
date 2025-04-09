#include <stdio.h>
#define FILAS 2
#define COLUMNAS 2

struct Fruta {
    float precio;   
    char nombre[20]; 
};

int main() {
    struct Fruta matriz[FILAS][COLUMNAS] = {
        {{1.50, "Manzana"}, {2.00, "Plátano"}},
        {{0.80, "Naranja"}, {3.50, "Mango"}}
    };

    printf("Información de tu fav fruta:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("| Precio: %.2f, Nombre: %s ", matriz[i][j].precio, matriz[i][j].nombre);
        }
        printf("|\n");
    }

    return 0;
}