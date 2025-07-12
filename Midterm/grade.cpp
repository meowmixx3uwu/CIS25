#include <iostream>
#include <fstream>
#include "grade.h"

Student::Student(float g, std::string n, int i) {
    gpa = g;
    name = n;
    id = i;
}

void Student::display() {
    std::cout << "Student's GPA: " << gpa << "\nStudent's Name: " << name << "\nStudent's ID#: " << id << std::endl; 
}

Roster::Roster(Student** sL, int stA) {
    studentAmount = stA;
    studentLst = sL;
}

Student Roster::binarySearch(int id) { //creating the bianry search function
    int begin = 0;
    int end = studentAmount;
    int middle = (begin + end) / 2;
    while (id != studentLst[middle]->id) {
        middle = (begin + end) / 2;
        if (begin == end)
            return {0.0,"Student Not Found",-1};     
        if (studentLst[middle]->id < id)
            begin = middle + 1;
        else
            end = middle;
    }
    return *studentLst[middle];     
}

Student Roster::linearSearch(std::string name){ //creating the lienar search function
    for(int i = 0; i < studentAmount; i++){
        if (name == studentLst[i]->name)
        return *studentLst[i];
    }
    return {0.0, "Student Not Found", -1};
} 

void Roster::saveToFile() { //saving to file
    std::ofstream out("students.txt"); 
    if (out.is_open()) { 
        for(int i = 0; i < studentAmount; i++){
            out << studentLst[i]->name << ", " << studentLst[i]->gpa << ", " << studentLst[i]->id << std::endl;
        }
        out.close(); 
        std::cout << "Student saved to file." << std::endl; 
    } else { 
        std::cout << "Unable to open file for writing." << std::endl; 
    } 
}

void Roster::display(){ //display student
    for(int i = 0; i < studentAmount; i++){
    studentLst[i]->display();
    }
}