#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/graph/bfs.h"

void read_data_to_graph(Graph *g, char *fn) {
	FILE *fp = fopen(fn, "r");

	if (fp == NULL) {
		printf("Can not open file !");
		exit(1);
	}

	char buff[1000];
	while (fgets(buff, 1000, fp) != NULL) {
		
	}
}


int main() {
	
	return 0;
}
