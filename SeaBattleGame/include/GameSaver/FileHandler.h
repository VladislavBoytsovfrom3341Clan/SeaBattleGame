#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <string>

#include "GameSaver.h"

class FileHandler
{
    std::string mName;
    std::ifstream mInFile;
    std::ofstream mOutFile;

public:
    FileHandler(std::string name = "testsave.txt");

    void openRead();
    void openWrite();

    void write(GameSaver& state);
    void read(GameSaver& state);


    void closeRead();
    void closeWrite();
};

#endif