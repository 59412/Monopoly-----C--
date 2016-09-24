//
//  residence.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef residence_h
#define residence_h

#include "propertySqr.h"

const int payPerRes = 25;

class Residence : public propertySqr{
public:
    Residence(std::string s,int posi,int cost,int X,int Y);
    //~Residence()override;
    int TotalVal() override;
    int getPrice() override;
    void toPaid(Player* p) override;//calculate how much p should pay and make p pay
    void notify(Player* p) override;//Call getPaid if p is not owner
};


#endif /* residence_hpp */
