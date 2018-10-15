#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./adj_list.h"
 
int main() {

	Graph g;
	read_graph_from_file(&g, "graph_input.txt", true);
	print_graph(&g);
	return 0;
}
