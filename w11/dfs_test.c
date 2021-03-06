#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/graph/dfs.h"
#include "../lib/graph/bfs.h"

int main() {
  Graph *g = (Graph *)malloc(sizeof(Graph));

  read_graph_from_file(g, "graph_input.txt", false);
  sort_vertex_graph(g);

  print_graph(g);

  
  initialize_dfs(g);
  dfs(g, 1);

  printf("\nTopological sort : \n");
  initialize_topo_sort(g);
  topo_sort(g);
  printf("\n");

  initialize_dfs(g);
  printf("\nisCyclic :  %d\n", is_cyclic(g));

  
  return 0;
}
