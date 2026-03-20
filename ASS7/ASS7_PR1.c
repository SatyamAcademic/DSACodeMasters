#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max];
int top = -1;

void push()
{
    int data, n, i;

    printf("How many elements you want to push? ");
    scanf("%d", &n);

    printf("Enter data: ");
    for(i = 0; i < n; i++)
    {
        if(top == max - 1)
        {
            printf("Stack is Full !! Cannot insert more elements.\n");
            return;
        }

        scanf("%d", &data);

        top++;
        stack[top] = data;
        printf("Element %d pushed successfully.\n", data);
    }
}

void pop()
{
    int data;
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    data = stack[top];
    top--;
    printf("Deleted Element is %d\n", data);
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top element is %d\n", stack[top]);
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is Empty...\n");
        return;
    }

    printf("Stack elements are:\n");
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top == max - 1)
        return 1;
    else
        return 0;
}

int main()
{
    int choice;

    do
    {
        printf("\n========= STACK MENU =========\n");
        printf("1. PUSH\n2. POP\n3. IsEmpty\n4. IsFull\n5. Peek\n6. Display\n0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                if(isEmpty() == 1)
                    printf("Stack is Empty\n");
                else
                    printf("Stack is Not Empty\n");
                break;

            case 4:
                if(isFull() == 1)
                    printf("Stack is Full\n");
                else
                    printf("Stack is Not Full\n");
                break;

            case 5:
                peek();
                break;

            case 6:
                display();
                break;

            case 0:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 0);

    return 0;
}
