#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "../lib/graph/dfs.h"
#include "../lib/graph/bfs.h"

void read_graph_from_file(Graph *g, char *fn, bool directed) {
	FILE *fp = fopen(fn, "r");

	if (fp == NULL) {
		printf("Can not open file \n");
	} else {
		init_graph(g, directed);

		int x, y; 
		int nedges;
		fscanf(fp, "%d %d", &(g->nvertices), &nedges);

		for (int i = 0; i < g->nvertices; i++) {
			char *buff = (char *)malloc(1000 * sizeof(char));
			fscanf(fp, "%s", buff);
			add_vertex_name(g, i, buff);
		}

		for (int i = 0; i < nedges; i++) {
			fscanf(fp, "%d %d", &x, &y);
			insert_edge(g, x, y, directed);
		}
	}
	return;
}

void read_data_from_file_to_matrix(int matrix[100][100], char *fn) {
	FILE *fp = fopen(fn , "r");
	if (fp == NULL) {
		printf("Can not open file !\n");
		return;
	}

	int m,n;
	fscanf(fp, "%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fp, "%d ", &matrix[i][j]);
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
	return;
}

int index_of(int x, int y) {
	return x + y*5;
}

void tranform_data_to_graph(int matrix[100][100], int m, int n, Graph *g) {
	init_graph(g, false);

	int n_verties = 0;
	int n_edges = 0;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				n_verties ++;
				
				if ((j - 1 >= 0) && (matrix[i][j - 1] == 0)) {
					insert_edge(g, index_of(i, j), index_of(i, j - 1), true);
				}

				if ((i - 1 >= 0) && (matrix[i - 1][j] == 0)) {
					insert_edge(g, index_of(i, j), index_of(i - 1, j), true);
				}

				if ((j + 1 < m) && (matrix[i][j + 1] == 0)) {
					insert_edge(g, index_of(i, j), index_of(i, j + 1), true);
				}

				if ((i + 1 < n) && (matrix[i + 1][j] == 0)) {
					insert_edge(g, index_of(i, j), index_of(i + 1, j), true);
				}
			}
		}
	}

	g->nvertices = 25;
	printf(
		"The graph has %d-verties and %d-edges \n", 
		n_verties, 
		g->nedges / 2
	);

	return;
}

void find_neighbours(Graph *g) {

	int position, x, y;

	printf("Enter the position : ");
	scanf(" %d", &position);
	x = position / 10;
	y = position % 10;
	print_graph_by_vertex_index(g);
	Edgenode *temp = NULL;
	temp = g->edges[index_of(x, y)];

	printf("neighbours : ");
	while (temp != NULL) {
		printf("%d%d ", (temp->y) % 5, (temp->y) / 5);
		temp = temp->next;
	}

	return;
}

void find_vertex_has_max_neighbours(Graph *g) {
	int max = 0;
	for (int i = 0; i < 25; i++) {
		if (max < g->degree[i]) {
			max = g->degree[i];
		}
	}

	printf("The vertexs has maximum neighbours : ");
	for (int i = 0; i < 25; i++) {
		if (g->degree[i] == max) {
			printf("%d%d ", i % 5, i / 5);
		}
	}
	printf("\n");
	return;
}

void find_island_vertex(Graph *g, int matrix[100][100]) {
	printf("\n Islands vertex : ");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] == 0) {
				if (g->degree[index_of(i, j)] == 0) {
					printf("%d%d ", j, i);
				}
			}
		}
	}
}

void find_the_shortes_path(Graph *g) {
	int start, end;
	printf("Enter the start vertex : ");
	scanf(" %d", &start);	
	printf("Enter the end vertex : ");
	scanf(" %d", &end);

	int startX = start % 10;
	int startY = start / 10;
	int endX = end / 10;
	int endY = end % 10;

	initialize_bfs(g);
	bfs(g, index_of(startX, startY));
	printf("The shorest path from %d to %d : \n", start , end);
	find_shortes_path(g, index_of(startY, startX), index_of(endX, endY), parent);
	return;
}

int main() {

	int op;
	Graph *g = (Graph *)malloc(sizeof(Graph));

	int matrix[100][100];

	do {
		printf("\n-----------------------------------------\n");
		printf("1. Read and Print graph from file! \n");
		printf("2. Print number of verties and edges\n");
		printf("3. Find neighbours !\n");
		printf("4. Find vertex has max neighbours\n");
		printf("5. Find island matrix \n");
		printf("6. Find the shorest path\n");
		printf("7. \n");
		
		printf("Your option : ");
		scanf("%d", &op);

		printf("\n-------------------------------------------\n\n");
		switch (op) {
			case 1: {
				read_data_from_file_to_matrix(matrix, "input.txt");
				break;
			}
			case 2: {
				tranform_data_to_graph(matrix, 5, 5, g);
				break;
			}
			case 3: {
				find_neighbours(g);
				break;
			}
			case 4: {
				find_vertex_has_max_neighbours(g);
				break;
			}
			case 5: {
				find_island_vertex(g, matrix);
				break;
			}
			case 6: {
				find_the_shortes_path(g);
				break;
			}
			case 7: {

				break;
			}
		}

	} while (1);

	return 0;
}
