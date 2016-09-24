//  map.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

//
//  map.cpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//


#include "map.h"
#include "academic.h"
#include "gym.h"
#include "residence.h"
#include "osap.h"
#include "goose.h"
#include "coop.h"
#include "slc.h"
#include "dctim.h"
#include "needles.h"
#include "tuition.h"
#include "gototim.h"

#include <iostream>
#include <vector> 
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <typeinfo>
#include <sstream>
using namespace std;

Map::Map(int totalPlayer) // constructor 1, for when new game is made
{
    numOfPlayer = totalPlayer;
    indexOfPlayer = 0;
    numOfCupLeft = 4;
    
    indexOfPlayer = 0;

    //read board.txt into cells
    cells = new char*[7];
    for (int i = 0; i < 7; ++i) {
        cells[i] = new char[29];
    }
    ifstream readFile;
    readFile.open("board.txt");
    char ch;
    for(int j = 0; j < 67; ++j) {
        for (int i = 0; i < 90; ++i) {
            readFile>>noskipws>>ch;
            cells[j][i] = ch;
        }
    }
    
    // Player constructors
    bool used[8];
    string nameArray[8];
    char charArray[8] = {'G','B','D','P','S','$','L','T'};
    for(int i = 0; i < 8; i++)
    {
         used[i] = false;
    }
    
    for(int i = 0; i < numOfPlayer; i++)
    {
    	cout << "Please input the name for player " << i+1 << ": " << endl;
    	cin >> nameArray[i];
        if(cin.fail())
         {
             cin.clear();
             cin.ignore();
        	 cout << "Invalid input, try again!" << endl;
        	 i--;
         }
    }
    
    for(int i = 0; i < totalPlayer; i++)
    {
         cout << "Player " << i + 1 <<" "<<nameArray[i]<< "," << endl;
    	 cout << "What particle do you prefer?`" << endl;
    	 cout << "Available: ";
    	 for(int j = 0; j < 8;j ++)
    	 {
    	      if(!(used[j]))
    	      {
    	           cout << charArray[j] << " ";
    	      }
    	 }
    	 cout << endl;
    	 bool failInput = true;
    	 char c;
		 cin >> c;
		 string pname;
		 char pparticle = '\0';
		 for(int k = 0; k < 8; k++)
		 {
		      if(c == charArray[k] && !(used[k]))
		      {
		    	  pname = nameArray[k];
		          pparticle = charArray[k];
		          used[k] = true;
		          failInput = false;
		      }
		 }
		 
		 if(failInput)
		 {
		      cout << "Invalid input or player name already exist!" << endl;
		      cout << "Try again!" << endl;
		      i--;
		 }
		 else
		 {
		      Player *p = new Player(pname, pparticle, this);
		      playerInGame.emplace_back(p);
		 }
    }
    currentPlayer = playerInGame.at(0);
    //  Buidling constructors    
    //Building* unit[numOfBuilding];
    unit[0] = new Osap();
    unit[1] = new Academic("AL","Arts1",40,1,9,10,50,2,10,30,90,160,250);
    unit[2] = new Slc(8,10,2);
    unit[3] = new Academic("ML","Arts1",60,3,7,10,50,4,20,60,180,320,450);
    unit[4] = new Tuition();
    unit[5] = new Residence("MKV",5,200,5,10);
    unit[6] = new Academic("ECH","Arts2",100,6,4,10,50,6,30,90,270,400,550);
    unit[7] = new Needles(3,10,7);
    unit[8] = new Academic("PAS","Arts2",100,8,2,10,50,6,30,90,270,400,550);
    unit[9] = new Academic("HH","Arts2",120,9,1,10,50,8,40,100,300,450,600);
    unit[10] = new DcTim();
    unit[11] = new Academic("RCH","Eng",140,11,0,9,100,10,50,150,450,625,750);
    unit[12] = new Gym("PAC",12,150,0,8);
    unit[13] = new Academic("DWE","Eng",140,13,0,7,100,10,50,150,450,625,750);
    unit[14] = new Academic("CPH","Eng",160,14,0,6,100,12,60,180,500,700,900);
    unit[15] = new Residence("UWP",15,200,0,5);
    unit[16] = new Academic("LHI","Health",180,16,0,4,100,14,70,200,550,750,950);
    unit[17] = new Slc(0,3,17);
    unit[18] = new Academic("BMH","Health",180,18,0,2,100,14,70,200,550,750,950);
    unit[19] = new Academic("OPT","Health",200,19,0,1,100,16,80,220,600,800,1000);
    unit[20] = new Goose();
    unit[21] = new Academic("EV1","Env",220,21,1,0,150,18,90,250,700,875,1050);
    unit[22] = new Needles(2,0,22);
    unit[23] = new Academic("EV2","Env",220,23,3,0,150,18,90,250,700,875,1050);
    unit[24] = new Academic("EV3","Env",240,24,4,0,150,20,100,300,750,925,1100);
    unit[25] = new Residence("V1",25,200,5,0);
    unit[26] = new Academic("PHYS","Sci1",260,26,6,0,150,22,110,330,800,975,1150);
    unit[27] = new Academic("B1","Sci1",260,27,7,0,150,22,110,330,800,975,1150);
    unit[28] = new Gym("CIF",28,150,8,0);
    unit[29] = new Academic("B2","Sci1",280,29,9,0,150,24,120,360,850,1025,1200);
    unit[30] = new GotoTim();
    unit[31] = new Academic("EIT","Sci2",300,31,10,1,200,26,130,390,900,1100,1275);
    unit[32] = new Academic("ESC","Sci2",300,32,10,2,200,26,130,390,900,1100,1275);
    unit[33] = new Slc(10,3,33);
    unit[34] = new Academic("C2","Sci2",320,34,10,4,200,28,150,450,100,1200,1400);
    unit[35] = new Residence("REV",35,200,10,5);;
    unit[36] = new Needles(6,10,36);
    unit[37] = new Academic("MC","Math",350,37,10,9,200,35,175,500,110,1300,1500);
    unit[38] = new Coop();
    unit[39] = new Academic("DC","Math",400,39,10,9,200,50,200,600,1400,1700,2000);
    //connect them into a chain
    unit[0]->setPrev(unit[39]);
    for (int i = 1; i < 39; ++i) {
        unit[i]->setPrev(unit[i-1]);
        unit[i]->setNext(unit[i+1]);
    }
    unit[39]->setNext(unit[0]);
}

Map::Map(string saveFileName) // constructor 2 for load game
{
    //read board.txt into cells
    cells = new char*[7];
    for (int i = 0; i < 7; ++i) {
        cells[i] = new char[29];
    }
    ifstream read;
    read.open("board.txt");
    char ch;
    for(int j = 0; j < 67; ++j) {
        for (int i = 0; i < 90; ++i) {
            read>>noskipws>>ch;
            cells[j][i] = ch;
        }
    }

    //read loading data
    string FileName = saveFileName + ".txt";
    ifstream readFile;
    readFile.open(FileName);
    string line;
    getline(readFile, line);
    istringstream num(line);
    num >>skipws>> numOfPlayer;
    // allocated player (but do not put them on the map)
    for (int i = 0; i < numOfPlayer; ++i) {
        istringstream ip(line);
        string pname;
        char pparticle;
        int cups;
        int cash;
        int pos;
        int sentToDC;
        int timesInDC = 0;
        ip >>skipws>> pname >> pparticle >> cups >> cash >> pos >> sentToDC >> timesInDC;
        if (cups > 0) {
            numOfCupLeft -= cups;
        }
        Player *p = new Player (pname,pparticle,cups,cash,pos,this);
        if (sentToDC == 0) {
            p->turnInDC = 3;
        }else{
            p->turnInDC = timesInDC;
        }
        playerInGame.emplace_back(p);
        
    }
    //initial buildings
    //Building* unit[numOfBuilding];
    unit[0] = new Osap();
    unit[1] = new Academic("AL","Arts1",40,1,9,10,50,2,10,30,90,160,250);
    unit[2] = new Slc(8,10,2);
    unit[3] = new Academic("ML","Arts1",60,3,7,10,50,4,20,60,180,320,450);
    unit[4] = new Tuition();
    unit[5] = new Residence("MKV",5,200,5,10);
    unit[6] = new Academic("ECH","Arts2",100,6,4,10,50,6,30,90,270,400,550);
    unit[7] = new Needles(3,10,7);
    unit[8] = new Academic("PAS","Arts2",100,8,2,10,50,6,30,90,270,400,550);
    unit[9] = new Academic("HH","Arts2",120,9,1,10,50,8,40,100,300,450,600);
    unit[10] = new DcTim();
    unit[11] = new Academic("RCH","Eng",140,11,0,9,100,10,50,150,450,625,750);
    unit[12] = new Gym("PAC",12,150,0,8);
    unit[13] = new Academic("DWE","Eng",140,13,0,7,100,10,50,150,450,625,750);
    unit[14] = new Academic("CPH","Eng",160,14,0,6,100,12,60,180,500,700,900);
    unit[15] = new Residence("UWP",15,200,0,5);
    unit[16] = new Academic("LHI","Health",180,16,0,4,100,14,70,200,550,750,950);
    unit[17] = new Slc(0,3,17);
    unit[18] = new Academic("BMH","Health",180,18,0,2,100,14,70,200,550,750,950);
    unit[19] = new Academic("OPT","Health",200,19,0,1,100,16,80,220,600,800,1000);
    unit[20] = new Goose();
    unit[21] = new Academic("EV1","Env",220,21,1,0,150,18,90,250,700,875,1050);
    unit[22] = new Needles(2,0,22);
    unit[23] = new Academic("EV2","Env",220,23,3,0,150,18,90,250,700,875,1050);
    unit[24] = new Academic("EV3","Env",240,24,4,0,150,20,100,300,750,925,1100);
    unit[25] = new Residence("V1",25,200,5,0);
    unit[26] = new Academic("PHYS","Sci1",260,26,6,0,150,22,110,330,800,975,1150);
    unit[27] = new Academic("B1","Sci1",260,27,7,0,150,22,110,330,800,975,1150);
    unit[28] = new Gym("CIF",28,150,8,0);
    unit[29] = new Academic("B2","Sci1",280,29,9,0,150,24,120,360,850,1025,1200);
    unit[30] = new GotoTim();
    unit[31] = new Academic("EIT","Sci2",300,31,10,1,200,26,130,390,900,1100,1275);
    unit[32] = new Academic("ESC","Sci2",300,32,10,2,200,26,130,390,900,1100,1275);
    unit[33] = new Slc(10,3,33);
    unit[34] = new Academic("C2","Sci2",320,34,10,4,200,28,150,450,100,1200,1400);
    unit[35] = new Residence("REV",35,200,10,5);;
    unit[36] = new Needles(6,10,36);
    unit[37] = new Academic("MC","Math",350,37,10,9,200,35,175,500,110,1300,1500);
    unit[38] = new Coop();
    unit[39] = new Academic("DC","Math",400,39,10,9,200,50,200,600,1400,1700,2000);
    //connect them into a chain
    unit[0]->setPrev(unit[39]);
    for (int i = 1; i < 39; ++i) {
        unit[i]->setPrev(unit[i-1]);
        unit[i]->setNext(unit[i+1]);
    }
    unit[39]->setNext(unit[0]);
    
    //set all fiels of buildings
    for (int i = 0; i < numOfBuilding; ++i) {
        istringstream ib(line);
        string bname;
        string ownerName;
        int numOfImp;
        ib >> bname >> ownerName >> numOfImp;
        if (ownerName != "BANK") {
            //if owned
            propertySqr *pqs = static_cast<propertySqr*>(unit[i]);
            for (int j = 0; j < numOfPlayer; ++j) {
                //found owner
                if (playerInGame.at(j)->name == ownerName) {
                    pqs->changeOwner(playerInGame.at(j));
                    playerInGame.at(j)->addOwning(pqs);
                }
            }
            if (numOfImp == -1) {
                //if mortaged
                pqs->changeMortagageStatus();
            }else if(numOfImp > 0){
                //if is academic building and have improvements > 0
                Academic *acadsqr = static_cast<Academic*>(pqs);
                for (int x = 0; x < numOfImp; ++x) {
                    acadsqr->addImp(currentPlayer);
                }
            }
        }
    }    
    //finally add all fields to map but not sure which player is te current one
    currentPlayer = playerInGame.at(0);
    indexOfPlayer = 0;
    
    //change cells of map
    for (int i = 0; i < (int)playerInGame.size(); ++i) {
        placePlayer(playerInGame.at(i)->particle, playerInGame.at(i)->position->getX(), playerInGame.at(i)->position->getY());
    }
}


void Map::placePlayer(char c, int posx, int posy){
    int x = posx * width;
    int y = posy * height;
    bool Line1Full = true;
    for (int i = 1; i <= 4; ++i) {
        if (cells[y][x+i] != ' ') {
            x += i;
            Line1Full = false;
        }
    }
    //if Line 1 is full of players
    if (Line1Full){
        y++;//change to next line
        for (int i = 1; i <= 4; ++i) {
            if (cells[y][x+i] != ' ') {
                x += i;
            }
        }
    }
    cells[y][x] = c;

}

void Map::changePlayer(char c, int originX, int originY, int newX, int newY){
    int x1 = originX * width;
    int y1 = originY * height + 4;
    int x2 = newX * width;
    int y2 = newY * height + 4;
    //recover the position player was on
    bool InLine1 = false;
    for (int i = 1; i <= 4; ++i) {
        if (cells[y1][x1+i] == c) {
            x1 += i;
            InLine1 = true;
        }
    }
    //if not in Line 1 for players
    if (!InLine1){
        y1++;//change to next line
        for (int i = 1; i <= 4; ++i) {
            if (cells[y1][x1+i] == c) {
                x1 += i;
            }
        }
    }
    cells[y1][x1] = ' ';

    //change the new player's position
    bool Line1Full = true;
    for (int i = 1; i <= 4; ++i) {
        if (cells[y2][x2+i] != ' ') {
            x2 += i;
            Line1Full = false;
        }
    }
    //if Line 1 is full of players
    if (Line1Full){
        y2++;//change to next line
        for (int i = 1; i <= 4; ++i) {
            if (cells[y2][x2+i] != ' ') {
                x2 += i;
            }
        }
    }
    cells[y2][x2] = c;
}


Map::~Map()
{
    
    for(int i = 0; i < numOfPlayer; i++)
    {
        playerInGame[i]->~Player();
    }
    
    
    
    for(int i = 0; i <= 39; i++)
    {
        delete unit[i];
    }
    
}

// print function operator overloading
ostream &operator<<(std::ostream &out, const Map &mp)
{
    for (int i = 0; i < 67; ++i) {
        for (int j = 0; j < 90; ++j) {
            out << mp.cells[i][j];
        }
        out <<noskipws<< "\n"<< endl;
    }
    out << endl;
    return  out;
}


void Map::rollDice()
{
    int origCoordX = currentPlayer->coordX;
    int origCoordY = currentPlayer->coordY;
	if(currentPlayer->turnInDC == 3)
	{
        cout << "CALLED ROLL DICE" << endl;
	    bool sendPlayerDc = false;
		int numFromRoll; // give a random
		srand((int)time(0));
		int Row1 = 1+rand()%6;
		int Row2 = 1+rand()%6;
		if(Row1 == Row2)
		{
            cout << "rolled doubles" << endl;
		     Row1 = 1+rand()%6;
		     Row2 = 1+rand()%6;
		     if(Row1 == Row2)
		     {
                 cout << "rolled doubles" << endl;
		          Row1 = 1+rand()%6;
		          Row2 = 1+rand()%6;
		          if(Row1 == Row2)
		          {
                      cout << "rolled doubles" << endl;
                      sendPlayerDc = true;
		          }
		     }
		}
		
		numFromRoll = Row1 + Row2;
        cout<< "player rolled " << numFromRoll << endl;
		
		if(!sendPlayerDc)
		{
            cout << "player not in dc" << endl;
		     currentPlayer->locationIndex += numFromRoll;
		     if(currentPlayer->locationIndex >= 40)
		     {
		          currentPlayer->locationIndex -= 40;
		     }
		     currentPlayer->position = unit[currentPlayer->locationIndex];
		     currentPlayer->coordX = currentPlayer->position->getX();
		     currentPlayer->coordY = currentPlayer->position->getY();
		
		     changePlayer(currentPlayer->particle,origCoordX,origCoordY,currentPlayer->coordX,
		              currentPlayer->coordY);
             cout << "Player moved to " << currentPlayer->locationIndex << endl;
		
		     rollCup();
            cout << "finished rollCup" << endl;
		}
		else
		{
		     currentPlayer->turnInDC = 0;
		     currentPlayer->locationIndex = 10;
		     currentPlayer->position = unit[currentPlayer->locationIndex];
		     currentPlayer->coordX = currentPlayer->position->getX();
		     currentPlayer->coordY = currentPlayer->position->getY();
		     cout << "Player " << currentPlayer->name;
		     cout << " just got sent to DC!" << endl;
		}
	}
	
    currentPlayer->notify(unit[currentPlayer->locationIndex]);
    
    numOfCupLeft = 0;
    for(int i = 0; i < numOfPlayer; i++)
    {
    	numOfCupLeft += playerInGame[i]->getCup();
    }
}

void Map::rollCup()
{
     if(numOfCupLeft > 0 && (currentPlayer->locationIndex == 2 ||
                             currentPlayer->locationIndex == 17 ||
                             currentPlayer->locationIndex == 33 ||
                             currentPlayer->locationIndex == 7 ||
                             currentPlayer->locationIndex == 22 ||
                             currentPlayer->locationIndex == 36))
     {
        int randCup; 
		srand((int)time(0));
		randCup = 1+rand()%100;
		if(randCup == 100)
		{
		    currentPlayer->addCup();
		}
     }
}

void Map::rollDice(int r1, int r2)
{//test mode
	int origCoordX = currentPlayer->coordX;
	    int origCoordY = currentPlayer->coordY;
		if(currentPlayer->turnInDC == 3)
		{
	        cout << "CALLED ROLL DICE" << endl;
		    bool sendPlayerDc = false;
			int numFromRoll; // give a random
			int Row1 = r1;
			int Row2 = r2;
			if(Row1 == Row2)
			{
	             cout << "input another 2 rolls please" << endl;
			     cin >> Row1;
			     cin >> Row2;
			     if(Row1 == Row2)
			     {
			    	  cout << "input another 2 rolls please" << endl;
			          cin >> Row1;
			    	  cin >> Row2;
			          if(Row1 == Row2)
			          {
	                      cout << "rolled doubles" << endl;
	                      sendPlayerDc = true;
			          }
			     }
			}
			
			numFromRoll = Row1 + Row2;
	        cout<< "player rolled " << numFromRoll << endl;
			
			if(!sendPlayerDc)
			{
	            cout << "player not in dc" << endl;
			     currentPlayer->locationIndex += numFromRoll;
			     if(currentPlayer->locationIndex >= 40)
			     {
			          currentPlayer->locationIndex -= 40;
			     }
			     currentPlayer->position = unit[currentPlayer->locationIndex];
			     currentPlayer->coordX = currentPlayer->position->getX();
			     currentPlayer->coordY = currentPlayer->position->getY();
			
			     changePlayer(currentPlayer->particle,origCoordX,origCoordY,currentPlayer->coordX,
			              currentPlayer->coordY);
	             cout << "Player moved to " << currentPlayer->locationIndex << endl;
			
			     rollCup();
	            cout << "finished rollCup" << endl;
			}
			else
			{
			     currentPlayer->turnInDC = 0;
			     currentPlayer->locationIndex = 10;
			     currentPlayer->position = unit[currentPlayer->locationIndex];
			     currentPlayer->coordX = currentPlayer->position->getX();
			     currentPlayer->coordY = currentPlayer->position->getY();
			     cout << "Player " << currentPlayer->name;
			     cout << " just got sent to DC!" << endl;
			}
		}
		
	    currentPlayer->notify(unit[currentPlayer->locationIndex]);
	    
	    numOfCupLeft = 0;
	    for(int i = 0; i < numOfPlayer; i++)
	    {
	    	numOfCupLeft += playerInGame[i]->getCup();
	    }
}

void Map::saveHelper(string saveFileName){
    ofstream writeFile;
    //if (writeFile.is_open()) {
    writeFile.open(saveFileName);
    writeFile << numOfPlayer << endl; //number of players
    //cout << "numplayer saved!" << endl;
    //cout << (int)playerInGame.size() << endl;
    //while (playerInGame.at(x)) {
    for (int i = 0; i < (int)playerInGame.size(); ++i) {    //save all players
        //Player* p = playerInGame.at(i);
        cout << "begin save player " << i << endl;
        writeFile << playerInGame.at(i)->name;
        writeFile << " ";
        writeFile <<playerInGame.at(i)->particle;
        writeFile<<" "<<playerInGame.at(i)->getCup()<<" "<<playerInGame.at(i)->getCash()<<" "<<playerInGame.at(i)->locationIndex<<" ";
        if (playerInGame.at(i)->turnInDC < 3 && playerInGame.at(i)->turnInDC >= 0) {
            writeFile << "1 " << playerInGame.at(i)->turnInDC << endl;
        }else{
            writeFile << "0" << endl;
        }
        cout << "player " << i << " " << playerInGame.at(i)->name << " saved!" << endl;
        //x++;
    }
    for (int i = 0; i < numOfBuilding; ++i) {       //save all buildings
        writeFile << unit[i]->name << " ";
        if(propertySqr* tmp = dynamic_cast<propertySqr*>(unit[i])){
            //if(typeid(unit[i])==typeid(propertySqr)){
            //if it might be owned(propertysquare)
            if (tmp->getOwner()!=nullptr) {
                //if owner not null
                writeFile << tmp->getOwner()->name << " " << endl;
                //if it might have improvements(academic)
                if(Academic *aca = dynamic_cast<Academic*>(unit[i])){
                    //if (typeid(unit[i])==typeid(Academic)) {
                    if (aca->mortagaged) {
                        writeFile << "-1 ";
                    }else{
                        writeFile << aca->getImp();
                    }
                }else{
                    writeFile << "0 ";
                }
                writeFile << endl;
            }else{
                //no owner
                writeFile << "BANK 0" << endl;
            }
        }
        else{
            //nonpropertysqyare
            writeFile << unit[i]->name << " ";
            writeFile << "BANK 0" << endl;
        }
    }
    // }
    writeFile.close();
}
void Map::saveGame(string FileName){
    string saveFileName = FileName + ".txt";
    ifstream ifile(saveFileName);
    if(ifile)
    {
        cout << "File already existed, replace?(Y/N)"<<endl;
        string replaceRespond;
        cin >>skipws>> replaceRespond;
        if(replaceRespond == "Y")
        {   // Replace(Delete all content in the file first)
            remove(saveFileName.c_str());
            saveHelper(saveFileName);
            cout << "Game saved and " << saveFileName << " replaced!" << endl;
        }
    }
    else
    {   //save game to a new file
        saveHelper(saveFileName);
        cout << "Game saved and new file " << saveFileName << " created!" << endl;
    }
}

void Map::nextPlayer()
{
    if(this->indexOfPlayer == numOfPlayer - 1){
        indexOfPlayer=0;
    }else{
        this->indexOfPlayer++;
    }
    currentPlayer = this->playerInGame[indexOfPlayer];
    cout<< "Now it's player" << indexOfPlayer + 1 << "'s turn!" << endl;
    
    if(this->playerInGame[indexOfPlayer]->isBroken())
    {
    	cout << this->playerInGame[indexOfPlayer]->name << "is broken!" << endl;
    	nextPlayer();
    }
}

void Map::auction(propertySqr *p)
{
	int currentPlayerRound = this->indexOfPlayer;
	
    int highestBid = 0;
    int bidder = -1;
    for(int i = 0; i < this->numOfPlayer; i++)
    {
        if(bidder == i)
        {
            // bid successfully
        	p->changeOwner(playerInGame[i]);
        	// PAY?
        	this->playerInGame[i]->addOwning(p);
        	//Let player pay
        	this->indexOfPlayer = currentPlayerRound;
        	break;
        }
        
        this->indexOfPlayer = i;
        
        cout << "Current bidding is " << highestBid << "!" << endl;
        cout << "Player " << i << " is now bidding!" << endl;//better to print name
        cout << "Raise the bid? (Y/N)" << endl;
        
        string raiseBid;
        cin >> raiseBid;
        
        
        while(raiseBid != "Y" && raiseBid != "N"){
            cout << "Invalid input, try again. (you may only input Y or N)" << endl;
            cin >> raiseBid;
        }
        
        
        if(raiseBid == "Y")
        {
        	int currentBid;

			bool tryBidAgain = true;
			bool enoughMoney = true;
			bool notGiveUp = true;
			while((!(cin >> currentBid) || currentBid < highestBid 
			                         || !enoughMoney) && tryBidAgain)
			{
				if(cin.fail())
				{
					cout << "Invalid input, please input a number!" << endl;
					cout << "Input Y to try again or anything else to";
					cout << "give up this round" << endl;
					
					string giveUpBid;
					cin >> giveUpBid;
					if(giveUpBid == "Y")
					{
						tryBidAgain = true;
					}
					else
					{
						cout << "Player " << this->indexOfPlayer;
						cout << " just gave up this round of bidding!" << endl;
						tryBidAgain = false;
						notGiveUp = false;
					}
				}
				else if(currentBid > highestBid)
				{
					cout << "You can't offer your current bidding!" << endl;
					cout << "Input Y to try again or anything else to give up this round" << endl;
					enoughMoney = false;
					
					string giveUpBid;
					cin >> giveUpBid;
					if(giveUpBid == "Y")
					{
						tryBidAgain = true;
					}
					else
					{
						cout << "Player " << this->indexOfPlayer;
						cout << " just gave up this round of bidding!" << endl;
						tryBidAgain = false;
						notGiveUp = false;
					}
				}
				else
				{
					cout << "Your bidding price is lower than current highest bidding!" << endl;
					cout << "Input Y to try again or anything else to give up this round" << endl;
				
					string giveUpBid;
					cin >> giveUpBid;
				
					if(giveUpBid == "Y")
					{
						tryBidAgain = true;
					}
					else
					{
						cout << "Player " << this->indexOfPlayer << " just gave up this round of bidding!" << endl;
						tryBidAgain = false;
						notGiveUp = false;
					}
				}
			}
			
			if(notGiveUp)
			{
				highestBid = currentBid;
				bidder = i;
			}
        }
        else if(raiseBid == "N")
        {
        	cout << "Player " << this->indexOfPlayer;
        	cout << " just gave up this round of bidding!" << endl;
        }
        
        if(bidder == -1 && i == this->numOfPlayer - 1)
        {
            p->changeOwner(nullptr);
            cout << "No player put a price"; 
            cout << " so the house is returned to the bank!" << endl;
            this->indexOfPlayer = currentPlayerRound;
        }
            
        if(i == this->numOfPlayer - 1)
        {
            i = -1;
        }
    }
}

void Map::allAsset(){
    for (int i = 0; i < (int)playerInGame.size(); ++i) {
        if (!playerInGame.at(i)->isBroken()) {
            playerInGame.at(i)->asset();
            cout << endl;
        }
    }
}


int Map::getNumPlayer(){
    int n = 0;
    for(auto x : playerInGame){
        if(!x->isBroken())++n;
    }
    return n;
}

string Map::oneLeft(){
    for(auto x : playerInGame){
        if(!x->isBroken())return x->name;
    }
    return "";
}

//trade
void Map::trade(string name, string give, string receive){
    stringstream ss1{give};
    stringstream ss2{receive};
    int lenG= (int)give.length();
    int lenR = (int)receive.length();
    int giveMoney  = 0;
    int receiveMoney = 0;
    
    Player *p = nullptr;
    propertySqr *buildgive = nullptr;
    propertySqr *buildreceive = nullptr;
    
    for(auto x : playerInGame){//find player to trade with
        if(name == x->name){
            p = x;
            break;
        }
    }
    
    if(!p){//not found
        cout<<"Player to trade with does not exist."<<endl;
        return;
    }
    
    ss1>>giveMoney;
    ss2>>receiveMoney;
    
    if(giveMoney){//contain a int
        if((1+giveMoney/10)!=lenG){
            cout<<"Wrong input of give."<<endl;
            return;
        }
    }else{//not contain int, search building
        for(int i = 0; i<numOfBuilding; i++){
            if(give==unit[i]->name){
                buildgive = dynamic_cast<propertySqr *>(unit[i]);
                break;
            }
        }
    }
    
    if(receiveMoney){//contain a int
        if((1+receiveMoney/10)!=lenR){
            cout<<"Wrong input of reveive."<<endl;
            return;
        }
    }else{//not contain int, search building
        for(int i = 0; i<numOfBuilding; i++){
            if(receive==unit[i]->name){
                buildreceive = dynamic_cast<propertySqr *>(unit[i]);
                break;
            }
        }
    }
    
    
}


propertySqr* Map::findProp(string name){
    for(int i = 0; i<40; i++){
        if(name==unit[i]->name){
            if(propertySqr*p = dynamic_cast<propertySqr*>(unit[i])){
                return p;
            }else{
                return nullptr;
            }
        }
    }
    return nullptr;
}
const int DCtim = 10;
Building* Map::getBuilding(int i){
    return  unit[i];
}
