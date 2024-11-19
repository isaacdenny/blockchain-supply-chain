#ifndef SC_NODE
#define SC_NODE

class SupplyChainNode {
private:
  // Blockchain blockchain - lockchain reference
  int id;
  SupplyChainNode* next;
public:
  SupplyChainNode(int id);
  int getId() { return id; }
  SupplyChainNode* getNext() { return next; }
  void setNext(SupplyChainNode* node);
  // Blockchain getBlockChain() - for saving all chains in one file
};

#endif
