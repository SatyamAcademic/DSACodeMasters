#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *arr, n, i, key, found = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the Elements to the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("%d is present at index %d",arr[i],i);
    else
        printf("Element is not present in the array\n");

    free(arr);
    return 0;
}
