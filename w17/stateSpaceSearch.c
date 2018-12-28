#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "./ultilities.h"

/**********************************************
   *  END_STATE:
   *
   *  | 1 | 2 | 3 |
   *  | 4 | 5 | 6 |
   *  | 7 | 8 | 0 |
   *
   *  corresponding to the hexadecimal encoding:
   *  0x087654321
   **********************************************/

typedef struct Puzzle {
    unsigned long currentState;
    unsigned long parentState;
    int nmoves;
    int nchildren;
    unsigned long child[4];  /* array cointaining children states */
    struct Puzzle *next;     /* pointer to next board */
} Puzzle;

/****************************************
 *       OPERATIONS FOR PUZZLE          *
 ****************************************/

Puzzle *boardInit(
    unsigned long currentState, 
    unsigned long parentState, 
    int nmoves) {
    Puzzle *boardp = (Puzzle *)malloc(sizeof(Puzzle));

    boardp->currentState = currentState;
    boardp->parentState = parentState;
    boardp->nmoves = nmoves;
    boardp->nchildren = 0;

    boardp->child[0] = 0;
    boardp->child[1] = 0;
    boardp->child[2] = 0;
    boardp->child[3] = 0;
    
    boardp->next = NULL;

    return boardp; 
}

unsigned long swapTiles(
    unsigned long state, 
    int index1,
    int index2) {
    /* swap tiles in index1 and index2, generating new state */

    unsigned long highShift; /* bits to shift for higher index */
    unsigned long lowShift;  /* bits t shift for lower index */
    unsigned long shiftDiff; /* different in bits of 2 positions */
    unsigned long shiftMask = 0xF;

    if (index1 == index2) {
        log_info("same index");
        return state;
    }

    if (index1 < 0 || index1 > 8 ) {
        log_info("invalid swap");
        return state;
    }

    if (index2 < 0 || index2 > 8) {
        log_info("invalid swap");
        return state;
    }

    if (index1 > index2) {
        highShift = index1 * 4;
        lowShift = index2 * 4;
    } else {
        highShift = index2 * 4;
        lowShift = index1 * 4;
    }

    unsigned long extractHigh = state & (shiftMask << highShift);
    unsigned long extractLow = state & (shiftMask << lowShift);

    /* swap 4-bits group */
    return 
        (state & (state ^ (extractHigh + extractLow))) | 
        (extractHigh >> shiftDiff) | 
        (extractLow << shiftDiff);
}

void insertChild(Puzzle *boardp, unsigned long newState) {
    boardp->child[boardp->nchildren] = newState;
    boardp->nchildren++;
    return;
}

unsigned getBlankIndex(unsigned long state) {
    unsigned blankIndex = 0;

    while (true) {
        if (((state >> (4 * i)) & 0xF) == 0) {
            return blackIndex;
        }
        blankIndex++;
    }
}

void getAllChildrenPossible(Puzzle *boardp, unsigned blankIndex) {
    switch (blankIndex) {
        case 0: 
            insertChild(boardp, swapTiles(state, 0, 1));
            insertChild(boardp, swapTiles(state, 0, 3));
            break;
        case 1: 
            insertChild(boardp, swapTiles(state, 1, 0));
            insertChild(boardp, swapTiles(state, 1, 2));
            insertChild(boardp, swapTiles(state, 1, 4));
            break;
        case 2: 
            insertChild(boardp, swapTiles(state, 2, 1));
            insertChild(boardp, swapTiles(state, 2, 5));
            break;
        case 3: 
            insertChild(boardp, swapTiles(state, 3, 0));
            insertChild(boardp, swapTiles(state, 3, 4));
            insertChild(boardp, swapTiles(state, 3, 6));
            break;
        case 4: 
            insertChild(boardp, swapTiles(state, 4, 1));
            insertChild(boardp, swapTiles(state, 4, 3));
            insertChild(boardp, swapTiles(state, 4, 5));
            insertChild(boardp, swapTiles(state, 4, 7));
            break;
        case 5: 
            insertChild(boardp, swapTiles(state, 5, 2));
            insertChild(boardp, swapTiles(state, 5, 4));
            insertChild(boardp, swapTiles(state, 5, 8));
            break;
        case 6: 
            insertChild(boardp, swapTiles(state, 6, 3));
            insertChild(boardp, swapTiles(state, 6, 7));
            break;
        case 7: 
            insertChild(boardp, swapTiles(state, 7, 4));
            insertChild(boardp, swapTiles(state, 7, 6));
            insertChild(boardp, swapTiles(state, 7, 8));
            break;
        case 8: 
            insertChild(boardp, swapTiles(state, 8, 5));
            insertChild(boardp, swapTiles(state, 8, 7));
            break;
        default: 
            log_info("invalid black index %d", blankIndex);
    }
    return;
}

void enumState(Puzzle *boardp) {
    /**********************************************
   * Indexed as follows:
   *
   *  | 0 | 1 | 2 |
   *  | 3 | 4 | 5 |
   *  | 6 | 7 | 8 |
   *
   *  corresponding to the hexadecimal encoding:
   *  0x876543210
   **********************************************/

    unsigned long state = boardp->currentState;
    unsigned blankIndex = getBlankIndex(state);;
    getAllChildrenPossible(boardp, blankIndex);
    return;    
}

/**************************************************
 *              PRINTING/TRACING BOARD            *
 **************************************************/
typedef struct HashNode {
  /* hash table stores information of state, parent state, 
     whether state is discovered, processed */
  unsigned long state;
  unsigned long parent;
  bool processed; /* processed upon extracting from priority queue */
  int fScore;    /* if f_score set, state is discovered */
} HashNode;

void printState(unsigned long states) {
    unsigned long temp;
    unsigned long mask = 0xF;
    printf("\n|");
    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            printf("\n|");
        }
        temp = state >> (4 * i);
        temp = temp & mask; /* extract value of least-significant 4 bits */
        printf(" %lu", temp);
    }
    printf("\n");
    return;
}

/* returns hash value, given state and count (double probing) */
int hashF(unsigned long state, int i);

/* 
    trace a final state to its initial state 
    using information from the closed set 
    prints out states in order of moves made 
*/
void trace(HashNode closed[], unsigned long state) {
    unsigned long traceArray[MAX_MOVES];
    unsigned long currentState = state;
    int moveCount = 0;
    int j = 0; /* trace array index */

    while (currentState != 0) {
        int i = 0;
        int index;

        traceArray[j++] = currentState;
        
        while (true) {
            index = hashF(currentState, i);
            if (closed[index].state == currentState) {
                currentState = closed[index].parent;
                break;
            }
            i++;
        }
    }

    while (j > 0) {
        j--;
        log_info("move %d: ", moveCount);
        printState(traceArray[j]);
        moveCount++;
    }
}

/********************************************
 *      OPERATIONS FOR CLOSED SET           *
 *           array of HashNode              *
 ********************************************/
void closedItemInit(HashNode *item) {
    item->state = 0;
    item.parent = 0;
    item.processed = false;
    item.fScore = INT_MAX;
    return;
}

HashNode *closedInit(void) {
    HashNode *ret = (HashNode *)malloc(PERMUTATIONS * sizeof(HashNode));
    check_mem(ret);
    for (int i = 0; i < PERMUTATIONS; i++) {
        closedItemInit(ret[i]);
    }
    return ret;
}

/* returns hash value, given state and count (double probing) */
int hashF(unsigned long state, int i) {
  return ((state % PERMUTATIONS) + (i * (PRIME - (state % PRIME)))) % PERMUTATIONS;
}


int main() {

    return 0;
}