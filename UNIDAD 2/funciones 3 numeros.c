#include <stdio.h>


int encontrarMayor(int a, int b, int c) {
    int max = a;  
    
    if (b > max) {
        max = b;  
    }
    if (c > max) {
        max = c;  
    }
    
    return max;
}

int main() {
    int a, b, c;
    
    printf("Ingrese el numero 1: ");
    scanf("%d", &a);
    
    printf("Ingrese el numero 2: ");
    scanf("%d", &b);
    
    printf("Ingrese el numero 3: ");
    scanf("%d", &c);
    
    if (a == b && b == c) {
        printf("Los tres numeros son iguales\n");
    } else {
        int mayor = encontrarMayor(a, b, c); 
        printf("El numero mas grande es: %d\n", mayor);
    }
    
    return 0;
}