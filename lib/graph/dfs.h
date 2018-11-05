#ifndef __GRAPH_DFS_H__
#define __GRAPH_DFS_H__

#include <stdio.h>
#include "./adj_list.h"

bool processed[MAXV + 1];  // which vertex have been processed
bool discoverded[MAXV + 1]; // which vertex have been discoverded
int parent[MAXV + 1];

int entry_time[MAXV + 1];
int exit_time[MAXV + 1];

int time;
bool finished;

void initialize_dfs(Graph *g) {
  for (int i = 0; i < g->nvertices; i++) {
    processed[i] = discoverded[i] = false;
    parent[i] = -1;
    entry_time[i] = exit_time[i] = 0;
  }
  
  time = 0;
  finished = false;
  return;
}

void find_path(int start, int end, int parent[]) {
  if ((start == end) || end == -1) {
    printf("\n %d", start);
  }
  else {
    find_path(start, parent[end], parent);
    printf(" %d", end);
  }
  
  return;
}

void process_vertex_ealy(int v) {
  printf("process vertex : %d\n", v);
  return;
}

void process_edge(int x, int y) {

  if ((parent[y] != x) && (parent[x] != y)) {
    printf("\nGraph contain a circle!\n");

    printf("Cycle from %d to %d", x, y);
    find_path(y, x, parent);
    printf("\n\n");

    finished = true;
  }
  return;
}

void process_vertex_late(int v) {

  return;
}

void dfs(Graph *g, int v) {
  Edgenode *p;     // temp node
  int y;           // successor vertex

  if (finished) return;
  
  discoverded[v] = true;
  time = time + 1;
  entry_time[v] = time;
	
  process_vertex_ealy(v);
  
  p = g->edges[v];
  
  while (p != NULL) {
    y = p->y;
    if (discoverded[y] == false) {
      parent[y] = v;
      process_edge(v, y);
      dfs(g, y);
    }
    else if (!processed[y] || g->directed) {
      process_edge(v, y);
    }

    if (finished) return;

    p = p->next;
  }

  process_vertex_late(v);

  time = time + 1;
  exit_time[v] = time;

  processed[v] = true;
  return;
}

#endif
