#include <stdio.h>

FILE * f =fopen("armonica.in" , "r");
FILE * g =fopen("armonica.out" , "w");

int v[1000], count;
int a, b, c;

void divizori()
{
	long long pb;
	if(b % 2 == 1)
	{
		pb = b * b;
		for(int i = 1; i <= pb / 2; i += 2)
			if(pb % i == 0)
				count++,
				v[count] = i;
		fprintf(g, "%d\n", 2 * count + 1);
		fprintf(g, "%d %d\n", b, b);
		for(int i = 1; i <= count; i++)
		{
			a = (b + v[i]) / 2;
			c = (b + pb / v[i]) / 2;
			fprintf(g, "%d %d\n%d %d\n", a, c, c, a);
		}
	}
	else
	{
		int k = b / 2;
		pb = k * k;
		for(int i = 1; i <= k * k; i ++)
			if(pb % i == 0)
			count++,
			v[count] = i;
		fprintf(g, "%d\n", 2 * count + 1);
		fprintf(g, "%d %d\n", b, b);
		for(int i = 1; i <= count; i++)
		{
			a = k + v[i];
			c = k + pb / v[i];
			fprintf(g, "%d %d\n%d %d\n", a, c, c, a);
		}
	}
}

int main()
{
    fscanf(f, "%d", &b);
	divizori();
}
