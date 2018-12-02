#include <stdio.h>
#include <string.h>
#include "../lib/graph/weighted_graph_algo.h"

int main() {
  
  Graph *g = (Graph *)malloc(sizeof(Graph));
  read_weighted_graph(g, "graph_input.txt", true);
  sort_vertex_graph(g);

  // print_graph_by_vertex_index(g);
  print_graph(g);
  // prim(g, 1);
  // print_mini_spanning_tree(g);
  kruskal(g);
  return 0;
}