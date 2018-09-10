
/* ------------- Declaration BEGIN -------------------------------- */

typedef int sortDataType;

int quickCmp(sortDataType a, sortDataType b) {

	// a > b return(1) => decreasing
	// a < b return(1) => increasing

	if (a < b) return(1); 

	if (a == b) return(0);
	
	return(-1);
}

/* ------------- Declaration END ----------------------------------- */

void quickSwap(sortDataType *a, sortDataType *b) {

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int partition(sortDataType arr[], int low, int high) {

	int i;
	int p;           // pivot element index
	int firsthing;   // divider position for pivot
	int partition(sortDataType arr[], int low, int high) {

	int i;
	int p;           // pivot element index
	int firsthing;   // divider position for pivot

	p = high;        // choose the pivot is the last element in array

	firsthing = low;
	
	for (i = low; i < high; i++) {
		if ( quickCmp(arr[i], arr[p]) == 1 ) {
			quickSwap(&arr[i], &arr[firsthing]);
			firsthing++;
		}
	}

	quickSwap(&arr[p], &arr[firsthing]);

	return(firsthing);
}

void quickSort(sortDataType arr[], int low, int high) {

	int p; // index of partition

	if ( low < high ) {
		p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
	
	return;
}
	p = high;        // choose the pivot is the last element in array

	firsthing = low;
	
	for (i = low; i < high; i++) {
		if ( quickCmp(arr[i], arr[p]) == 1 ) {
			quickSwap(&arr[i], &arr[firsthing]);
			firsthing++;
		}
	}

	quickSwap(&arr[p], &arr[firsthing]);

	return(firsthing);
}

void quickSort(sortDataType arr[], int low, int high) {

	int p; // index of partition

	if ( low < high ) {
		p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
	
	return;
}
