#include "Blocks.h" // Include the Blocks header file
#include <sstream>    // For formatting hash into a string
#include <iomanip>    // For controlling output format (hexadecimal hash)
#include <openssl/evp.h> // For OpenSSL EVP interface (modern cryptographic API)

using namespace std;

// Utility function to compute SHA-256 hash for a given input string
// This function uses OpenSSL's EVP interface to calculate the hash securely.
string sha256(const string& str) {
    unsigned char hash[EVP_MAX_MD_SIZE]; // Buffer to store the hash
    unsigned int hashLength;            // Length of the resulting hash

    // Create and initialize an EVP_MD_CTX structure for hashing
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (!context) { // Check if the context was created successfully
        throw runtime_error("Failed to create EVP_MD_CTX");
    }

    // Initialize the SHA-256 operation
    if (!EVP_DigestInit_ex(context, EVP_sha256(), nullptr)) {
        EVP_MD_CTX_free(context); // Free the context in case of failure
        throw runtime_error("Failed to initialize SHA-256 digest");
    }

    // Update the hash with the input data
    if (!EVP_DigestUpdate(context, str.c_str(), str.size())) {
        EVP_MD_CTX_free(context); // Free the context in case of failure
        throw runtime_error("Failed to update SHA-256 digest");
    }

    // Finalize the hash computation
    if (!EVP_DigestFinal_ex(context, hash, &hashLength)) {
        EVP_MD_CTX_free(context); // Free the context in case of failure
        throw runtime_error("Failed to finalize SHA-256 digest");
    }

    // Free the EVP_MD_CTX structure after use
    EVP_MD_CTX_free(context);

    // Convert the hash to a readable hexadecimal string
    stringstream ss;
    for (unsigned int i = 0; i < hashLength; ++i) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str(); // Return the hash as a hexadecimal string
}

// Constructor to initialize a block with index, data, and previous hash
Blocks::Blocks(int idx, const string& dat, const string& prevHash)
    : index(idx), data(dat), previousHash(prevHash) {
    // Get the current system time as a timestamp
    time_t now = time(0);         // Get the current time in seconds since epoch
    timestamp = to_string(now);   // Convert the time to a string format

    // Calculate and store the block's hash
    hash = calculateHash();
}

// Private method to calculate the block's hash based on its attributes
string Blocks::calculateHash() const {
    // Combine block attributes to form the input for hashing
    string input = to_string(index) + previousHash + timestamp + data;

    // Compute the hash using the `sha256` utility function
    return sha256(input);
}

// Getter method to return the block's index
int Blocks::getIndex() const {
    return index; // Return the index value
}

// Getter method to return the block's timestamp
string Blocks::getTimestamp() const {
    return timestamp; // Return the timestamp value
}

// Getter method to return the block's data
string Blocks::getData() const {
    return data; // Return the data value
}

// Getter method to return the hash of the previous block
string Blocks::getPreviousHash() const {
    return previousHash; // Return the previous block's hash
}

// Getter method to return the hash of the current block
string Blocks::getHash() const {
    return hash; // Return the current block's hash
}

// Method to validate the block's integrity
bool Blocks::isValid() const {
    // Recalculate the hash and compare it to the stored hash
    return hash == calculateHash();
}
