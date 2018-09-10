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
	int result = val_of_a - val_of_b;
	//printf("%p - %p = %d\n", a, b, result);
	return result;
}

int main() {
	
	int arr[] = { 2, 1, 4, 3, 6, 5, 8, 9, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	
	quickSort(arr, 0, n - 1, sizeof(int), cmpInt);
	//quickSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;
}


