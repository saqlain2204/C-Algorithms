// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *next;
}NODE;

NODE *head = NULL;

NODE *push(int data)
{
    NODE *newnode = malloc(sizeof(struct Node));
    newnode -> info = data;
    newnode -> next = head;
    
    head = newnode;
    return head;
}
NODE *pop()
{
    NODE *temp = head;
    head = head -> next;
    free(temp);
    return head;
}
void display(NODE *head)
{
    NODE *temp = head;
    while(temp->next != NULL)
    {
        printf("\n%d\n",temp->info);
        temp = temp->next;
    }
}
int main()
{
    
    head = push(5);
    head = push(7);
    head = push(9);
    head = push(10);
    printf("\nThe stack contents before pop operation is:  ");
    display(head);
    printf("\nThe stack contents after pop operation is: ");
    head = pop();
    display(head);
}