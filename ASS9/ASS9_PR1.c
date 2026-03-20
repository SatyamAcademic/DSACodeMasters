#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} st;

st *createNode(int value)
{
    st *newnode = (st *)malloc(sizeof(st));
    if (newnode == NULL)
    {
        printf("Memory allocation failed....\n");
        return NULL;
    }
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

st *insertNode(st *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        root->left = insertNode(root->left, value);

    return root;
}

st *findMin(st *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty\n");
        return NULL;
    }
    while (root->left != NULL)
        root = root->left;

    printf("Minimum Element: %d\n", root->data);
    return root;
}

st *findMax(st *root)
{
    if (root == NULL)
    {
        printf("Tree is Empty\n");
        return NULL;
    }
    while (root->right != NULL)
        root = root->right;

    printf("Maximum Element: %d\n", root->data);
    return root;
}

st *deleteNode(st *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        printf("Deleted element: %d\n", value);

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            st *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            st *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            st *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

st *searchNode(st *root, int value)
{
    if (root == NULL)
    {
        printf("Element Not Found\n");
        return NULL;
    }

    if (root->data == value)
    {
        printf("Element Found\n");
        return root;
    }

    if (value < root->data)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

void preOrder(st *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(st *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(st *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    st *root = NULL;
    int choice, val;

    do
    {
        printf("\n===== Binary Search Tree Menu =====\n");
        printf("1.Insert\n2.Delete\n3.Search\n4.FindMax\n5.FindMin\n6.PreOrder\n7.InOrder\n8.PostOrder\n0.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insertNode(root, val);
            printf("Inserted element: %d\n", val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            root = deleteNode(root, val);
            printf("Deleted element: %d\n", val);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            searchNode(root, val);
            printf("Searched element: %d\n", val);
            break;

        case 4:
            findMax(root);
            break;

        case 5:
            findMin(root);
            break;

        case 6:
            printf("PreOrder: ");
            preOrder(root);
            break;

        case 7:
            printf("InOrder: ");
            inOrder(root);
            break;

        case 8:
            printf("PostOrder: ");
            postOrder(root);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 0);

    return 0;
}