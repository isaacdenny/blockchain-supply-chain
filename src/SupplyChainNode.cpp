#include "SupplyChainNode.h"

SupplyChainNode::SupplyChainNode(int id) : id(id) {}

Transaction SupplyChainNode::handleProduct(Product &p) {
  p.addNodeVisited();
  Transaction t(p.getId(), id, next->getId());
  return t;
}

void SupplyChainNode::setNext(SupplyChainNode &node) {
  this->next = &node;
}
