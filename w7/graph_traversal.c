#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/graph/bfs.h"

int main() {
	Graph g;

	read_graph_from_file(&g, "graph_input.txt", true);
	print_graph(&g);
	bfs(&g, 1);
	
	return 0;
}
