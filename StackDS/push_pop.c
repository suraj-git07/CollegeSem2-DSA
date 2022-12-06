#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size; // complete size
    int top;  // index of top ele
    int *arr;
};

int isFull(struct Stack *head)
{
    if (head->top == (head->size - 1))
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Stack *head)
{
    if (head->top < 0) // one ele top index = 0
    {
        return 1;
    }
    return 0;
}

int push(struct Stack *head, int value)
{
    if (isFull(head))
    {
        printf("Stack Overflow !!\n");
        return -1;
    }

    else
    {
        head->top++;
        head->arr[head->top] = value;
        return 1;
    }
}
int pop(struct Stack *head) // pop and return the value
{
    if (isEmpty(head))
    {
        printf("Stack Underflow !!\n");
        return -1;
    }

    else
    {
        int val = head->arr[head->top];
        head->top--;
        return val;
    }
}

void traversing(struct Stack *head)
{
    if (head->top < 0)
    {
        printf("Entered Stack is Empty\n");
        return;
    }
    int i = 0;
    printf("traversing stack \n");
    while (i <= head->top)
    {
        printf("Element: %d \n", *(head->arr +(head->top)- i));
        i++;
    }
}

void main()
{

    printf("Create a Stack !!\n");
    int size;
    printf("Enter the size:\n");
    scanf("%d", &size);

    struct Stack *head;

    head = (struct Stack *)malloc(sizeof(struct Stack));
    head->top = -1;
    head->size = size;
    head->arr = malloc(sizeof(int[size]));

    while (1)
    {
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:Push, 2:Pop, 3: traversing,  4:exit\n");
        scanf("%d", &menu1);
        int menu2 = 0;
        switch (menu1)
        {
            int value = 0;
        case 1:;
            printf("Enter value :");
            scanf("%d", &value);
            if (push(head, value) != -1)
                printf("Value pushed!!\n");
            break;
        case 2:;
            value = pop(head);
            if (value != -1)
                printf("Popped value :%d \n", value);
            break;
        case 3:;
            traversing(head);
            break;

        default:
            printf("Code Ended Successfully");
            return;
        }
    }

    return ;
}