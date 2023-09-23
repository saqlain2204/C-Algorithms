#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

NODE *enqueue(int data)
{
    NODE *newnode = malloc(sizeof(struct Node));
    newnode -> info = data;
    
    if(head==NULL && tail==NULL)
    {
        head = tail = newnode;
    }
    else{
        tail -> next = newnode;
        tail = newnode;
    }
    
    return tail;
}
NODE *dequeue(){
    NODE *ptr = head;
    if(head==NULL && tail==NULL)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        head = head -> next;
        free(ptr);
    }
    
    return head;
}
void display(NODE *head)
{
    NODE *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp = temp -> next;
    }
}
int main(){
    printf("Before dequeue: \n");
    tail = enqueue(1);
    tail = enqueue(2);
    tail = enqueue(4);
    tail = enqueue(3);
    display(head);
    printf("\nAfter dequeue: \n");
    head = dequeue();
    head = dequeue();
    display(head);
    
}