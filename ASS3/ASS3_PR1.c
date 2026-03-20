#include <stdio.h>

void input(int sparse[10][10], int r, int c)
{
    int i, j;
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &sparse[i][j]);
        }
    }
}

int checkSparse(int sparse[10][10], int r, int c)
{
    int i, j;
    int nz = 0, z = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (sparse[i][j] == 0)
                z++;
            else
                nz++;
        }
    }

    return (z > nz);
}

void convertTriplet(int sparse[10][10], int r, int c, int triplet[20][3], int nz)
{
    int i, j, k = 1;

    triplet[0][0] = r;
    triplet[0][1] = c;
    triplet[0][2] = nz;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (sparse[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparse[i][j];
                k++;
            }
        }
    }
}

void displayTriplet(int triplet[20][3], int nz)
{
    int i;
    printf("\nTriplet Representation:\n");
    printf("Row Col Value\n");

    for (i = 0; i <= nz; i++)
    {
        printf("%d   %d   %d\n",
               triplet[i][0],
               triplet[i][1],
               triplet[i][2]);
    }
}

int main()
{
    int sparse[10][10], triplet[20][3];
    int r, c;
    int nz = 0, z = 0;
    int i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    input(sparse, r, c);

    if (checkSparse(sparse, r, c))
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (sparse[i][j] != 0)
                    nz++;
            }
        }

        convertTriplet(sparse, r, c, triplet, nz);
        displayTriplet(triplet, nz);
    }
    else
    {
        printf("\nMatrix is NOT Sparse\n");
    }

    return 0;
}
