#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/sort/quickSort.h"
//#include "../cLib/lib/sort/quickSort.h"

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int cmpInt(void const *a, void const *b) {
	int val_of_a = *(int *)a;
	int val_of_b = *(int *)b;
	return val_of_a - val_of_b;
}

int main() {
	
	int arr[] = { 2, 1, 4, 3, 6, 5, 8, 9, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, sizeof(int), cmpInt, 0, n - 1);
	//swap(&arr[1], &arr[4], sizeof(int));
	printArray(arr, n);
	return 0;
}


