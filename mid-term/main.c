#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "./lib/graph/dfs.h"
#include "./lib/graph/bfs.h"

void read_graph_from_file(Graph *g, char *fn, bool directed) {
	FILE *fp = fopen(fn, "r");

	if (fp == NULL) {
		printf("Can not open file \n");
    return;
	}

  
	return;
}

int main() {

	int op;
	Graph *g = (Graph *)malloc(sizeof(Graph));

	do {
		printf("\n-----------------------------------------\n");
		printf("1. \n");
		printf("2. \n");
		printf("3. \n");
		printf("4. \n");
		printf("5. \n");
		printf("6. \n");
		printf("7. \n");
		
		printf("Your option : ");
		scanf("%d", &op);

		printf("\n-------------------------------------------\n\n");
		switch (op) {
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				break;
			}
			case 5: {
				break;
			}
			case 6: {
				break;
			}
			case 7: {

				break;
			}
		}

	} while (1);

	return 0;
}
