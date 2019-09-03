//
//  ChequingAccount.hpp
//  WS8
//
//  Created by Irene Park on 2019-07-29.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict{
    
    class ChequingAccount : public Account{
        double tFee;
        double mFee;
    public:
        ChequingAccount(double,double,double);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
}


#endif /* ChequingAccount_h */
