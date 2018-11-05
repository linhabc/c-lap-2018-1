#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/graph/dfs.h"

int main() {
  Graph *g = (Graph *)malloc(sizeof(Graph));

  read_graph_from_file(g, "graph_input.txt", true);

  add_vertex_name(g, 1, "V1");
  add_vertex_name(g, 2, "V2");
  add_vertex_name(g, 3, "V3");
  add_vertex_name(g, 4, "V4");
  
  print_graph(g);
  
  initialize_dfs(g);

  dfs(g, 1);
  
  return 0;
}
