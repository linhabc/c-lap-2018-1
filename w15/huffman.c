#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/huffman_coding.h"

int main() {

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    printHuffmanCodes(arr, freq, size);
    
    return 0;
}