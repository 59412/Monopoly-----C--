//
//  building.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef building_h
#define building_h
#include "observer.h"

class Player;

class Building: public Observer{
protected:
    Building* prev;
    Building* next;
    int coordX;
    int coordY;
public:
    //virtual ~Building()=0;
    int number;
    std::string name;
    int getX();
    int getY();
    void setPrev(Building* b);
    void setNext(Building* b);
    Building* getPrev();
    Building* getNext();
    virtual void notify(Player* p)=0;
};



#endif /* building_hpp */
