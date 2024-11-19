#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "SupplyChainNode.h"
#include <iostream>

using namespace std;

/*
 * Supply chain controller class responsible for handling simulation details
 * and generating the blockchain.
 */
class SupplyChainController {
private:
  int numNodes;
  SupplyChainNode *scHead;
  // int numThreads - for multithreading later
  // file saveFile - the file for reading the nodes and blockchains
public:
  SupplyChainController(int numNodes); // add overload for saved blockchain file
  ~SupplyChainController();            // add overload for saved blockchain file
  int getNumNodes() { return numNodes; }
  SupplyChainNode *getSCHead() { return scHead; }
  void startSimulation();
  void saveBlocks();
};

#endif
