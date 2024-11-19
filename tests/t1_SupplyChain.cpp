#include <cassert>
#include <iostream>
#include "../src/SupplyChainController.h"

using namespace std;

#define NUM_NODES 5

/*
*	Unit test to test all values of the SupplyChainController after initialization
*/ 
int main() {
	SupplyChainController controller(NUM_NODES);
	
	int num1 = controller.getNumNodes();
	SupplyChainNode* head = controller.getSCHead();

	cout << "getNumNodes(): " << num1 << endl;
	cout << "getSCHead().getId(): " << head->getId() << endl;

	assert(num1 == NUM_NODES);
	assert(head->getId() == 0);

	int num2 = 0;
	SupplyChainNode* current = head;
	while(current != nullptr) {
		current = current->getNext();
		num2++;
	}

	assert(num2 == NUM_NODES);
}
