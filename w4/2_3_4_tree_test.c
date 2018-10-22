#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/array_functions.h"
#include "./2_3_4_tree.h"

BTree_node *new_BTree_node(void *key, void *payload, int min_degree, int is_leaf) {
  BTree_node *ret = (BTree_node *)malloc(sizeof(BTree_node));
  ret->min_degree = min_degree;
  ret->key = key; ret->payload = payload;
  ret->is_leaf = is_leaf;
}

int main() {
  
  return 0;
}
