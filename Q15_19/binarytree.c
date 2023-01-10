#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// create a new empty node
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Insertion
struct node *insertNode(struct node *root, int key)
{
    struct node *prev = NULL;
    if (root == NULL)
    {
        struct node *ele = createNode(key);
        root = ele;
        return root;
    }

    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *ele = createNode(key);
    if (key < prev->data)
    {
        prev->left = ele;
    }
    else
    {
        prev->right = ele;
    }
    return root;
}

// Deletion

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{

    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->data == value)
    {
        free(root);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

// Traversal codes
// PreOrder
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post Order
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// InOrder
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        printf("%d ", root->data);
        postOrder(root->right);
    }
}

// Searching
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{

    // initially empty root
    struct node *root = NULL;

    while (1)
    {
        int menu1 = 0;
        printf("Enter you Choice :\n");
        printf("Enter 1:insertion, 2:Deletion, 3:traverse, 4: Search, 4:exit\n");
        scanf("%d", &menu1);
        int value = 0;
        switch (menu1)
        {
        case 1:;

            printf("Enter the value to be added\n");
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("Element added\n");
            break;
        case 2:;

            printf("Enter value to be deleted\n");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:;
            int menu2 = 0;
            printf("Enter 1 : Preorder, 2: Inorder, 3: postorder\n");
            scanf("%d", &menu2);
            switch (menu2)
            {
            case 1:
                printf("PreOrder Traversal!!!\n");
                preOrder(root);
                printf("\n");
                break;
            case 2:
                printf("InOrder Traversal!!!\n");
                inOrder(root);
                printf("\n");
                break;

            default:
                printf("PostOrder Traversal!!!\n");
                postOrder(root);
                printf("\n");
                break;
            }
            break;

        case 4:
            printf("Enter value to be Search\n");
            scanf("%d", &value);
            struct node *rel = search(root, value);
            if (rel == NULL)
            {
                printf("Element not found!!\n");
            }
            else
            {
                printf("Element found!!\n");
            }

            break;

        default:
            printf("Code Ended Successfully");
            return 0;
        }
    }

    return 0;
}