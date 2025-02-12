#include <stdio.h>
#include <math.h>

FILE * f = fopen("recyclebin.in", "r");
FILE * g = fopen("recyclebin.out", "w");

int n, v[1001];
int sum[1001][1001];

void caut_maxim(int poz)
{
	int poz_i = 0;
	long long max = sum[1][n];
	for(int i = 1; i <= n - poz + 1; i++)
		if(sum[1][i - 1] + sum[i + poz][n]> max)
			max = sum[1][i - 1] + sum[i + poz][n],
			poz_i = i;
	if(poz_i)
	{
		for(int i = 1; i < poz_i; i++)
			for(int j = poz_i + poz; j <= n; j++)
				sum[i][j - poz] = sum[i][j] - sum[poz_i][poz_i + poz - 1];
		for(int i = poz_i + poz; i <= n; i++)
			for(int j = i; j <= n; j++)
				sum[i - poz][j - poz] = sum[i][j];
		n -= poz;
	}
}

int main()
{
	fscanf(f, "%d", &n);
    for(int i = 1; i <= n; i++)
		fscanf(f, "%d", &v[i]);
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			sum[i][j] = sum[i][j - 1] + v[j];
	int p = 0;
	while(pow(2, p) <= n)
	{
		caut_maxim(pow(2, p));
		p++;
	}
	int max = -1 * pow(10, 9);
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			if(sum[i][j] > max)
				max = sum[i][j];
	fprintf(g, "%d ", max);
}

