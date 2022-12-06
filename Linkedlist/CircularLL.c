#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversing(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty!!\n");
        return;
    }

    struct Node *ptr = head;
    do
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // data of last node
}
//   INSERTION IN  Circular LINKED LIST

// Function for Inserting in the begining
struct Node *Insert_At_End(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        ptr->next = ptr;
        ptr->data = data;
        return ptr;
    }

    struct Node *last = head;
    do
    {
        last = last->next;
    } while (last->next != head);

    ptr->next = head;
    last->next = ptr;
    ptr->data = data;
    return head;
}
struct Node *Insert_At_First(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        ptr->next = ptr;
        ptr->data = data;
        return ptr;
    }

    struct Node *last = head;
    do
    {
        last = last->next;
    } while (last->next != head);

    ptr->next = head;
    last->next = ptr;
    ptr->data = data;
    return ptr;
}

// Function for Inserting at index
struct Node *Insert_After_value(struct Node *head, int data, int value)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    if (p->data == value)
    {
        printf("Element inserted after head!\n");
    }

    else
    {
        p = p->next;
        while (p->data != value && p->next != head)
        {
            p = p->next;
        }
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

//   DELITION IN LINKED LIST

// Function to delete the First Node, In the doubly circular Linked list
struct Node *Delete_At_First(struct Node *head)
{
    if (head == NULL)
    {
        printf("list is empty!!\n");
        return head;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *last = head;
    do
    {
        last = last->next;
    } while (last->next != head);

    head = head->next;
    last->next = head;
    free(ptr); // free the space of first node
    ptr = NULL;
    return head;
}
struct Node *Delete_At_End(struct Node *head)
{
    if (head == NULL)
    {
        printf("list is empty!!\n");
        return head;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *last = head;
    do
    {
        last = last->next;
    } while (last->next != head);

    while (ptr->next != last)
    {
        ptr = ptr->next;
    }

    ptr->next = head;

    free(last); // free the space of first node
    last = NULL;
    return head;
}

// Function to delete any Node with given index, In the  doubly circular Linked list
struct Node *Delete_value(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("list is empty!!\n");
        return head;
    }

    if (head->data == value && head->next == head)
    {
        free(head);
        head = NULL;
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head;
    int valueFound = 0;

    // int i = 0, j = 0;
    do
    {
        if (p->data == value)
        {
            valueFound = 1;
            break;
        }
        p = p->next;
    } while (p->next != head);

    if (valueFound)
    {
        while (q->next != p)
        {
            q = q->next;
        }
        q->next = p->next;
        free(p);
        p = NULL;
    }

    else
    {
        printf("Value Not Found\n");
    }
    return head;
}

void main(int argc, char const *argv[])
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;

    while (1)
    {
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:insertion, 2:Deletion, 3:traverse, 4:exit\n");
        scanf("%d", &menu1);
        int menu2 = 0;
        switch (menu1)
        {
        case 1:;

            printf("1: At_Start/End 2:After_value \n");
            scanf("%d", &menu2);
            int data = 0;
            int value = 0;
            switch (menu2)
            {
            case 1:;

                printf("Enter data :");
                scanf("%d", &data);
                printf("Enter 1: start 2:End:\n");
                int menu3 = 0;
                scanf("%d", &menu3);
                switch(menu3)
                {
                    case 1:;
                        head = Insert_At_First(head, data);
                        break;
                    default:;
                        head = Insert_At_End(head,data);
                }
                
                break;
            default:;
                printf("Enter data :");
                scanf("%d", &data);
                printf("\nEnter value :");
                scanf("%d", &value);
                head = Insert_After_value(head, data, value);
            }
            break;
        case 2:;

            printf("1: From_Start/End 2:Value \n");
            scanf("%d", &menu2);
            switch (menu2)
            {
            case 1:;
                int menu3 = 0;
                printf("1: Start 2:End \n");
                scanf("%d", &menu3);
                switch(menu3){
                    case 1:;
                        head = Delete_At_First(head);
                        break;
                    default:;
                        head = Delete_At_End(head);
                }
                break;
            default:;
                int value = 0;
                printf("\nEnter value :");
                scanf("%d", &value);
                head = Delete_value(head, value);
            }
            break;
        case 3:;
            traversing(head);
            break;
        default:
            printf("Code Ended Successfully");
            return;
        }
    }
}
