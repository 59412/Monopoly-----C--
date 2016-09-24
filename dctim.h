#ifndef dctim_h
#define dctim_h

#include "nonPropertySqr.h"

class DcTim : public nonPropertySqr{
public:
    DcTim();
    //~DcTim()override;
    void leaveDC(Player *p, int point);
    void notify(Player* p) override; //not sure what to write
};

#endif

