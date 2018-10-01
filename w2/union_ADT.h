#ifndef __UNION_ADT
#define __UNION_ADT

typedef union {
	int i;
	long l;
	float f;
	double d;
	void *v;
	char *str;
	char ch;
} Jval;

Jval new_jval_i(int int_number) {
	Jval a;
	a.i = int_number;
	return a;
}

Jval new_jval_l(long long_number) {
	Jval a;
	a.l = long_number;
	return a;
}

Jval new_jval_f(int float_number) {
	Jval a;
	a.f = float_number;
	return a;
}

Jval new_jval_d(int double_number) {
	Jval a;
	a.d = double_number;
	return a;
}

Jval new_jval_str(char *str) {
	Jval a;
	a.str = str;
	return a;
}

Jval new_jval_c(char ch) {
	Jval a;
	a.ch = ch;
	return a;
}

int jval_i(Jval j) { return j.i; }
long jval_l(Jval j) { return j.l; }
float jval_f(Jval j) { return j.f; }
double jval_d(Jval j) { return j.d; }
char *jval_str(Jval j) { return j.str; }
char jval_ch(Jval j) { return j.ch; }

typedef int (* Comparator)(Jval a, Jval b);

int binarySearch(Jval *arr, int left, int right, Comparator cmp, Jval x) {
	if (left > right) return -1;

	int mid = left + (right - 1) / 2;
	if (cmp(arr[mid], x) == 0) {
		return mid;
	}

	if (cmp(arr[mid], x) > 0) {
		return binarySearch(arr, left, mid - 1, cmp, x);
	} else {
		return binarySearch(arr, mid + 1, right, cmp, x);
	}
}

void swap(Jval *a, Jval *b) {
	Jval temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int partition_two_way(Jval *arr, int low, int high, Comparator cmp) {
	int i;
	int p;
	int firsthing;

	p = high;
	firsthing = low;

	for (int i = low; i < high; i++) {
		if (cmp(arr[i], arr[p]) < 0) {
			swap(&arr[i], &arr[firsthing]);
			firsthing++;
		}
	}
	swap(&arr[p], &arr[firsthing]);
	return firsthing;
}

void qsort_two_way(Jval *arr, int low, int high, Comparator cmp) {
	int p;
	if (low < high) {
		p = partition_two_way(arr, low, high, cmp);
		qsort_two_way(arr, low, p - 1, cmp);
		qsort_two_way(arr, p + 1, high, cmp);
	}
	return;
}

#endif
