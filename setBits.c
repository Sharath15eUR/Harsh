#include <stdio.h>

// 144/2=72
// 72/2=36
// 36/2=18
// 18/2=9
// 9/2=4 ,rem=1
// 4/2=2
// 2/2=1
// 1/2=0 ,rem=1

int main(){
    int num;
    printf("Enter your number:");
    scanf("%d", &num);
    int count = 0;
    while(num){
        if(num % 2)
        count++;
        num /= 2;
    }
    printf("The number of set bits is: %d", count);
    return 0;
}