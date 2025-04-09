#include <stdio.h>

void tablaMultiplicar(int numero) {
    printf("\n--- Tabla del %d ---\n", numero);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
}

int main() {
    int num;
    
    printf("Ingrese un número para generar su tabla de multiplicar: ");
    scanf("%d", &num);
    
    tablaMultiplicar(num); 
    
    return 0;
}