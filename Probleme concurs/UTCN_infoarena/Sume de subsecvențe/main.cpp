#include <stdio.h>

FILE * f = fopen("sume3.in", "r");
FILE * g = fopen("sume3.out", "w");

int v[501];

int maxim(int a, int b, int n)
{
	int min = -1, index = 0;
	for(int i = 1; i <= n - a; i++)
		if(n - i - a > b || i > n)
			if(v[i + a - 1] - v[i - 1] < min || min == -1)
				min = v[i + a - 1] - v[i - 1],
				index = i;
	int min1 = -1, index1 = 0;
	for(int i = 1; i + b <= index; i++)
		if(v[i + b - 1] - v[i - 1] < min1 || min1 == -1)
			min1 = v[i + a - 1] - v[i - 1],
			index1 = i;
	if(min1 > min)
		min = min1;
	min1 = -1;
	for(int  i = 1; i <= n; i++)
		if(i < index || i >= index + a)
			if(i < index1 || i >= index1 + b)
				if(v[i] - v[i - 1] < min1 || min1 = -1)
					min1 = v[i] - v[i - 1];
	if(min1 > min)
		min = min1;
	return min;
}

int rezolva(int n, int k)
{
	int min = -1;
	for(int i = 1; i <= n - k + 1; i++)
	{
		int x = maxim(, i, n);
		if(x < min || min == -1)
			min = x;
	}
	return min;
}

int main()
{
    int n, k;
    for(int i = 1; ; i++)
	{
		fscanf(f, "%d", &n);
		if(!n)
			break;
		fscanf(f, "%d", &k);
		for(int j = 1; j <= n; j++)
			fscanf(f, "%d", &v[i]),
			v[i] += v[i-1];
		fprintf(g, "%d:%d", i, rezolva(n, k));
	}
}
