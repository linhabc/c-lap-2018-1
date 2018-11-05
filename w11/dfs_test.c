#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/graph/dfs.h"

int main() {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  read_graph_from_file(g, "graph_input.txt", true);

  print_graph(g);
  
  initialize_dfs(g);

  dfs(g, 1);
  
  return 0;
}
