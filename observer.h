//
//  observer.hpp
//  watopoly
//
//  Created by Zhihan Wen on 2016-07-14.
//  Copyright © 2016 Zhihan Wen. All rights reserved.
//

#ifndef observer_hpp
#define observer_hpp

#include <iostream>
#include <memory>
//#include "player.h"

class Player;
class Observer {
public:
    virtual void notify(Player *p) = 0;
    virtual ~Observer() = default;
};

#endif /* observer_h */



