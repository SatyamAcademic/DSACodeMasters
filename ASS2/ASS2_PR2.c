#include <stdio.h>

struct STUDENT
{
    char name[60];
    int roll_no;
    char branch[20];
    float CGPA;
};

int main()
{
    struct STUDENT s[5];
    int i, topIndex = 0;

    for (i = 0; i < 5; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);

        printf("Branch: ");
        scanf(" %s", s[i].branch);

        printf("CGPA: ");
        scanf("%f", &s[i].CGPA);
    }

    for (i = 1; i < 5; i++)
    {
        if (s[i].CGPA > s[topIndex].CGPA)
        {
            topIndex = i;
        }
    }

    printf("\n--- Student with Highest CGPA ---\n");
    printf("Name   : %s\n", s[topIndex].name);
    printf("Roll No: %d\n", s[topIndex].roll_no);
    printf("Branch : %s\n", s[topIndex].branch);
    printf("CGPA   : %.2f\n", s[topIndex].CGPA);

    return 0;
}
