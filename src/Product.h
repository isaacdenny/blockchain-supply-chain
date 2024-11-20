#ifndef PRODUCT_H
#define PRODUCT_H

#include <cstdint>
class Product {
private:
  int id;
  int nodesVisited;

public:
  Product(int id);
  int getId() { return id; }
  void setId(int id);
  int getNodesVisited() { return nodesVisited; }
  void addNodeVisited();
};

#endif
