#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./lib/graph/weighted_graph_algo.h"
#include "./algorithms.h"

int main(int argc, char *argv[]) {
    
    Product *products = (Product *)malloc(1000 * sizeof(Product));
    Store *stores = (Store *)malloc(1000 * sizeof(Store));
    Graph *g = (Graph *)malloc(sizeof(Graph));
    int nproducts = 0;
    int nstores = 0;

    if (argc == 2 && strcmp(argv[1], "-t") == 0) {
        printTitle();
    }

    if (argc == 3 && strcmp(argv[1], "-s") == 0) {
        nproducts = readProductFile(argv[2], products);
        printProductList(products, nproducts);
    }

    if (argc == 6 && strcmp(argv[1], "-w") == 0) {
        nproducts = readProductFile(argv[3], products);
        nstores = readStoreFile(argv[2], stores, nproducts);
        readGraphFromStoreFile(argv[2], g, nstores,nproducts);
        findDistance(
            g,
            stores, 
            nstores, 
            nproducts, 
            argv[4][0] - '0', 
            argv[5][0] - '0'
        );
    }

    if (argc == 4 && strcmp(argv[1], "-a") == 0) {
        nproducts = readProductFile(argv[3], products);
        nstores = readStoreFile(argv[2], stores, nproducts);
        checkoutStores(stores, nstores, products, nproducts);
    }

    if (argc == 6 && strcmp(argv[1], "-h") == 0) {
        nproducts = readProductFile(argv[3], products);
        nstores = readStoreFile(argv[2], stores, nproducts);
        readGraphFromStoreFile(argv[2], g, nstores, nproducts);
        print_graph_by_vertex_index(g);
        checkoutProductInStores(
            g,
            stores,
            nstores,
            products,
            nproducts,
            argv[4][0] - '0',
            argv[5][0] - '0'
        );
    }

    if (argc == 8 && strcmp(argv[1], "-g") == 0) {
        nproducts = readProductFile(argv[3], products);
        nstores = readStoreFile(argv[2], stores, nproducts);
        readGraphFromStoreFile(argv[2], g, nstores, nproducts);
        
        orderHandler(
            g,
            stores,
            nstores,
            products,
            nproducts,
            atoi(argv[4]),
            atoi(argv[5]),
            atoi(argv[6]),
            atoi(argv[7])
        );
    }

    return 0;
}
