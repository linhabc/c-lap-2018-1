#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/graph/weighted_graph_algo.h"

typedef struct {
    int id;
    char name[1000];
} Product;

typedef struct {
    int id;
    char name[1000];
    int quanityOfproducts[1000];
} Store;

void printTitle() {
    printf("C-Advanced, HK 20182 \n");
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

int readProductFile(char *fn, Product *products) {
    FILE *fp = openFileWithErrorCatching(fn);

    int nproducts;
    fscanf(fp, " %d", &nproducts);
    for (int i = 0; i < nproducts; i++) {
        fscanf(fp, "%s %d", products[i].name, &(products[i].id));
    }

    fclose(fp);
    return nproducts;
}


void printProductList(Product products[], int nproducts) {
    for (int i = 0; i < nproducts; i++) {
        printf("%s %d\n", products[i].name, products[i].id);
    }    
    return;
}


int readStoreFile(char *fn, Store *stores, int nproducts) {
    FILE *fp = openFileWithErrorCatching(fn);
    
    int nstores;
    fscanf(fp, " %d", &nstores);
    for (int i = 0; i < nstores; i++) {
        fscanf(fp, " %s %d", stores[i].name, &(stores[i].id));
        for (int k = 0; k < nproducts; k++) {
            int currentProductId;
            int currentQuanity;
            fscanf(fp, "%d %d", &currentProductId, &currentQuanity);
            stores[i].quanityOfproducts[currentProductId] = currentQuanity;
        }
    }

    fclose(fp);
    return nstores;
}

char *getProductNameById(Product *products, int nproduct, int id) {
    for (int i = 0; i < nproduct; i++) {
        if (products[i].id == id) {
            return products[i].name;
        }
    }
    return NULL;
}

void checkoutStores(Store stores[], int nstores, Product products[], int nproducts) {
    for (int i = 0; i < nstores; i++) {
        printf("%s \n", stores[i].name);
        for (int k = 0; k < nproducts; k++) {
            int currentProductId = products[k].id;
            int currentQuanity = stores[i].quanityOfproducts[currentProductId];
            char *currentProductName = getProductNameById(products, nproducts, currentProductId);
            printf("%s %d \n", currentProductName, currentQuanity);
        }
        printf("-------------------------------------------\n");
    }
    return;
}

void moveToLineThN(FILE *fp, int n) {
    char buffer[1000];
    for (int i = 0; i < n; i++) {
        fgets(buffer, 1000, fp);
    }
    return;
}

void readGraphFromStoreFile(char *fn, Graph *g, int nstores, int nproducts) {
    FILE *fp = openFileWithErrorCatching(fn);

    int nlines = nstores * (1 + nproducts) + 1;
    moveToLineThN(fp, nlines);

    init_graph(g, false);
    int x, y, weight;
    int nedges;
    fscanf(fp, "%d", &nedges);

    g->nvertices = nstores;
    for (int i = 1; i <= nedges; i++) {
        fscanf(fp,"%d %d %d ", &x, &y, &weight);
        insert_weighted_edge(g, x, y, weight, false);
    }
    fclose(fp);
    return;
}

int isVaildStoreId(Store stores[], int nstores, int storeId) {
    for (int i = 0; i < nstores; i++) {
        if (stores[i].id == storeId) {
            return 1;
        }
    }
    return 0;
}

void findDistance(
    Graph *g,
    Store stores[], 
    int nstores, 
    int nproducts, 
    int sourceId, 
    int targetId
) {

    if (!isVaildStoreId(stores, nstores, sourceId) || !isVaildStoreId(stores, nstores, targetId)) {
        printf("-1\n");  
        return;
    }

    if (g->edges[sourceId] == NULL) {
        printf("-1\n");
    } else {
        printf("%dkm\n", g->edges[sourceId]->weight);
    }
}

Store *getStoreById(Store stores[], int nstores, int id) {
    for (int i = 0; i < nstores; i++) {
        if (stores[i].id == id) {
            return stores + i;
        }
    }
    return NULL;
}

Product *getProductById(Product products[], int nproducts, int id) {
    for (int i = 0; i < nproducts; i++) {
        if (products[i].id == id) {
            return products + i;
        }
    }
    return NULL;
}

int getQuanityOfProductInStore(Store *store, int productId) {
    return store->quanityOfproducts[productId];
}

void checkoutProductInStores(
    Graph *g,
    Store stores[],
    int nstores,
    Product products[],
    int nproducts,
    int productId,
    int storeId
) {
    printf("productId : %d, storeId: %d \n", productId, storeId);
    Store *targetStore = getStoreById(stores, nstores, storeId);
    Product *targetProduct = getProductById(products, nproducts, productId);
    printf("%s\n", targetStore->name);
    printf(
        "%s %d\n", 
        targetProduct->name, 
        getQuanityOfProductInStore(targetStore, targetProduct->id)
    );

    printf("-----Cac kho lien ke la: \n");
    Edgenode *temp = g->edges[targetStore->id];
    while (temp != NULL) {
        int neighborStoreId = temp->y;
        Store *neightborStore = getStoreById(stores, nstores, neighborStoreId);
        printf("%s\n", neightborStore->name);
        printf(
            "%s %d\n", 
            targetProduct->name, 
            getQuanityOfProductInStore(neightborStore, targetProduct->id)
        );

        temp = temp->next;
    }
    return;
}



int getTotalPathWeight(Graph *g, int start, int end) {
   return distance_dijkstra[end];
}

void orderHandler(
    Graph *g,
    Store stores[],
    int nstores,
    Product products[],
    int nproducts,
    int productId,
    int orderQuanity,
    int firstStoreId,
    int secondStoreId
) {
    printf(
        "ProductId: %d, quanity: %d, firstStoreId: %d, secondStoreId: %d",
        productId,
        orderQuanity,
        firstStoreId,
        secondStoreId
    );

    Store *firstStore = getStoreById(stores, nstores, firstStoreId);
    int quanityInFirstStore = getQuanityOfProductInStore(firstStore, productId);

    if (quanityInFirstStore >= orderQuanity) {
        printf("Dat hang thanh cong!\n");
        printf("Thoi gian giao hang la 0 gio 30 phut.\n");
        return;
    }

    int orderQuanityRemain = orderQuanity - quanityInFirstStore;
    Store *secondStore = getStoreById(stores, nstores, secondStoreId);
    int quanityInSecondStore = getQuanityOfProductInStore(secondStore, productId);

    if (quanityInSecondStore < orderQuanityRemain) {
        printf("Dat hang khong thanh cong!\n");
        return;
    }

    dijkstra(g, firstStoreId);
    int totalWeight = getTotalPathWeight(g, firstStoreId, secondStoreId);
    float orderIntervalInHour = (float)totalWeight/30.0 + 0.5;
    printf("\nDat hang thanh cong! \n");
    printf("Thoi gian giao hang la : %d gio %.2f phut \n",
        (int)orderIntervalInHour,
        (orderIntervalInHour - 1) * 60.0
    );
    return;
}



