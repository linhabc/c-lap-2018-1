#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/graph/adj_list.h"

void create_edge_in_line(Graph *g, int *vertices) {
	for (int i = 0; i < 4; i++) {
		insert_edge(g, vertices[i], vertices[i + 1], false);
	}
	return;
}

void create_graph_from_file(Graph *g, char *fn) {
	FILE *fp = fopen(fn, "r");

	if (fp == NULL) {
		printf("Can not open file!\n");
		exit(1);
	} else {
		init_graph(g, false);
		int nline = 0;
		fscanf(fp, "%d ", &nline);
		g->nvertices = 4 * nline;
		
		char buff[1000];
		int vertices[5];
		while (fgets(buff, 1000, fp) != NULL) {
			sscanf(buff, "%d %d %d %d %d ",
				   &vertices[0],
				   &vertices[1],
				   &vertices[2],
				   &vertices[3],
				   &vertices[4]
				   );

			create_edge_in_line(g, vertices);
		}
	}
	
	fclose(fp);
	return;
}

int main() {

	Graph g;
	create_graph_from_file(&g, "station_input.txt");
	print_graph(&g);
	return 0;
}
