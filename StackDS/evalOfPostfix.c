#include <stdio.h>
#include <stdlib.h>

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

int postfixEval(char *expression, int _size)
{
    struct Stack *useStack = (struct Stack *)malloc(sizeof(struct Stack));
    useStack->size = _size;
    useStack->top = -1;
    useStack->arr = (char *)malloc((useStack->size) * sizeof(char));
    int ans;
    int i = 0;
    while (expression[i] != '\0') // till not null
    {
        if (!isOperator(expression[i]))
        {
            printf("operator nahi hai\n");
            printf("%d ko push kiya\n", expression[i] - '0');
            push(useStack, expression[i] - '0');
        }
        else
        {
            printf("operator hai \n");
            int val1 = pop(useStack);
            printf("%d value ko pop kiya\n", val1);
            int val2 = pop(useStack);
            printf("%d value ko pop kiya\n", val2);
            if (expression[i] == '+')
            {
                printf("%d ko push kiya\n", val2 + val1);
                push(useStack, (val2 + val1));
            }
            else if (expression[i] == '-')
            {
                printf("%d ko push kiya\n", val2 - val1);
                push(useStack, val2 - val1);
            }
            else if (expression[i] == '*')
            {
                printf("%d ko push kiya\n", val2 * val1);
                push(useStack, val2 * val1);
            }
            else
            {
                printf("%d ko push kiya\n", val2 / val1);
                push(useStack, val2 / val1);
            }
        }
        i++;
    }

    return ans = pop(useStack);
}

void main()
{
    int expsize = 0;
    printf("Enter the size of expression:\n ");
    scanf("%d", &expsize);
    char postfixString[expsize + 1];
    printf("Enter the expression\n");
    scanf("%s", &postfixString);
    printf(" Evalution of this postfix expression is %d", postfixEval(postfixString, expsize));

    return;
}


// 562+*84/-
// 456+*
// 12345*+*+