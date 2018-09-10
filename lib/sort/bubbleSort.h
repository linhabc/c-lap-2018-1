// no need extra lib

/*------- Declaration BEGIN-------------------------------------------*/

typedef int sortDataType;

int bubbleSortCmp(sortDataType a, sortDataType b) {

	// a > b return(1) => increasing
	// a < b return(1) => decreasing
	if (a  < b) return(1);
	
	if (a == b) return(0);
	
	return(-1);
}

/*------- Declaration END ------------------------------------------- */

void bubbleSwap(sortDataType *a, sortDataType *b) {

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void bubbleSort(sortDataType arr[], int n) {

	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if ( bubbleSortCmp(arr[j], arr[j + 1]) == 1) {
				bubbleSwap(&arr[j], &arr[j + 1]);
			}
		}
	}
	
	return;
}
