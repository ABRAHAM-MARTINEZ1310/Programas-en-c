#include <stdio.h>

int encontrarMayor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1, num2;
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    
    if (num1 == num2) {
        printf("Los numeros son iguales.\n");
    } else {
        int mayor = encontrarMayor(num1, num2);
        printf("El numero mayor es: %d\n", mayor);
    }
    
    return 0;
}