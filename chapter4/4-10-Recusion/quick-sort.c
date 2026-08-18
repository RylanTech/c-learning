#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main(void) {
	int arr[] = {10, 249, 12, 3, 5, 2001, 6, 1, 80,  6, 7};
	size_t length = sizeof(arr) / sizeof(arr[0]);
	
	qsort(arr, 0, length);

	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void qsort(int v[], int left, int right) {
	int i, last;

	if (left >= right) { /* do nothing if array contains fewer than two elements */
		return;
	}
	
	swap(v, left, (left + right)/2); /* move partition elememt */
	last = left;

	for (i = left + 1; i <= right; i++) { /* partition */
		if (v[i] < v[left]) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
