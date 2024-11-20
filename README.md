# decentralized-supply-chain
A hashing project for CSC2710 - Algorithms that features a decentralized, blockchain supply chain in C++

## Overview

Designing a blockchain-based supply chain traceability system involves creating a decentralized and secure framework where each participant (node) can track the movement and history of goods across various stages in the supply chain. Below is an overview of the key concepts and their role in the project.

We want to create a supply chain simulation that stores its events (i.e. "Product B delivered to Warehouse 334") in decentralized blockchain. The blockchain uses hashing to verify new nodes and chains. 

![Flow of transactions in blockchain supply-chain](https://github.com/isaacdenny/decentralized-supply-chain/blob/main/research/blockchain-logistic.png)

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

![More descriptions on process of blockchain](https://github.com/isaacdenny/decentralized-supply-chain/blob/main/research/blockchain-for-supply-chain.png)

## Project Proposal

- [ ] Problem Space - Common supply chain failures and security flaws of centralized data systems
- [ ] Proposed Solution
      1. Decentralization
      2. Hashing of id's, transactions, data to be immutable
- [ ] Feasability - Short classes, low functionality to get things working fast

## MVP

What does our program need to do to?

1. Simulate a supply chain
2. Generate a blockchain log of each transaction - [Javascript BlockChain Videos](https://www.youtube.com/watch?v=zVqczFZr124&list=PLggJAWhpyrRxKmetiP3RdTa7VAbGaXWub)
3. Validate the blockchain record (check for data tampering)

![Simple blockchain supply-chain diagram](https://github.com/isaacdenny/decentralized-supply-chain/blob/main/research/Blockchain-in-the-supply-chain-2.png)

## Extendible Functionality

Things to add to our project if we have time:

1. Blockchain record resolution techniques (see research methods above)
2. Different attack methods
3. Multithreading to speed up supply chain AND/OR blockchain validation

## Program Design

### Class Structures

#### Product
- id (int)
- nodesVisited (int)

#### SupplyChainNode
- TBD

#### SupplyChainController
- list of nodes (vector SupplyChainNode)
- list of products (vector Product)
- blockchain (BlockChain)
- startSimulation()

#### Blocks
- timestamp
- data (product #, from, to)
- previousHash (using any commercial)

#### BlockChain
- list of blocks (vector Block)
- addBlock()
- validateChain()
