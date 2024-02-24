#include <stdio.h>

int checkOddOrEven(int);

int main(){
    int num;
    printf("Enter an integer to check whether it is odd or even:");
    scanf("%d", &num);
    int exitStatus = -1;
    exitStatus = checkOddOrEven(num);
    return exitStatus;
}

int checkOddOrEven(int a){
    if(a & 1){
        printf("The number entered is odd: %d", a);
    }else{
        printf("The number entered is even: %d", a);
    }
    return 0;
}