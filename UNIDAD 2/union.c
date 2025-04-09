#include <stdio.h>
union Dato {
    int entero;
    float decimal;
    char texto[20];
};
int main(){
    union Dato variable;
    variable.entero=42;
    printf("Entero: %d\n",variable.entero);
    variable.decimal=3.34;
    printf("Decimal: %.2f\n",variable.decimal);
    sprintf(variable.texto,"HOLA C");
    printf("Texto: %s\n",variable.texto);

    printf("\n Despues de asignar un exto: \n");
    printf("Entero: %d\n",variable.entero);
    printf("Decimal: %f\n",variable.decimal);
    printf("Texto: %s\n",variable.texto);

    return 0;
}
