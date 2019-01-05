#include "./algos.h"

int main() {
    int op = 0;
    
    Product *products =  (Product *)malloc(1000 * sizeof(Product));
    int nproducts = readProductInFile(products, "products.txt");
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init_graph(g, false);

    do {
        printf("\n-------------------------------------\n");
        printf("1. Print product list.\n");
        printf("2. Print order history.\n");
        printf("3. Display level of relation of products.\n");
        printf("4. Print related products.\n");
        printf("5. Display relation of two products.\n");
        printf("Your option: ");
        scanf("%d", &op);
        clearBuffer();
        printf("-----------------------------------------\n");

        switch(op) {
            case 1:
                printProductList(products, nproducts);
                break;
            case 2:
                readOrderHistoryFileAndCreateGraph(
                    products, 
                    nproducts, 
                    g,
                    "orderHistory.txt" 
                );
                break;
            case 3:
                displayLevelRelationOfTwoProduct(g, products, nproducts);
                break;
            case 4:
                displayRelatedProduct(g, products, nproducts);
                break;
            case 5:
                displayRelationBetweenTwoProduct(g, products, nproducts);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Syntax error! Please input again!\n");
                break;
        }
    } while (op != 6) ;

    return 0;
}
