#ifndef __ADJ_LIST_H_
#define __ADJ_LIST_H_

#include <stdlib.h>

#define MAXV 1000 // max vertex

typedef int bool;
enum { false, true };

typedef struct Edgenode {
	int y;                    // adjacency info
	int weight;
	struct Edgenode *next;    // the next adge in list
} Edgenode;

typedef struct {
	Edgenode *edges[MAXV + 1];
	int degree[MAXV + 1];      // outter degree of each vertex
	int nvertices;             // number of vertex in graph
	int nedges;                // number of edge in graph;
	bool directed;             // is graph directed 
} Graph;

void init_graph(Graph *g, bool directed) {
	int i;

	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;

	for (int i = 1; i <= MAXV; i++) g->degree[i] = 0;
	for (int i = 1; i <= MAXV; i++) g->edges[i] = NULL;

	return;
}

void insert_edge(Graph *g, int x, int y, bool directed) {
	Edgenode *p = (Edgenode *)malloc(sizeof(Edgenode));  // temp pointer

	p->weight = 0;
	p->y = y;
	p->next = g->edges[x];

	g->edges[x] = p;
	g->degree[x] ++;

	if (directed == false) {
		insert_edge(g, y, x, true);
	} else {
		g->nedges ++;
	}

	return;
}

void read_graph_from_file(Graph *g, char *fn, bool directed) {
	
	FILE *fp = fopen(fn, "r");
	if (fp == NULL) {
		printf("Can not open file !\n");
	} else {
		init_graph(g, directed);

		int x, y; // vertex in edge (x, y)
		int nedges;
		fscanf(fp, "%d %d", &(g->nvertices), &nedges);
		
		for (int i = 1; i <= nedges; i++) {
			fscanf(fp, "%d %d", &x, &y);
			insert_edge(g, x, y, directed);
		}
	}

	fclose(fp);
	return;
}

void print_graph (Graph *g) {
	Edgenode *p; // temp pointer

	for (int i = 1; i <= g->nvertices; i++) {
		printf("degree : %d ||  %d ", g->degree[i], i);
		p = g->edges[i];
		while (p != NULL) {
			printf("--> %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
	return;
}

#endif
