#include <stdio.h>

FILE * f = fopen("coarde.in", "r");
FILE * g = fopen("coarde.out", "w");

const int max = 9999991;
int v[1001];

int coarda(int n)
{
	if(n > 15)
		return max;
	if(v[n])
		return v[n];
	for(int i = 2; i <= n; i+=2)
		v[n] += 2 * coarda((i - 2) / 2) * coarda((2 * n - i) / 2);
	if((n + 1) % 2 == 0)
		v[n] += coarda((n - 1) / 2) * coarda((n - 1) / 2);
	return v[n];
}

int main()
{
    int n;
    v[0] = 1;
    v[1] = 1;
    for(int i = 1; ; i++)
	{
		fscanf(f, "%d", &n);
		if(!n)
			break;
		fprintf(g, "%d:%d\n", i, coarda(n));
	}
}
