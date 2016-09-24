//
//  academic.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef academic_h
#define academic_h

#include "propertySqr.h"


class Academic : public propertySqr{
    std::string improvements;
    const int Imp0Tut;
    const int Imp1Tut;
    const int Imp2Tut;
    const int Imp3Tut;
    const int Imp4Tut;
    const int Imp5Tut;
    const int ImpCost;
    const std::string block;
public:
    std::string getBlock();
    Academic(std::string s,std::string b,int p,int m,int X,int Y,int c,int p0,int p1, int p2, int p3, int p4, int p5);
    //ctor parameter order:name, price, position number, coordX, coordY, Improvement cost, tution when improvements is 0~5
    //~Academic()override;
    void clearImp();//reset Improvements
    int TotalVal() override;//return the total value when the building is sold
    int getImpCost();//return field ImpCost
    std::string Imp();//return the improvements string
    int getImp();//return the length of improvement string(number of improvements)
    void sellImp(Player *p);//sell improvements and change the length of improvements string
    int getPrice() override;//get price of academic building
    void toPaid(Player* p) override;//let player p paid when he stands on an academic buidling(including all calculations)
    void addImp(Player* p);//manipulate the improvements string
    void notify(Player* p) override;
};

#endif /* academic_hpp */
