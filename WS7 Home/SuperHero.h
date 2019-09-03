//
//  SuperHero.hpp
//  WS7
//
//  Created by Irene Park on 2019-07-23.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H_

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Hero.h"

using namespace std;
namespace sict{
    
    class SuperHero : public Hero{
    
        int sBonus;
        int sDefend;
        
        void setEmpty();
        
    public:
        SuperHero();
        SuperHero(const char*,int, int, int, int);
        int attackStrength() const;
        int defend() const;
 
      
    };
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
    
    
    
    
}



#endif
