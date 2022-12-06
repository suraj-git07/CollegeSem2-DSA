#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (head == NULL)
    {
        ptr->next = NULL;
        return ptr;
    }
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}


void traversing(struct Node *head)
{
    struct Node *p = head;
    if (head == NULL)
    {
        printf("Traversing completed\n");
        return;
    }

    while (p->next != NULL)
    {
        printf("Element : %d \n", p->data);
        p = p->next;
    }
    printf("Element : %d \n", p->data); // data of last node

    printf("\n");
    printf("Traversing completed\n");
    return;
}

struct Node *mergeLL(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->data = -1;
    tempNode->next = NULL;
    struct Node *ptr3 = tempNode;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data <= ptr2->data)
        {
            ptr3->next = ptr1;
            // printf("%d addded to dummy1\n", ptr1->data);
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            // printf("%d addded to dummy2\n", ptr2->data);
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1 != NULL)
    {
        // printf("%d addded to dummy khatam1\n", ptr1->data);
        ptr3->next = ptr1;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        // printf("%d addded to dummy khatam2\n", ptr2->data);
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
    }

    ptr3->next = NULL;
    return tempNode->next;
}

void main(int argc, char const *argv[])
{
    struct Node *head;
    // struct Node *head_1;
    // struct Node *head_2;
    // struct Node *head_3;
    // struct Node *head_4;

    struct Node *head2;
    // struct Node *head2_1;
    // struct Node *head2_2;
    // struct Node *head2_3;

    head = (struct Node *)malloc(sizeof(struct Node));
    // head_1 = (struct Node *)malloc(sizeof(struct Node));
    // head_2 = (struct Node *)malloc(sizeof(struct Node));
    // head_3 = (struct Node *)malloc(sizeof(struct Node));
    // head_4 = (struct Node *)malloc(sizeof(struct Node));

    // head->data = 4;
    // head->next = head_1;
    // head_1->data = 5;
    // head_1->next = head_2;
    // head_2->data = 8;
    // head_2->next = head_3;
    // head_3->data = 12;
    // head_3->next = head_4;
    // head_4->data = 13;
    // head_4->next = NULL;

    head2 = (struct Node *)malloc(sizeof(struct Node));
    // head2_1 = (struct Node *)malloc(sizeof(struct Node));
    // head2_2 = (struct Node *)malloc(sizeof(struct Node));
    // head2_3 = (struct Node *)malloc(sizeof(struct Node));

    // head2->data = 0;
    // head2->next = head2_1;
    // head2_1->data = 3;
    // head2_1->next = head2_2;
    // head2_2->data = 5;
    // head2_2->next = head2_3;
    // head2_3->data = 8;
    // head2_3->next = NULL;

    head = NULL;
    head2 = NULL;

    while (1)
    {
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:insertion, 2:traverse, 3:merge, 4:exit\n");
        scanf("%d", &menu1);
        int menu2 = 0;
        switch (menu1)
        {
        case 1:;

            printf("1: To first 2:To second\n");
            scanf("%d", &menu2);
            int data = 0;
            switch (menu2)
            {
            case 1:;

                printf("Enter data :\n");
                scanf("%d", &data);

                head = insert(head, data);
                break;
            default:;
                printf("Enter data :\n");
                scanf("%d", &data);

                head2 = insert(head2, data);
            }
            break;
        case 2:;

            printf("1: Polynomial1 2:polynomial2\n");
            scanf("%d", &menu2);
            switch (menu2)
            {
            case 1:;
                traversing(head);
                break;

            default:;
                traversing(head2);
            }
            break;
        case 3:;
            struct Node *mergedHead = mergeLL(head, head2);
            printf("\n After Merging\n");
            traversing(mergedHead);

            break;
        default:;
            printf("Code Ended Successfully");
            return;
        }
    }

}
