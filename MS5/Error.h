//
//  Error.hpp
//  MS2
//  Jo Eun Park - 147 824 189
//  ipark10@myseneca.ca
//  Created by Irene Park on 2019-07-19.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef AID_ERROR_H_
#define AID_ERROR_H_
#include <iostream>
#include <iomanip>
namespace aid{
    class Error{
        char* error;
    public:
        explicit Error(const char* errorMessage = nullptr);
    
        void clear();
        bool isClear() const; // revised to const for isClear() function in Good class
        void message(const char* str);
        const char* message() const;
        
        virtual ~Error();

    };
    std::ostream& operator << (std::ostream&, Error&);
}

#endif
