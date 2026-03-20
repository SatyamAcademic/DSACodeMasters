#include <stdio.h>

void sumofele(int a[], int b[], int c[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }
}

int main()
{
    int arr[10], ar[20], res[50];
    int f, s, i;

    printf("Enter the size of First Array: ");
    scanf("%d", &f);

    printf("Enter the Elements to Array: ");
    for (i = 0; i < f; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the size of Second Array: ");
    scanf("%d", &s);

    printf("Enter the Elements to Array: ");
    for (i = 0; i < s; i++)
    {
        scanf("%d", &ar[i]);
    }

    if (f != s)
    {
        printf("Array sizes must be equal for addition\n");
        return 0;
    }

    sumofele(arr, ar, res, f);

    printf("The New Array is: ");
    for (i = 0; i < f; i++)
    {
        printf("%d ", res[i]);
    }

    return 0;
}
