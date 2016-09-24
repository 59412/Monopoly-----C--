//
//  gym.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#include "gym.h"
#include "map.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Gym::Gym(string s,int posi,int cost,int X,int Y){
    name=s;
    number=posi;
    price=cost;
    coordX=X;
    coordY=Y;
    prev=nullptr;
    next=nullptr;
    owner=nullptr;
    mortagaged = false;
}
//Gym::~Gym(){}

int Gym::TotalVal(){return price * mortPortion;}
int Gym::getPrice(){return price;}
void Gym::toPaid(Player* p){
    srand((int)time(0));
    int Row1 = 1+rand()%6;
    int Row2 = 1+rand()%6;
    int RowSum = Row1 + Row2;
    int numGym;
    int payment;
    for (int i = 0; i < (int)owner->ownings.size(); ++i) {
        if(Gym* g = dynamic_cast<Gym*>(owner->ownings.at(i).front())){
            numGym = (int)owner->ownings.at(i).size();
            break;
        }
    }
    if (numGym == 1) {
        payment = RowSum * 4;
    }else if(numGym == 2){
        payment = RowSum * 10;
    }
    p->pay(payment, owner);
    //return sum;
}

void Gym::notify(Player* p){
    if (owner == nullptr) {
        cout << "Do you want buy this building? (Y/N)";
        char c;
        cin >> c;
        if (c == 'Y') {
            p->pay(price);
        }else{
            p->getMap()->auction(this);
        }
    }else if(owner != p && mortagaged == false){
        toPaid(p);
    }
}
