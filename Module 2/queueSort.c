#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int item = queue[front];
    front++;
    return item;
}

void display() {
    if (front == -1) {
        printf("Error: Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void sortQueue() {
    int n = rear - front + 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
}

int main() {
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(5);
    enqueue(1);

    printf("Elements of the queue:\n");
    display();
    sortQueue();
    printf("Elements of the sorted queue in ascending order:\n");
    display();
    return 0;
}
