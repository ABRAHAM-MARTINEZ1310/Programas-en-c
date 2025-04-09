#include <stdio.h>
#include <stdbool.h>

void llenar_matriz(int tam, char matriz[tam][tam]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("Ingrese el caracter para [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]); 
        }
    }
}

void mostrar_matriz(int tam, char matriz[tam][tam]) {
    printf("\nMatriz de caracteres %dx%d:\n", tam, tam);
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%c\t", matriz[i][j]);
        }
        printf("\n");
    }
}



void almacenar_en_arreglo(int tam, char matriz[tam][tam], char arreglo[]) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            arreglo[i * tam + j] = matriz[i][j]; 
        }
    }
}



void mostrar_arreglo(int tam, char arreglo[]) {
    printf("\nArreglo con los caracteres:\n");
    for (int i = 0; i < tam * tam; i++) {
        printf("%c ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    int r;
    printf("Ingrese un numero para calcular su raiz cuadrada: ");
    scanf("%d", &r);
    
    bool flag = false;
    int raiz = 0;
    
    for(int i = 0; i <= r; i++) {
        if(i * i == r) {
            flag = true;
            raiz = i;
            break;
        }
    }
    

    char matriz[raiz][raiz];
    char arreglo[raiz * raiz]; 
    
    llenar_matriz(raiz, matriz);
    mostrar_matriz(raiz, matriz);
    
    almacenar_en_arreglo(raiz, matriz, arreglo);
    mostrar_arreglo(raiz, arreglo);
    
    return 0;
}