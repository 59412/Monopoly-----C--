//
//  building.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#include "building.h"
using namespace std;

int Building::getX(){return coordX;}
int Building::getY(){return coordY;}
void Building::setPrev(Building* b){prev = b;}
void Building::setNext(Building* b){next = b;}
Building* Building::getPrev(){return prev;}
Building* Building::getNext(){return next;}

