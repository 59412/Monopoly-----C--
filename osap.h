#ifndef osap_h
#define osap_h

#include "nonPropertySqr.h"

const int OsapGet = 200;
class Osap : public nonPropertySqr{
public:
    Osap();
    //~Osap()override;
    void notify(Player* p) override;//Give p $200
};

#endif

