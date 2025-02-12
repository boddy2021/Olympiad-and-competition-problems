#include <stdio.h>

FILE * f = fopen("deminare.in", "r");
FILE * g = fopen("deminare.out", "w");

int k, l, c, m, v[501][501];

int caut_maxim(int l1, int c1)
{
	int max = 0;
	for(int i = 1; i <= c - c1 + 1; i++)
		for(int j = 1; j <= l - l1 + 1; j++)
		{
			int sum = 0;
			for(int i1 = i; i1 <= i + c1; i1++)
				for(int j1 = j; j1 <= j + l1; j1++)
					sum += v[i1][j1];
			if(sum > max)
				max = sum;
		}
	return max;
}

int drep()
{
	int max = 0;
	for(int i = 1; i <= m / 2; i++)
	{
		if(i > l)
			break;
		if(m % i == 0)
		{
			int j = m / i;
			if(j <= c)
			{
				int x = caut_maxim(i, j);
				if(x > max)
					max = x;
			}
		}
	}
	if(m <= l)
	{
		int x = caut_maxim(m, 1);
		if(x > max)
			max = x;
	}
	return m - max;
}

void maxim_mine()
{
	int mine[501] = {0}, k = 0;
	int max = 0;
	for(int i = 1; i <= c; i++)
	{
		int sum = 0;
		for(int j = 1; j <= l; j++)
			sum += v[i][j];
		if(sum > max)
		{
			max = sum;
			k = 1;
			mine[k] = i;
		}
		else if(sum == max)
		{
			k++;
			mine[k] = i;
		}
	}
	for(int i = 1; i <= k; i++)
		fprintf(g, "%d ", mine[i]);
}

int main()
{
    fscanf(f, "%d%d%d%d", &k, &c, &l, &m);
    int x, y;
    for(int i = 1; i <= m; i++)
	{
		fscanf(f, "%d%d", &x, &y);
		v[x][y] = 1;
	}
	if(k == 1)
		maxim_mine();
	else
		fprintf(g, "%d", drep());
}
