//
//  gym.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef gym_h
#define gym_h

#include "propertySqr.h"

class Gym : public propertySqr{
public:
    Gym(std::string s,int posi,int cost,int X,int Y);
    //~Gym()override;
    int TotalVal() override;
    int getPrice() override;
    void toPaid(Player* p) override;//Get p paid for standing on gym
    void notify(Player* p) override;
};

#endif /* gym_hpp */
