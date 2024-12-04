#include <iostream>
#include "../src/BlockChain.h"

using namespace std;

int main() {
    
    // Initialize the blockchain
    Blockchain blockchain;

    // Print the initial state of the blockchain (genesis block)
    cout << "Initial blockchain state:\n";
    for (const auto &block : blockchain.getChain()) {
        cout << "Index: " << block.getIndex() << "\n"
             << "Timestamp: " << block.getTimestamp() << "\n"
             << "Data: " << block.getData() << "\n"
             << "Previous Hash: " << block.getPreviousHash() << "\n"
             << "Hash: " << block.getHash() << "\n"
             << "----------------------------------\n";
    }

    // Transactions...
    cout << "\nAdding transactions...\n";
    blockchain.addTransaction(Transaction(101, 0, 1));
    blockchain.addTransaction(Transaction(102, 2, 3));
    blockchain.addTransaction(Transaction(103, 4, 5));

    // Display pending transactions
    cout << "\nPending transactions:\n";
    for (const auto &transaction : blockchain.getPendingTransactions()) {
        cout << "ProductID: " << transaction.getProductId()
             << ", NodeFrom: " << transaction.getNodeFrom()
             << ", NodeTo: " << transaction.getNodeTo() << "\n";
    }

    // Create a block from pending transactions
    cout << "\nCreating block from pending transactions...\n";
    blockchain.createBlock();

    // Display the updated blockchain
    cout << "\nUpdated blockchain state:\n";
    for (const auto &block : blockchain.getChain()) {
        cout << "Index: " << block.getIndex() << "\n"
             << "Timestamp: " << block.getTimestamp() << "\n"
             << "Data: " << block.getData() << "\n"
             << "Previous Hash: " << block.getPreviousHash() << "\n"
             << "Hash: " << block.getHash() << "\n"
             << "----------------------------------\n";
    }

    // Validate the blockchain
    cout << "\nValidating blockchain integrity...\n";
    if (blockchain.isChainValid()) {
        cout << "Blockchain is valid.\n";
    } else {
        cout << "Blockchain is invalid!\n";
    }

    // Add more transactions and create another block
    cout << "\nAdding more transactions...\n";
    blockchain.addTransaction(Transaction(104, 3, 4));
    blockchain.addTransaction(Transaction(105, 4, 5));

    // Display pending transactions again
    cout << "\nPending transactions:\n";
    for (const auto &transaction : blockchain.getPendingTransactions()) {
        cout << "ProductID: " << transaction.getProductId()
             << ", NodeFrom: " << transaction.getNodeFrom()
             << ", NodeTo: " << transaction.getNodeTo() << "\n";
    }

    cout << "\nCreating another block from pending transactions...\n";
    blockchain.createBlock();

    // Final state of the blockchain
    cout << "\nFinal blockchain state:\n";
    for (const auto &block : blockchain.getChain()) {
        cout << "Index: " << block.getIndex() << "\n"
             << "Timestamp: " << block.getTimestamp() << "\n"
             << "Data: " << block.getData() << "\n"
             << "Previous Hash: " << block.getPreviousHash() << "\n"
             << "Hash: " << block.getHash() << "\n"
             << "----------------------------------\n";
    }

    // Validate the blockchain again
    cout << "\nFinal validation of blockchain integrity...\n";
    if (blockchain.isChainValid()) {
        cout << "Blockchain is valid.\n";
    } else {
        cout << "Blockchain is invalid!\n";
    }

    // Tamper with the blockchain
    cout << "\nTampering with block 1...\n";
    blockchain.tamperBlock(1, "Tampered Data");

    // Validate the blockchain after tampering
    cout << "\nValidating blockchain integrity after tampering...\n";
    if (blockchain.isChainValid()) {
        cout << "Blockchain is valid.\n";
    } else {
        cout << "Blockchain is invalid.\n";
    }

    return 0;
}
