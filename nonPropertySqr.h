//
//  nonPropertySqr.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef nonPropertySqr_h
#define nonPropertySqr_h

#include "building.h"

class nonPropertySqr : public Building{
public:
    //virtual ~nonPropertySqr()=0;
    virtual void notify(Player* p)=0;
};


#endif /* nonPropertySqr_hpp */
