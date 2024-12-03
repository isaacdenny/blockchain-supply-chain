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

	// use assertions like this to throw errors if something is not as it should be
	assert(nodes.size() == NUM_NODES);

	vector<Product> products = controller.runSimulation(NUM_PRODUCTS);

	// make sure all products are finished (have visited 5 nodes)
	bool productsFinished = true;
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getNodesVisited() != NUM_NODES) {
			productsFinished = false;
			cout << "Product not finished, id: " << products[i].getId() << " " << products[i].getNodesVisited() << endl;
		}
	}

	for (const auto &block : controller.getBlockChain().getChain()) {
        cout << "Index: " << block.getIndex() << "\n"
             << "Timestamp: " << block.getTimestamp() << "\n"
             << "Data: " << block.getData() << "\n"
             << "Previous Hash: " << block.getPreviousHash() << "\n"
             << "Hash: " << block.getHash() << "\n"
             << "----------------------------------\n";
    }

	assert(productsFinished);
}
