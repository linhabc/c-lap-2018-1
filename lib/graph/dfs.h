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

void dfs(Graph *g, int start) {
	Edgenode *p;     // temp node
	int y;           // successor vertex

	discoverded[start] = true;
	time = time + 1;
	entry_time[start] = time;

	process_vertex_ealy(start);

	p = g->edges[start];

	while (p != NULL) {
		y = p->next;
	}
}


#endif
