#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

#include <stdlib.h>
#include "./avl_tree.h"

typedef int (*Compare_key_function)(void *, void *);

typedef struct
{
	Entry *entries;
	int size;
	int nmemb;
	New_entry_function new_entry;
	Compare_key_function cmp;
} Symbol_table;

#endif
