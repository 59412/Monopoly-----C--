#include "needles.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

Needles::Needles(int X, int Y, int m){
    name = "NEEDLES HALL";
    coordX = X;
    coordY = Y;
    number = m;
    prev = nullptr;
    next = nullptr;
}
//Needles::~Needles(){}
void Needles::notify(Player* p){    
    srand((int)time(0));
    int Row = 1+rand()%18;
    int payment;
    if (Row == 1) {
        payment = -200;
    }else if (Row == 2 || Row == 3){
        payment = -100;
    }else if (Row == 4 || Row == 5 || Row == 6) {
        payment = -50;
    }else if (Row == 7 || Row == 8 || Row == 9 || Row == 10 || Row == 11 || Row == 12) {
        payment = 25;
    }else if (Row == 13 || Row == 14 || Row == 15) {
        payment = 50;
    }else if (Row == 16 || Row == 17) {
        payment = 100;
    }else if (Row == 18) {
        payment = 200;
    }
    
    if (payment < 0) {
        cout << "You lost $" << -payment << endl;
        p->pay(-payment);
    }else{
        cout << "You got $" << payment << endl;
        p->getPaid(payment);
    }
}
