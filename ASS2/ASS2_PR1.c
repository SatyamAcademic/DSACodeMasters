#include <stdio.h>
#include <math.h>
struct POINT
{
    int xco, yco;
};
int main()
{
    struct POINT p1, p2;
    printf("Enter the coordinate of First Point: ");
    scanf("%d %d", &p1.xco, &p1.yco);
    printf("Enter the coordinate of Second Point: ");
    scanf("%d %d", &p2.xco, &p2.yco);
    float distance = sqrt(pow((p2.yco - p1.yco), 2) + pow((p2.xco - p1.xco), 2));
    printf("The distance is : %.2f", distance);
    return 0;
}