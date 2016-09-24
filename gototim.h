#ifndef gototim_h
#define gototim_h

#include "nonPropertySqr.h"

class DcTim;
class GotoTim : public nonPropertySqr{
public:
    GotoTim();
    //~GotoTim()override;
    DcTim* dcTim;
    void notify(Player* p) override; //check if p can be sent to dc and do so
};

#endif

