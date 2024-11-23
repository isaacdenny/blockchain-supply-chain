#include <iostream> // For printing test results to the console
#include "../src/Block.h" // Include the Blocks class for testing

using namespace std;

// Test to verify block creation and attribute initialization
void testBlockCreation() 
{
    cout << "Running testBlockCreation..." << endl;

    Block block(1, "Test Transaction", "0000");

    // Check if the block's index is correctly initialized
    if (block.getIndex() != 1) 
    {
        cout << "Failed: Block index is incorrect!" << endl;
        return;
    }

    // Check if the timestamp is properly generated
    if (block.getTimestamp().empty()) 
    {
        cout << "Failed: Block timestamp is empty!" << endl;
        return;
    }

    // Verify that the block's data is stored correctly
    if (block.getData() != "Test Transaction") 
    {
        cout << "Failed: Block data is incorrect!" << endl;
        return;
    }

    // Ensure the previous hash matches the input
    if (block.getPreviousHash() != "0000") 
    {
        cout << "Failed: Block previous hash is incorrect!" << endl;
        return;
    }

    // Check if the block's hash is generated and not empty
    if (block.getHash().empty()) 
    {
        cout << "Failed: Block hash is empty!" << endl;
        return;
    }

    cout << "testBlockCreation passed!" << endl; // Test passed
}

// Test to validate hash consistency
void testBlockHashConsistency() 
{
    cout << "Running testBlockHashConsistency..." << endl;

    // Create a block with test data
    Block block(2, "Sample Data", "12345");

    // Store the block's initial hash
    string initialHash = block.getHash();

    // Verify that the hash remains consistent
    if (initialHash != block.getHash()) 
    {
        cout << "Failed: Hash is not consistent!" << endl;
        return;
    }

    cout << "testBlockHashConsistency passed!" << endl; // Test passed
}


// Test to ensure the hash reflects the previous block's hash
void testPreviousHashLinkage() 
{
    cout << "Running testPreviousHashLinkage..." << endl;

    // Create the first block (genesis block)
    Block genesisBlock(0, "Genesis Data", "0000");

    // Create a second block linked to the first
    Block secondBlock(1, "Second Block Data", genesisBlock.getHash());

    // Verify that the second block's previous hash matches the first block's hash
    if (secondBlock.getPreviousHash() != genesisBlock.getHash()) 
    {
        cout << "Failed: Previous hash linkage is incorrect!" << endl;
        return;
    }

    cout << "testPreviousHashLinkage passed!" << endl; // Test passed
}

int main() 
{
    // Run all the test cases
    testBlockCreation();
    testBlockHashConsistency();
    testPreviousHashLinkage();

    // Print a success message if all tests pass
    cout << "All tests completed successfully!" << endl;
}
// g++ -o test_Blocks Blocks.cpp test_Blocks.cpp -lssl -lcrypto to complile
