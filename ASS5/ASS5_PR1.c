#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

/* ================= CREATE ================= */
void create()
{
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct Node *temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    printf("List Created Successfully...\n");
}

/* ================= TRAVERSAL Forward ================= */
void forwardTraversal()
{
    if(head == NULL)
    {
        printf("List is Empty...\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// TRAVERSAL For Backward
void backwardTraversal()
{
    if(head == NULL)
    {
        printf("List is Empty...\n");
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

/* ================= INSERT ================= */

void insertAtBeginning()
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Inserted at Beginning...\n");
}

void insertAtEnd()
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Inserted at End...\n");
}

void insertAtPosition()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        insertAtBeginning();
        return;
    }

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    struct Node *temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid Position...\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Inserted at Position %d...\n", pos);
}

/* ================= DELETE ================= */

void deleteAtBeginning()
{
    if(head == NULL)
    {
        printf("List is Empty...\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Deleted from Beginning...\n");
}

void deleteAtEnd()
{
    if(head == NULL)
    {
        printf("List is Empty...\n");
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
    printf("Deleted from End...\n");
}

void deleteAtPosition()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid Position...\n");
        return;
    }

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Deleted from Position %d...\n", pos);
}

/* ================= MAIN ================= */

int main()
{
    int choice;

    do
    {
        printf("\n1.Create\n2.Forward\n3.Backward\n");
        printf("4.Insert Beginning\n5.Insert End\n6.Insert Position\n");
        printf("7.Delete Beginning\n8.Delete End\n9.Delete Position\n0.Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: forwardTraversal(); break;
            case 3: backwardTraversal(); break;
            case 4: insertAtBeginning(); break;
            case 5: insertAtEnd(); break;
            case 6: insertAtPosition(); break;
            case 7: deleteAtBeginning(); break;
            case 8: deleteAtEnd(); break;
            case 9: deleteAtPosition(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid Choice\n");
        }

    } while(choice != 0);

    return 0;
}
