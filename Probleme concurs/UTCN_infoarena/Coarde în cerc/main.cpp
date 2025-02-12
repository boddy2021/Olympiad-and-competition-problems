#include <stdio.h>

FILE * f = fopen("coarde.in", "r");
FILE * g = fopen("coarde.out", "w");

int v[1001];

int coarda(int n)
{
	if(v[n] || n == 0)
		return v[n];
	for(int i = 2; i <= n + 1; i+=2)
		v[n] += 2 * coarda((i - 2) / 2) * coarda((2 * n - i) / 2);
	return v[n];
}

int main()
{
    int n;
    v[1] = 1;
    for(int i = 1; ; i++)
	{
		fscanf(f, "%d", &n);
		if(!n)
			break;
		fprintf(g, "%d:%d\n", i, coarda(n));
	}
}
