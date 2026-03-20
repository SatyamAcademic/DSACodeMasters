#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue()
{
    int value, n;
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter value to enqueue: ");
    for (int i = 0; i < n; i++)
    {
        if (rear == MAX - 1)
        {
            printf("Queue Overflow\n");
            return;
        }

        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
    }
    printf("Inserted successfully\n");
}

// Dequeue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

// Size
void size()
{
    if (front == -1)
        printf("Queue size: 0\n");
    else
        printf("Queue size: %d\n", rear - front + 1);
}

// Traverse
void traverse()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            size();
            break;
        case 4:
            traverse();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}