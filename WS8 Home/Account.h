//
//  Account.hpp
//  WS8
//
//  Created by Irene Park on 2019-07-27.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_ACCOUNT_H_
#define SICT_ACCOUNT_H_

#include <iostream>
#include "iAccount.h"

namespace sict {
    
    class Account : public iAccount{
        double cBalance;
        
    public:
        Account(double);
        bool credit(double);
        bool debit(double);
        
    protected:
        double balance() const;
        
    };
}

#endif /* Account_h */
