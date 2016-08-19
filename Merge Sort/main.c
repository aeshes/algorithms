#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int L[], int left_count, int R[], int right_count, int out[])
{
	int left_iter = 0, right_iter = 0, out_iter = 0;

	while(left_iter < left_count && right_iter < right_count)
	{
		if(L[left_iter] <= R[right_iter])
			out[out_iter] = L[left_iter++];
		else
			out[out_iter] = R[right_iter++];
		out_iter++;
	}

	// Process the rest of elements
	if(left_iter == left_count)
		while (out_iter < (left_count + right_count))
			out[out_iter++] = R[right_iter++];
	else
		while (out_iter < (left_count + right_count))
			out[out_iter++] = L[left_iter++];
}

void mergesort(int a[], int n)
{
	int i = 0, split = n / 2;
	int *L = malloc(split * sizeof(a[0]));
	int *R = malloc((n - split) * sizeof(a[0]));

	if(n > 1)
	{
		for(i = 0; i < split; i++)
			L[i] = a[i];
		for(i = split; i < n; i++)
			R[i - split] = a[i];
		mergesort(L, split);
		mergesort(R, n - split);
		merge(L, split, R, n - split, a);
	}
	free(L);
	free(R);
}

int main(int argc, char *argv[])
{
	int i = 0;
	const int size = 300;
	int v[size];

	for (i = 0; i < size; i++)
		v[i] = i % 17;

	mergesort(v, size);

	for(i = 0; i < size; i++)
		printf("%d ", v[i]);

	scanf("%d", &i);
	return 0;
}