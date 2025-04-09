#include<stdio.h>
int suma (int a, int b){
    return a + b ;
}
int resta (int a, int b){
    int result = a-b;
    return result;
}
int multiplicacion (int a){
    return a*a;
}
float division (int a, int b){
    return a/b;
}
void imprimir(int a , int b, int c, float d){
    printf("\nResultados: \nsuma:%d \nResta:%d\nMulti:%d\nDivision:%.2f",a,b,c,d);

}
int main(){
    //Mandar a llamar las funciones 
    int op1=suma(3,2);
    int op2=resta(5,3);
    int op3=multiplicacion(3);
    float op4=division(5,3);
    imprimir(op1,op2,op3,op4);

    return 0;
}