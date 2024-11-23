#ifndef BLOCK_H
#define BLOCK_H

#include <ctime>
#include <string>

using namespace std;

// The Blocks class represents an individual block in the blockchain.
// Each block contains details like its index, timestamp, data (transactions),
// previous hash, and hash.
class Block {
private:
  int index;           // Unique index of the block in the chain
  string timestamp;    // Time when the block was created
  string data;         // Transaction data or a list of transactions as a string
  string previousHash; // Hash of the previous block to maintain chain integrity
  string hash;         // Hash of the current block, ensuring data immutability

  // Private method to calculate the hash of the block using its data and
  // metadata
  string calculateHash() const;

public:
  Block(int index, const string &data, const string &previousHash);
  int getIndex() const { return index; }
  string getTimestamp() const { return timestamp; }
  string getData() const { return data; }
  string getPreviousHash() const { return previousHash; }
  string getHash() const { return hash; }
  bool isValid() const;
};

#endif
