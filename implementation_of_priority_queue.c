#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    int priority;
    struct Node *next;
} NODE;

NODE *head = NULL;
NODE *enqueue(NODE *head, int data, int priority)
{
    NODE *newnode = malloc(sizeof(struct Node));
    newnode->info = data;
    newnode->priority = priority;
    newnode->next = NULL;
    if (head == NULL || priority < head->priority)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    else
    {
        NODE *temp = head;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }
}
NODE *dequeue()
{
    NODE *temp = head;
    head = head->next;
    free(temp);
    return head;
}
void display(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = enqueue(head, 1, 5);
    head = enqueue(head, 2, 4);
    head = enqueue(head, 4, 1);
    display(head);

    printf("After dequeue, the queue looks like this: \n");
    head = dequeue();
    head = dequeue();
    display(head);
}