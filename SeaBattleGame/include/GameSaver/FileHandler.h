#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <string>

#include "GameSaver.h"

class FileHandler
{
    std::ifstream mInFile;
    std::ofstream mOutFile;

public:
    FileHandler(std::string name = "testsave.txt", bool writeMode = true);

    void write(GameSaver& state);
    void read(GameSaver& state);

    ~FileHandler();
};

#endif