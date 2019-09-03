//
//  Error.hpp
//  MS2
//
//  Created by Irene Park on 2019-07-19.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef AID_ERROR_H_
#define AID_ERROR_H_

#include <iostream>
#include <iomanip>
using namespace std;

namespace aid{
    
    
    class Error{
        
        char* error;
        
        
    public:
        explicit Error(const char* errorMessage = nullptr);
        ~Error();
    
        void clear();
        bool isClear();
        void message(const char* str);
        const char* message() const;
        
        

    };
    std::ostream& operator << (std::ostream&, Error&);

    
    
    
    
    
}




#endif
