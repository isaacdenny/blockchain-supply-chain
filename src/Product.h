#ifndef PRODUCT_H
#define PRODUCT_H

#include <cstdint>
class Product {
private:
  uint64_t id;
  uint64_t nodesVisited;

public:
  Product(uint64_t id);
  uint64_t getId() { return id; }
  uint64_t getNodesVisited() { return nodesVisited; }
  void addNodeVisited();
};

#endif
