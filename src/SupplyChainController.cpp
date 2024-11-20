#include "SupplyChainController.h"

SupplyChainController::SupplyChainController(int numNodes) {
  // Initialize supply chain
  for (int i = 0; i < numNodes; i++) {
    SupplyChainNode newNode(i);
    nodes.push_back(newNode);
  }

  for (int i = 0; i < numNodes - 1; i++) {
    nodes[i].setNext(nodes[i + 1]);
  }
}

/*
 * Starts the supply chain simulation and generates blockchain
 */
vector<Product> SupplyChainController::runSimulation(int numProducts) {
  // Initialize our products
  vector<Product> products;
  for (int i = 0; i < numProducts; i++) {
    Product p(i);
    products.push_back(p);
  }

  // Move products through simulation -> open to multithreading later
  for (int i = 0; i < nodes.size(); i++) {
    cout << "Node " << i << " handling products" << endl;
    for (int j = 0; j < products.size(); j++) {
      nodes[i].handleProduct(products[j]);
      if (i < nodes.size() - 1) {
        Transaction t(products[i].getId(), nodes[i].getId(),
                      nodes[i].getNext()->getId());
        // create a block with the transaction data, timestamp etc...
      }
    }
  }
  cout << "Simulation finished" << endl;

  return products;
}

/*
 * Saves blockchain to a file
 */
void SupplyChainController::saveBlocks() { cout << "NOT IMPLEMENTED" << endl; }
