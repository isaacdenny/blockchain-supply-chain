#include "SupplyChainController.h"
#include "SupplyChainNode.h"

SupplyChainController::SupplyChainController(int numNodes)
    : numNodes(numNodes) {
  // Initialize supply chain
  scHead = new SupplyChainNode(0);
  SupplyChainNode *newNode = nullptr;
  SupplyChainNode *current = scHead;

  for (int i = 0; i < numNodes; i++) {
    newNode = new SupplyChainNode(i);
    current->setNext(newNode);
    current = current->getNext();
  }
}

SupplyChainController::~SupplyChainController() {
  SupplyChainNode *current = scHead;
  SupplyChainNode *temp = nullptr;

  while (current != nullptr) {
    temp = current->getNext();
    delete current;
    current = temp;
  }
}

/*
 * Starts the supply chain simulation and generates blockchain
 */
void SupplyChainController::startSimulation() {
  cout << "NOT IMPLEMENTED" << endl;
}

/*
 * Saves blockchains of each node to one file
 */
void SupplyChainController::saveBlocks() { cout << "NOT IMPLEMENTED" << endl; }
