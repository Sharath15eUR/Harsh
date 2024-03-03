#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack is full\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    char item = stack[top--];
    return item;
}

int main(){
    char str[MAX_SIZE];
    printf("Enter your string:");
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++){
        push(str[i]);
    }
    for (int i = 0; i < n; i++){
        str[i] = pop(stack);
    }
    printf("Reversed string: %s", str);
    return 0;
}