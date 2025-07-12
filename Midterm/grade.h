#pragma once
#include <string>

class Student { // creating class student assinging functions to it
public:
    std::string name;
    float gpa;
    int id;
    Student(float g, std::string n, int i);
    void display();
    };

class Roster { //creating class roster assigning functions to it
public: 
    int studentAmount;
    Student** studentLst;
    Roster(Student** sL, int stA);
    Student binarySearch(int id);
    Student linearSearch(std::string name);
    void saveToFile();    
    void display();
};
