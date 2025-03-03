#include <stdio.h> /*Incluir la libreria stdio.h*/

int main() /*Funcion principal del programa*/
{
    int fahr, celsius; /* Declarar variables en formato int*/
    int lower, upper, step; /* Declarar variables en formato int*/

        lower = 0; /* Asignar valores a una variable*/
        upper = 300;  /* Asignar valores a una variable*/
        step = 20;  /* Asignar valores a una variable*/
        fahr = lower;  /* Asignar valores a una variable*/

            while (fahr <= upper) {  /* Declarar un ciclo que se realiza mientraas fahr es menor o igual a upper*/
                celsius = 5 * (fahr-32) / 9; /*Realizar la aperacion para celsius*/
                printf("%d\t%d\n", fahr, celsius); /* imprimir las variables fahr y celsius con una tabulacion y un salto de linea*/
                fahr = fahr + step; /*Sumar step a fahr*/
                
            } /*fin del ciclo*/
 
    return 0; /* finalizar programa*/
}