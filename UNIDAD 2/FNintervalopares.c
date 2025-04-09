#include <stdio.h>

void imprimirPares(int inicio, int fin) {
    printf("Números pares entre %d y %d:\n", inicio, fin);
    for (int i = inicio; i <= fin; i++) {
        if (i % 2 == 0) {  
            printf("%d ", i);
        }
    }
    printf("\n");  
}

int main() {
    int inicio, fin;
    
    printf("Ingrese el inicio del intervalo: ");
    scanf("%d", &inicio);

    printf("Ingrese el fin del intervalo: ");
    scanf("%d", &fin);
    
    imprimirPares(inicio, fin);  
    
    return 0;
}