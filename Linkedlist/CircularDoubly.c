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
    if (head == NULL)
    {
        printf("No elements\n");
        return;
    }
    struct Node *ptr = head;
    do
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // data of last node

    printf("traversing completed\n");
}

//   INSERTION IN doubly Circular LINKED LIST

// Function for Inserting in the begining
struct Node *Insert_At_First(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL)
    {
        ptr->next = ptr;
        ptr->prev = ptr;
    }
    else
    {
        ptr->next = head;
        ptr->prev = head->prev;
        head->prev->next = ptr;
        head->prev = ptr;
    }

    ptr->data = data;
    return ptr;
}
struct Node *Insert_At_End(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL)
    {
        ptr->next = ptr;
        ptr->prev = ptr;
        return ptr;
    }
    else
    {
        ptr->prev = head->prev;
        head->prev->next = ptr;
        ptr->next = head;
        head->prev = ptr;
    }

    return head;
}

// Function for Inserting after a value
struct Node *Insert_After_value(struct Node *head, int data, int value)
{
    if (head == NULL)
    {
        printf("NO element exists\n");
        return head;
    }
    else
    {
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        struct Node *p = head;
        if (p->data == value || p->next == p)
        {
            ptr->data = data;
            ptr->prev = p;
            ptr->next = p->next;
            p->next = ptr;
            ptr->next->prev = ptr;
            return head;
        }
        else
        {
            p = p->next;
        }
        while (p->data != value && p->next != head)
        {
            p = p->next;
        }
        if (p->next == head)
        {
            printf("value not found adding at start\n");
            p->next = ptr;
            ptr->next = head;
            head->prev = ptr;
            ptr->prev = p;

            ptr->data = data;
            return head;
        }

        ptr->prev = p;
        ptr->next = p->next;
        p->next = ptr;
        ptr->next->prev = ptr;
        ptr->data = data;
    }

    return head;
}

//   DELITION IN LINKED LIST

// Function to delete the First Node, In the doubly circular Linked list
struct Node *Delete_At_First(struct Node *head)
{
    if (head == NULL)
    {
        printf("No ele in list\n");
        return head;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct Node *ptr = head;
    struct Node *last = head->prev;
    head = head->next;
    last->next = head;
    head->prev = last;
    free(ptr); // free the space of first node
    ptr = NULL;
    return head;
}
struct Node *Delete_At_End(struct Node *head)
{
    if (head == NULL)
    {
        printf("No ele in list\n");
        return head;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    struct Node *ptr = head->prev;
    ptr->prev->next = head;
    head->prev = ptr->prev;
    free(ptr); // free the space of first node
    ptr = NULL;
    return head;
}

// Function to delete any Node with given index, In the  doubly circular Linked list
struct Node *Delete_value(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head;

    if (head == NULL)
    {
        printf("No ele in list\n");
        return head;
    }

    if (head->data == value && head->next == head)
    {
        free(head);
        head = NULL;
        return NULL;
    }

    int valueFound = 0;
    do
    {
        if (p->data == value)
        {
            valueFound = 1;
            break;
        }
        p = p->next;
    } while (p != head);

    if (valueFound)
    {
        while (q->next != p)
        {
            q = q->next;
        }
        q->next = p->next;
        p->next->prev = q;
        free(p);
        p = NULL;
    }

    else
    {
        printf("Value Not Found\n");
    }

    // q->next = p->next;
    // p->next->prev = q;
    // free(p);
    // p = NULL;
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
                switch (menu3)
                {
                case 1:;
                    head = Insert_At_First(head, data);
                    break;
                default:;
                    head = Insert_At_End(head, data);
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

            printf("1: From_Start/End 2:value \n");
            scanf("%d", &menu2);
            switch (menu2)
            {
            case 1:;
                int menu3 = 0;
                printf("1: Start 2:End \n");
                scanf("%d", &menu3);
                switch (menu3)
                {
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
            goto L;
        }
    }
L:
    printf("Code Ended Successfully");
}
