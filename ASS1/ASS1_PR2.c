#include<stdio.h>
int main()
{
    int arr[30];
    int n, i, loc;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    printf("Enter the Elements to Array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the location you want to delete from Array: ");
    scanf("%d", &loc);
    for(i=loc;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    printf("The New Array is: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
    
    return 0;
}
