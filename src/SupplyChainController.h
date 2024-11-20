#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "SupplyChainNode.h"
#include "Product.h"
#include <iostream>

using namespace std;

/*
 * Supply chain controller class responsible for handling simulation details
 * and generating the blockchain.
 */
class SupplyChainController {
private:
  vector<SupplyChainNode> nodes;
  // int numThreads - for multithreading later
  // file saveFile - the file for reading the nodes and blockchains
  // BlockChain blockChain - reference to a blockchain
public:
  SupplyChainController(int numNodes); // add overload for saved blockchain file
  int getNumNodes() { return nodes.size(); }
  vector<SupplyChainNode> getNodes() { return nodes; }
  vector<Product> runSimulation(int numProducts);
  void saveBlocks();
};

#endif
