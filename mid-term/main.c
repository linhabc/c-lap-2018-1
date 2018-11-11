#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "../lib/graph/dfs.h"
#include "../lib/graph/bfs.h"

int main()
{

	Graph *g = (Graph *)malloc(sizeof(Graph));
	read_graph_from_file(g, "graph_input.txt", true);

	initialize_dfs(g);
	dfs(g, 2);

	find_shortes_path(g, 0, 4, parent);
	printf("\n\n");
	return 0;
}
