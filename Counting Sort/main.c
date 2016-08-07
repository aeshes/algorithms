#include <stdio.h>
#include <stdlib.h>

int * csort(int v[], int size){
	int i, j;
	int *c = (int *)malloc(size * sizeof(int));
	int *b = (int *)malloc(size * sizeof(int));

	memset(c, 0, size * sizeof(int));
	for(i = 0; i < size - 1; i++)
		for(j = i + 1; j < size; j++)
			if(v[i] < v[j])
				c[j]++;
			else
				c[i]++;
	for(i = 0; i < size; i++)
		b[c[i]] = v[i];
	for(i = 0; i < size; i++)
		printf("%d ", c[i]);
	printf("\n");
	free(c);
	return b;
}

int * dsort(int v[], int size, int lo, int hi){
	int i, j;
	int *d = (int *)malloc((hi - lo + 1) * sizeof(int));
	int *s = (int *)malloc(size * sizeof(int));

	memset(d, 0, (hi - lo + 1) * sizeof(int));
	for(i = 0; i < size; i++)
		d[v[i] - lo]++;
	for(i = 1; i <= hi - lo; i++)
		d[i] = d[i] + d[i - 1];
	for(i = size - 1; i >= 0; i--){
		j = v[i] - lo;
		s[d[j] - 1] = v[i];
		d[j]--;
	}
	free(d);
	return s;
}

int main(){
	int i;
	int v[] = {7, 2, 7, 2, 7, 2, 7, 2, 7, 2};
	
	int *a = csort(v, 8);
	int *b = dsort(v, 8, 0, 13);
	for(i = 0; i < 8; i++)
		printf("%d ", a[i]);

	putchar('\n');

	for(i = 0; i < 8; i++)
		printf("%d ", b[i]);

	free(a);
	free(b);
	scanf("%d", &i);
	return 0;
}
