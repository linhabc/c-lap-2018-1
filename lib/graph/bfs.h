#ifndef __GRAPH_BFS_H__
#define __GRAPH_BFS_H__

#include <stdio.h>
#include <stdlib.h>
#include "./adj_list.h"
#include "./queue.h"

bool processed[MAXV + 1];  // which vertex have been processed
bool discoverded[MAXV + 1]; // which vertex have been discoverded
int parent[MAXV + 1];

void initialize_bfs(Graph *g) {
	for (int i = 0; i < g->nvertices; i++) {
		processed[i] = discoverded[i] = false;
		parent[i] = -1;
	}
	return;
}

void process_vertex_ealy(int v) {
	printf("process vertex : %d\n", v);
	return;
}

void process_edge(int x, int y) {
	printf("process edge (%d, %d) \n", x, y);
	return;
}

void process_vertex_late(int v) {
	//printf("process vertex late : %d \n", v);
	return;
}

void bfs(Graph *g, int start) {
	Queue *q;    // queue of vertices to visit
	int v;       // current vertex
	int y;       // successor vertex
	Edgenode *p; // temp node

	initialize_bfs(g);

	q = createQueue();
	enQueue(q, start);
	discoverded[start] = true;

	while (empty_queue(q) == false) {
		v = deQueue(q);
		process_vertex_ealy(v);
		processed[v] = true;
		p = g->edges[v];

		while (p != NULL) {
			y = p->y;

			if (processed[y] == false || g->directed) {
				process_edge(v, y);
			}

			if (discoverded[y] == false) {
				enQueue(q, y);
				discoverded[y] = true;
				parent[y] = v;
			}

			p = p->next;
		}
		process_vertex_late(v);
	}
	return;
}


#endif
