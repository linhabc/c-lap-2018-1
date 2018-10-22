#ifndef __2_3_4_TREE_H__
#define __2_3_4_TREE_H__

typedef BTree_node* (*New_node_func)(void *, void *, int, int);

typedef struct _BTree_node {
  void *key;
  void *payload;
  int min_degree;
  int current_num_key;
  int is_leaf;
  _BTree_node **node_list;
} BTree_node

typedef struct {
  BTree_node *root;
  int min_degree;
  New_node_func new_node;
} BTree;


#endif
