#include "BlockChain.h"
#include <sstream>

//Constructor
Blockchain::Blockchain() {
    chain.push_back(createGenesisBlock());
}

//Create the genesis block
Block Blockchain::createGenesisBlock() {
    return Block(0, "Genesis Block", "0");
}

//Get the blockchain chain
std::vector<Block> Blockchain::getChain() const {
    return chain;
}

//Add a transaction to pending transactions
void Blockchain::addTransaction(const Transaction &transaction) {
    pendingTransactions.push_back(transaction);
}

//Get pending transactions
std::vector<Transaction> Blockchain::getPendingTransactions() const {
    return pendingTransactions;
}

//Create a block from pending transactions
void Blockchain::createBlock() {
    std::ostringstream oss;

    //Loop through pending transactions and format their data into a string.
    for (const auto &transaction : pendingTransactions) {
        oss << "ProductID=" << transaction.getProductId()
            << ", NodeFrom=" << transaction.getNodeFrom()
            << ", NodeTo=" << transaction.getNodeTo() << "\n";
    }

    addBlock(oss.str());

    pendingTransactions.clear();
}

//Add a block to the chain
void Blockchain::addBlock(const std::string &data) {
    const Block &lastBlock = getLatestBlock();

    Block newBlock(lastBlock.getIndex() + 1, data, lastBlock.getHash());

    chain.push_back(newBlock);
}

//Get the latest block in the chain
const Block &Blockchain::getLatestBlock() const {
    return chain.back();
}

//Validate the blockchain integrity
bool Blockchain::isChainValid() const {
    //Loop through the chain starting from the second block (index 1).
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block &currentBlock = chain[i];
        const Block &previousBlock = chain[i - 1];

        if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
            return false;
        }

        if (!currentBlock.isValid()) {
            return false;
        }
    }
    return true;
}

//Tamper with a specific block's data
void Blockchain::tamperBlock(size_t index, string newData) {
    //Ensure the index is within the valid range.
    if (index < chain.size()) {
        //Replace the block's data with the new data, maintaining the same index and previous hash.
        chain[index].setData(newData);
    } else {
        // Throw an exception if the index is out of range.
        throw std::out_of_range("Block index out of range");
    }
}
