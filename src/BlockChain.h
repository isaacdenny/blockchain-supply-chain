#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"
#include "Transaction.h"

class Blockchain {
private:
    std::vector<Block> chain;                  // The blockchain, a list of blocks
    std::vector<Transaction> pendingTransactions; // Transactions waiting to be added to a block

    // Function to create the genesis block
    Block createGenesisBlock();

public:
    // Constructor
    Blockchain();

    // Get the latest block in the chain
    const Block &getLatestBlock() const;

    // Add a new block with specific data
    void addBlock(const std::string &data);

    // Get the entire blockchain
    std::vector<Block> getChain() const;

    // Validate the blockchain integrity
    bool isChainValid() const;

    // Manage pending transactions
    std::vector<Transaction> getPendingTransactions() const; // Retrieve pending transactions
    void addTransaction(const Transaction &transaction);      // Add a transaction to the list
    void createBlockFromPendingTransactions();                // Create a block from pending transactions

    //Used for testing isChainValid()
    void tamperBlock(size_t index, const std::string &newData);


};

#endif // BLOCKCHAIN_H
