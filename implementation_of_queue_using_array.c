#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int queue[5];

void enqueue(int data){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[front] = data;
    }
    else{
        rear++;
        queue[rear] = data;
    }
}
void dequeue(){
    front ++;
}
void display(){
    for(int i=front; i<rear+1;i++){
        printf("%d ",queue[i]);
    }
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    printf("\nafter one queue: \n");
    display();
    return 0;
}