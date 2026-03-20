#include <stdio.h>
int main()
{
    int arr[10], ar[20], res[50];
    int f, s, i, j;
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

    for (i = 0; i < f; i++)
    {
        res[i] = arr[i];
    }
   for (j= 0; j < s; j++)
    {
        res[i+j] = ar[j];
    }
    printf("The New Array is: ");
    for (i = 0; i < f+s; i++)
    {
        printf("%d ", res[i]);
    }
    
    return 0;
}