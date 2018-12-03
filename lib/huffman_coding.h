#ifndef __HUFFMAN_CODING_H__
#define __HUFFMAN_CODING_H__

#include <string.h>
#include <stdlib.h>

#define MAX_TREE_HT 1000

typedef struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct {
    int size;     // current size of min heap
    int capacity; // capacity of min heap
    MinHeapNode **array;
} MinHeap;

MinHeapNode *createMinHeapNode(char data, int freq) {
    MinHeapNode *ret = (MinHeapNode *)malloc(sizeof(MinHeapNode));
    ret->data = data;
    ret->freq = freq;
    ret->left = ret->right = NULL;
    return ret;
}

MinHeap *createMinHeap(int capacity) {
    MinHeap *ret = (MinHeap *)malloc(sizeof(MinHeap));
    MinHeapNode **array = (MinHeapNode **)malloc(capacity * sizeof(MinHeapNode *));

    ret->size = 0;
    ret->capacity = capacity;
    ret->array = array;

    return ret;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) { 
    MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
    return;
} 

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (
        left < minHeap->size && 
        minHeap->array[left]->freq < minHeap->array[smallest]->freq
    ) smallest = left; 
  
    if (
        right < minHeap->size && 
        minHeap->array[right]->freq < minHeap->array[smallest]->freq
    ) smallest = right; 
  
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
}

MinHeapNode* extractMin(MinHeap *minHeap) { 
  
    MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
  
    --minHeap->size; 
    minHeapify(minHeap, 0); 
  
    return temp; 
} 

void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) { 
  
    ++minHeap->size; 
    int i = minHeap->size - 1; 
  
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
  
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
  
    minHeap->array[i] = minHeapNode; 
    
    return;
}

void buildMinHeap(MinHeap* minHeap) { 
    int n = minHeap->size - 1; 
    int i; 
    
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }

    return; 
} 

MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap *ret = createMinHeap(size);
    
    for (int i = 0; i < size; i++) {
        ret->array[i] = createMinHeapNode(data[i], freq[i]);
    }
    ret->size = size;
    buildMinHeap(ret);

    return ret;
}

MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap *heap = createAndBuildMinHeap(data, freq, size);

    while (heap->size != 1) {
        left = extractMin(heap);
        right = extractMin(heap);

        top = createMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    return extractMin(heap);
}

int isLeaf(MinHeapNode *root) { 
    return !(root->left) && !(root->right); 
} 

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
    return;
}

void printCodes(MinHeapNode *root, int array[], int top) {
    if (root->left) {
        array[top] = 0;
        printCodes(root->left, array, top + 1);
    }

    if (root->right) {
        array[top] = 1;
        printCodes(root->right, array, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArray(array, top);
    }

    return;
}

void printHuffmanCodes(char data[], int freq[], int size) {
    MinHeapNode *root = buildHuffmanTree(data, freq, size);
    
    int array[MAX_TREE_HT];
    int top = 0;
    printCodes(root, array, top);
    
    return;
}




#endif