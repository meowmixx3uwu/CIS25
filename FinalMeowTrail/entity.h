#pragma once
#include <array>
#include <string>

class Entity {
public:
    Entity() = default;
    Entity(int hp, int spd, int dmg); 
    int health;
    int speed;
    int damage;
    virtual void display() = 0;
    void setHealth(int newHealth);
};


class Cat : public Entity {
public:
    Cat(std::string name);
    Cat(std::string name, int health, int speed, int damage, int mrowCoins);
    void displayBalance();
    virtual void display() override;
    int mrowCoins;
    std::string name;
};


class OrangeCat : public Cat {
public: 
    OrangeCat(std::string name); 
    static std::string getCatDescription();
};

class CalicoCat : public Cat {
public:
  
CalicoCat(std::string name);
    static std::string getCatDescription();
};

class TortoiseshellCat : public Cat {
public: 
    TortoiseshellCat(std::string name);      
    static std::string getCatDescription();
}; 


class Enemy : public Entity {
public:
    Enemy();
    void display() override;
    int reward;
    std::string type;
};

class Human : public Enemy {
public:
    Human();
};

class Dog : public Enemy {
public:
    Dog();
};

class AnimalControl : public Enemy {
public:
    AnimalControl();
};

class Fox : public Enemy {
public:
    Fox();
};

class Pistachio : public Enemy {
public:
    Pistachio();
};