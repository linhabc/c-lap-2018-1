
#ifndef __QUICKSORT
#define __QUICKSORT

typedef int (*comparator)(void const *, void const *);

#ifndef __SWAP_FUNCTION
#define __SWAP_FUNCTION

void swap(void *a, void *b, size_t elementSize){
    void *tmp = malloc(elementSize);
    memcpy(tmp, a, elementSize);
    memcpy(a, b, elementSize);
    memcpy(b, tmp, elementSize);
    free(tmp);
	return;
}

#endif

int partition(void *arr, int low, int high, int size, comparator cmp) {
  
	int i;           // counter
	int p;           // pivot element index
	int firsthing;   // divider position for pivot

	char *ptr_i;
	char *ptr_p;
	char *ptr_firsthing;

	p = high;        // choose the pivot is the last element in array
	firsthing = low;
	
	ptr_p = (char *)arr + p * size;
  
	for (i = low; i < high; i++) {
		printf("low = %d, high = %d, i = %d\n", low, high, i);
		ptr_i = (char *)arr + i * size;
		ptr_firsthing = (char *)arr + firsthing * size;

		if ( cmp(ptr_i, ptr_p) < 0 ) {
			swap(ptr_i, ptr_firsthing, size);
			firsthing++;
		}
	}

	ptr_firsthing = (char *)arr + firsthing * size;
	swap(ptr_p, ptr_firsthing, size);

	printf("p = %d -----------\n", firsthing);
	return firsthing;
}

void quickSort(void *arr, int low, int high, int size, comparator cmp) {
	
	int p; // index of partition

	if ( low < high ) {
		p = partition(arr, low, high, size, cmp);
		quickSort(arr, low, p - 1, size, cmp);
		quickSort(arr, p + 1, high, size, cmp);
	}
	
	return;
}

#endif
