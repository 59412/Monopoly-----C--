#ifndef slc_h
#define slc_h

#include "nonPropertySqr.h"

class Slc : public nonPropertySqr{
public:
    Slc(int X, int Y, int m);
    //~Slc()override;
    void sendPlayer(Player *p, int steps);
    void notify(Player* p) override;//sent p to random places NOT COMPLETE YET!!!
};

#endif

