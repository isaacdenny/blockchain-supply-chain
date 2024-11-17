# decentralized-supply-chain
A hashing project for CSC2710 - Algorithms that features a decentralized, blockchain supply chain in C++

## Overview

Designing a blockchain-based supply chain traceability system involves creating a decentralized and secure framework where each participant (node) can track the movement and history of goods across various stages in the supply chain. Below is an overview of the key concepts and their role in the project.

We want to create a supply chain simulation that stores its events (i.e. "Product B delivered to Warehouse 334") in decentralized blockchain. The blockchain uses hashing to verify new nodes and chains. 

![Flow of transactions in blockchain supply-chain](https://github.com/isaacdenny/decentralized-supply-chain/blob/main/research/blockchain-logistic.png)
![More descriptions on process of blockchain](https://github.com/isaacdenny/decentralized-supply-chain/blob/main/research/blockchain-for-supply-chain.png)
![Simple blockchain supply-chain diagram](https://github.com/isaacdenny/decentralized-supply-chain/blob/main/research/Blockchain-in-the-supply-chain-2.png)


### Layout and Usage

- [ ] `src/`: source code for supply chain simulation
- [ ] `tests/`: unit tests and other relevant testing files

Example usage:

```
// Main program/driver file "main.cpp"

#include "supplychain.h"

int main(int argc, char* argv[]) {
    // takes in command line arguments for number of products, threads, etc...

    SupplyChainController controller(...simulation arguments);

    controller.start(); // starts the simulation

    // code for outputting results to file
}
```

The main file should be responsible for starting up the simulation and taking in any arguments (great for testing). With the simulation running, we should be able to run other scripts that attack the blockchain in different ways, forcing our simulation to handle it accordingly via different methods: 

***RESEARCH METHODS***
1. Quarantining products
2. Forking the blockchain
3. Rolling back to safe state
4. ...


### Node Design:

In a blockchain-based supply chain, a "node" represents a participant in the network. Each node interacts with the blockchain to verify transactions, store data, and propagate updates across the network.

Key Functions:

    Participant Identification: Each node should have a unique identifier (e.g., public key or hash) to distinguish it from other participants in the supply chain (e.g., a manufacturer, warehouse, distributor, retailer).
    Blockchain Copy: Each node maintains a local copy of the blockchain. The blockchain will store a list of transactions, which represent the movement of products.
    Transaction Validation: Before accepting a new block into the local blockchain, a node will validate the block’s authenticity. This includes checking the digital signature, ensuring the block's contents are correct (e.g., product ID, timestamp, sender, receiver), and verifying consensus with neighboring nodes.
    State Management: The node should manage and update the state of the goods as they move through the supply chain. For example, it should be able to store whether the goods are "in transit," "delivered," "inspected," etc.

Data Structure:

    Node Class: Should store information such as the node’s ID, the current blockchain state (blockchain stored in a vector or linked list), and transaction logs.
    Methods for interaction: Nodes should be able to communicate with each other (peer-to-peer communication for consensus, block propagation, etc.).
    Transaction Generation: Nodes will generate and broadcast transactions when an event (like a product shipment) occurs.

### Blockchain:

The blockchain in this context serves as the immutable ledger that records the events in the supply chain. Every transaction represents a state change in the movement of a product, and each block contains a set of transactions.
Key Functions:

    Chain Structure: The blockchain is made up of blocks, each containing a list of transactions. Each block should store a hash of the previous block to ensure immutability. The genesis block (the first block) will have no previous hash.
    Transaction Storage: Each block contains multiple transactions, with each transaction recording details such as product ID, timestamp, sender, receiver, quantity, and current status.
    Proof of Work (PoW) or Consensus Mechanism: Depending on the design, consensus might be achieved through a PoW (if simulating cryptocurrency-style consensus) or simpler techniques like a Proof of Stake (PoS) or Practical Byzantine Fault Tolerance (PBFT) if you need a lightweight, more centralized consensus.
    Block Creation: When a node generates a new transaction, it packages it into a block, signs the block using its private key, and broadcasts it to other nodes.
    Validation of Blocks: Nodes will validate each incoming block before appending it to their blockchain. This includes checking the block’s integrity (hash, timestamp, digital signature) and ensuring that it correctly follows the previous block (maintaining the chain's integrity).

Data Structure:

    Block Class: Contains a list of transactions, the previous block’s hash, and a unique block identifier.
    Blockchain Class: Stores the chain of blocks and methods for adding blocks, validating blocks, and ensuring the chain’s integrity.

### Transaction Design:

Transactions represent events that occur in the supply chain, such as the movement of goods between two nodes or a status update.
Key Functions:

    Transaction Details: Each transaction will include:
        Product ID: Unique identifier for the product.
        Sender and Receiver: IDs or addresses of the sender and receiver nodes (participants in the supply chain).
        Timestamp: When the transaction occurred.
        Status: Current state of the product (e.g., "dispatched," "in transit," "delivered").
        Digital Signature: To verify the authenticity of the transaction and the integrity of the data.
    Event Recording: When an event occurs, a transaction is generated that includes the relevant details. For example, when a manufacturer sends goods to a warehouse, a transaction would be created and broadcasted to the network.
    Validation: When a node receives a new transaction, it must check the validity (signature, product ID, sender/receiver information, etc.) before appending it to its local blockchain.

Data Structure:

    Transaction Class: Stores details of a transaction, including product ID, sender, receiver, timestamp, and a digital signature.

## Testing

Unit testing is crucial for ensuring the correctness of each individual component in the blockchain system, such as the node, blockchain, and transaction handling.
Key Functions:

    Node Tests:
        Test for proper initialization of nodes, including unique identifiers and local blockchain setup.
        Ensure that transactions can be correctly generated and validated.
        Test that nodes correctly handle incoming transactions and blocks, ensuring data integrity.
    Blockchain Tests:
        Test for the creation and appending of blocks.
        Test for chain validation, ensuring blocks are correctly linked.
        Test for handling invalid or corrupted blocks.
    Transaction Tests:
        Verify the correctness of the transaction creation process.
        Ensure that transactions contain all necessary fields and that digital signatures are valid.
    Edge Case Testing: Test scenarios like network failures, invalid blocks, or conflicting transactions.

Scaling the system to simulate a large number of nodes (hundreds or even thousands) is necessary to evaluate the system's performance and resilience.
Key Considerations:

    Node Creation: Efficiently instantiate a large number of nodes, each with its own blockchain and transaction log.
    Network Simulation: Use a simple network model where nodes can send and receive transactions to each other. This can be achieved by simulating a peer-to-peer network and having nodes communicate asynchronously.
    Transaction Load: Simulate a high transaction throughput by generating a large number of transactions and broadcasting them to multiple nodes.
    Scalability Testing: Measure the system’s response to high transaction volume, block size, and network traffic. Simulate network latencies, failures, and node crashes to test fault tolerance.
    Performance Benchmarks: Collect data on how long it takes to propagate blocks and validate transactions across a large network of nodes.
    Consensus Mechanism Efficiency: Test how well the consensus algorithm (e.g., PoW or PoS) scales with the number of nodes and transactions.

## Speed/Extra

Tools and Techniques:

    Multi-threading or Parallelism: 
    Simulated Latency: Introduce artificial latencies like delivery delays, failed shipments, refunds in supply chain model.
