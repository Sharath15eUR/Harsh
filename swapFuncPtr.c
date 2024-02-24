#include <stdio.h>

typedef void (*swapper)(int* x, int* y);

void swapIntegers(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){
    swapper swap = &swapIntegers;
    int a, b;
    printf("Enter the two numbers to swap: ");
    scanf("%d %d", &a, &b);
    printf("Before swap a = %d and b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap a = %d and b = %d", a, b);
    return 0;
}
