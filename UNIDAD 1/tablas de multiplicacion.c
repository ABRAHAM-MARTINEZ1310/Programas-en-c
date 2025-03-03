#include <stdio.h>
int main(){

int tabla = 0;
    while(tabla <= 10){
    int numero = 0;
    while (numero <= 10){
        int multi= numero * tabla;
        printf("%s%d%s%d%s%d\n",
            "(",tabla,")(",numero,")=",multi);
        numero++;}  
    tabla++;
    
}
return 0;
}
