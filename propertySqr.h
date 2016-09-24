//
//  propertySqr.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef propertySqr_h
#define propertySqr_h

#include "building.h"
#include <string>
const std::string A1 = "Arts1";
const std::string A2 = "Arts2";
const std::string E = "Eng";
const std::string H = "Health";
const std::string Ev = "Env";
const std::string S1 = "Sci1";
const std::string S2 = "Sci2";
const std::string M = "Math";

const int mortPortion = 0.5;

//class player;

class propertySqr : public Building{
protected:
    int price;
    Player* owner;
public:
    bool mortagaged;
        
    void changeMortagageStatus();
    void changeOwner(Player* p);
    Player* getOwner();
    //virtual ~propertySqr()=0;
    virtual int TotalVal()=0;
    virtual int getPrice()=0;
    virtual void toPaid(Player* p)=0;
    virtual void notify(Player* p)=0;
};



#endif /* propertySqr_hpp */
