#include "Product.h"

Product::Product(int id) : id(id), nodesVisited(0) { }

/*
 * When this product visits a node, increment the counter
 */
void Product::addNodeVisited() { this->nodesVisited++; }

void Product::setId(int id) {
	this->id = id;
}
