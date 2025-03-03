#include <stdio.h>

int main(){

int asteriscos=1;
for (int i=6 ; i>=0;i--) {
    for (int j=1; j<= asteriscos; j++) {
    printf("%5s", "*");
}
asteriscos++;
printf("\n");




}
return 0;
}