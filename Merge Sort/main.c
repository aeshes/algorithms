#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int L[], int left_count, int R[], int right_count, int a[]){
	int i = 0, j = 0, k = 0;

	while(i < left_count && j < right_count){
		if(L[i] <= R[j])
			a[k] = L[i++];
		else
			a[k] = R[j++];
		k++;
	}
	if(i == left_count)
		memcpy(&a[k], &R[j], sizeof(R[0]) * (right_count - j));
	else
		memcpy(&a[k], &L[j], sizeof(L[0]) * (left_count - i));
}

void mergesort(int a[], int n){
	int i;
	int split = n / 2;
	int *L = (int *)malloc(split * sizeof(a[0]));
	int *R = (int *)malloc((n - split) * sizeof(a[0]));

	if(n > 1){
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

int main(int argc, char *argv[]){
	int i;
	int v[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

	mergesort(v, 10);

	for(i = 0; i < 10; i++)
		printf("%d ", v[i]);

	scanf("%d", &i);
	return 0;
}
