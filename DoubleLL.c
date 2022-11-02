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
    struct Node *p = head;
    while (p->next != NULL)
    {
        printf("Element : %d \n", p->data);
        p = p->next;
    }
    printf("Element : %d \n", p->data); // data of last node

    printf("\n");
    while (p != NULL) // for re-traversing
    {
        printf("Element : %d \n", p->data);
        p = p->prev;
    }
}
//   INSERTION IN LINKED LIST

// Function for Inserting in the begining
struct Node *Insert_At_First(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->prev = NULL;
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
    ptr->prev = p;
    p->next = ptr;

    return head;
}

// Function for Insering At end
struct Node *Insert_At_End(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    ptr->prev = p;
    return head;
}

//   DELITION IN LINKED LIST

// Function to delete the First Node, In the Linked list
struct Node *Delete_At_First(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr); // free the space of first node
    ptr = NULL;
    return head;
}

// Function to delete any Node with given index, In the Linked list
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
    free(p);
    p = NULL;
    return head;
}

// Function to delete last Node, In the Linked list
struct Node *Delete_last_node(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (q->next != p)
    {
        q = q->next;
    }

    q->next = NULL;
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

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 4;
    second->prev = head;
    second->next = third;

    third->data = 46;
    third->prev = second;
    third->next = fourth;

    fourth->data = 12;
    fourth->prev = third;
    fourth->next = NULL;

    head = Insert_At_Index(head, 5, 1);
    traversing(head);
}
