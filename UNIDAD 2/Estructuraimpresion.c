#include <stdio.h>
struct direccion {
    char calle[50];
    int numero;
};
struct persona {
    char nombre[50];
    struct direccion domicilio;
};
int main(){
    int n;
    printf("Ingrese el numero de personas: ");
    scanf("%d", &n);
    getchar();
    struct persona personas [n];

    for(int i=0; i<n;i++){
        printf("\nIngrese los datos de la persona %d:\n", 1+i);
        printf("Nombre: ");
        scanf(" %s", personas[i].nombre);
        printf("calle: ");
        scanf("%s",personas[i].domicilio.calle);
        printf("Numero: ");
        scanf("%d",&personas[i].domicilio.numero);
        getchar();
    }
    printf("\n%-20s| %-20s | %-10s\n", "Nombre", "Direccion", "Numero");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<n; i++){
        printf("%-20s| %-20s|%-10d\n",
            personas[i].nombre,
            personas[i].domicilio.calle,
            personas[i].domicilio.numero);
    }
    return 0;
}