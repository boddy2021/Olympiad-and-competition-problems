#include <stdio.h>

struct nod
{
	int val = 0;
	nod *vecin = NULL;
};

int n, m, q, rez;
int apar[250000];
nod *v[250000];

void init()
{
	for(int i = 1; i <= n; i++)
		v[i] = new nod;
}

void adaugare(int x, int y)
{
	nod *p = v[x];
	while(p -> vecin != NULL)
		p = p -> vecin;
	p -> val = y;
	nod *q = new nod;
	p -> vecin = q;
}

int dfs(int x, int r)
{
	if(apar[x] == 1)
		return x;
	if(apar[x] == 2)
		return -1;
	apar[x] = 1;
	nod *p = v[x];
	int c = 0, y = 0;
	while(p -> vecin != NULL)
	{
		if(r != p -> val)
		{
			y = dfs(p -> val, x);
			if(y > 0)
			{
				c = y;
				if(p -> val == y)
					apar[x]++;
			}
			else if(y == 0)
				rez++;
			if(c == x)
				c = -1;
		}
		p = p -> vecin;
	}
	if(c == -1)
		return 0;
	return c;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	int x, y;
	init();
	for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			adaugare(x, y);
			adaugare(y, x);
		}
	for(int j = 1; j <= q; j++)
	{
		scanf("%d%d", &x, &y);
		adaugare(x, y);
		adaugare(y, x);
		m++;
		for(int i = 1; i <= n; i++)
		{
			if(!apar[i])
				dfs(i, 0);
			apar[i] = 0;
		}
		printf("%d\n", rez);
		rez = 0;
	}
}
