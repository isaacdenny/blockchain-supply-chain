#ifndef FILEIO_H
#define FILEIO_H

#include <string>

class FileIO {
public:
    FileIO(const std::string& fileName);
    void writeToFile(const std::string& data);
    void readFromFile();
    void clearFile();

private:
    std::string fileName;
};

#endif // FILEIO_H
