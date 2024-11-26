#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
private:
  int productId;
  int nodeFrom;
  int nodeTo;
public:
  Transaction(int productId, int nodeFrom, int nodeTo);
  int getProductId() const { return productId; }
  int getNodeFrom() const { return nodeFrom; }
  int getNodeTo() const { return nodeTo; }
};

#endif
