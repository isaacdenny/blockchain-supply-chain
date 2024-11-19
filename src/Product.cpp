#include "Product.h"

Product::Product(uint64_t id) : id(id) { nodesVisited = 0; }

/*
 * When this product visits a node, increment the counter
 */
void Product::addNodeVisited() { nodesVisited++; }
