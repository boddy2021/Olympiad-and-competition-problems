#include <stdio.h>

FILE * f = fopen("arbori2.in", "r");
FILE * g = fopen("arbori2.out", "w");

const int max = 9999991;
int n, v[201], val[201];

int nod(int k)
{
	if(val[k])
		return val[k];
	for(int i = 0; i <= k / 2; i++)
		val[k] += (2 * nod(i) * nod(k - i - 1)) % max;
	if(k % 2 == 1)
		val[k] += val[k / 2 + 1];
	return val[k];
}

int rezolva()
{
	//for(int i = 1; i <= n; i++)

}

int main()
{
	val[2] = 2; val[0] = 1; val[1] = 1;
/*	for(int j = 1; ; j++)
	{
		fscanf(f,"%d", &n);
		if(!n)
			break;
		for(int i = 1; i <= n; i++)
			fscanf(f, "%d", &v[i]);
		//fprintf(g, "%d:%d", j, rezolva(v[1], n));
		nod(n);
	}*/
	printf("%d", nod(3));
}
