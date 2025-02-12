#include <stdio.h>

FILE * f = fopen("rufe.in", "r");
FILE * g = fopen("rufe.out", "w");

long long n, m, k, a, b;
long long minn, minm;

long long val_abs(int x, int y)
{
	if(x > y)
		return x - y;
	return y - x;
}

long long card_sum(long long x, long long maxn, long long maxm)
{
	long long sum = 0;
	if(maxn > maxm)
	{
		long long m1;
		if(x > maxn)
			m1 = x - maxn;
		else
			m1 = 0;
		if(m1 <= minm)
		{
			sum += (minm - m1 + 1) * 2;
			if(maxn - (minm - m1 + 1) > minn)
				sum += maxn - (minm - m1 + 1) - minn;
		}
		else
			if(maxn - (maxm - m1 + 1) > minn)
				sum += maxn - (maxm - m1 + 1);
			else
				sum += minn - (maxn - (maxm - m1 + 1));
		if(maxn - (maxm - m1) <= minn)
			sum  += (minn - (maxn - (maxm - m1)) + 1) * 2;
	}
	else
	{
		long long n1;
		if(x > maxm)
			n1 = x - maxm;
		else
			n1 = 0;
		if(n1 <= minn)
		{
			sum += (minn - n1 + 1) * 2;
			if(maxm - (minn - n1 + 1) > minm)
				sum += maxm - (minn - n1 + 1) - minm;
		}
		else
			if(maxm - (maxn - n1 + 1) > minm)
				sum += maxm - (maxn - n1 + 1);
			else
				sum += minm - (maxm - (maxn - n1 + 1));
		if(maxm - (maxn - n1) <= minm)
			sum  += (minm - (maxm - (maxn - n1)) + 1) * 2;
	}
	return sum;
}

long long abs(int a, int b)
{
	long long x = a - b;
	if(b - 1 >= x)
		return b - 1;
	return x;
}

long long abs1(int a, int b)
{
	long long x = a - b;
	if(b - 1 >= x)
		return x;
	return b - 1;
}

int main()
{
    fscanf(f, "%lld%lld%lld%lld%lld", &n, &m, &a, &b, &k);
    long long sum = 0, maxn = abs(n, a), maxm = abs(m, b);
    minn = abs1(n, a);
    minm = abs1(m, b);
    int contor = maxn + maxm;
    while(sum < k)
	{
		sum += card_sum(contor, maxn, maxm);
		contor--;
	}
	fprintf(g, "%d", contor + 1);
}
