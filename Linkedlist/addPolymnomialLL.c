#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node *next;
};

struct Node *insert(struct Node *head, int coeff, int expo)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->coeff = coeff;
    ptr->power = expo;
    if (head == NULL)
    {
        ptr->next = NULL;
        return ptr;
    }
    struct Node *ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }

    ptr1->next = ptr;
    ptr->next = NULL;
    return head;
}

void traverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("No Polynomial entered\n");
        return;
    }
    while (head != NULL)
    {
        printf(" %d X^%d ", head->coeff, head->power);
        head = head->next;
    }
    // printf("Element : %d X^%d \n", head->coeff,head->power); // data of last node

    printf("\n");
    printf("Polynomial Printed\n");
    return;
}

struct Node *add(struct Node *poly1, struct Node *poly2)
{
    if (poly1 == NULL)
    {
        return poly2;
    }
    if (poly2 == NULL)
    {
        return poly1;
    }
    if (poly1 == NULL && poly2 == NULL)
    {
        printf("Enter the polynomial First\n");
    }

    struct Node *ptr1 = poly1;
    struct Node *ptr2 = poly2;
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->next = NULL;
    struct Node *ptr3 = tempNode;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->power < ptr2->power)
        {
            // printf("pol2 ka laga\n");
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        if (ptr1->power == ptr2->power)
        {
            // printf("dono ka laga\n");
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->coeff = ptr1->coeff + ptr2->coeff;
            temp->power = ptr1->power;
            temp->next = NULL;
            ptr3->next = temp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            // printf("pol2 ka laga\n");
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
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

void main()
{
    struct Node *poly1;
    struct Node *poly2;

    poly1 = (struct Node *)malloc(sizeof(struct Node));
    poly2 = (struct Node *)malloc(sizeof(struct Node));

    poly1 = NULL;
    poly2 = NULL;

    while (1)
    {
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:insertion, 2:traverse, 3:add, 4:exit\n");
        scanf("%d", &menu1);
        int menu2 = 0;
        switch (menu1)
        {
        case 1:;

            printf("1: To first 2:To second\n");
            scanf("%d", &menu2);
            int coeff = 0;
            int expo = 0;
            switch (menu2)
            {
            case 1:;

                printf("Enter Coeff :\n");
                scanf("%d", &coeff);
                printf("Enter expo :\n");
                scanf("%d", &expo);
                poly1 = insert(poly1, coeff, expo);
                break;
            default:;
                printf("Enter Coeff :\n");
                scanf("%d", &coeff);
                printf("Enter expo :\n");
                scanf("%d", &expo);
                poly2 = insert(poly2, coeff, expo);
            }
            break;
        case 2:;

            printf("1: Polynomial1 2:polynomial2\n");
            scanf("%d", &menu2);
            switch (menu2)
            {
            case 1:;
                traverse(poly1);
                break;

            default:;
                traverse(poly2);
            }
            break;
        case 3:;
            printf("adding ho gyi\n");
            struct Node *addPoly = add(poly1, poly2);
            printf("\n After adding polynomials\n");
            traverse(addPoly);
            break;
        default:;
            printf("Code Ended Successfully");
            return;
        }
    }

    return;
}