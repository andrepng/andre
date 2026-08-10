//Opção B — Fibonacci. F(0) = 0, F(1) = 1, F(n)= F(n ↑ 1) + F(n ↑ 2). Implemente int
//fibonacci(int n) e diga quais são os 6 primeiros termos.

#include <stdio.h>

int fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
    return fibonacci(n -1) + fibonacci(n -2);
}

int main() {
    for(int i = 0; i <= 6; i ++)
        printf("fib(%d) = %d\n", i, fibonacci(i));
    return 0;
}
