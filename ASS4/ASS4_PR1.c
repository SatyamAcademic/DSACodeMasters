#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Global head pointer */
struct Node* head = NULL;

/* Function declarations */
void createList();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition();
void traverseList();
void display();
void search();
void sortList();
void mergeList();
int countNodes();

/* Main function */
int main() {
    int choice;

    do {
        printf("\n========== Singly Linked List Menu ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Specific Position\n");
        printf("8. Sort the Linked List\n");
        printf("9. Merge Another Linked List\n");
        printf("10. Search an Element\n");
        printf("11. Display the Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: insertAtBeginning(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: deleteAtBeginning(); break;
            case 6: deleteAtEnd(); break;
            case 7: deleteAtPosition(); break;
            case 8: sortList(); break;
            case 9: mergeList(); break;
            case 10: search(); break;
            case 11: traverseList(); break;
            case 0: printf("Exiting program. Execution complete.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

/* Create linked list */
void createList() {
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes you want to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    head = NULL;

    for (i = 1; i <= n; i++) 
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked List created successfully.\n");
}

/* Insert at beginning */
void insertAtBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

/* Insert at end */
void insertAtEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

/* Insert at specific position */
void insertAtPosition() {
    int pos, i = 1;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (pos < 1 || pos > countNodes() + 1) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d.\n", pos);
}

/* Delete at beginning */
void deleteAtBeginning() {
    struct Node* temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.\n");
}

/* Delete at end */
void deleteAtEnd() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Node deleted from end.\n");
}

/* Delete at specific position */
void deleteAtPosition() {
    int pos, i = 1;
    struct Node *temp = head, *prev = NULL;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > countNodes()) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        head = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
        return;
    }

    while (i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node deleted from position %d.\n", pos);
}

/* Traverse linked list */
void traverseList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Traversing Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



/* Search element */
void search() {
    int key, pos = 1;
    struct Node* temp = head;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d.\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    printf("Element not found.\n");
}

/* Sort linked list */
void sortList() {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked List sorted successfully.\n");
}

/* Merge another list */
void mergeList() {
    int n, i, value;
    struct Node *temp = head, *newNode;

    printf("Enter number of nodes to merge: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return;
    }

    while (temp && temp->next)
        temp = temp->next;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked Lists merged successfully.\n");
}

/* Count nodes */
int countNodes() {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}
