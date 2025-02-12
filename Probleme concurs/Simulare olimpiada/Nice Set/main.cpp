#include <stdio.h>

FILE * f = fopen("niceset.in", "r");
FILE * g = fopen("niceset.out", "w");

long long n, v[300001], k;

void QuickSort(long long v[], int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(v, st , i - 1);
		QuickSort(v, i + 1 , dr);
	}
}

void rezolva()
{
	long long sum = v[1], modul = 0;
	int max = 0, index = 1;
	for(int i = 2; i <= n; i++)
	{
		while(modul + v[i] * (i - index) - sum > k && sum > 0)
		{
			sum -= v[index];
			modul = modul - (sum - v[index] * (i - 1 - index));
			index++;
		}
		if(i - index + 1 > max)
			max = i - index + 1;
		if(i - index > 0)
			modul += v[i] * (i - index) - sum;
		sum += v[i];
	}
	fprintf(g, "%d", max);
}

int main()
{
    fscanf(f, "%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++)
		fscanf(f, "%lld", &v[i]);
	QuickSort(v, 1, n);
	rezolva();
}
