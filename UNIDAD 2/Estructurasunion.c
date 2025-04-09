#include <stdio.h>
#define FILAS;
#define COLUMNAS;

int main() {
    Celda matriz[FILAS][COLUMNAS];
    strcpy(matriz[0][0].valor.persona.nombre,"Alejandro");
    matriz [0][1].valor.persona.edad=30;
    matriz[0][1].tipo=1;

    strcpy(matriz[1][0].valor.producto.producto,"Conejo");
    matriz [1][0].valor.producto.precio=88.99;
    matriz[1][0].tipo=2;
    
    strcpy(matriz[0][0].valor.persona.nombre,"Golden");
    matriz [0][1].valor.producto.precio=1377.99;
    matriz[0][1].tipo=2;
    
    printf("Recorriendo la matriz de uniones con estructuras:\n");
    for (int i=0;i<FILAS; i++){
        for(int j=0;j<COLUMNAS; j++){
            printf("Celda [%d][%d:",i,j);
            if (matriz[i][j].tipo==i){
                printf("Persona= Nombre: %s")
            }
        }
    }
}

