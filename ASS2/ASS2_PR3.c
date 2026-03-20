#include <stdio.h>

struct Distance {
    int km;
    int m;
};

struct Distance addDistance(struct Distance d1, struct Distance d2) {
    struct Distance result;
    result.m = d1.m + d2.m;
    result.km = d1.km + d2.km + (result.m / 1000);
    result.m = result.m % 1000;
    return result;
}

int main() {
    struct Distance d1, d2, sum;

    printf("Enter first distance (km m): ");
    scanf("%d %d", &d1.km, &d1.m);

    printf("Enter second distance (km m): ");
    scanf("%d %d", &d2.km, &d2.m);

    sum = addDistance(d1, d2);

    printf("Addition of Two Distance is : %d km %d m\n", sum.km, sum.m);
    return 0;
}
