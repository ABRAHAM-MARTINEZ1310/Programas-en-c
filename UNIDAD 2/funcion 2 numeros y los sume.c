#include <stdio.h>
int suma(int a, int b) {
    return a + b;
}

int main() {

    int numMayor, numMenor;
    
    printf("\nIngrese el numero mayor: ");
    scanf("%d", &numMayor);
    
    printf("Ingrese el numero menor: ");
    scanf("%d", &numMenor);
    
    if(numMayor <= numMenor) {
        printf("Error: El primer numero debe ser mayor que el segundo\n");
        return 1; 
    }
    
    int resultado = suma(numMayor, numMenor);
    printf("La suma es: %d\n",resultado);
    
    return 0;
}