#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <stdlib.h>

typedef struct {
	int *matrix;
	int max_size;
} Graph;

Graph *new_graph(int max_size);
void init_graph(Graph *g);
void add_edge(Graph *g, int x, int y);
void print_graph(Graph *g);
void drop_graph(Graph *g);
#endif

