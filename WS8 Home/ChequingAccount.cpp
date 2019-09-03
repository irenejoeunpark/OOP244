//
//  ChequingAccount.cpp
//  WS8
//
//  Created by Irene Park on 2019-07-29.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "ChequingAccount.h"


using namespace std;
namespace sict{
    
    ChequingAccount::ChequingAccount(double init, double transactionFee, double monthEndFee) : Account(init)
    {
        if (transactionFee > 0) {
            this->tFee = transactionFee;
        }
        else {
            this->tFee = 0;
        }
        if (monthEndFee > 0) {
            this->mFee = monthEndFee;
        }
        else {
            this->mFee = 0;
        }
    }
    
    bool ChequingAccount::credit(double bal){
        Account::debit(this->tFee);
        return Account::credit(bal);
    }
    
    bool ChequingAccount::debit(double bal){
        return Account::debit(bal + this->tFee);
    }
    
    void ChequingAccount::monthEnd(){
        Account::debit(mFee + tFee);
    }
    
    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << endl;
        os << "Balance: $" << (int)ceil(this->balance()) << ".00"<< endl;
        os << "Per Transaction Fee: " << this->tFee <<"0"<<  endl;
        os << "Monthly Fee: " << this->mFee << ".00"<< endl;
    }
}

