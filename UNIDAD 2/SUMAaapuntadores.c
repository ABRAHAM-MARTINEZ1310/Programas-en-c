#include <stdio.h>

int main (){
int fno, sno, *ptr, *qtr, sum;

printf("\n\n Pointer: Add two numbers: \n");
printf("----------------------\n");

printf("Input the first number:");
scanf("%d",&fno);

printf("Input the second number:");
scanf("%d",&sno);

ptr= &fno;
qtr= &sno;
printf("\n\n Pointer1:%p:",ptr);
printf("\n\n Pointer2:%p:",qtr);

sum= *ptr+ *qtr;

printf("\n\n The sum of the entered numbers is:%d\n\n", sum);
return 0;
}