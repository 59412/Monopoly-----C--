//
//  academic.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#include "academic.h"
#include "map.h"
#include <string>
#include <typeinfo>
using namespace std;

Academic::Academic(string s,string b,int p,int m,int X,int Y,int c,int p0,int p1, int p2, int p3, int p4, int p5):block{b},Imp0Tut{p0},Imp1Tut{p1},Imp2Tut{p2},Imp3Tut{p3},Imp4Tut{p4},Imp5Tut{p5},ImpCost{c}{
    name=s;
    price=p;
    number=m;
    coordX=X;
    coordY=Y;
    prev=nullptr;
    next=nullptr;
    improvements="";
    owner=nullptr;
    mortagaged = false;
}
//Academic::~Academic(){}

void Academic::clearImp(){
    improvements = "";
}

string Academic::Imp(){return improvements;}

string Academic::getBlock(){return block;}

int Academic::getImpCost(){return ImpCost;}

int Academic::getImp(){return (int)improvements.length();}

int Academic::TotalVal(){
    int sum = price * mortPortion;
    sum += (int)improvements.length() * mortPortion * ImpCost;
    return sum;
}

int Academic::getPrice(){return price;}
void Academic::toPaid(Player* p){
    bool ownAll = false;
    int payment = Imp0Tut;
    int x = 0;
    //check if the owner owns all the monopoly block
    for (int i = 0; i < (int)owner->ownings.size(); ++i) {
        if (Academic *a = dynamic_cast<Academic*>(owner->ownings.at(i).front())) {
            if(a->block == block) {
                if ((block == A2||block == E||block == H||block == Ev||block == S1||block == S2)&&((int)owner->ownings.at(i).size() == 3)){
                    ownAll = true;
                    x = i;
                    break;
                }else if((a->block == A2||a->block == M)&&((int)owner->ownings.at(i).size() == 2)){
                    ownAll = true;
                    x = i;
                    break;
                }
            }
        }
    }
    //check improvements and decide how much to pay
    if (improvements == "") {
        if (ownAll) {
            payment = Imp0Tut * 2;
        }else{
            payment = Imp0Tut;
        }
    }else if(improvements.length() == 1){
        payment = Imp1Tut;
    }else if(improvements.length() == 2){
        payment = Imp2Tut;
    }else if(improvements.length() == 3){
        payment = Imp3Tut;
    }else if (improvements.length() == 4){
        payment = Imp4Tut;
    }else if (improvements.length() == 5){
        payment = Imp5Tut;
    }
    p->pay(payment, owner);
}

void Academic::addImp(Player* p){
    Map* m = p->getMap();
    int len = (int)improvements.length();
    if (len < maxImp) {
        improvements += "I";
        //update map
        int x = coordX * width + (int)improvements.length() + 1;
        int y = coordY * height + 1;
        m->cells[y][x] = 'I';
    }
}

void Academic::sellImp(Player* p){
    Map* m = p->getMap();
    if (getImp() == 0) {
        cout << "No improvements to sell." << name << endl;
    }else{
        cout << "You are selling one improvements on your building " << name << endl;
        improvements = improvements.substr(0, improvements.length()-1);
        p->getPaid(mortPortion * ImpCost);
        cout << "You got $" << mortPortion * ImpCost << endl;
        //update map
        int x = coordX * width + (int)improvements.length() + 1;
        int y = coordY * height + 1;
        m->cells[y][x] = ' ';
    }
}

void Academic::notify(Player* p){
    //ONLY be notified when it is owned and the player on it may have to pay tuition
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


