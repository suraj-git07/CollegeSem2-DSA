#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int frontIdx;
    int backIdx;
    int *arr;
};

int isEmpty(struct Queue *ptr)
{
    if ((ptr->backIdx) == ptr->frontIdx)
    {
        return 1;
    }

    return 0;
}

int isFull(struct Queue *ptr)
{
    if ((ptr->backIdx + 1) / ptr->size == ptr->frontIdx)
    {
        return 1;
    }

    return 0;
}

void enQueue(struct Queue *ptr, int value)
{

    if (isFull(ptr))
    {
        printf("Queue overflow!!!\n");
    }

    else
    {
        ptr->backIdx = (ptr->backIdx + 1) / ptr->size;
        ptr->arr[ptr->backIdx] = value;
        printf("Element %d is added\n", value);
    }
}

int deQueue(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue Underflow!!!\n");
        return -1;
    }

    else
    {
        int a;
        ptr->frontIdx = (ptr->frontIdx + 1) / ptr->size;
        a = ptr->arr[ptr->frontIdx];
        printf("element %d is removed\n ", a);
        return a;
    }
}

void traversing(struct Queue *ptr)
{
    printf("Queue:\n");
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }

    int i = ptr->frontIdx + 1;
    while (i != ptr->frontIdx)
    {
        printf("Element: %d\n", ptr->arr[i]);
        i = (i + 1) / ptr->size;
    }
}

void main()
{

    printf("Create a Queue !!\n");
    int size;
    printf("Enter the size:\n");
    scanf("%d", &size);

    struct Queue *myQueue;

    myQueue = (struct Queue *)malloc(sizeof(struct Queue));
    myQueue->size = size;
    myQueue->backIdx = -1;
    myQueue->frontIdx = -1;
    myQueue->arr = malloc(sizeof(int[size]));

    while (1)
    {
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:enqueue, 2:Dequeue, 3:traverse, 4:exit\n");
        scanf("%d", &menu1);
        switch (menu1)
        {
        case 1:;
            int value;
            printf("Enter the value\n");
            scanf("%d", &value);
            enQueue(myQueue, value);
            break;
        case 2:;
            int ele = deQueue(myQueue);
            break;
        case 3:;
            traversing(myQueue);
            break;

        default:
            printf("Code Ended Successfully");
            return;
        }
    }

    return;
}