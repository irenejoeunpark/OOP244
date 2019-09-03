//
//  Hero.cpp
//  WS7
//
//  Created by Irene Park on 2019-07-18.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Hero.h"
using namespace std;
namespace sict{
    
    void Hero::setEmpty(){
        this->hName[0]='\0';
        this->hHealth = 0;
        this->hStrength = 0;
        
        
    }
    
    Hero::Hero(){
        
        setEmpty();
    }
    
    
    Hero::Hero(const char* name, int health, int strength){
        if (name[0] != '\0' && health > 0 && strength >0){
            strncpy(this->hName, name, SIZE);
            this->hHealth = health;
            this->hStrength = strength;
            
        }else{
            setEmpty();
        }
        
    }
    
    void Hero::operator-=(int attack){
        if (attack > 0){
            this->hHealth -= attack;
            if (this->hHealth <=0)
                this->hHealth =0;
        }else{
             this->hHealth -= 0;
        }
        
    }
    
    bool Hero::isAlive() const{
        bool result = true;
        if (this->hHealth == 0){
            result = false;
        }
        return result;
    }
    
    int Hero::attackStrength() const{
        
        return this->hStrength;
    }
    
    ostream& Hero::display(ostream& os) const{
        if (this->hName[0] == '\0'){
            os << "No Hero";
        }else{
            os << this->hName;
        }
        return os;
    }
    
    
    std::ostream& operator<<(std::ostream& os, const Hero& hero){
        
        return hero.display(os);
        
    }
    
    const Hero& operator*(const Hero& first, const Hero& second){
        Hero copyF = first;
        Hero copyS = second;
        const Hero* winner;
        
        
        winner = nullptr;
        
        int round;
        int i;
        cout << "Ancient Battle! ";
        first.display();
        cout << " vs ";
        second.display();
        cout << " : ";
        
        for (i=0; i<MAX_ROUNDS && copyF.isAlive() && copyS.isAlive(); i++){
            copyF -= copyS.attackStrength();
            copyS -= copyF.attackStrength();
        }
        round = i;
        if(copyF.isAlive()){
            winner = &first;
        }else{
            winner = &second;
        }
        
        cout << "Winner is ";
        winner->display();
        cout << " in " << round << " rounds." << endl;
        return *winner;
    }
    
    
    

}
