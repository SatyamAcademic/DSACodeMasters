#include <stdio.h>

void tripletToSparse(int triplet[20][3], int sparse[10][10])
{
    int i, r, c, nz;

    r = triplet[0][0];
    c = triplet[0][1];
    nz = triplet[0][2];

    for (i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sparse[i][j] = 0;
        }
    }

    for (i = 1; i <= nz; i++)
    {
        sparse[triplet[i][0]][triplet[i][1]] = triplet[i][2];
    }
}

void displaySparse(int sparse[10][10], int r, int c)
{
    int i, j;
    printf("\nSparse Matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int triplet[20][3];
    int sparse[10][10];
    int i, nz;

    printf("Enter number of non-zero elements: ");
    scanf("%d", &nz);

    printf("Enter triplet matrix (row col value):\n");
    for (i = 0; i <= nz; i++)
    {
        scanf("%d %d %d",
              &triplet[i][0],
              &triplet[i][1],
              &triplet[i][2]);
    }

    tripletToSparse(triplet, sparse);
    displaySparse(sparse, triplet[0][0], triplet[0][1]);

    return 0;
}
