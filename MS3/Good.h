//
//  Good.hpp
//  MS3
//
//  Created by Irene Park on 2019-07-30.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#ifndef AID_GOOD_H
#define AID_GOOD_H

#include "Error.h"

namespace aid{
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax_rate = 0.13;
    
    class Good{
        char typeGood;
        char skuGood[max_sku_length+1];
        char unitGood[max_unit_length+1];
        char* nameGood;
        int qtyOnHand;
        int qtyNeed;
        double iPrice;
        bool isTaxable;
        Error eState;
        
        int i;

        
    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
        
     
        
    public:
        Good(char gType ='N');
        Good(const char*, const char*, const char*, int qty=0, bool taxable=true, double proce=0, int numItem=0);
        Good(const Good& cp);
        Good& operator=(const Good& cp);
        virtual ~Good();
        
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const Good&) const;
        int operator+=(int);
        
        void set(const char*, const char*, const char*, int, bool, double, int);
        void setEmpty();

        
    };
    
    std::ostream& operator<<(std::ostream&, const Good&);
    std::istream& operator>>(std::istream&,Good&);
    double operator+=(double&, const Good&);
    
    
    
    
    
    
    
}


#endif
