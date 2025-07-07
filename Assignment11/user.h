#pragma once
#include <string>

class User {
public:
    virtual void accessLevel();
};

class Employee : public User{
    void accessLevel() override;
};

class InventoryManager : public Employee{
public:
    void accessLevel() override;
};