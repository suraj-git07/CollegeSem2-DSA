#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversing(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // data of last node

    printf("\n NOW BACK \n");
    ptr = ptr->prev;
    do
    {

        printf("Element : %d \n", ptr->data);
        ptr = ptr->prev;
    } while (ptr != head->prev);
}
//   INSERTION IN doubly Circular LINKED LIST

// Function for Inserting in the begining
struct Node *Insert_At_First_End(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->prev = head->prev;
    head->prev->next = ptr;
    head->prev = ptr;
    ptr->data = data;
    return ptr;
}

// Function for Inserting at index
struct Node *Insert_At_Index(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next->prev = ptr;
    ptr->prev = p;
    p->next = ptr;
    return head;
}

//   DELITION IN LINKED LIST

// Function to delete the First Node, In the doubly circular Linked list
struct Node *Delete_At_First_End(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *last = head->prev;
    head = head->next;
    last->next = head;
    head->prev = last;
    free(ptr); // free the space of first node
    ptr = NULL;
    return head;
}

// Function to delete any Node with given index, In the  doubly circular Linked list
struct Node *Delete_node_between(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head;

    int i = 0, j = 0;
    while (i < index)
    {
        p = p->next;

        i++;
    }

    while (j < index - 1)
    {

        q = q->next;
        j++;
    }

    q->next = p->next;
    p->next->prev = q;
    free(p);
    p = NULL;
    return head;
}

void main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *last; // to keep track of last

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    last = fourth;

    head->data = 7;
    head->prev = last;
    head->next = second;

    second->data = 4;
    second->prev = head;
    second->next = third;

    third->data = 46;
    third->prev = second;
    third->next = fourth;

    fourth->data = 12;
    fourth->prev = third;
    fourth->next = head;
}
