#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/huffman_coding.h"

int main(char argc, char *argv[]) {

    if (argc != 3) {
        printf("Syntax error!\n");
        return 1;
    }

    char *fnIn = argv[1]; 
    char *fnOut = argv[2]; 

    HuffmanTree *root = createHuffmanTreeFromFile("huffman_input.txt");
    char *decodedString = huffmanDecodingToString(fnIn, root);
    printStringToFile(fnOut, decodedString);

    return 0;
}