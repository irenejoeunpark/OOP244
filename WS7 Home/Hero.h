//
//  Hero.hpp
//  WS7
//
//  Created by Irene Park on 2019-07-18.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_HERO_H_
#define SICT_HERO_H_

#include <iostream>
#include <cstring>
#include <iomanip>

#define MAX_ROUNDS 100
#define SIZE 41

using namespace std;

namespace sict{
    
    class Hero{
        char hName[SIZE];
        int hHealth;
        int hStrength;
        
        
        
    public:
        
        Hero();
        Hero(const char*, int, int);
        
        void setEmpty();
        
        void operator-=(int attack);
        bool isAlive() const;
        int attackStrength() const;
        
        std::ostream& display(std::ostream& os = std::cout) const;
        
        
        
    };
    
    std::ostream& operator<< (ostream& os, const Hero& hero);
    const Hero& operator* (const Hero& first, const Hero& second);
    
    
}


#include <stdio.h>

#endif
