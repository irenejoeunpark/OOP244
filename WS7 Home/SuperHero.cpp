//
//  SuperHero.cpp
//  WS7
//
//  Created by Irene Park on 2019-07-23.
//  Copyright © 2019 Irene Park. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <iomanip>

#include "SuperHero.h"
#include "Hero.h"
using namespace std;

namespace sict{
    
    
    void SuperHero::setEmpty(){
        Hero::setEmpty();
        
        this->sBonus = 0;
        this->sDefend = 0;
        
    }
    
    SuperHero::SuperHero() : Hero(){
        setEmpty();
        
    }
    
    SuperHero::SuperHero(const char* name,int health, int attack, int bonus, int defend) : Hero(name, health, attack){
        
        if (bonus > 0 && defend >0){
            this->sBonus = bonus;
            this->sDefend = defend;
            
        }else{
            setEmpty();
        }
        
        
    }
    
    int SuperHero::attackStrength() const{
        
        return Hero::attackStrength() + sBonus;
    }
    
    int SuperHero::defend() const{
        
        return sDefend;
        
    }
    

    
    
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        
        SuperHero copyF = first;
        SuperHero copyS = second;
        const SuperHero* winner;
        
        
        winner = nullptr;
        
        int round;
        int i;
        
        cout << "Super Fight! ";
        first.Hero::display();
        cout << " vs ";
        second.Hero::display();
       
        
        
        for (i=0; i<MAX_ROUNDS && copyF.isAlive() && copyS.isAlive(); i++){
            copyF -= copyS.attackStrength() - copyF.defend();
            copyS -= copyF.attackStrength() - copyS.defend();
        }
        round = i;
        if(copyF.isAlive()){
            winner = &first;
        }else{
            winner = &second;
        }
        
        
        cout << " : Winner is ";
        winner->Hero::display();
        cout << " in " << round << " rounds." << endl;

        return *winner;
    }
    
    
}
