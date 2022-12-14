#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size; // complete size
    int top;  // index of top ele
    char *arr;
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

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int checkPrecedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char *infix_to_postfix(char *initial, int _size)
{
    struct Stack *useStack = (struct Stack *)malloc(sizeof(struct Stack));
    useStack->size = _size;
    useStack->top = -1;
    useStack->arr = (char *)malloc((useStack->size) * sizeof(char));
    char *ans = (char *)malloc((useStack->size + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (initial[i] != '\0') // till not null
    {
        if (!isOperator(initial[i]))
        {
            ans[j] = initial[i];
            j++;
            i++;
        }
        else
        {
            if (checkPrecedence(initial[i]) > checkPrecedence(useStack->arr[useStack->top]))
            {
                push(useStack, initial[i]);
                i++;
            }
            else
            {
                ans[j] = pop(useStack);
                j++;
            }
        }
    }
    while (!isEmpty(useStack))
    {
        ans[j] = pop(useStack);
        j++;
    }
    ans[j] = '\0'; // end null character for valid char array
    return ans;
}

void main()
{
    // char *infixString = "a+b*c*dE*FG";
    int expsize = 0;
    printf("Enter the size of expression:\n ");
    scanf("%d", &expsize);
    char infixString[expsize + 1];
    printf("Enter the expression\n");
    scanf("%s", &infixString);
    // for (int i = 0; i < expsize; i++)
    // {
    //     printf("Enter the %d character: \n",i+1);
    //     scanf("%c\n",&infixString[i]);

    // }
    // infixString[expsize-1] = '/0';

    // for (int i = 0; i < expsize; i++)
    // {
    //     printf("%c ",infixString[i]);
    // }

    // printf("postfix of expression is %s", infix_to_postfix(infixString, 11));
    printf("postfix of expression is %s", infix_to_postfix(infixString, expsize));

    return;
}