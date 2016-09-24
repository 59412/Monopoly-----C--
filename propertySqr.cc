//
//  propertySqr.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#include "propertySqr.h"
#include "player.h"
using namespace std;

Player* propertySqr::getOwner(){return owner;}

void propertySqr::changeOwner(Player* p){
    if (owner != p)owner = p;
    p->addOwning(this);
}


void propertySqr::changeMortagageStatus(){
    if (mortagaged) {
        mortagaged = false;
    }else{
        mortagaged = true;
    }
}
