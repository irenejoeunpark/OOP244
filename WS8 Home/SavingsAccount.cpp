//
//  SavingsAccount.cpp
//  WS8
//
//  Created by Irene Park on 2019-07-27.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include <iostream>
#include "SavingsAccount.h"

using namespace std;
namespace sict{
    
    SavingsAccount::SavingsAccount(double iBalance ,double interest) : Account(iBalance){
        if (interest > 0) {
            int_rate = interest;
        }
        else {
            int_rate = 0;
        }
    }
    
    void SavingsAccount::monthEnd(){
        double mIntRate;
        mIntRate = balance() * int_rate;
        credit(mIntRate);
    }
    
    void SavingsAccount::display(std::ostream& os) const {
        os << "Account type: Savings" << endl;
        os << "Balance: $" << (int)this->balance() << ".00"<< endl;
        os << "Interest Rate (%): " << this->int_rate * 100 << ".00"<<  endl;
    }
}
