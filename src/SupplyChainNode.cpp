#include "SupplyChainNode.h"
using namespace std;

SupplyChainNode::SupplyChainNode(int id) : id(id) {}

void SupplyChainNode::handleProduct(Product &p) {
  p.addNodeVisited();
}

void SupplyChainNode::setNext(SupplyChainNode &node) {
  this->next = &node;
}
