#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./avl_tree.h"
#include "./printTreeASCII.h"

int cmp_func(void *root_key, void *cmp_key) {
	int root_key_val = *(int *)root_key;
	int cmp_key_val = *(int *)cmp_key;

	return root_key_val - cmp_key_val;
}

void print_payload(Tree_node *root) {
	int payload_val = *(int *)(root->payload);
	printf("%d ", payload_val);
	return;
}

int main(void) {
	Tree_node *root = NULL;
	int keys[] = { 10, 20, 30, 40, 50, 25 };
    int payloads[] = { 10, 20, 30, 40, 50, 25 };
    int nmemb = sizeof(keys) / sizeof(keys[0]);
    printf("%d \n", nmemb);
    for (int i = 0; i < nmemb; i++) {
		insert(&root, keys + i, payloads + i, cmp_func);
	}
    

	print_ascii_tree(root);
	int del_key_1 = 10;
	int del_key_2 = 40;
	int del_key_3 = 50;

	delete_node(&root, &del_key_1, cmp_func);
	delete_node(&root, &del_key_2, cmp_func);
	delete_node(&root, &del_key_3, cmp_func);

	print_ascii_tree(root);
	printf("\n");
	return 0;
}
