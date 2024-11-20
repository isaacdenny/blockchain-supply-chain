#include "SupplyChainNode.h"

SupplyChainNode::SupplyChainNode(int id) : id(id) {}

void SupplyChainNode::handleProduct(Product &p) {
  p.addNodeVisited();
  // maybe build the transaction data here and return it?
}
