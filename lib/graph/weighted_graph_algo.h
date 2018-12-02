#ifndef __WEIGHTED_GRAPH_ALGO_H__
#define __WEIGHTED_GRAPH_ALGO_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../graph/adj_list.h"

#define INT_MAX 100000000

int parent[MAXV + 1];

// Prim's minimum  spanning tree algorithm 
void prim(Graph *g, int start) {
  int i;                   /* counter */
  Edgenode *p;             /* temporary pointer */
  bool intree[MAXV + 1];   /* is the vertex is in tree yet ? */
  int distance[MAXV + 1]; /* cost off adding vertex to tree */
  int v;                   /* current vertex to process */
  int y;                   /* candidate next vertex */
  int weight;              /* edge weight */
  int dist;                /* best current distance from start */

  for (i = 1; i <= g->nvertices; i++) {
    intree[i] = false;
    distance[i] = INT_MAX;
    parent[i] = -1;
  }

  distance[start] = 0;
  v = start;

  while (intree[v] == false) {
    intree[v] = true;
    p = g->edges[v];
    
    while (p != NULL) {
      y = p->y;
      weight = p->weight;
      if ((distance[y] > weight) && (intree[y] == false)) {
        distance[y] = weight;
        parent[y] = v;
        printf("edge (%d, %d) weight : %d\n", v, y, weight);
      }
      
      p = p->next;
    }

    v = 1;
    dist = INT_MAX;
    for (i = 1; i <= g->nvertices; i++) {
      if ((intree[i] == false) && (dist > distance[i])) {
        dist = distance[i];
        v = i;
      }
    }
      
  }

  return;
}

void print_mini_spanning_tree(Graph *g) {
  printf("\n");
  for (int i = 1; i <= g->nvertices; i++) {
    printf(" %d", parent[i]);
  }
  printf("\n");
  return;
}

/* END Prim's algorithms */

/* Kruskal's Algorithms */
/* finding spanning tree */

#define SET_SIZE 10000

typedef struct {
  int p[SET_SIZE + 1];    /* parent elements */
  int size[SET_SIZE + 1]; /* number of element in subtree i */
  int n;                  /* number of element in set */
} Set_union;

typedef struct {
  int x;
  int y;
  int weight;
} Edge_pair;

void print_graph(Graph *g) {
  Edgenode *p; // temp pointer

  for (int i = 1; i <= g->nvertices; i++) {
    p = g->edges[i];
    while (p != NULL) {
      printf("(%d, %d, %d) \n", i, p->y, p->weight);
      p = p->next;
    }
    printf("\n");
  }
  return;
}

void set_union_init(Set_union *s, int n) {
  for (int i = 1; i <= n; i++) {
    s->p[i] = i;
    s->size[i] = 1;
  }
  s->n = n;
  return;
}

/*
  Find(i) – Find the root of tree containing element i, 
  by walking up the parent pointers 
  until there is nowhere to go. 
  Return the label of the root.
*/
int find(Set_union *s, int x) {
  if (s->p[x] == x) {
    return x;
  } else {
    return find(s, s->p[x]);
  }
}

void union_sets(Set_union *s, int s1, int s2) {
  int r1 = find(s, s1);      /* root of the set s1 */
  int r2 = find(s, s2);      /* root of the set s2 */

  if (r1 == r2) return;      /* already in same component */

  if (s->size[r1] >= s->size[r2]) {
    s->size[r1] = s->size[r1] + s->size[r1];
    s->p[r2] = r1;
  } else {
    s->size[r2] = s->size[r1] + s->size[r2];
    s->p[r1] = r2;
  }
  return;
}

bool same_component(Set_union *s, int s1, int s2) {
  return find(s, s1) == find(s, s2);
}

void to_edge_array(Graph *g, Edge_pair *e) {
  Edgenode *p;
  int index = 1;
  for (int i = 1; i <= g->nvertices; i++) {
    p = g->edges[i];
    while (p != NULL) {
      e[index].x = i;
      e[index].y = p->y;
      e[index].weight = p->weight;
      
      p = p->next;
      index++;
    }
  }
  return;
}

int weight_compare(const void *a, const void *b) {
  int weight_a = ((Edge_pair *)a)->weight;
  int weight_b = ((Edge_pair *)b)->weight;
  return weight_a - weight_b;
}

void kruskal(Graph *g) {
  Set_union s;                   /* set union data structure */
  Edge_pair e[MAXV + 1];         /* array of edge data structure */

  set_union_init(&s, g->nvertices);

  to_edge_array(g, e);                         
  qsort(&e, g->nedges,sizeof(Edge_pair), weight_compare); /* sort edges by increasing cost */
  
  for (int i = 1; i < g->nedges; i++) {
    if (!same_component(&s, e[i].x, e[i].y)) {
      printf("edge (%d, %d) in MST\n", e[i].x, e[i].y);
      union_sets(&s, e[i].x, e[i].y);
    }
  }
  return;
}
/* END Kruskal's Algo */
#endif