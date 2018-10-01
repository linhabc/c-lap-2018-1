#include <stdio.h>
#include "../lib/array_functions.h"
#include "./union_ADT.h"

int cmpJvalInt(Jval a, Jval b) {
	return jval_i(a) - jval_i(b);
}

void printJvalInt(void const *ptr) {
	int value = jval_i(*(Jval *)ptr);
	printf("%d ", value);
	return;
}

int main() {

	Jval arr[] = {
		new_jval_i(1),
		new_jval_i(6),
		new_jval_i(3),
		new_jval_i(4),
		new_jval_i(5),
		new_jval_i(2),
		new_jval_i(7),
	};

	int nmemb = len(arr);
	//int index = binarySearch(arr, 0, nmemb - 1, cmpJvalInt, new_jval_i(5));
	//printf("%d \n", index);
	qsort_two_way(arr, 0, nmemb - 1, cmpJvalInt);
	forEach(arr, nmemb, sizeof(Jval), printJvalInt);
	return 0;
}
