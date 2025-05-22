#include <stdio.h>

int sumaNenteros(int number) {
    if (number == 1)
        return 1;
    else
        return number + sumaNenteros(number - 1);
}



int main(){


    int n;
    printf("Ingrese un numero a sumar: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Error: Ingrese un número válido \n");
    } else {
        printf("La suma de los primeros enteros es: %d\n", sumaNenteros(n));
    }
return 0;
}