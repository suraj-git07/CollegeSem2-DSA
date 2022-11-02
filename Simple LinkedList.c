#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traverse(struct Node *ptr)
{

    while (ptr != NULL)
    {

        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}
//   INSERTION IN LINKED LIST

// Function for Inserting in the begining
struct Node *Insert_At_First(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
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

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 14;
    third->next = NULL;

    head = Delete_node_between(head, 0);
    linked_list_traverse(head);
}
