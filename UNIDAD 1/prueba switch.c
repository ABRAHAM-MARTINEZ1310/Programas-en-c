#include <stdio.h>

int main(){
    int opcion;
    printf("1.- Suma\n");
    printf("2.- Resta\n");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            printf("Elegiste la suma\n");
            break;
        case 2:
            printf("Elegiste la resta\n");
            break;
    }
    return 0;
}