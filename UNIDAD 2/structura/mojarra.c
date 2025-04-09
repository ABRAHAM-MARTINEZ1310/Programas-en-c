#include <stdio.h>
struct rio {
    char colonia[50];
    int numero;
};
struct mojarra {
    char especie[50];
    char color[50];
    char tamano[50];
    char pesokg[50];
    char alimentacion[50];
    char statusespecie[50];
    char depredadores[50];
    char comidafavorita[50];
    char habitad[50];
    char tipopesca[50];
    char valornutricional[50];
    char platillos[50];
    struct rio radica;
};
int main(){
    int n;
    printf("Ingrese el numero de mojarras: ");
    scanf("%d", &n);
    getchar();
    struct mojarra mojarras [n];

    for(int i=0; i<n;i++){
        printf("\nIngrese los datos de la mojarra %d:\n", 1+i);
        printf("Especie: ");
        scanf(" %s", mojarras[i].especie);
        printf("Color: ");
        scanf(" %s", mojarras[i].color);
        printf("Tamaño: ");
        scanf(" %s", mojarras[i].tamano);
        printf("Peso en KG: ");
        scanf(" %s", mojarras[i].pesokg);
        printf("Status: ");
        scanf(" %s", mojarras[i].statusespecie);
        printf("Depredadores: ");
        scanf(" %s", mojarras[i].depredadores);
        printf("Alimentacion: ");
        scanf(" %s", mojarras[i].alimentacion);
        printf("Comida favorita: ");
        scanf(" %s", mojarras[i].comidafavorita);
        printf("Habitad: ");
        scanf(" %s", mojarras[i].habitad);
        printf("Tipo de pesca de la mojarra: ");
        scanf(" %s", mojarras[i].tipopesca);
        printf("Valor nutricional: ");
        scanf(" %s", mojarras[i].valornutricional);
        printf("Platillos: ");
        scanf(" %s", mojarras[i].platillos);

        getchar();
    }
    printf("\n%-20s| %-20s | %-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s\n", 
        "Especie", "Color", "Tamaño", "Peso en Kg","Alimentacion","Status de la especie","Depredadores","Comida favorita",
        "habitad","Tipo Pesca","ValorNutricional","Platillos");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<n; i++){
        printf("%-20s| %-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s\n",
            mojarras[i].especie,
            mojarras[i].color,
            mojarras[i].tamano,
            mojarras[i].pesokg,
            mojarras[i].alimentacion,
            mojarras[i].statusespecie,
            mojarras[i].depredadores,
            mojarras[i].comidafavorita,
            mojarras[i].habitad,
            mojarras[i].tipopesca,
            mojarras[i].valornutricional,
            mojarras[i].platillos
        );
    }
    return 0;
}