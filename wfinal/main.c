#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/graph/adj_list.h"
#include "./lib/graph/dfs.h"
#include "./lib/graph/weighted_graph_algo.h"

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

int intInStringToIntArray(char *str, int array[]) {
    int currIndex = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        array[currIndex] = atoi(token);
        token = strtok(NULL, " ");
        currIndex ++;
    }
    return currIndex;
}

void moveToThLineN(FILE *fp, int n) {
    char buffer[1000];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1000, fp);
    }
    return;
}

Edgenode *getEdgeByXY(Graph *g, int x, int y) {
    Edgenode *temp = g->edges[x];
    if (temp == NULL) return NULL;
    while (temp != NULL) {
        if (temp->y == y) return temp; 
        temp = temp->next;
    }
    return NULL;
}

void printArray(int array[], int nmemb) {
    for (int i = 0; i < nmemb; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
    return;
}

typedef struct {
    int x;
    int y;
} State;

int m, n;

int isStateExist(int x, int y, State *states, int nstates) {
    for (int i = 0; i < nstates; i++) {
        if (x == states[i].x && y == states[i].y) {
            return 1;
        }
    }
    return 0;
}

void generateStates(int x, int y, State *states, int *nstates) {
    if (isStateExist(x, y, states, *nstates)) return;

    states[*nstates].x = x;
    states[*nstates].y = y;
    *nstates = *nstates + 1;

    if (x == 0) {
        generateStates(m, y, states, nstates);
    }

    if (y == 0) {
        generateStates(x, n, states, nstates);
    }

    if (x != 0) {
        generateStates(0, y, states, nstates);
    }

    if (y != 0) {
        generateStates(x, 0, states, nstates);
    }

    if (x < m) {
        generateStates(m, y, states, nstates);
    }

    if (y < n) {
        generateStates(x, n, states, nstates);
    }

    int currCapOfbot1 = m - x;
    int currCapOfbot2 = n - y;
    if (currCapOfbot1 >= y) {
        generateStates(x + y, 0, states, nstates);
    }
    if (currCapOfbot1 < y) {
        generateStates(m, y - currCapOfbot1, states, nstates);
    }

    if (currCapOfbot2 >= x) {
        generateStates(0, y + x, states, nstates);
    }
    if (currCapOfbot2 < x) {
        generateStates(x - currCapOfbot2, n, states, nstates);
    }
}

void printStates(State states[], int nstates) {
    for (int i = 0; i < nstates; i++) {
        printf("(%d, %d) \n", states[i].x, states[i].y);
    }
    printf("\n");
    return;
}

void printAllPossibleNextStates(int x, int y) {
    
    if (x == 0) {
        printf("(%d, %d)\n", m, y);
    }

    if (y == 0) {
        printf("(%d, %d)\n", x, n);
    }

    if (x != 0) {
        printf("(%d, %d)\n", 0, y);
    }

    if (y != 0) {
        printf("(%d, %d)\n", x, 0);
    }

    if (x < m) {
        printf("(%d, %d)\n", m, y);
    }

    if (y < n) {
        printf("(%d, %d)\n", x, n);
    }

    int currCapOfbot1 = m - x;
    int currCapOfbot2 = n - y;
    if (currCapOfbot1 >= y) {
        printf("(%d, %d)\n", x + y, 0);
    }
    if (currCapOfbot1 < y) {
        printf("(%d, %d)\n", m, y - currCapOfbot1);
    }

    if (currCapOfbot2 >= x) {
        printf("(%d, %d)\n", 0, y + x);
    }
    if (currCapOfbot2 < x) {
        printf("(%d, %d)\n", x - currCapOfbot2, n);
    }
    return;
}

int printAllPossibleStates(Graph *g, State *states) {
    printf("The capacitor of bottle 1: ");
    scanf(" %d", &m);
    printf("The capacitor of bottle 2: ");
    scanf(" %d", &n);

    int nvertices = (n + 1) * (m + 1);
    printf("Total number of verties : %d\n", nvertices);

    int nstates = 0;
    generateStates(0, 0, states, &nstates);
    printf("Total number of edges : %d\n", nstates);

    printStates(states, nstates);
    return nstates;
}

void printResult(State states[]) {
    int k;
    int nstates;
    printf("k = ");
    scanf("%d", &k);
    generateStates(0, 0, states, &nstates);

    int targetIndex = 0;
    for (int i = 0; i < nstates; i++) {
        if (states[i].x == k || states[i].y == k) {
            targetIndex = i;
            break;
        }
    }

    for (int i = 0; i <= targetIndex; i++) {
        printf("(%d, %d)\n", states[i].x, states[i].y);
    }
    return;
}

int main() {
    char op = 0;
    State *states = (State *)malloc(1000 * sizeof(State));
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init_graph(g, true);

    int nstates;
    for (int i = 0; i < 1000; i++) {
        states[i].x = 0; 
        states[i].y = 0;
    }

    int a;
    int b;

    do {
        printf("\n---------------------------------------\n");
        printf("1. Print out the total of vertices and edges. \n");
        printf("2. Print out possible next state.\n");
        printf("3. Print out total of reachable states.\n");
        printf("4. Print out one solution for taking out k liters of water.\n");
        printf("5. Print out the best solution.\n");
        printf("Your option: ");
        scanf("%c", &op);
        clearBuffer();
        printf("-----------------------------------------\n");
        
        switch(op) {
            case '1':
                nstates = printAllPossibleStates(g, states);
                clearBuffer();
                break;
            case '2':
                printf("a = ");
                scanf("%d", &a);
                printf("b = ");
                scanf("%d", &b);
                printAllPossibleNextStates(a, b);
                clearBuffer();
                break;
            case '3':

                break;
            case '4':
                printResult(states);
                clearBuffer();
                break;
            case '5':
                printResult(states);
                clearBuffer();
                break;
            case '6':
                printf("Goodbye!\n");
                break;
            default:
                printf("Syntax error! Please input again!\n");
                break;
        }
    } while (op != '6');

    return 0;
}