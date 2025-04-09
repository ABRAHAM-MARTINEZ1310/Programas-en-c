#include <stdio.h>
#include <math.h>
#include <string.h> 

struct eccuadratica {
    int a;
    int b;
    int c;
    int discriminante;
    float x1;
    float x2;
    char solucion[30];
};

int main (){
    int size;
    printf("Ingrese tamaño del arreglo:\n");
    scanf("%d", &size);

    struct eccuadratica arreglo[size];


    for(int i=0; i<size; i++){
        printf("Ingrese a: ");
        scanf("%d", &arreglo[i].a);
        printf("Ingrese b: ");
        scanf("%d", &arreglo[i].b);
        printf("Ingrese c: ");
        scanf(" %d",&arreglo[i].c);
        int d = (arreglo[i].b * arreglo[i].b) - (4 * arreglo[i].a * arreglo[i].c);
        arreglo[i].discriminante = d;
        if(d < 0){
            strcpy(arreglo[i].solucion, "No tiene solucion");
        } else {
            arreglo[i].x1 = ((-1) * arreglo[i].b + sqrt(d)) / (2 * arreglo[i].a);
            arreglo[i].x2 = ((-1) * arreglo[i].b - sqrt(d)) / (2 * arreglo[i].a);
            strcpy(arreglo[i].solucion, "Tiene solucion");
        }
    }

    printf("(%s|%s|%s|%s|%s|%s)\n", "a", "b", "c", "x1", "x2", "sol");
    for(int i=0; i<size; i++){
        printf("%d|%d|%d|%.2f|%.2f|%s\n",
        arreglo[i].a,
        arreglo[i].b,
        arreglo[i].c,
        arreglo[i].x1,
        arreglo[i].x2,
        arreglo[i].solucion);
    }

    return 0;
}