#include <stdio.h>
#include <string.h>

int n;
char m[1001][1001];

int rezolvare_1()
{
	int c = 0, l = 0;
	for(int i = 0; i < n; i++)
	{
		c = 0;
		l = 0;
		for(int j = 0; j < n; j++)
			{
				c += m[j][i] - '0';
				l += m[i][j] - '0';
			}
		if(c != n / 2 || l != n / 2)
			return 0;
	}
	int e = 1, d = 0;
	for(int i = 1; i < n; i++)
	{
		if(strcmp(m[0], m[i]))
		{
			d = i;
			break;
		}
	}
	if(d == 0)
		return 0;
	for(int i = 1; i < n; i++)
	{
		if(!strcmp(m[0], m[i]))
			e++;
		else if(strcmp(m[d], m[i]))
				return 0;
	}
	return e == n / 2;
}

int maxim(int x)
{
	if(x > n / 2 - x)
		return n / 2 - x;
	return x;
}

int rezolvare_2()
{
	int l_1 = 0, c_1 = 0;
	for(int i = 0; i < n; i+=2)
	{
		if(m[i][0] - '0' == 1)
			c_1++;
		if(m[0][i] - '0' == 1)
			l_1++;
	}
	return maxim(l_1) + maxim(c_1);
}

int minim(int x)
{
	if(x < n / 2 - x)
		return 0;
	return 1;
}

void interschimbare(int i, char v[])
{
	for(int j = (i + 1) % 2; j < n; j += 2)
		if(v[j] != v[i])
		{
			printf("%d %d\n", i + 1, j + 1);
			char aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			return;
		}
}

void rezolvare_3()
{
	int x = rezolvare_2();
	printf("%d\n", x);
	if(!x)
		return;
	int cs = 0, ls = 0;
	char c1[1001] = {0}, l1[1001];
	strcpy(l1, m[0]);
	for(int i = 0; i < n; i++)
		c1[i] = m[i][0];
	for(int i = 0; i < n; i+=2)
	{
		if(m[i][0] - '0' == 1)
			cs++;
		if(m[0][i] - '0' == 1)
			ls++;
	}
	for(int i = minim(cs); i < n; i += 2)
		if(c1[i] - '0' == 1)
		{
			printf("L ");
			interschimbare(i, c1);
		}
	for(int i = minim(ls); i < n; i += 2)
		if(l1[i] - '0' == 1)
		{
			printf("C ");
			interschimbare(i, l1);
		}
}

int main()
{
    int p, t;
    scanf("%d %d", &p, &t);
    for(int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
			scanf("%s", m[j]);
		if(p == 1)
			printf("%d\n", rezolvare_1());
		if(p == 2)
			printf("%d\n", rezolvare_2());
		if(p == 3)
			rezolvare_3();
	}
}
