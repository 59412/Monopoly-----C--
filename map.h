//
//  map.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

//  map.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef map_h
#define map_h

#include <iostream>
#include <vector>
#include "player.h"

const int numOfBuilding = 40;

const int width = 8;
const int height = 6;
const int maxPlayer = 8;
class Player;

class Map{
	int numOfCupLeft;
    int numOfPlayer;
    std::vector<Player *>playerInGame;
    Building *unit[numOfBuilding];
    //helper
    void saveHelper(std::string saveFileName);
    //
public:
    char** cells;
    Player *currentPlayer;
    int indexOfPlayer;
    int getNumPlayer();//num of player in game currently
    std::string oneLeft();//return the first nonbroken player
    propertySqr* findProp(std::string name);//find a propertySqr
    Building* getBuilding(int i);
    
    
    // Constructors and Destructor
    Map(int totalPlayer); // constructor 1, for when new game is made
    Map(std::string saveFileName); // constructor 2 for load game
    ~Map();
    
    // print
    friend std::ostream &operator<<(std::ostream &out, const Map &mp);
    
    // Functions
    void rollDice();
    void rollCup();
    void rollDice(int r1, int r2);

    //helper
    void changePlayer(char c, int originX, int originY, int newX, int newY);
    void placePlayer(char c, int posx, int posy);
    //
    
    void saveGame(std::string FileName); // ask for a file name, replace/create
    void nextPlayer();
    void auction(propertySqr *p);
    
    //asset
    void allAsset();
    //trade
    void trade(std::string name, std::string give, std::string receive);
};


#endif /* map_hpp */

