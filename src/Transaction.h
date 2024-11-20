#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
private:
  int productId;
  int nodeFrom;
  int nodeTo;
public:
  Transaction(int productId, int nodeFrom, int nodeTo);
  int getProductId() { return productId; }
  int getNodeFrom() { return nodeFrom; }
  int getNodeTo() { return nodeTo; }
};

#endif
