#include <stdio.h>
#include <math.h>

FILE * f = fopen("ornament.in", "r");
FILE * g = fopen("ornament.out", "w")
;
struct patrat
{
	int n, e, s, v;
};

patrat p[17];
int n, v[17], sol[5][5], nr1;

int corect(int i, int j)
{
	if(p[sol[i][j]].n != p[sol[i - 1][j]].s && sol[i - 1][j] != 0)
		return 0;
	if(p[sol[i][j]].s != p[sol[i + 1][j]].n && sol[i + 1][j] != 0)
		return 0;
	if(p[sol[i][j]].e != p[sol[i][j + 1]].v && sol[i][j + 1] != 0)
		return 0;
	if(p[sol[i][j]].v != p[sol[i][j - 1]].e && sol[i][j - 1] != 0)
		return 0;
	return 1;
}

void afisare()
{
	for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				fprintf(g, "%d ", sol[i][j]);
			fprintf(g, "\n");
		}
}

void backtrack(int i)
{
	int x = i % n;
	int y = i / n;
	y++;
	if(i % n == 0)
		y--;
	if(!x) x = n;
	for(int j = 1; j <= n * n; j++)
	{
		if(!v[j])
		{
				v[j] = 1;
				sol[y][x] = j;
			if(corect(y, x))
			{
				if(n * n == i)
						afisare(),
						nr1++;
				else
					backtrack(i + 1);
			}
			v[j] = 0;
		}
	}
	sol[y][x] = 0;
}

int main()
{
	fscanf(f, "%d", &n);
	n = sqrt(n);
	for(int i = 1;i <= n * n; i++)
		fscanf(f, "%d%d%d%d", &p[i].n, &p[i].e, &p[i].s, &p[i].v);
	int nr;
	fscanf(f, "%d", &nr);
	backtrack(1);
	if(nr == 2)
		fprintf(g, "%d", nr1);
}
