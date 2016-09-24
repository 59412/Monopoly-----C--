//
//  residence.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#include "residence.h"
#include "map.h"
using namespace std;

Residence::Residence(string s,int posi,int cost,int X,int Y){
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
//Residence::~Residence(){}

int Residence::TotalVal(){return price * mortPortion;}
int Residence::getPrice(){return price;}
void Residence::toPaid(Player* p){
    int numRes;
    for (int i = 0; i < (int)owner->ownings.size(); ++i) {
        if (Residence* r = dynamic_cast<Residence*>(owner->ownings.at(i).front())) {
        //if (typeid(owner->ownings.at(i).front()) == typeid(Residence)){
            numRes = (int)owner->ownings.at(i).size();
            break;
        }
    }
    p->pay(numRes * payPerRes, owner);
}

void Residence::notify(Player* p){
    if (owner == nullptr) {
        cout << "Do you want buy this building? (Y/N)";
        char c;
        cin >> c;
        if (c == 'Y') {
            p->pay(price);
        }else{
            p->getMap()->auction(this);
        }
    }else if (owner != p && mortagaged == false){
        toPaid(p);
    }
}