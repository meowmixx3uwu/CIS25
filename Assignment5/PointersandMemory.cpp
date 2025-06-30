#include <iostream>
#include <string>
using namespace std;
// Define a struct to represent a student
struct Student {
  int id;
  string name;
  double gpa;
};

struct Item {
  string name;
  int id;
};

Item binary_search(int id, Item* lst, int lstSize) {
  int begin = 0;
  int end = lstSize;
  int middle = (begin + end) / 2;
  while (id != lst[middle].id) {
    middle = (begin + end) / 2;
    if (begin == end)
      return {"ID not found", id};

    if (lst[middle].id < id)
      begin = middle + 1;
    else
      end = middle;
  }
  return lst[middle];
}

int main() {
  // Declare an array of Student structs
  Student students[3]; // Initialize the elements of the array
  students[0] = {101, "Michael", 3.8};
  students[1] = {102, "Lakisha", 3.5};
  students[2] = {103, "Charlie", 3.9};

  // Access and print data from the array of structs
  for (int i = 0; i < 3; ++i) {
    cout << "Student ID: " << students[i].id << ", Name: "
              << students[i].name << ", GPA: " << students[i].gpa
              << endl;
  }

  Item* itemList = new Item[3];
  itemList[0] = {students[0].name, students[0].id};
  itemList[1] = {students[1].name, students[1].id};
  itemList[2] = {students[2].name, students[2].id};
  int input;
  cout << "Type ID: ";
  cin >> input;

  Item obtainedItem = binary_search(input, itemList, 3);
  cout << "Name " << obtainedItem.name << "\nID " << obtainedItem.id << endl;

  delete[] itemList;

  return 0;
}