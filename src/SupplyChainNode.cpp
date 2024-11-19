#include "SupplyChainNode.h"

SupplyChainNode::SupplyChainNode(int id)
    : id(id), next(nullptr) {}

void SupplyChainNode::setNext(SupplyChainNode* node) {
	next = node;
}
