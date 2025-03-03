// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
int main() {
    float r;
    float h;
    float pi=3.1416;
   printf("%s\n","ingresa el radio del cono");
   scanf("%f",&r);
   printf("%s\n","ingresa la altura del cono");
   scanf("%f",&h);
   float g=sqrt((r*r)+(h*h));
   float v=((pi*(r*r)*h)/3);
   float a=(pi*r)*(r+g);
   printf("%s%f\n","El area es:",a);
   printf("%s%f\n","El volumen es:",v);
}