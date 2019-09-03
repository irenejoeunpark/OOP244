//
//  Error.cpp
//  MS2
//
//  Created by Irene Park on 2019-07-19.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include "Error.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace aid{
    
    
    Error::Error(const char* errorMessage ){
        if (errorMessage == nullptr || strlen(errorMessage) == 0){
            error = nullptr;
        }else{
            long length = strlen(errorMessage) + 1;
            
            error = new char [length];
            strncpy(error, errorMessage, length);
            
            
        }
        
    }
    
    
    Error::~Error(){
        
        clear();
        
        
    }
    
    void Error::clear(){
        
        delete [] error;
        error = nullptr;
        
    }
    
    
    bool Error::isClear(){
        
        bool result = false;
        if (error == nullptr || strlen(error) == 0){
            result = true;
        }
        return result;
        
    }
    
    void Error::message(const char* str){
        
        clear();
        long length = strlen(str) + 1;
        
        error = new char [length];
        strncpy(error, str, length);
        
        
        
    }
    
    const char* Error::message() const{
        return error;
    }
    
    
    std::ostream& operator << (std::ostream& os, Error& e){
        if (!e.isClear())
            os << e.message();
        return os;
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
