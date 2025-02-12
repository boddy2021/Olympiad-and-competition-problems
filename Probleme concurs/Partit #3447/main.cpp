#include <stdio.h>
#include <math.h>

FILE * f = fopen("partit.in", "r");
FILE * g = fopen("partit.out", "w");

void afisare_partit(long long n, long long k)
{
	if(n == 0)
		return;
	long long l = 1;
	if(n <= 64)
	{
		long long m = 2, x = pow(2, n - 2);
		while(k > x && l != n)
		{
			k -= x;
			m++;
			l++;
			x = pow(2, n - m);
		}
	}
	fprintf(g, "%lld ", l);
	if(l == n)
		return;
	afisare_partit(n - l, k);
}

void prelucrare_nr(long long n, long long l, long long &nr)
{
	if(n == l)
		nr += pow(2, n - 1);
	else
		{
			for(int i = 2; i <= l; i++)
				nr += pow(2, n - i);
		}
}

int main()
{
    long long c, n, k, nr = 0;
    fscanf(f, "%lld%lld", &c, &n);
    if(c == 1)
	{
		fscanf(f, "%lld", &k);
		afisare_partit(n, k);
	}
	if(c == 2)
	{
		while(!feof(f))
		{
			fscanf(f, "%lld", &k);
			prelucrare_nr(n, k, nr);
			n -= k;
		}
		fprintf(g, "%lld", nr);
	}
}
