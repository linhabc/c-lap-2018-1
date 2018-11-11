#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "../lib/graph/dfs.h"
#include "../lib/graph/bfs.h"

void read_graph_from_file(Graph *g, char *fn, bool directed) {
	FILE *fp = fopen(fn, "r");

	if (fp == NULL) {
		printf("Can not open file \n");
	} else {
		init_graph(g, directed);

		int x, y; 
		int nedges;
		fscanf(fp, "%d %d", &(g->nvertices), &nedges);

		for (int i = 0; i < g->nvertices; i++) {
			char *buff = (char *)malloc(1000 * sizeof(char));
			fscanf(fp, "%s", buff);
			add_vertex_name(g, i, buff);
		}

		for (int i = 0; i < nedges; i++) {
			fscanf(fp, "%d %d", &x, &y);
			insert_edge(g, x, y, directed);
		}
	}
	return;
}

int main() {
	Graph *g = (Graph *)malloc(sizeof(Graph));
	read_graph_from_file(g, "graph_input.txt", true);

	print_graph_by_vertex_name(g);
	printf("\n");
	print_graph_by_vertex_index(g);

	printf("\n");
	initialize_dfs(g);
	dfs(g, 0);

	find_shortes_path(g, 0, 4, parent);
	printf("\n");
	return 0;
}
