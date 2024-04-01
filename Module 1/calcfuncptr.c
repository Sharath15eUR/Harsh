#include <stdio.h>

typedef int (*operation)(int, int);

int add(int a, int b){
    return (a+b);
}

int mul(int a, int b){
    return (a*b);
}

int calculator(operation op, int x, int y){
    return op(x,y);
}

void main(){
    printf("%d",calculator("add", 2, 3));
}