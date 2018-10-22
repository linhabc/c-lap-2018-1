#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./graph.h"

int main() {

	Graph *g = new_graph(10);

	add_edge(g, 1, 2);
	add_edge(g, 2, 3);
	add_edge(g, 1, 4);
	add_edge(g, 3, 2);
	add_edge(g, 5, 5);
	
	print_graph(g);
	drop_graph(g);
	return 0;
}
