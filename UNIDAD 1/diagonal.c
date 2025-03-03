#include <stdio.h>
int main(){

        int espacio=1;
            
    for(int a=9;a>=0;a--){

        for(int b=2;b<=espacio;b++){
            printf("%4s"," ");
        }
        
        espacio++;
        printf("%4s","*");
        printf("\n");

    }
 return 0;
}    