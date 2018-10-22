#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./graph.h"

Graph *new_graph(int max_size) {
	Graph *ret = (Graph *)malloc(sizeof(Graph));
	int *matrix = (int *)malloc((max_size + 1) * (max_size + 1) * sizeof(int));
	ret->max_size = max_size;
	ret->matrix = matrix;
	init_graph(ret);
	return ret;
}

void init_graph(Graph *g) {
	int max_size = g->max_size;
	int nmemb = (max_size + 1) * (max_size + 1);
	for (int i = 1; i < nmemb; i++) {
		g->matrix[i] = 0;
	}
	return;
}

void add_edge(Graph *g, int x, int y) {
	int max_size = g->max_size;
	int *matrix = g->matrix;
	int target_index = x + y * max_size;
	matrix[target_index] = 1;
	return;
}

void print_graph(Graph *g) {
	int max_size = g->max_size;
	int *matrix = g->matrix;
	for (int i = 1; i <= max_size; i++) {
		for (int j = 1; j <= max_size; j++) {
			int index = i + j * max_size;
			printf(" %d", matrix[index]);
		}
		printf("\n");
	}
	return;
}

void drop_graph(Graph *g) {
	free(g->matrix);
	free(g);
	return;
}

