//
//  Account.cpp
//  WS8
//
//  Created by Irene Park on 2019-07-27.
//  Copyright © 2019 Irene Park. All rights reserved.
//
#include <iostream>
#include "Account.h"

using namespace std;
namespace sict{
    
    Account::Account(double iBalance){
        if (iBalance < 0){
            this->cBalance=0;
        }else{
            this->cBalance=iBalance;
        }
   
    }
    
    bool Account::credit(double cr){
        bool result = false;
        if (cr>0){
            this->cBalance += cr;
            result = true;
        }
        return result;
    }
    
    bool Account::debit(double db){
        bool result = false;
        if (db>0){
            this->cBalance -= db;
            result = true;
        }
        return result;
        
    }
    
    double Account::balance() const {
        return this->cBalance;
    }
    
    iAccount::~iAccount(){
        
    }
    
    
}
