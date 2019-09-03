//
//  iAccount.h
//  WS8
//
//  Created by Irene Park on 2019-07-27.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_IACCOUNT_H_
#define SICT_IACCOUNT_H_

#include <iostream>

namespace sict{
    
    class iAccount{
        
    public:
        
        virtual bool credit(double)=0;
        virtual bool debit(double)=0;
        virtual void monthEnd()=0;
        virtual void display(std::ostream&) const =0;
        
        virtual ~iAccount() = 0;
        
    };
    
    iAccount* CreateAccount(const char*, double);

}


#endif /* iAccount_h */
