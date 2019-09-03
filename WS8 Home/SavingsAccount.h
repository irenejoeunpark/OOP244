//
//  SavingsAccount.hpp
//  WS8
//
//  Created by Irene Park on 2019-07-27.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_SAVINGSACCOUNT_H_
#define SICT_SAVINGSACCOUNT_H_

#include <iostream>
#include"Account.h"

namespace sict {
    class SavingsAccount : public Account{
        double int_rate;
    public:
        SavingsAccount(double,double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}

#endif /* SavingsAccount_h */
