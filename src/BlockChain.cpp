#include "BlockChain.h"
#include <sstream>

// Constructor
// Initializes the blockchain by creating and adding the genesis block.
Blockchain::Blockchain() {
    chain.push_back(createGenesisBlock());
}

// Create the genesis block
// The genesis block is the first block in the blockchain, with index 0 and a fixed "Genesis Block" data.
Block Blockchain::createGenesisBlock() {
    return Block(0, "Genesis Block", "0");
}

// Get the blockchain chain
// Returns the entire blockchain (a vector of blocks).
std::vector<Block> Blockchain::getChain() const {
    return chain;
}

// Add a transaction to pending transactions
// Stores a transaction in the pending transactions list for future inclusion in a block.
void Blockchain::addTransaction(const Transaction &transaction) {
    pendingTransactions.push_back(transaction);
}

// Get pending transactions
// Returns the list of transactions that are yet to be included in a block.
std::vector<Transaction> Blockchain::getPendingTransactions() const {
    return pendingTransactions;
}

// Create a block from pending transactions
// Combines all pending transactions into a single block and clears the pending transactions list.
void Blockchain::createBlockFromPendingTransactions() {
    std::ostringstream oss;

    // Loop through pending transactions and format their data into a string.
    for (const auto &transaction : pendingTransactions) {
        oss << "ProductID=" << transaction.getProductId()
            << ", NodeFrom=" << transaction.getNodeFrom()
            << ", NodeTo=" << transaction.getNodeTo() << "\n";
    }

    // Add the new block to the blockchain using the formatted transaction data.
    addBlock(oss.str());

    // Clear the pending transactions after creating the block.
    pendingTransactions.clear();
}

// Add a block to the chain
// Creates a new block with the given data and adds it to the blockchain.
void Blockchain::addBlock(const std::string &data) {
    // Retrieve the latest block in the blockchain for reference.
    const Block &lastBlock = getLatestBlock();

    // Create a new block with an incremented index, the given data, and the hash of the last block.
    Block newBlock(lastBlock.getIndex() + 1, data, lastBlock.getHash());

    // Add the new block to the chain.
    chain.push_back(newBlock);
}

// Get the latest block in the chain
// Returns the most recently added block in the blockchain.
const Block &Blockchain::getLatestBlock() const {
    return chain.back();
}

// Validate the blockchain integrity
// Checks if the blockchain is valid by verifying the hashes and integrity of each block.
bool Blockchain::isChainValid() const {
    // Loop through the chain starting from the second block (index 1).
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block &currentBlock = chain[i];
        const Block &previousBlock = chain[i - 1];

        // Check if the current block's previous hash matches the previous block's hash.
        if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
            return false;
        }

        // Validate the block's integrity (e.g., hash computation).
        if (!currentBlock.isValid()) {
            return false;
        }
    }
    return true;
}

// Tamper with a specific block's data
// Replaces the data of a block at the specified index with new data, for testing purposes.
void Blockchain::tamperBlock(size_t index, const std::string &newData) {
    // Ensure the index is within the valid range.
    if (index < chain.size()) {
        // Replace the block's data with the new data, maintaining the same index and previous hash.
        chain[index] = Block(chain[index].getIndex(), newData, chain[index].getPreviousHash());
    } else {
        // Throw an exception if the index is out of range.
        throw std::out_of_range("Block index out of range");
    }
}
