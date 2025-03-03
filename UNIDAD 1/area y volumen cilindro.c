// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
int main() {
    float r;
    float h;
    float pi=3.1416;
   printf("%s\n","ingresa el radio del cilindro");
   scanf("%f",&r);
   printf("%s\n","ingresa la altura del cilindro");
   scanf("%f",&h);
   float v=(pi*(r*r)*h);
   float a=(2*pi*r)*(r+h);
   printf("%s%f\n","El area es:",a);
   printf("%s%f\n","El volumen es:",v);
}