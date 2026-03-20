#include <stdio.h>

int main() {
    int sparse[50][3], trans[50][3];
    int i, n;

    printf("Enter number of non-zero elements: ");
    scanf("%d", &n);

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &sparse[0][0], &sparse[0][1]);
    sparse[0][2] = n;

    printf("Enter row column value for each non-zero element:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }

    trans[0][0] = sparse[0][1];
    trans[0][1] = sparse[0][0];
    trans[0][2] = sparse[0][2];

    for (i = 1; i <= n; i++) {
        trans[i][0] = sparse[i][1];
        trans[i][1] = sparse[i][0];
        trans[i][2] = sparse[i][2];
    }

    printf("\nOriginal Sparse Matrix (Triplet Form):\n");
    printf("Row Col Val\n");
    for (i = 0; i <= n; i++) {
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    printf("\nTransposed Sparse Matrix (Triplet Form):\n");
    printf("Row Col Val\n");
    for (i = 0; i <= n; i++) {
        printf("%d   %d   %d\n", trans[i][0], trans[i][1], trans[i][2]);
    }

    return 0;
}
