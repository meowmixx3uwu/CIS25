#pragma once
#include <iostream>
#include <string>
#include "entity.h"

void shop(Cat* user);

class Game {
public: 
    int currentScene;
    std::string location;
    Game();
    ~Game();
    void saveToFile();
    void loadFromFile();
    Cat* user; 
    std::string sceneZero();
    void sceneOne();
    void sceneTwo();
    bool sceneThree();
    void sceneFour();
    bool sceneFive();
    bool sceneSix();
    bool sceneSeven();
    void run(); 

};


