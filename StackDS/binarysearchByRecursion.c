#include <stdio.h>
#include <stdlib.h>
int binarySearchRecursion(int arr[], int ele, int low, int high)
{

    if (low > high)
    {
        return -1;
    }

    else
    {

        int mid = (low + high) / 2;
        if (ele == arr[mid])
        {

            return mid;
        }

        else if (ele > arr[mid])
        {

            return binarySearchRecursion(arr, ele, mid + 1, high);
        }

        else
        {

            return binarySearchRecursion(arr, ele, low, mid - 1);
        }
    }
}

int main()
{
    int _size;
    printf("Enter the size of array\n");
    scanf("%d", &_size);
    int arr[_size];
    printf("enter the sorted array\n");
    for (int i = 0; i < _size; i++)
    {
        printf("Enter the %d element\n", i + 1);
        scanf("%d", &(arr[i]));
    }

    while (1)
    {
        int menu;
        printf("Enter 1 to search, 2 to exit\n");
        scanf("%d", &menu);
        if (menu == 1)
        {
            int ele;
            printf("enter the element you want to search\n");
            scanf("%d", &ele);
            int result = binarySearchRecursion(arr, ele, 0, _size - 1);
            if (result != (-1))
            {
                printf("element at pos %d in array\n", result);
            }
            printf("element not in array\n");
        }
        else
        {
            break;
        }
    }
    return 0;
}