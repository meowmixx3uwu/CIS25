#include <string>
#include <iostream>
#include "story.h"
#include "entity.h"
#include "encounters.h"
#include <fstream>


Game::Game(){
    user = nullptr;
    location = "n/a";
    currentScene = 0;
}

Game::~Game(){
    delete user;
}

void Game::run(){
    
    std::string playerInput = sceneZero();
    if(playerInput == "No") {
        std::cout << "Okay :(" << std::endl;
        return;
    }
    currentScene = 1;
    loadFromFile();
    
    if(currentScene == 1) {
        sceneOne();
        currentScene++;
        saveToFile();
    }
    
    if(currentScene == 2) {
        sceneTwo();
        currentScene++;
        saveToFile();
    }

    if(currentScene == 3) {
        if(!sceneThree()) {
            saveToFile();
            return;
        }
        currentScene++;
        saveToFile();
    }
    

    if(currentScene == 4) {
        sceneFour();
        currentScene++;
        saveToFile();
    }
    

    if(currentScene == 5) {
        if(!sceneFive()) {
            saveToFile();
            return;
        }
        currentScene++;
        saveToFile();
    }

    if(currentScene == 6) {
         if(!sceneSix()) {
            saveToFile();
            return;
        }
        currentScene++;
        saveToFile();
    }
    
    if(currentScene == 7) {
        if(!sceneSeven()) {
            saveToFile();
            return;
        }
        user->setHealth(0); // this so when player wins it resets game
        saveToFile();
    }
    
}


void Game::saveToFile() {
    std::ofstream file("user.txt");
    if (file.is_open()) {
        if(user != nullptr) {
            if(user->health <= 0) {
                file << "";
            } else {
                file << user->name << "," << location << "," << user->mrowCoins << "," << user->health << "," << user->damage << "," << user->speed << "," << currentScene;
            }
        }
        file.close();
    }
}

void Game::loadFromFile() {
    std::ifstream in("user.txt");  // allowing it to read from the file
    
    if (in.is_open()) {  
        
        std::string line;
        getline(in, line); // here down grabs five values and loads
        
        if(line == "") {
            return;
        }
    
        std::string name = line.substr(0, line.find(","));
        line = line.substr(line.find(",") + 1, line.size() - 1);

        location = line.substr(0, line.find(",")); 
        line = line.substr(line.find(",") + 1, line.size() - 1);
        
        int mrowCoins = std::stoi(line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1, line.size() - 1);
        
        int health = std::stoi(line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1, line.size() - 1);
        
        int damage = std::stoi(line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1, line.size() - 1);
        
        int speed = std::stoi(line.substr(0, line.find(",")));
        line = line.substr(line.find(",") + 1, line.size() - 1);
        
        currentScene = std::stoi(line.substr(0));

        
        
        user = new Cat(name, health, speed, damage, mrowCoins);
        in.close(); 
    }
}





std::string Game::sceneZero() { // making the intro scene, returns "Yes" or "No" depending on their input
    std::cout << "\n*****************************************************" << std::endl;
    std::cout << "\nWelcome to Meow Trail. Thank you for playing." << std::endl;
    std::string playerInput; 
    do {
        std::cout << "Would you like to play Meow Trail? (Yes/No): "; //prompitng user if they want to play or not 
        std::cin >> playerInput;
    } while (playerInput != "Yes" && playerInput != "No"); 
    
    return playerInput;
}

void Game::sceneOne() { //scene one includes choosing player's type, name, and giving a story introducition
    std::cout << "\n" << "You, the Player, are a house cat that craves more milk." << std::endl; //introducing the story
    std::cout << "However, your owners won't give you any, under the guise that it is apparently not good for your stomachs.\n";
    std::cout << "So, to get the milk you desire, you have decided to traverse the Meow Trail, a treacherous route leading to the land of Dairy.\n" << std::endl;

    std::string isThisTheirDesiredName;   
    std::string playerName; 
    do {
        std::cout << "Please input your name: ";
        std::cin >> playerName; //add username file saving here :3  
        std::cout << "You have chosen " << playerName << " as your name. Is this correct? (Yes/No): ";
        std::cin >> isThisTheirDesiredName;
    } while (isThisTheirDesiredName != "Yes");

    std::string whichCat;
    std::string isThisTheirDesiredType;
    bool areTheyStupid;
    do { 
        do {
            std::cout << "\nBefore you begin your journey, you must decide which cat you are.\nChoose from Orange Cat, Tortoiseshell Cat, or Calico Cat." << "\n" << std::endl; 
            std::cout << OrangeCat::getCatDescription() << "\n" << std::endl;
            std::cout << TortoiseshellCat::getCatDescription() << "\n" << std::endl;
            std::cout << CalicoCat::getCatDescription() << "\n" << std::endl;
            std::cout << "Input your choice (Calico, Orange, Tortoiseshell): ";
            std::cin >> whichCat;
            areTheyStupid = whichCat != "Calico" && whichCat != "Tortoiseshell" && whichCat!= "Orange";
            if (areTheyStupid) {
                std::cout << "Invalid input. Please choose again." << std::endl;
            }
        } while (areTheyStupid);
        std::cout << "You have chosen " << whichCat << " as your type. Is this correct? (Yes/No) ";
        std::cin >> isThisTheirDesiredType;
    } while (isThisTheirDesiredType != "Yes");

    if(whichCat == "Orange")
        user = new OrangeCat(playerName);   
    else if(whichCat == "Calico")
        user = new CalicoCat(playerName);
    else
        user = new TortoiseshellCat(playerName);
}

void Game::sceneTwo() { // scene two includes some story, some choices.
    std::string whichRoute;
    bool routeCheck;
    do {
        std::cout << "\nYour story begins in your owner's apartment building." << std::endl;
        std::cout << "You decide that there are two possible options for which you may make your escape, the front door, and a window." << std::endl;
        std::cout << "\nWhat would you like to do? (Window/Door): ";
        std::cin >> whichRoute;
        routeCheck = whichRoute != "Door" && whichRoute != "Window";
    } while (routeCheck);
    std::cout << "You have chosen the " << whichRoute << " option." << std::endl;
    if(whichRoute == "Window") {
        std::cout << "\nYou pad over to the window, small pawpads making little noise as you hop up the sofa and jump onto the windowsill." << std::endl;
        std::cout << "It is open, but there is a thin mesh screen blocking freedom. You extend a claw and cut a small hole in the screen." << std::endl;
        std::cout << "You jump through the hole, and land gracefully on your feet. You have entered the Alleyway." << std::endl;
        location = "Alleyway";
    }
    if(whichRoute == "Door") {
        std::cout << "\nYou quietly crawl over to the front door, but find it closed." << std::endl;
        std::cout << "Luckily, your Owner taught you to open the door. So, you gracefully jump up, pull the handle down with your paws, and the door creaks open." << std::endl;
        std::cout << "You cross the threshold, free of your home, but nowhere near the end. You have now entered the Hallway." << std::endl;
        location = "Hallway";
    }
}

bool Game::sceneThree() { // scene three includes the first combat. 
    Enemy* enemy = nullptr;
    if(location == "Hallway") {
        std::cout << "\nYou walk down the Hallway, claws sheathed, for now." << std::endl;
        std::cout << "You turn a corner, and your slitted eyes fall upon a Human!" << std::endl;
        std::cout << "The Human turns to look at you, its eyes wide as it speaks: 'Oh, hey little kitty... you lost? C'mere...'" << std::endl;
        std::cout << "You hiss, and initiate battle." << std::endl;
        enemy = new Human();
    }
    
    if(location == "Alleyway") {
        std::cout << "\nYour sheathed claws click quietly on the pavement as you walk, the putrid aroma making your ears flatten in disgust," << std::endl;
        std::cout << "Just as you are about to reach the mouth of the Alleyway, a growl from behind freezes you in your place, your hackles rising." << std::endl;
        std::cout << "You quickly turn, your eyes catching a large, mangy Dog. It bares its fangs, ears pinned back. It looks ready to strike." << std::endl;
        std::cout << "You unsheathe your claws, and initiate combat." << std::endl;
        enemy = new Dog();
    }
    
    bool didPlayerDie = !combat(user, enemy); //sees if they die, runs combat, ends code if they died.
    delete enemy;
    if(!didPlayerDie) {
        return true;
    } else {
        return false;
    }
    
}

void Game::sceneFour() { // scene four includes the first shop
    if(location == "Hallway") { // they fight a human if they chose door
        std::string playerInput;
        std::cout << "You walk away from the Human, alive, but damaged. You make it to the front door of the apartment building, but it's closed, and locked." << std::endl;
        std::cout << "You check your money and stats.\n" << std::endl;
        user->display();
        user->displayBalance();
        std::cout << "Satisfied, you sit, licking your claws clean from the Human's blood. Your eyes scan the Hallway, searching for escape routes, but find nothing." << std::endl;
        std::cout << "Instead, you hear a stage-whisper; 'Come, fellow feline. I've things for you, little cat.'. You turn, hackles raising...\n" << std::endl;
        std::cout << "But you don't see an enemy. You see a fellow cat, dressed in a large, silky, purple cape, glasses made from tuna cans. It beckons you closer." << std::endl;
        std::cout << "When you pad over, it grins, all of its sharp teeth bared, and speaks: 'Hello, child. You are escaping to the Dairy land, yes?'" << std::endl;
        std::cout << "You nod, and he laughs. 'I assumed as much. I'm the Duke. Also known as the shopkeeper. You may buy stat upgrades from me, using those precious Mrow Coins of yours.\n" << std::endl;
        
        do { // same do while loop in other scenes. just error checking.
            std::cout << "'Would you like to view my offerings, youngling?' The shopkeeper rasps, slitted eyes on yours. (Yes/No): ";
            std::cin >> playerInput;
        } while (playerInput != "Yes" && playerInput != "No");
       
        if (playerInput == "Yes") {
            shop(user);
        } else if(playerInput == "No") {
            std::cout << "You shake your head, and walk away, determined to find an exit out of the apartment building." << std::endl;
        }
    
        std::cout << "You walk, the shopkeep, or 'Duke' as he calls himself, behind you. " << std::endl;
        std::cout << "A rattle sounds at the Hallway's door, and you scamper over, slipping between a Human's legs as it enters. You have successfully entered the City." << std::endl;
    
    }
    
    if(location == "Alleyway") { // they fight a dog if they chose window
        std::string playerInput;
        std::cout << "You walk away from the Dog, alive. Your claws click, the sound loud in the suddenly quiet Alleyway, as you make it to the outlet." << std::endl;
        std::cout << "But, just as you are about to scurry out, a low, raspy chuckle sounds from behind you. You turn, claws unsheathing...\n" << std::endl;
        std::cout << "And your eyes fall upon a fellow cat. You narrow them in suspicion. The cat grins, all teeth, and speaks: " << std::endl;
        std::cout << "'Hello, fellow feline. I assume you are on your way to the Dairy land, yes?' Without waiting for an answer, he beckons you closer, moving through a hole carved into a dumpster." << std::endl;
        std::cout << "You follow, and he turns, dressed in a silky purple cape, with eye glasses made from tuna cans, fur whispy with age." << std::endl;
        std::cout << "'Many call me the Duke. But you may call me Shopkeep, youngling. I have many a stat upgrade for you to purchase, using those delectable Mrow Coins of yours..." << std::endl;
    
    do {
        std::cout << "\n'Would you like to view my offerings, youngling?' The shopkeeper rasps, slitted eyes on yours. (Yes/No): ";
        std::cin >> playerInput;
    } while (playerInput != "Yes" && playerInput != "No");

    if (playerInput == "Yes") {
        shop(user);
    } else if(playerInput == "No") {
        std::cout << "You shake your head, and walk away, determined to continue your path to the land of Dairy." << std::endl;
    }
    
    std::cout << "\nYou retreat back to the mouth of the Alleyway, scampering through." << std::endl;
    std::cout << "You have now entered the City" << std::endl;
    
    }
}

bool Game::sceneFive() { // scene five includes second combat.
    Enemy* enemy = nullptr;
    
    std::cout << "\nYou make your way through the City, flitting between Human's legs, stealing sandwiches when no one's looking, enjoying your freedom." << std::endl;
    std::cout << "You make it near the end of the City, tail held high, confident, until a whistle blows from behind, your ears ringing from the awful noise." << std::endl;
    std::cout << "Your narrowed eyes fall upon a Human, but they are in a special uniform, and are holding a catch-pole, the cable at its end dangling ominously." << std::endl;
    std::cout << "It is Animal Control. Your pupils dilate in panic. But, there's nowhere to run. So, with your small heart beating fast, you hiss, and initiate combat." << std::endl;
    
    enemy = new AnimalControl();
    
    bool didPlayerDie = !combat(user, enemy); 
    delete enemy;
    

    
    if(didPlayerDie) {
        return false;
    }
    
    std::cout << "\nYou walk away from the Animal Control Human, slightly worse for the wear, but alive. For now." << std::endl;
    std::cout << "You make it out of the City, skyscrapers and streets giving way to fields and farmland. You have now entered the Valley." << std::endl;
    return true;
}

bool Game::sceneSix() { // scene six includes second shop and third combat
    std::string playerInput;
    Enemy* enemy = nullptr;
    
    std::cout << "\nYou grow close to the land of Dairy. Walking along dirt roads, rows of corn, orchards of oranges, apples, almonds your only entertainment." << std::endl;
    std::cout << "The occasional car rumbles along the road, but the Humans within never seem to notice, or care, about your presence." << std::endl;
    std::cout << "A few more miles and you will make it. But just as you are about to scurry through an almond orchard, a snarl from behind freezes you in place." << std::endl;
    std::cout << "\nYou turn, claws bared, eyes slitted, ears pinned back, familiar with this routine by now. You gaze falls upon a red Fox." << std::endl;
    std::cout << "Its teeth are bared, its hackles raised. It clearly considers this its territory." << std::endl;
    std::cout << "You hiss, and initiate battle." << std::endl;

    enemy = new Fox();
    bool didPlayerDie = !combat(user, enemy); 
    delete enemy;
    if(didPlayerDie) {
        return false;
    }
    
    std::cout << "\nYou walk away from the Fox, exhausted, battered, bruised from the onslaught of enemies." << std::endl;
    std::cout << "You trudge through the orchard, eyes heavy, until you're snatched by the scruff like a kitten, and dragged into a hollowed out oak tree" << std::endl;
    std::cout << "You hiss, but are too exhausted, eyes falling upon... the Duke. You sigh, relieved." << std::endl;
    std::cout << "\n'Hello, child. You look much worse for the wear. Worry not, I shall help, free of charge.'" << std::endl;
    std::cout << "You blink, eyes heavy, until he pulls out a shimmery can of cat food and brings it to your muzzle." << std::endl;
    std::cout << "'Drink, youngling. It will revitalize you.' You do, swallowing the watery food, and instantly, you feel like you just woke up from a great, seventeen hour nap." << std::endl;
    user->health += 10;
    user->display();
    std::cout << "'There, youngling. Now... I see you've gathered some more Mrow Coins.'" << std::endl;

    do {
        std::cout << "\n'Would you like to view my offerings?' The shopkeeper rasps, grinning, his fur pristine despite the tree you both sit in. (Yes/No): ";
        std::cin >> playerInput;
    } while (playerInput != "Yes" && playerInput != "No");

    if (playerInput == "Yes") {
        shop(user);
    } else if(playerInput == "No") {
        std::cout << "You shake your head, and walk away, determined to continue your path to the land of Dairy." << std::endl;
    }

    std::cout << "\nThe hollowed out oak tree falls behind you as you make your way out of the orchard. You look ahead, seeing a large dairy ranch." << std::endl;
    std::cout << "You walk forward, determined. You have made it to the Dairy Ranch, aka... the land of Dairy." << std::endl;

    return true;

}

bool Game::sceneSeven() { // scene seven includes last combat and end of the game.
    Enemy* enemy = nullptr;
    std::cout << "\nYour eyes fall upon the large, red building that you know, via scent, holds the milk you so desire." << std::endl;
    std::cout << "You have traveled far, from your apartment, to the City, to the Valley... and now, you're finally here." << std::endl;
    std::cout << "But of course, it would not be that easy." << std::endl;
    std::cout << "\nYou hear a laugh, smug, like the creature behind it has already won." << std::endl;
    std::cout << "You snarl, your fangs bared, and peer up at the haybale where the noise came from." << std::endl;
    std::cout << "Your heart stutters. It's a fellow cat. But definitely *not* the Duke." << std::endl;
    std::cout << "\nIt stares down at you, its pupils blown black with jealous rage as it speaks: " << std::endl;
    std::cout << "'You have come far, " << user->name << ". And yes, fool, I know your name.'" << std::endl;
    std::cout << "The cat gestures with groomed paws to a cage, where a somber Duke lays trapped. You growl. The cat grins." << std::endl;
    std::cout << "'This will be the end of your little journey. The milk here is mine, and mine alone.'" << std::endl;
    std::cout << "'I am Pistachio, and all shall fear me.'" << std::endl;
    std::cout << "You hiss, determined, and initiate combat." << std::endl;
    
    enemy = new Pistachio();
    bool didPlayerDie = !combat(user, enemy); 
    delete enemy;
    if(didPlayerDie) {
        return false;
    }
    
    std::cout << "\nYou stand over a defeated Pistachio, your journey finally, finally at its end." << std::endl;
    std::cout << "But before you consume your milk, you crawl over to the Duke, and free him, giving him a slight nod of acknowledgement." << std::endl;
    std::cout << "'I knew you had it in you, youngling. Go, enjoy your prize.' He rasps. You turn, padding over to the Barn." << std::endl;
    std::cout << "You crawl under the large door, scamper over to a full bucket, and drink milk, finally." << std::endl;
    std::cout << "\n This is the end of Meow Trail. Thank you for playing!" << std::endl;
    
    
    return true;
}
