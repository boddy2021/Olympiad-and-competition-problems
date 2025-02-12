#include <stdio.h>
#include <string.h>

char v[1000001], s[1000001];
int m, n, k;

FILE * f = fopen("eliminare.in", "r");
FILE * g = fopen("eliminare.out", "w");

int main()
{
    fscanf(f, "%s%d", v, &m);
    n = strlen(v);
    for(int i = 0; i < n; i++)
	{
		bool verif = false;
		if(n - m - k <= n - i)
			for(int j = 0; j <= k; j++)
				if(v[i] - '0' > s[j] - '0' && n - m - j <= n - i)
				{
					s[j] = v[i];
					k = j;
					verif = true;
					break;
				}
		if(!verif && k < n - m - 1)
			k++,
			s[k] = v[i];
	}
	fprintf(g, "%s", s);
}
