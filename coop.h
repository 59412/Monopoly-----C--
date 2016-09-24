#ifndef coop_h
#define coop_h

#include "nonPropertySqr.h"

const int CoopFee = 150;
class Coop : public nonPropertySqr{
public:
    Coop();
    //~Coop()override;
    void notify(Player* p) override; // let p pay $150
};

#endif

