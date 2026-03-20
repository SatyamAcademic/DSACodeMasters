#include <stdio.h>
int larofele(int a[50], int n)
{
    int i, lar = a[0];
    for (i = 0; i < n; i++)
    {
        if (lar < a[i])
            lar = a[i];
    }
    return lar;
}
int main()
{
    int arr[10];
    int n, i;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    printf("Enter the Elements to Array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int larg = larofele(arr, n);

    printf("The largest Element is :%d ", larg);
    return 0;
}