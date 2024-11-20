#ifndef SC_NODE
#define SC_NODE

#include <vector>
#include "Product.h"

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
  void handleProduct(Product &p);
};

#endif
