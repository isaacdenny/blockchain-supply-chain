//This is a temporary file for io written by Kevin
//Mostly for testing and ease of implementation when time comes
//has a basic write and read function to display our hashes


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class fileioBASE {
public:

    // Function to write data to the file
    void writeToFile(const string& data) {
        ofstream outFile(fileName, ios::app); // Open in append mode
        if (outFile.is_open()) {
            outFile << data << endl;
            outFile.close();
        } else {
            cout << "Wrong file name" << endl;
        }
    }

    // Function to read data from the file
    void readFromFile() {
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "File not loaded" << endl;
        }
    }

    // Function to clear the contents of the file
    void clearFile() {
        ofstream outFile(fileName, ios::trunc); // Truncate mode
        if (outFile.is_open()) {
            outFile.close();
        } else {
            cerr << "File not loaded" << endl;
        }
    }

private:
    string fileName;
};

/* EXAMPLE USE CASE 
int main() {
    // Example usage

    //file declaration (How we declare a file)
    FileIO file("example.txt");

    
    file.writeToFile("This is a test.");

    Read file line by line
    file.readFromFile();

    To clear the file
    file.clearFile();

    

    return 0;


*/
