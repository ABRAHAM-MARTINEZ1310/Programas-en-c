// Online C compiler to run C program online
#include <stdio.h>
int main() {
    float r;
    float pi=3.1416;
   printf("%s\n","ingresa el radio de la esfera");
   scanf("%f",&r);
   float v=((4*pi*(r*r*r))/3);
   float a=(4*pi*(r*r));
   printf("%s%f\n","El area es:",a);
   printf("%s%f\n","El volumen es:",v);
}