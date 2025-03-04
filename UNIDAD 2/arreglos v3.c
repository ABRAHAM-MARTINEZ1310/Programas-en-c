#include <stdio.h>

int main() {
    int size;
    printf("Ingrese el tamaño del arreglo: \n");
    scanf("%d", &size);
    
    int arreglonum[size];

    for (int i = 0; i < size; i++) {
        printf("Ingrese valor en posicion [%d]: \n", i);
        int swap;
        scanf("%d", &swap);
        arreglonum[i] = swap;
    }

    // Imprimiendo los valores del arreglo
    for (int i = 0; i < size; i++) {
        printf("arreglo [%d] = %d\n", i, arreglonum[i]);
    }

    return 0;
}