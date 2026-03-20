#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create circular linked list
void create() {
    int n, value;
    struct Node *newnode, *temp;

    printf("Enter how many nodes you want to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if (newnode == NULL) {
            printf("Memory Allocation Failed...\n");
            return;
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            head->next = head; 
            temp = head;
        } else {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
    }
    printf("List Created Successfully.....\n");
}

// Traversal
void nodetraversal() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insertion at beginning
void insertatbeg() {
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        head->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    printf("Node inserted at beginning.\n");
}

// Insertion at end
void insertatend() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        head->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
    printf("Node inserted at end.\n");
}

// Insertion at specific position
void insertatspec() {
    int pos, value, count = 1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;

    if (pos == 1) {
        insertatbeg();
        return;
    }

    struct Node *temp = head;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void deleteatbeg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *last = head;
    while (last->next != head)
        last = last->next;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteatend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        free(head);
        head = NULL;
    } else {
        prev->next = head;
        free(temp);
    }
    printf("Node deleted from end.\n");
}

// Delete from specific position
void deleteatspec() {
    int pos, count = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    if (pos == 1) {
        deleteatbeg();
        return;
    }

    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == pos) {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
    } else {
        printf("Invalid position.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n========== Circular Linked List =================\n");
        printf("Enter Your Choice:\n");
        printf("1. Creation\n2. Traversal\n3. Insertion at Beginning\n4. Insertion at End\n");
        printf("5. Insertion at Specific Position\n6. Delete from Beginning\n7. Delete from End\n");
        printf("8. Delete from Specific Location\n0. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;
            case 2: nodetraversal(); break;
            case 3: insertatbeg(); break;
            case 4: insertatend(); break;
            case 5: insertatspec(); break;
            case 6: deleteatbeg(); break;
            case 7: deleteatend(); break;
            case 8: deleteatspec(); break;
            case 0: printf("Exiting Program......\n"); break;
            default: printf("Invalid Choice\n");
        }
    } while(choice != 0);

    return 0;
}