#include <stdio.h>
 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
 
int main() {

 int ope;
 int num1,num2;
 int sum, rest, mul;
 float div;
    printf("\033[2J"); // Limpia la pantalla
    setColor("\033[7;32m");
 
    gotoxy(10, 5);
    printf("Calculadora Basica con gotoxy y switch case");

    setColor("\033[7;31m");
    gotoxy(10, 6);
    printf("%s", "1:");
    setColor("\033[0;30m");
    gotoxy(13, 6);
    printf("%s", "Sumar");

    setColor("\033[7;32m");
    gotoxy(10, 7);
    printf("%s", "2:");
    setColor("\033[0;30m");
    gotoxy(13, 7);
    printf("%s", "Restar");

    setColor("\033[7;33m");
    gotoxy(10, 8);
    printf("%s", "3:");
    setColor("\033[0;30m");
    gotoxy(13, 8);
    printf("%s", "Multiplicar");

    setColor("\033[7;34m");
    gotoxy(10, 9);
    printf("%s", "4:");
    setColor("\033[0;30m");
    gotoxy(13, 9);
    printf("%s", "Dividir");


    setColor("\033[0;30m");
    gotoxy(10, 10);
    printf("Seleccione una opcion");
    setColor("\033[4;33m");
    gotoxy(32,10);
    printf("(1-4): ");
    scanf("%d", &ope);
    printf("\033[2J");

    setColor("\033[0;30m");
    gotoxy(10, 5);
    printf("Ingrese el primer numero: ");
    scanf("%d",&num1);

    gotoxy(10, 6);
    printf("Ingrese el segundo numero: ");
    scanf("%d",&num2);


    switch(ope){
        case 1:
        sum=num1+num2;
        gotoxy(10, 7);
        setColor("\033[7;31m");
        printf("El resultado de la suma es: %d",sum);
            break;

        case 2:
        rest=num1-num2;
        gotoxy(10, 7);
        setColor("\033[7;32m");
        printf("El resultado de la resta es: %d ",rest);
            break;

        case 3:
        mul=num1*num2;
        gotoxy(10, 7);
        setColor("\033[7;33m");
        printf("El resultado de la multiplicacion es: %d",mul);
            break;
            
        case 4:
        if (num2 == 0) {
            setColor("\033[7;34m");
            gotoxy(10, 7);
            printf("Error: No se puede dividir por cero.\n");
        } else {
            div = num1 / num2;
            gotoxy(10, 7);
            setColor("\033[7;34m");
            printf("El resultado de la division es: %f\n", div);
        }
            break;

    }
setColor("\033[0;30m");
return 0;
}