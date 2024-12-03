#!/bin/bash

# This script compiles the C++ code using g++ and links OpenSSL libraries.

# Set the source files and output binary name
SOURCE_FILES="src/* "
TEST_FILE="tests/presentationT.cpp"
OUTPUT_BINARY="presentation_test"

# Compile with g++, link the OpenSSL libraries (ssl and crypto)
g++ $SOURCE_FILES $TEST_FILE -o $OUTPUT_BINARY -lssl -lcrypto

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! The output is '$OUTPUT_BINARY'."
else
    echo "Compilation failed."
fi
