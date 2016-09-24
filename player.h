//
//  player.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef player_h
#define player_h

#include <iostream>
#include <vector>
#include "building.h"
//#include "display.h"

//const string A1 = "Arts1";
const int cA1 = 50;
const int mA1 = 2;
//const string A2 = "Arts2";
const int cA2 = 50;
const int mA2 = 3;
//const string E = "Eng";
const int cE = 100;
const int mE = 3;
//const string H = "Health";
const int cH = 100;
const int mH = 3;
//const string Ev = "Env";
const int cEv = 150;
const int mEv = 3;
//const string S1 = "Sci1";
const int cS1 = 150;
const int mS1 = 3;
//const string S2 = "Sci2";
const int cS2 = 200;
const int mS2 = 3;
//const string M = "Math";
const int cM = 200;
const int mM = 2;
const int maxImp = 5;

class Academic;
class propertySqr;
class Building;
class Map;

class Player{
    Map *m;
    int cash;
    int cups;
    int ifToBreak();
    void bankruptcy();
    void bankruptcy(Player *);
    int total();
    bool broken;
    //Display *dp;//added after Diaplay is constructed
public:
    const std::string name;
    const char particle;
    Building *position;
    int locationIndex;
    int turnInDC;//initialized to be 3
    int coordX;
    int coordY;
    int rollOne;
    int rollTwo;
    std::vector<std::vector<propertySqr *>> ownings;
    
    //SubscriptionType subType()override;
    
    Player(std::string name, char particle, Map *m);//called by map and mortgage
    Player(std::string name, char particle,int cups,int cash, int pos, Map *m);//ctor for load
    Player(std::string name, char particle,int cups,int cash, int pos,int dc, Map *m);//ctor for load with turn in dc
    
    void swap(Player &other);
    Player(const Player &other);
    Player(Player &&other);
    Player &operator=(const Player &other);
    Player &operator=(Player &&other);
    ~Player();
    
    void notify(Building *b);//can only be called by map, discuss later...
    //auctions should be done before calling this
    
    void notifyOb();//notify building when land on it, pass *this in param
    
    bool blockImp(Academic *a);//check if the monopoly has improvements//for trade
    
    bool isBroken();// return if player is broken
    
    const int getCash();// return the cash value
    
    const int getCup();// return the cap value
    
    void buyMort(propertySqr *b);//buy a mortgaged building from others, auction/askedTrade call
    //does not check the mortgage status
    //only collect tax and money if unmortgaged at once, does not modify owner
    
    //int total();// after reading Bankruptcy, I found that we may not need it
    
    //pay only raises auction when negative payment(e.g. tuition) is more than cash
    //checked for all methods in this method, careful use please
    void pay(int n, Player *p);//pay tuition/rent/...| must be called by building get paid
    
    void pay(int n); //pay to nonPropertySqr/others do not need a receiver
    ///////////////////////////////////////////////////////
    
    void getPaid(int n);// get cash from others
    
    void improve(Academic *b);// make improvements to building
    
    void addOwning(propertySqr *b);
    //simply add b to your ownings vector
    //this method does not make any change to "cash"
    //make sure you call pay()&getPaid() after you call this one
    //Buy a building, called by map/auction/trade. Check if bulding can be added inside this method
    
    void removeOwnings(propertySqr *b);
    //simply remove the pointer from the vector
    //this method does not make any change to "cash"
    //make sure you call pay()&getPaid() after you call this one
    //sell/lose a building by any means
    
    void addCup();
    // add a cup, called by SLC or Needles Hall, only changes player's cup field
    
    void lostCup();
    
    void goToDC(Building *dc);// change X, Y, position, turnInDc to 0
    
    
    //No pot here, all checked!
    void askedTrade(Player *p, propertySqr *otherB, propertySqr *myB);
    
    void askedTrade(Player *p, int oMoney, propertySqr *myB);
    
    void askedTrade(Player *p, propertySqr *otherB, int myMoney);
    
    void askedTrade(Player *p, int oMoney, int myMoney);//reject trade money w money
    
    //call by map, go take from cin
    //owner, impr, cash, mtgstatus check
    void mortgage(propertySqr *p);
    void unmortgage(propertySqr *p);
    
    //sell impr
    //all checked here
    void sellImp(Academic *a);
    
    //ASSET, tuition resolved in tuition
    void asset();
    
    //give a map pointer
    Map* getMap();
};


#endif /* player_hpp */
