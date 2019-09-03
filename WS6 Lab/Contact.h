//
//  Contacts.h
//  OOP244-WS6
//
//  Created by Irene Park on 2019-07-11.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_





namespace sict{
    const int MAX_CHAR = 20;
    
    
    class Contact{
    private:
        char name[MAX_CHAR];
        long long* phoneNums = nullptr;
        int NoPhoneNums;
        void setEmpty();
 
        
        
    public:
        Contact();
        Contact(const char*, long long*, int);
        
        bool isEmpty() const;
        void display() const;
        
        ~Contact();
        
    };
    
    
    
    
    
}

#endif /* Contact_h */
