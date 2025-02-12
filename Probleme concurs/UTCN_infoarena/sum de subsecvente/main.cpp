#include <stdio.h>

FILE * f = fopen("sume3.in", "r");
FILE * g = fopen("sume3.out", "w");

int v[501];

int maxim(int a, int b, int n)
{
	int min = -1, index = 0;
	for(int i = 1; i <= n - a + 1; i++)
		if(n - i - a + 1 >= b || i > b)
			if(v[i + a - 1] - v[i - 1] < min || min == -1)
				min = v[i + a - 1] - v[i - 1],
				index = i;
	int min1 = -1, index1 = 0;
	for(int i = 1; i <= n - b + 1; i++)
		if(i + b <= index || i >= index + a)
			if(v[i + b - 1] - v[i - 1] < min1 || min1 == -1)
				min1 = v[i + b - 1] - v[i - 1],
				index1 = i;
	if(min1 > min)
		min = min1;
	min1 = -1;
	for(int i = 1; i <= n; i++)
		if(i < index || i >= index + a)
			if(i < index1 || i >= index1 + b)
				if(v[i] - v[i - 1] > min1 || min1 == -1)
					min1 = v[i] - v[i - 1];
	if(min1 > min)
		min = min1;
	return min;
}

int rezolva(int n, int k)
{
	if(k == 1)
		return v[n];
	int min = -1;
	for(int i = 1; i <= (n - k + 1) / 2 + 1; i++)
	{
		int x = maxim(n - k + 2 - i, i, n);
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
			fscanf(f, "%d", &v[j]),
			v[j] += v[j - 1];
		fprintf(g, "%d:%d\n", i, rezolva(n, k));
	}
}
