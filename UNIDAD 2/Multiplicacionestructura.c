#include <stdio.h>
struct Tabla {
    int valor1;
    int valor2;
    int resultado;
};
int main(){
    struct Tabla arreglo[3] = {
        {1,3,0},
        {2,3,0},
        {3,3,0},
    };
    for(int i=0 ;i<3 ;i++){
        int resultado= (arreglo[1].valor1)*(arreglo[1].valor2);
        arreglo[1].resultado= resultado;
    }
    for(int i=0 ;i<3 ;i++){
        printf("%d x %d =%d\n", 
            arreglo[i].valor1,
            arreglo[i].valor2,
            arreglo[i].resultado);
        } 
    return 0;
        }
