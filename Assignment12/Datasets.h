#include <string>
#pragma once


class ReadCSV { //creating the read from file class
public:
    std::string fileName;
    ReadCSV (std::string fN);
    void readFromFile(); //adding the function that actualyl reads the file to the class
};

