#include "coop.h"
#include "player.h"
#include <iostream>
using namespace std;

Coop::Coop(){
    name = "COOP FEE";
    coordX = 10;
    coordY = 8;
    number = 38;
    prev = nullptr;
    next = nullptr;
}
//Coop::~Coop(){}
void Coop::notify(Player* p){
    cout << "Pay $" << CoopFee << " to School." << endl;
    p->pay(CoopFee);
}
