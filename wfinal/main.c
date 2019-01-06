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

void printArray(int array[], int nmemb) {
    for (int i = 0; i < nmemb; i++) {
        printf(" %d", array[i]);
    }
    printf("\n");
    return;
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

int main() {
    int op = 0;
    
    do {
        printf("\n-------------------------------------\n");
        printf("1. \n");
        printf("2. \n");
        printf("3. \n");
        printf("4. \n");
        printf("5. \n");
        printf("Your option: ");
        scanf("%d", &op);
        clearBuffer();
        printf("-----------------------------------------\n");
        
        switch(op) {
            case 1:
                break;
            case 2:
              
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Syntax error! Please input again!\n");
                break;
        }
    } while (op != 6);

    return 0;
}