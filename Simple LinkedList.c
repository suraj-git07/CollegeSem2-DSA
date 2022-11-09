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
    
    while(1){
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:insertion, 2:Deletion, 3:traverse, 4:exit\n");
        scanf("%d",&menu1);
        int menu2 = 0;
        switch(menu1) {
        case 1:;
            
            printf("1: At_Start 2:At_Index 3: At_end\n");
            scanf("%d",&menu2);
            int data=0;
            int index =0;
            switch(menu2) {
            case 1:;
                
                printf("Enter data :");
                scanf("%d",&data);
                head = Insert_At_First(head,  data);
                break;
            case 2:;
                printf("Enter data :");
                scanf("%d",&data);
                printf("\nEnter =index :");
                scanf("%d",&index);
                head = Insert_At_Index(head,  data,index);
                break;
            default:;
                
                printf("Enter data :");
                scanf("%d",&data);
                head = Insert_At_End(head,  data);
            }
            break;
        case 2:;
           
            printf("1: From_Start 2:From_Index 3: From_end\n");
            scanf("%d",&menu2);
            switch(menu2) {
            case 1:;
                head = Delete_At_First(head );
                break;
            case 2:;
                int index = 0;
                printf("\nEnter =index :");
                scanf("%d",&index);
                head = Delete_node_between(head,index);
                break;
            default:
                head = Delete_last_node(head);
                
            }
            break;
        case 3:;
            linked_list_traverse(head);
            break;
        default:
           goto L;
        }
       
       
    }
    L:
     printf("Code Ended Successfully");
}
