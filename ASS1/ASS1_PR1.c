// C Program to Insert an new Element at Desired Location of a partially filled Array.
#include <stdio.h>
int main()
{
	int arr[50];
	int n, i, loc, val;
	printf("Enter the size of Array: ");
	scanf("%d", &n);
	printf("Enter the Elements to Array: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the location and value of Array: ");
	scanf("%d %d", &loc, &val);
	if (loc < 0 || loc > n)
    {
        printf("Invalid location\n");
        return 0;
    }

	for (i = n; i > loc; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[loc] = val;
	printf("The New Array is: ");
	for (i = 0; i < n+1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
