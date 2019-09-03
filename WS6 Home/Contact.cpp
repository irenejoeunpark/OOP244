//
//  Contact.cpp
//  OOP244-WS6
//
//  Created by Irene Park on 2019-07-11.
//  Copyright © 2019 Irene Park. All rights reserved.
//


#include "Contact.h"
#include <iostream>
#include <cstring>
#include <iomanip>



using namespace std;
namespace sict{
    
    
    bool Contact::isValid(const long long pn){
        bool result = false;
        if((pn>=11001000000 && pn<=99999999999)||(pn>=101001000000 && pn<=999999999999))
            result = true;
       
        return result;
    }
    
    void Contact::setEmpty(){
        this->name[0] = '\0';
        this->phoneNums = nullptr;
        this->NoPhoneNums = 0;
        
    }
    
    Contact::Contact(){
        
        setEmpty();
        
    }
    
    
    Contact::Contact(const char* nm, long long* pn, int nPn){
        
       
        if (!(nm == nullptr || nm[0] == '\0')){
            strncpy(this->name, nm, MAX_CHAR);
            this->name[20] = '\0';
        }else{
            setEmpty();
        }
        
        int i;
        
        if( pn == nullptr || nPn == 0){
            this->phoneNums = nullptr;
            this->NoPhoneNums = 0;
            
        }else{
            this->phoneNums = new long long [nPn];
            this->NoPhoneNums = 0;
            for (i =0; i<nPn; i++){
                if(isValid(pn[i])){
                    this->NoPhoneNums += 1;
                    this->phoneNums[NoPhoneNums-1] = pn[i];
                }
            }
        }
    }
    
    
    bool Contact::isEmpty() const{
        bool result = false;
        if(this->name[0]=='\0')
            result = true;
        return result;
        
    }
    
    
    void Contact::display() const{
        if (isEmpty()){
            cout << "Empty contact!" << endl;
        }else{
            if (this->phoneNums != nullptr){
                cout << this->name << endl;
                int i;
                for (i=0; i<NoPhoneNums; i++){
            
                 cout << "(+" << phoneNums[i]/10000000000 << ") " << (phoneNums[i]/10000000) %1000 << " " << (phoneNums[i]%10000000)/10000 << "-" << setfill('0') << setw(4) << (phoneNums[i]%10000000)%10000 << endl;
                }
                
            }else{
                cout << this->name << endl;
            }
            
        }
    }
    
    
    Contact::~Contact(){
        
        if (phoneNums != nullptr){
            delete [] phoneNums;
            phoneNums = nullptr;
        }
        
        
    }
    
    
    
    Contact::Contact(const Contact& src){
        *this = src;
    }
    
    Contact& Contact::operator=(const Contact& src){
        if (this!= &src){
            strncpy(this->name, src.name, MAX_CHAR);
            this->name[MAX_CHAR] = '\0';
            NoPhoneNums = src.NoPhoneNums;
            delete [] phoneNums;
            phoneNums = new long long [NoPhoneNums];
            int i;
            for (i=0; i<NoPhoneNums; i++){
                this->phoneNums[i] = src.phoneNums[i];
            }
            
            
        }
        
        return *this;
    }
    
    Contact& Contact::operator+=(const long long pn){
        int i;
        if(isValid(pn)){
            NoPhoneNums += 1;
            long long* newPn;
            newPn = new long long [NoPhoneNums];
            for (i=0; i<NoPhoneNums-1; i++){
                newPn[i] = phoneNums[i];
            }
            newPn[NoPhoneNums-1]=pn;
            delete [] phoneNums;
            phoneNums = newPn;
        }
        return *this;
    }
    
    
    
}
