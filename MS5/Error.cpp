//
//  Error.cpp
//  MS2
//  Jo Eun Park - 147 824 189
//  ipark10@myseneca.ca
//  Created by Irene Park on 2019-07-19.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Error.h"

using namespace std;

namespace aid{
    Error::Error(const char* errorMessage ){
        if (errorMessage == nullptr || strlen(errorMessage) == 0){
            error = nullptr;
        }else{
            int l = (int)strlen(errorMessage);
            this->error = new char[l+1];
            for (int i=0; i<l; i++){
                this->error[i] = errorMessage[i];
            }
            this->error[l] = '\0';
        }
    }
    
    Error::~Error(){
        clear();
    }
    
    void Error::clear(){
        delete [] error;
        error = nullptr;
    }
    
    bool Error::isClear() const{
        return error == nullptr || strlen(error) == 0;
    }
    
    void Error::message(const char* str){
        clear();
        int l = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            l++;
        }
        error = new char[l + 1];
        strncpy(error, str, l);
        error[l] = '\0';
    }
    
    const char* Error::message() const{
        return error;
    }
    

    ostream& operator << (ostream& os, Error& e){
        if (!e.isClear())
            os << e.message();
        return os;
    }
    
    
    
    
    
    
    
    
    
    
    
    
}
