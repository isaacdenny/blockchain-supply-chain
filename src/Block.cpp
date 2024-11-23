#include "Block.h"
#include <iomanip>
#include <openssl/evp.h> // For OpenSSL EVP interface (modern cryptographic API)
#include <sstream>

using namespace std;

// Utility function to compute SHA-256 hash for a given input string
// This function uses OpenSSL's EVP interface to calculate the hash securely.
string sha256(const string &str) {
  unsigned char hash[EVP_MAX_MD_SIZE]; // Buffer to store the hash
  unsigned int hashLength;             // Length of the resulting hash

  // Create and initialize an EVP_MD_CTX structure for hashing
  EVP_MD_CTX *context = EVP_MD_CTX_new();
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

Block::Block(int idx, const string &dat, const string &prevHash)
    : index(idx), data(dat), previousHash(prevHash) {
  // Get the current system time as a timestamp
  time_t now = time(0);       // Get the current time in seconds since epoch
  timestamp = to_string(now); // Convert the time to a string format

  hash = calculateHash();
}

// Private method to calculate the block's hash based on its attributes
string Block::calculateHash() const {
  // Combine block attributes to form the input for hashing
  string input = to_string(index) + previousHash + timestamp + data;

  // Compute the hash using the `sha256` utility function
  return sha256(input);
}

bool Block::isValid() const { return hash == calculateHash(); }
