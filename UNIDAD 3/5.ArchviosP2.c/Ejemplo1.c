#include <stdio.h>
#include <stdlib.h>

FILE *pf;
char nm[] = "./licencia.est";

int main(){
    pf = fopen (nm, "r");
    if (pf == NULL){
        puts("Error al abrir el archivo.");
        exit(1);
    }
return 0;
}