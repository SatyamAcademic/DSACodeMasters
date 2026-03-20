#include <stdio.h>
void transposemat(int a[10][10], int trans[10][10], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            trans[j][i] = a[i][j];
        }
    }
}
int main()
{
    int arr[10][10], trans[10][10];
    int r, c, i, j;
    printf("Enter the size of rows and column of Array: ");
    scanf("%d %d", &r, &c);
    printf("Enter the Elements to Array: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    transposemat(arr, trans, r, c);
    printf("The Transposed Matrix is: \n");
    for (i = 0; i < c; i++)
    {
        for (j= 0; j < r; j++)
        {

            printf("%d \t", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}