#ifndef goose_h
#define goose_h

#include "nonPropertySqr.h"

class Goose : public nonPropertySqr{
public:
    Goose();
    //~Goose()override;
    void notify(Player* p) override; //print a msg about goose
};

#endif

