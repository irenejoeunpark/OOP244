
//  Perishable.cpp
//  MS5
//
//  Jo Eun Park - 147 824 189
//  ipark10@myseneca.ca

#include <iostream>
#include <fstream>

#include "iGood.h"
#include "Perishable.h"

using namespace std;
namespace aid{
    
    Perishable::Perishable() : Good('P'){}
    
    fstream& Perishable::store(fstream& file, bool newLine) const{
        Good::store(file,false);
        file << ',';
        exp.write(file);
        
        if (newLine){
            file << endl;
        }
        return file;
    }
    
    fstream& Perishable::load(fstream& file){
        Good::load(file);
        exp.read(file);
        
        return file;
    }
    
    ostream& Perishable::write(ostream& os, bool linear) const{
        Good::write(os, linear);
        if (Good::isClear() && !Good::isEmpty()){
            if (linear){
                exp.write(os);
            } else {
                os << endl << " Expiry date: ";
                exp.write(os);
            }
        }
        return os;
    }
    
    //read the expiry date and validate
    istream& Perishable::read(istream& is){
        Good::read(is);
        if (!isEmpty()){
            eState.clear();
            cout << " Expiry date (YYYY/MM/DD): ";
            exp.read(is);
            if (exp.errCode() == CIN_FAILED){
                eState.message("Invalid Date Entry");
                is.setstate(ios::failbit);
            } else if(exp.errCode() == YEAR_ERROR) {
                eState.message("Invalid Year in Date Entry");
                is.setstate(ios::failbit);
            } else if(exp.errCode() == MON_ERROR){
                eState.message("Invalid Month in Date Entry");
                is.setstate(ios::failbit);
            }else if(exp.errCode() == DAY_ERROR){
                eState.message("Invalid Day in Date Entry");
                is.setstate(ios::failbit);
            }else if(exp.errCode() == PAST_ERROR){
                eState.message("Invalid Expiry in Date Entry");
                is.setstate(ios::failbit);
            }else {
                eState.clear();
            }
        }
        return is;
    }
    
    const Date& Perishable::expiry() const{
        return exp;
    }

    // creat and set the type of the current object based on the given tag parameter
    iGood* CreateProduct(char tag){
        iGood* type;
        if (tag == 'N' || tag == 'n'){
            type = new Good();
        }else if(tag == 'P' || tag == 'p'){
            type =  new Perishable();
        }else {
            type = nullptr;
        }
    return type;
    }
}

