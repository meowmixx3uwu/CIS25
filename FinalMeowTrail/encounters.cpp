#include <string>
#include <iostream>
#include "entity.h"
#include "encounters.h"




bool combat(Cat* user, Enemy* enemy) {
    std::string playerMove;
    enemy->display();
    std::cout << "You face " << enemy->type << ", thinking of two possible options in combat. You could either claw at them, or defend yourself in preparation." << std::endl;
    Entity* first;
    Entity* second;

    if(user->speed > enemy->speed) {
        first = user;
        second = enemy;
    } else {
        first = enemy;
        second = user;
    }

    do {
        std::cout << "\nWhat would you like to do? (Attack/Defend): ";
        std::cin >> playerMove;
        
        if(playerMove == "Attack") {
            
            if(user == first) { 
                std::cout << "\nYou lash out with your claws, striking your foe. You do " << user->damage << " damage." << std::endl;
            } else {
                std::cout << "\nThe " << enemy->type << " moves first, striking you for " << enemy->damage << " damage." << std::endl;
            } 
            
            second->setHealth(second->health - first->damage);

            enemy->display();
            user->display(); 
            
            if(second->health <= 0) {
                continue;
            }

            if(enemy == second) {
                std::cout << "The " << enemy->type << " moves last, striking you for " << enemy->damage << " damage." << std::endl;       
            } else {
                std::cout << "You lash out with your claws, moving second, striking your foe. You do " << user->damage << " damage." << std::endl;
            }
            
            first->setHealth(first->health - second->damage);          
            
        
        }
        
        if(playerMove == "Defend") {
            
            if (user == first) {
                std::cout << "\nWith your superior speed, you assume a defensive position, forcing the " << enemy->type << " to do 0 damage." << std::endl;
            
            } else {
                user->setHealth(user->health - enemy->damage);
                std::cout << "\nYou attempt to defend yourself, but are too slow, and the " << enemy->type << " attacks you anyway. You take " << enemy->damage << " damage." << std::endl;
            }
            
        
        }
        
        enemy->display();
        user->display(); 
    
    } while (enemy->health > 0 && user->health > 0);
            
    
    
    if(user->health <= 0) {
        std::cout << "You have perished. Sorry :(" << std::endl;
        return false;
    } 
    
    std::cout << "You have defeated the " << enemy->type << " successfully.\nYou gain " << enemy->reward << " Mrow Coins." << std::endl;
    user->mrowCoins += enemy->reward;
    return true;
}

void shop(Cat* user) {
    user->displayBalance();
    std::cout << "The shopkeep pulls open his cape, revealing pockets lined with small catfood cans." << std::endl;
    std::string playerInput;
    do {
        std::string hpUp = "hpUp: Adds 2 to your health stat. Costs 30 Mrow Coins.\n";
        std::string spdUp = "spdUp: Adds 1 to your speed stat. Costs 35 Mrow Coins.\n";
        std::string dmgUp = "dmgUp: Adds 1 to your damage stat. Costs 50 Mrow Coins.\n";
        std::cout << "You look. The shopkeep describes them as follows: \n" << hpUp << spdUp << dmgUp << std::endl;
        std::cout << "Would you like to purchase anything? (Yes/No): ";
        std::cin >> playerInput;
        
        if (playerInput == "Yes") {
            std::cout << "What would you like to purchase? (hpUp/spdUp/dmgUp): ";
            std::cin >> playerInput;
            
            if (playerInput == "hpUp" && user->mrowCoins >= 30) {
                user->health += 2;
                user->mrowCoins -= 30;
                user->display();
                user->displayBalance();
                continue;
            } else if (user->mrowCoins <= 30) {
                std::cout << "Insufficient balance.\n" << std::endl;
                continue;
            }
            
            if (playerInput == "spdUp" && user->mrowCoins >= 35) {
                user->speed += 1;
                user->mrowCoins -= 35;
                user->display();
                user->displayBalance();
                continue;
            } else if (user->mrowCoins <= 35) {
                std::cout << "Insufficient balance.\n" << std::endl;
                continue;
            }
            
            if (playerInput == "dmgUp" && user-> mrowCoins >= 50) {
                user->damage += 1;
                user->mrowCoins -= 50;
                user->display();
                user->displayBalance();
                continue;
            } else if(user->mrowCoins <= 50) {
                std::cout << "Insufficient balance.\n" << std::endl;
                continue;
            }

        }
    } while (playerInput != "No"); // return to scene four

    std::cout << "Exiting shop..." << std::endl;
}