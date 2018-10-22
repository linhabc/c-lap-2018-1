#include <stdio.h>
#include <stdlib.h>

int main (void) {

	int *nums = (int *)malloc(4 * sizeof(int));
	printf("nums : %p \n", nums);

	int *new_nums = (int *)realloc(nums, 5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		printf("%d ", new_nums[i]);
	}
	printf("new_nums: %p \n ", new_nums);
	return 0;
}
