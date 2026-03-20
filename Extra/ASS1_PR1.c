#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX];
    int n = 0;
    int choice, i, pos, val, key, temp, found;
    int sum = 0;

    while (1) {
        printf("\n================ ARRAY MENU =================\n");
        printf("1. Create Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Display Array\n");
        printf("5. Search Element\n");
        printf("6. Sort Array (Ascending)\n");
        printf("7. Reverse Array\n");
        printf("8. Find Max and Min\n");
        printf("9. Sum of Elements\n");
        printf("10. Exit\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // Create
            printf("Enter number of elements: ");
            scanf("%d", &n);

            if (n <= 0 || n > MAX) {
                printf("Invalid size.\n");
                n = 0;
                break;
            }

            printf("Enter %d elements:\n", n);
            for (i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Array created successfully.\n");
            break;

        case 2: // Insert
            if (n >= MAX) {
                printf("Array is full.\n");
                break;
            }
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &val);

            for (i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = val;
            n++;
            printf("Element inserted.\n");
            break;

        case 3: // Delete
            if (n == 0) {
                printf("Array is empty.\n");
                break;
            }
            printf("Enter position (0 to %d): ", n - 1);
            scanf("%d", &pos);

            for (i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
            printf("Element deleted.\n");
            break;

        case 4: // Display
            if (n == 0) {
                printf("Array is empty.\n");
                break;
            }
            printf("Array elements: ");
            for (i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 5: // Search
            printf("Enter element to search: ");
            scanf("%d", &key);
            found = 0;

            for (i = 0; i < n; i++) {
                if (arr[i] == key) {
                    printf("Element found at index %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Element not found.\n");
            break;

        case 6: // Sort
            for (i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] > arr[j]) {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Array sorted successfully.\n");
            break;

        case 7: // Reverse
            for (i = 0; i < n / 2; i++) {
                temp = arr[i];
                arr[i] = arr[n - i - 1];
                arr[n - i - 1] = temp;
            }
            printf("Array reversed.\n");
            break;

        case 8: // Max & Min
            if (n == 0) {
                printf("Array is empty.\n");
                break;
            }
            int max = arr[0], min = arr[0];
            for (i = 1; i < n; i++) {
                if (arr[i] > max) max = arr[i];
                if (arr[i] < min) min = arr[i];
            }
            printf("Max = %d, Min = %d\n", max, min);
            break;

        case 9: // Sum
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Sum of elements = %d\n", sum);
            break;

        case 10: // Exit
            printf("Program terminated successfully.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
