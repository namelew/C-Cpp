# include <stdio.h>
# include "cartesian.c"

int main(){
    Point a, b;

    scanf("%i %i", &a.x, &a.y);
    scanf("%i %i", &b.x, &b.y);

    printf("%.2lf\n", euclidians_distance(a, b));

    return 0;
}