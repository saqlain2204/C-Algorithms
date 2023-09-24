#include <stdio.h>
#include <stdlib.h>

int top = -1;
int stack[5];

void push(int data){
    if(top == 5 - 1){
        printf("Stack overflow\n");
    }
    else{
        top++;
        stack[top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("Stack underflow\n");
    }
    else{
        top--;
    }
}

void display(){
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    return 0;
}
