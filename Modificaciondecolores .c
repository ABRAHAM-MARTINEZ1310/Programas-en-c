#include <stdio.h>

setColor("\033[;37m");
void limpiarPantalla(){
    printf("\033[2J");
} 
void gotoxy(int x, int y){
    printf("\033[%d;%dH",x,y);
}

int main(){
    limpiarPantalla(),
    gotoxy(5,3),
    printf("Helloou from (10,3)");


}