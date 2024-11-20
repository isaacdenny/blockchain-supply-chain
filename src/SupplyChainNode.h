#ifndef SC_NODE
#define SC_NODE

#include <vector>
#include "Product.h"
#include "Transaction.h"

using namespace std;

class SupplyChainNode {
private:
  int id;
  SupplyChainNode* next;
public:
  SupplyChainNode(int id);
  int getId() { return id; }
  SupplyChainNode* getNext() { return next; }
  void setId(int id);
  void setNext(SupplyChainNode &node);
  Transaction handleProduct(Product &p);
};

#endif
