#include <stdio.h>

void Signo(int numero) {
    if (numero > 0) {
        printf("El numero %d es positivo.\n", numero);
    } else if (numero < 0) {
        printf("El numero %d es negativo.\n", numero);
    } else {
        printf("El numero es cero.\n");
    }
}

int main() {
    int num;
    
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);
    
    Signo(num); 
    
    return 0;
}