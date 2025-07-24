#include <array>
#include <string>
#include <iostream>
#include "entity.h"

Entity::Entity(int hp, int spd, int dmg) {
    health = hp;
    speed = spd;
    damage = dmg;
}

void Entity::setHealth(int newHealth) {
    health = newHealth;
    if(health < 0) {
        health = 0;
    }
}


Cat::Cat(std::string name) { // base cat constrcutor
    mrowCoins = 100;
    this -> name = name;
    health = 14;
    damage = 2;
    speed = 1;
    
}

Cat::Cat(std::string name, int health, int speed, int damage, int mrowCoins) {
    this -> name = name;
    this -> health = health;
    this -> speed = speed;
    this -> damage = damage;
    this -> mrowCoins = mrowCoins;
}

void Cat::displayBalance() {
    std::cout << "Mrow Coins: " << mrowCoins << "\n" << std::endl;
}

void Cat::display() {
    std::cout << "\n" << name << "'s stats:" << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Speed: " << speed << "\n" << std::endl;
}

OrangeCat::OrangeCat(std::string name) : Cat(name) { // orange cat constructor, 50 more coins
    mrowCoins += 50; 
    health -= 1;
    damage += 5;
    speed += 5;

};

std::string OrangeCat::getCatDescription() { // returns orange cat's description
    return "\nOranges start with the following: 150 Mrow Coins. The Orange Cat's base stats are: 13 Health, 7 Damage, 6 Speed.";
};
CalicoCat::CalicoCat(std::string name) : Cat(name){ //calico cat constructor, 100 more coins, 15 more fish
    mrowCoins += 100;
    health += 2;
    damage += 3;
    speed += 3;
}
std::string CalicoCat::getCatDescription() {
    return "\nCalicos start with the following: 200 Mrow Coins. The Calico's base stats are: 16 Health, 5 Damage, 4 Speed.";
};

TortoiseshellCat::TortoiseshellCat(std::string name) : Cat(name) { // tortoiseshell cat constructor, 75 more coins, 10 more fish
    mrowCoins += 75;
    health += 6;
    damage += 2;
    speed += 2;
};
std::string TortoiseshellCat::getCatDescription() {
    return "\nTortoiseshells start with the following: 175 Mrow Coins. The Tortoiseshell Cat's base stats are: 20 Health, 4 Damage, 3 Speed.";
};

Enemy::Enemy() { //base enemy constructor
    health = 14;
    damage = 1;
    speed = 2;
    reward = 20;
    type = "If you are seeing this, an error has most likely occured.";
}


void Enemy::display() {
    std::cout << "\nEnemy: ";
    std::cout << type << std::endl;
    std::cout << "Health: " << health << "\n" << std::endl; 
}


Human::Human() {
    health += 3;
    damage += 2;
    speed = 2;
    reward += 20;
    type = "the Human";
}

Dog::Dog() {
    health -= 2;
    damage += 2;
    speed += 3;
    reward += 10;
    type = "the Dog";
}

AnimalControl::AnimalControl() {
    health += 5;
    damage += 2;
    speed -= 1;
    reward += 30;
    type = "Animal Control";
}

Fox::Fox() {
    health -= 6;
    damage += 4;
    speed += 4;
    reward += 30;
    type = "the Fox";
}

Pistachio::Pistachio() {
    health += 25;
    damage += 1;
    speed += 2;
    reward += 50;
    type = "Pistachio";
}
