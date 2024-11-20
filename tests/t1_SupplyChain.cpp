#include <cassert>
#include <iostream>
#include "../src/SupplyChainController.h"

using namespace std;

#define NUM_NODES 5
#define NUM_PRODUCTS 100

/*
*	Unit test to test all values of the SupplyChainController after initialization
*/ 
int main() {
	SupplyChainController controller(NUM_NODES);
	
	vector<SupplyChainNode> nodes = controller.getNodes();

	assert(nodes.size() == NUM_NODES);

	vector<Product> products = controller.startSimulation(NUM_PRODUCTS);

	bool productsFinished = true;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getNodesVisited() != NUM_NODES) {
			productsFinished = false;
			cout << "Product not finished, id: " << products[i].getId() << " " << products[i].getNodesVisited() << endl;
		}
	}

	assert(productsFinished);
}
