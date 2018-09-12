
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

int partition_two_way(void *arr, int low, int high, int size, comparator cmp) {
  
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

	return firsthing;
}

void quickSort_two_way (void *arr, int low, int high, int size, comparator cmp) {
	
	int p; // index of partition

	if ( low < high ) {
		p = partition_two_way(arr, low, high, size, cmp);
		quickSort_two_way(arr, low, p - 1, size, cmp);
		quickSort_two_way(arr, p + 1, high, size, cmp);
	}
	
	return;
}

void partition(void *arr, int size, comparator cmp, int low, int high, int *i, int *j)
{
	char *ptr_mid;
	char *ptr_high;
	char *ptr_low;
    // To handle 2 elements
    if (high - low <= 1)
    {
		ptr_high = (char *)arr + high *size;
		ptr_low = (char *)arr + low * size;
        if (cmp(ptr_high, ptr_low) < 0) {
			swap(ptr_high, ptr_low, size);
		}
            
        *i = low;
        *j = high;
        return;
    }
 
    int mid = low;
    void *ptr_pivot = malloc(size);

	ptr_high = (char *)arr + high * size;
	memcpy(ptr_pivot, ptr_high, size);
 
    while (mid <= high)
    {
		ptr_mid = (char *)arr + mid * size;
		ptr_high = (char *)arr + high * size;
		ptr_low = (char *)arr + low * size;;
		
        if (cmp(ptr_mid, ptr_pivot) < 0) {
			ptr_low = (char *)arr + (low++) * size;
			ptr_mid = (char *)arr + (mid++) * size;
			swap(ptr_low, ptr_mid, size);
		}
        else if (cmp(ptr_mid, ptr_pivot) == 0) {
            mid++;
		}
		else if (cmp(ptr_mid, ptr_pivot) > 0) {
			ptr_mid = (char *)arr + mid * size;
			ptr_high = (char *)arr + (high--) * size;
			swap(ptr_mid, ptr_high, size);
		}
    }
 
    *i = low - 1;
    *j = mid;
}

void quicksort(int arr[], int size, comparator cmp, int low, int high)
{
    if (low >= high) return;
 
    int i, j;

    partition(arr, size, cmp, low, high, &i, &j);
    quicksort(arr, size, cmp, low, i);
    quicksort(arr, size, cmp, j, high);
}

#endif

