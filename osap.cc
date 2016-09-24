#include "osap.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

Osap::Osap(){
    name = "COLLECT OSAP";
    coordX = 10;
    coordY = 10;
    prev = nullptr;
    next = nullptr;
    number = 0;
}
//Osap::~Osap(){}
void Osap::notify(Player* p){
    cout << "You get $" << OsapGet << " from OSAP." << endl;
    p->getPaid(OsapGet);
}
