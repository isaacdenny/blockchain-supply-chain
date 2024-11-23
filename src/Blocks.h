#ifndef BLOCKS_H
#define BLOCKS_H

#include <string>
#include <ctime>

// Use the standard namespace for cleaner code
using namespace std;

// The Blocks class represents an individual block in the blockchain.
// Each block contains details like its index, timestamp, data (transactions), previous hash, and hash.
class Blocks {
private:
    int index;                 // Unique index of the block in the chain
    string timestamp;          // Time when the block was created
    string data;               // Transaction data or a list of transactions as a string
    string previousHash;       // Hash of the previous block to maintain chain integrity
    string hash;               // Hash of the current block, ensuring data immutability

    // Private method to calculate the hash of the block using its data and metadata
    string calculateHash() const;

public:
    // Constructor to initialize a block with given details
    Blocks(int index, const string& data, const string& previousHash);

    // Getters to access private data members (ensures encapsulation)
    int getIndex() const;                 // Returns the block's index
    string getTimestamp() const;          // Returns the block's creation timestamp
    string getData() const;               // Returns the data stored in the block
    string getPreviousHash() const;       // Returns the hash of the previous block
    string getHash() const;               // Returns the block's own hash

    // Verifies if the hash stored in the block matches the hash calculated from its current data
    bool isValid() const;
};

#endif // BLOCKS_H
