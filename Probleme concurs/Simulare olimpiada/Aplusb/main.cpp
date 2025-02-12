#include <stdio.h>

FILE * f = fopen("aplusb.in", "r");
FILE * g = fopen("aplusb.out", "w");

int main()
{
    int a, b;
    fscanf(f, "%d%d", &a, &b);
    fprintf(g, "%d", a + b);
}
