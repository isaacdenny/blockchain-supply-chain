#ifndef SC_NODE
#define SC_NODE

#include <vector>
#include "Product.h"

using namespace std;

class SupplyChainNode {
private:
  int id;
public:
  SupplyChainNode(int id);
  int getId() { return id; }
  void setId(int id);
  void handleProduct(Product &p);
};

#endif
