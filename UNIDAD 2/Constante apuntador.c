#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    printf("Ingrese el valor A\n");
    scanf("%d", &a);
    printf("Ingrese el valor B\n");
    scanf("%d", &b);
    printf("Ingrese el valor C\n");
    scanf("%d", &c);
    printf("Ingrese el valor D\n");
    scanf("%d", &d);
    printf("Ingrese el valor E\n");
    scanf("%d", &e);
    printf("Ingrese el valor F\n");
    scanf("%d", &f);  


    int DH;  
    int* DL = &DH;
    const int* AH = &a;
    const int* AL = &b;
    const int* BH = &c;
    const int* BL = &d;
    const int* CH = &e;
    const int* CL = &f;
    

    printf("Valores ingresados: A=%p\n", AH);
    printf("Valores ingresados: B=%p\n", AL);
    printf("Valores ingresados: C=%p\n", BH);
    printf("Valores ingresados: D=%p\n", BL);
    printf("Valores ingresados: E=%p\n", CH);
    printf("Valores ingresados: F=%p\n", CL);

    /////////// AH Y AL operaciones
    // SUMA
    *DL = *AH + *AL;
    printf("Resultado de la suma: %d\n", *DL);
    printf("Valor nuevo: A=%d\n", *DL);

    // RESTA
    *DL = *AH - *AL;
    printf("Resultado de la resta: %d\n", *DL);
    printf("Valor nuevo: B=%d\n", *DL);

    // MULTIPLICACION
    *DL = *AH * *AL;
    printf("Resultado de la multiplicacion: %d\n", *DL);
    printf("Valor nuevo: C=%d\n", *DL);

    // DIVISION
        *DL = *AH / *AL;
        printf("Resultado de la division: %d\n", *DL);
        printf("Valor nuevo: D=%d\n", *DL);



    //////// BH Y BL operaciones
    // SUMA
    *DL = *BH + *BL;
    printf("Resultado de la suma: %d\n", *DL);
    printf("Valor nuevo: A=%d\n", *DL);

    // RESTA
    *DL = *BH - *BL;
    printf("Resultado de la resta: %d\n", *DL);
    printf("Valor nuevo: B=%d\n", *DL);

    // MULTIPLICACION
    *DL = *BH * *BL;
    printf("Resultado de la multiplicacion: %d\n", *DL);
    printf("Valor nuevo: C=%d\n", *DL);

    // DIVISION
    *DL = *BH / *BL;
    printf("Resultado de la division: %d\n", *DL);
    printf("Valor nuevo: D=%d\n", *DL);

    // CH Y CL operaciones
    // SUMA
    *DL = *CH + *CL;
    printf("Resultado de la suma: %d\n", *DL);
    printf("Valor nuevo: A=%d\n", *DL);

    // RESTA
    *DL = *CH - *CL;
    printf("Resultado de la resta: %d\n", *DL);
    printf("Valor nuevo: B=%d\n", *DL);

    // MULTIPLICACION
    *DL = *CH * *CL;
    printf("Resultado de la multiplicacion: %d\n", *DL);
    printf("Valor nuevo: C=%d\n", *DL);

    // DIVISION
    *DL = *CH / *CL;
    printf("Resultado de la division: %d\n", *DL);
    printf("Valor nuevo: D=%d\n", *DL);

    return 0;
}
