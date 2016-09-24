#include "tuition.h"
#include "academic.h"
#include "player.h"
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

Tuition::Tuition(){
    name = "TUITION";
    coordX = 6;
    coordY = 10;
    number = 4;
    prev = nullptr;
    next = nullptr;
}
//Tuition::~Tuition(){}
void Tuition::notify(Player* p){
    int choice;
    cout << "You can choose from:" << endl;
    cout << "1.Paying $300 tuition." << endl;
    cout << "2.Paying 10% of your total worth." << endl;
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cin.clear();
        cin.ignore();
        cout << "Error! Please enter your choice again. (1/2)" << endl;
        cin >> choice;
    }
    if (choice == 1) {
        p->pay(TuitPay);
        cout << "You paid $" << TuitPay << " tuition." << endl;
    }else if(choice == 2){
        int payment = p->getCash();
        for (int i = 0; i < (int)p->ownings.size(); ++i) {
            if (typeid(p->ownings.at(i).front()) == typeid(Academic)) {
                for (int j = 0; i < (int)p->ownings.at(i).size(); ++j) {
                    ///////not sure if can run correctly
                    Academic *a = static_cast<Academic*>(p->ownings.at(i).at(j));
                    payment += a->getPrice();
                    payment += a->getImp() * a->getImpCost();
                }
            }else{
                for (int j = 0; i < (int)p->ownings.at(i).size(); ++j) {
                    payment += p->ownings.at(i).at(j)->getPrice();
                }
            }
        }
        p->pay(payment * TuitPortion);
        cout << "You paid $" << payment * TuitPortion << " tuition." << endl;
    }
}

