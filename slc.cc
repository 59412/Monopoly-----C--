#include "slc.h"
#include "player.h"
#include "map.h"
#include <string>
#include <iostream>
using namespace std;


Slc::Slc(int X, int Y, int m){
    name = "SLC";
    coordX = X;
    coordY = Y;
    number = m;
    prev = nullptr;
    next = nullptr;
}
//Slc::~Slc(){}

void Slc::sendPlayer(Player *p, int steps)
{
	int origCoordX = p->coordX;
	int origCoordY = p->coordX;
	p->locationIndex += steps;
	if(p->locationIndex >= 40)
	{
		 p->locationIndex -= 40;
	}
	p->position = p->getMap()->getBuilding(p->locationIndex);
	p->coordX = p->position->getX();
	p->coordY = p->position->getY();

	p->getMap()->changePlayer(p->particle,origCoordX,origCoordY,p->coordX,p->coordY);

	p->getMap()->rollCup();
	 
	p->position->notify(p);
}

void Slc::notify(Player* p){
    srand((int)time(0));
    int outcomeIndex = 1 + rand()%24;
    
    if(outcomeIndex <= 3)
    {
    	cout << "Player " << p->name;
    	cout << " just got sent backward 3 steps!" << endl;
    	sendPlayer(p,-3);
    }
    else if(outcomeIndex <= 7)
	{
    	cout << "Player " << p->name;
    	cout << " just got sent backward 2 steps!" << endl;
    	sendPlayer(p,-2); 
	}
    else if(outcomeIndex <= 11)
   	{
    	cout << "Player " << p->name;
    	cout << " just got sent backward 1 steps!" << endl;
    	sendPlayer(p,-1);
   	}
    else if(outcomeIndex <= 14)
   	{
    	cout << "Player " << p->name;
    	cout << " just got sent forward 1 steps!" << endl;
    	sendPlayer(p,1);
   	}
    else if(outcomeIndex <= 18)
    {
    	cout << "Player " << p->name;
    	cout << " just got sent forward 2 steps!" << endl;
    	sendPlayer(p,2);
    }
    else if(outcomeIndex <= 22)
    {
    	cout << "Player " << p->name;
    	cout << " just got sent forward 3 steps!" << endl;
    	sendPlayer(p,3);
    }
    else if(outcomeIndex == 23)
    {
    	cout << "Player " << p->name;
    	cout << " just got sent to DC Tims!" << endl;
        p->getMap()->getBuilding(10)->notify(p);
    }
    else 
    {
    	p->locationIndex = 0;
		p->position = p->getMap()->getBuilding(0);
		p->coordX = p->position->getX();
		p->coordY = p->position->getY();
		cout << "Player " << p->name;
		cout << " just got sent to OSAP!" << endl;
		p->position->notify(p);
    }
}
