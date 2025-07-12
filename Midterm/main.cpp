#include <iostream> 
#include <fstream>
#include <string>
#include "grade.h"


int main() { 
    std::string gotName; 
    int gotidNumber;
    int amount;
    std::cout << "Please input how many students you'd like to add to the roster as a whole number: "; // from here down the code is creating an array based off of user inputs
    std::cin >> amount;
    std::cout << "You have chosen " << amount << " students.\nPlease input ID#s in ascending order." << std::endl;
    
    Student** rosterLst = new Student*[amount]; 
    for(int i = 0; i < amount; i++) {
        std::string name;
        float gpa;
        int id;
        std::cout << "Please input student's name: " << std::endl;
        std::cin >> name;
        std::cout << "Please input student's gpa as a decimal: " << std::endl;
        std::cin >> gpa;
        std::cout << "Please input student's id number as a whole number: " << std::endl;
        std:: cin >> id;
        rosterLst[i] = new Student(gpa, name, id);
    }   

    Roster* roster = new Roster(rosterLst, amount); // from here down I'm calling the functions and allowing the user to choose between searching from id# (int) or name (string)
    roster->saveToFile();
    roster->display();
    
    std::cout << "Would you like to search your roster by name or ID#? (Name/ID#).";
    std::cin >> gotName;
    if(gotName == "Name") {
        std::cout << "What is the name you are looking for? (Input Name): ";
        std::cin >> gotName;
        Student retrievedStudent = roster->linearSearch(gotName);
        retrievedStudent.display();
    } else if(gotName == "ID#") {
        std::cout << "What is the ID# you are looking for? (Input ID# as a whole number.): "; 
        std::cin >> gotidNumber;
        Student retrievedidNumber = roster->binarySearch(gotidNumber);
        retrievedidNumber.display();
    }
    delete[] rosterLst; // here i am freeing memory from the heap
    delete roster; 
    return 0; 
} 