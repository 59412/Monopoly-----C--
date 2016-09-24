#ifndef needles_h
#define needles_h

#include "nonPropertySqr.h"

class Needles : public nonPropertySqr{
public:
    Needles(int X, int Y, int m);
    //~Needles()override;
    void notify(Player* p) override;//Make p get or lose money by rolling 2 dices
};

#endif
