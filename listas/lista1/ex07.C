#include <stdio.h>

float somar(float a, float b){
    return a + b;
}
float subtrair(float a, float b){
    return a - b;
}
float multiplicar(float a, float b){
    return  a * b;
}
float dividir(float a, float b){
    if(b == 0){
        return 0;
    } else{
        return  a / b;
    }
}

int main(){
    float num1;
    float num2;

        printf("digite um número: ");
        scanf("%f", &num1);
        printf("digite um número: ");
        scanf("%f", &num2);
        
        printf("soma: %f\n", somar(num1, num2));
        printf("subtração: %f\n", subtrair(num1, num2));
        printf("multiplicação: %f\n", multiplicar(num1, num2));
        printf("divisão: %f\n", dividir(num1, num2));
}
