#include <stdio.h>
int main() {
    int numeros[] = {12,20,30,20};
    int size = sizeof(numeros)/sizeof(numeros[0]);
    printf("Tamaño: %d\n", size);
    for (int i=0; i<size; i++) {
        printf("%d\n", numeros[i]);
    }
    return 0;
}