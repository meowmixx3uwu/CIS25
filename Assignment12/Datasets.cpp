#include <iostream>
#include <fstream>
#include "Datasets.h"

ReadCSV::ReadCSV(std::string fN){    
fileName = fN;
}

void ReadCSV::readFromFile(){ 
    std::ifstream in("LoL_champion_data.csv");  // allowing it to read from the file
    
    if (in.is_open()) {  
        std::string line;
        for (int i = 0; i < 10; i++) { 
            getline(in, line); // here down grabs five values and displays them
            std::string name = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1, line.size() - 1);
            std::string idNumber = line.substr(0,line.find(","));
            line = line.substr(line.find(",") + 1, line.size() - 1);
            line = line.substr(line.find(",") + 1, line.size() - 1);
            std::string title = line.substr(0,line.find(","));
            line = line.substr(line.find(",") + 1, line.size() - 1);
            std::string difficultyLevel = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1, line.size() - 1);
            std::string archetype = line.substr(0, line.find(","));
            std::cout << "Name: " << name << " ID: " << idNumber << " Title: " << "'" << title << "'" << " Difficulty Level: " << difficultyLevel << " Archetype: " << archetype << std::endl; 
        }
        
        in.close(); 
    } else { 
        std::cout << "Unable to open file for reading." << std::endl; //error checking
    } 
}