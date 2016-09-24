#include "goose.h"
#include <iostream>
using namespace std;

Goose::Goose(){
    name = "Goose Nesting";
    prev = nullptr;
    next = nullptr;
    number = 20;
    coordX = 0;
    coordY = 0;
}
//Goose::~Goose(){}
void Goose::notify(Player* p){
    cout << "DANGER! YOU ARE ATTACKED BY GEESE." << endl;
}
