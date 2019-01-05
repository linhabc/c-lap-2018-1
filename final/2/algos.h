#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/graph/adj_list.h"
#include "../lib/graph/weighted_graph_algo.h"
#include "../lib/graph/dfs.h"

void clearBuffer() {
    while ( getchar() != '\n' )
        ;
}

FILE *openFileWithErrorCatching(char *fn) {
    FILE *fp = fopen(fn, "r");
    if (fp == NULL) {
        printf("Can not open file!\n");
        exit(1);
    }
    return fp;
}

typedef struct {
    char name[100];
    int id;
} Product;

int readProductInFile(Product products[], char *fn) {
    FILE *fp = openFileWithErrorCatching(fn);
    char buffer[1000];
    
    int i = 0;
    while (fgets(buffer, 1000, fp) != NULL) {
        sscanf(buffer, "%d %s", &(products[i].id), products[i].name);
        i++;
    }
    return i;
}

void printProductList(Product products[], int nproducts) {
    for (int i = 0; i < nproducts; i++) {
        printf("Ma san pham: %d\n", products[i].id);
        printf("Ten san pham: %s \n\n", products[i].name);
    }
    return;
}

Product *getProductById(Product products[], int nproducts, int id) {
    for (int i = 0; i < nproducts; i++) {
        if (products[i].id == id) {
            return products + i;
        }
    }
    return NULL;
}

int stringLineToIntArray(char *str, int array[]) {
    int currIndex = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        array[currIndex] = atoi(token);
        token = strtok(NULL, " ");
        currIndex ++;
    }
    return currIndex;
}

void printArray(int array[], int nmemb) {
    for (int i = 0; i < nmemb; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
    return;
}

void printProductByNameInLine(
    int ids[], 
    int nids, 
    Product products[], 
    int nproducts    
) {
    for (int i = 0; i < nids; i++) {
        Product *currProduct = getProductById(products, nproducts, ids[i]);
        printf("%s ", currProduct->name);
    }
    printf("\n");
    return;
}

void initMatrix(int matrix[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            matrix[i][j] = 0;
        }
    }
    return;
}

void createGraphFromMatrix(Graph *g, int matrix[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (matrix[i][j] != 0) {
                insert_weighted_edge(g, i, j, matrix[i][j], false);
                g->nedges++;
            }
        }
    }
    return;
}

void readOrderHistoryFileAndCreateGraph(
    Product products[],
    int nproducts,
    Graph *g,
    char *fn
) {
    FILE *fp = openFileWithErrorCatching(fn);
    char buffer[1000];
    int buffArray[100];
    int nmemb;
    
    int matrix[100][100];
    initMatrix(matrix);
    g->nvertices = nproducts;

    while (fgets(buffer, 1000, fp) != NULL) {
        nmemb = stringLineToIntArray(buffer, buffArray);
        printProductByNameInLine(buffArray, nmemb, products, nproducts);
        for (int i = 0; i < nmemb; i++) {
            for (int j = i + 1; j < nmemb; j++) {
                matrix[buffArray[i]][buffArray[j]]++;
            }
        }
    }
    createGraphFromMatrix(g, matrix);
    print_graph_by_vertex_index(g);
    return;
}

void displayLevelRelationOfTwoProduct(
    Graph *g,
    Product products[],
    int nproducts   
) {
    int firstId, secondId;
    printf("Id of the frist product: ");
    scanf("%d", &firstId);
    printf("Id of the second product: ");
    scanf("%d", &secondId);
    
    Edgenode *temp = g->edges[firstId];
    while (temp != NULL) {
        if (temp->y == secondId) {
            printf("Do lien quan giua 2 san pham la : %d\n", temp->weight);
            return;
        }
        temp = temp->next;
    }
    printf("Do lien quan giua 2 san pham la : -1\n");
    return;
}

void displayRelatedProduct(
    Graph *g,
    Product products[],
    int nproducts
) {
    int id;
    printf("Id of the target product : ");
    scanf("%d", &id);
    sort_vertex_graph(g);

    printf("Cac san pham lien quan : ");
    Edgenode *temp = g->edges[id];
    while (temp != NULL) {
        Product *p = getProductById(products, nproducts, temp->y);
        printf("%s, ", p->name);
        temp = temp->next;
    }   
    printf("\n");
    return;
}

int isPathExist(Graph *g,int start, int end, int parent[]) {
    if (end == -1) return 0;
	if (end == start) return 1; 
	return isPathExist(g, start, parent[end], parent);
}

void printRelations(
    Graph *g, 
    int start, int end,
    int parent[],
    Product products[], int nproducts
) {
    if (start == end){
		printf("%s", getProductById(products, nproducts, start)->name);
	} 
    else {
		printRelations(g, start, parent[end], parent, products, nproducts);
		printf(" -- %s", getProductById(products, nproducts, end)->name);
	}
    return;
}
void displayRelationBetweenTwoProduct(
    Graph *g,
    Product products[],
    int nproducts
) {
    int firstId, secondId;
    printf("Id of the frist product: ");
    scanf("%d", &firstId);
    printf("Id of the second product: ");
    scanf("%d", &secondId);

    initialize_dfs(g);
    dfs(g, firstId);
    
    if (!isPathExist(g, firstId, secondId, parent)) {
        printf("Hai san pham nay khong co lien he voi nhau !\n");
        return;
    }

    printRelations(g, firstId, secondId, parent, products, nproducts);
    return;
}


