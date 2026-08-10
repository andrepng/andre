# include <stdio.h>

int fatorial(int n) {
    
    if(n == 0) return 1;
    return n * fatorial(n - 1);
    
}
int main() {
    
    for(int i = 0; i <= 4; i++)
        printf("%d! = %d \n", i, fatorial(i));
        
    return 0;
}