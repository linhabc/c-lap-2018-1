#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/array_functions.h"
#include "./red_black_tree.h"
#include "./printTreeASCII.h"

int cmp_int(void *a, void *b) {
	int val_of_a = *(int *)a;
	int val_of_b = *(int *)b;
	return val_of_a - val_of_b;
}

void print_int(RBT_node *root) {
	printf("%d ", *(int *)(root->key));
	return;
}

void auto_insert(RBT *tree, int *keys, int *payloads, int nmemb) {
	for (int i = 0; i < nmemb; i++) {
		RBT_insert(tree, keys + i, payloads + i);
	}
	return;
}

int main() {

	int keys[] = {7, 6, 5, 4, 3, 2, 1};
	int payloads[] = {7, 6, 5, 4, 3, 2, 1};
	int nmemb = len(keys);

	RBT *tree = new_RBT(cmp_int);
	
	auto_insert(tree, keys, payloads, nmemb);

	print_ascii_tree(tree->root);

	return 0;
}
