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
            this->name[MAX_CHAR] = '\0';
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
                if(pn[i] >= 11001000000 && pn[i] < 1000000000000 ){
                    this->NoPhoneNums += 1;
                    this->phoneNums[NoPhoneNums-1] = pn[i];
                }
            }
        }
    }
    
    
    bool Contact::isEmpty() const{
        bool result = false;
        if(this->name[0]=='\0' && phoneNums == nullptr && NoPhoneNums == 0)
            result = true;
        return result;
        
    }
    
    
    void Contact::display() const{
        if (isEmpty()){
            cout << "Empty contact!" << endl;
        }else{
            cout << this->name << endl;
            if (this->phoneNums != nullptr){
                int i;
                for (i=0; i<this->NoPhoneNums; i++){
            
                 cout << "(+" << phoneNums[i]/10000000000 << ") " << (phoneNums[i]/10000000) %1000 << " " << (phoneNums[i]%10000000)/10000 << "-" << setfill('0') << setw(4) << (phoneNums[i]%10000000)%10000 << endl;
                }
                
            }
            
        }
    }
    
    
    Contact::~Contact(){
        
        delete [] phoneNums;
        
    }
    
    
    
    
}
