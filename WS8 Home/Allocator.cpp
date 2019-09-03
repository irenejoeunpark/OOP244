//
//  Allocator.cpp
//  WS8
//
//  Created by Irene Park on 2019-07-27.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;

namespace sict{

    const double intRate = 0.05;
    const double tRate = 0.50;
    const double mRate = 2.00;
    
    // Receives address of C string indicates type of account
    // initial character of the string is S -> saving account
    // string identifies other than 'S' -> nullptr
    
    iAccount* CreateAccount(const char* accType, double initialBal){
        iAccount* type;
        if (accType[0] == 'S'){
            type = new SavingsAccount(initialBal, intRate);
        }else{
            type = new ChequingAccount(initialBal, tRate, mRate);
        }
        return type;
    }

}
