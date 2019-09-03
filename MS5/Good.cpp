//
//  Good.cpp
//  MS3
//  Jo Eun Park - 147 824 189
//  ipark10@myseneca.ca  
//  Copyright © 2019 Irene Park. All rights reserved.

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Good.h"

using namespace std;
namespace aid{
    
    Good::Good(const char* sku, const char* nm, const char* unit, int qty, bool taxable, double price, int numItem){
        if (sku != nullptr && strlen(sku) != 0 && nm != nullptr && nm[0] != 0 && unit != nullptr && unit[0] != 0)
            set(sku,nm,unit,qty,taxable,price,numItem);
        else
            setEmpty();
    }

    //set the values of current object to the given values
    void Good::set(const char* sku, const char* nm, const char* unit, int qty, bool taxable, double price, int numItem){
        
        strncpy(this->skuGood, sku, strlen(sku));
        this->skuGood[strlen(sku)]='\0';
        name(nm);
        strncpy(this->unitGood, unit, strlen(unit));
        this->unitGood[strlen(unit)]='\0';
        this->qtyOnHand = qty;
        this->isTaxable = taxable;
        this->iPrice = price;
        this->qtyNeed = numItem;
    }
    
    void Good::setEmpty(){
        this->nameGood =nullptr;
        this->skuGood[0] ='\0';
        this->unitGood[0] ='\0';
        this->qtyOnHand = 0;
        this->qtyNeed = 0;
        this->iPrice = 0.0;
        this->isTaxable = false;
    }
 
    void  Good::name(const char* nm){
        if (nm == nullptr){
            delete[] nm;
        }else{
            //set name with the given parameter
            int l = (int)strlen(nm);
            this->nameGood = new char[l+1];
            for (i=0; i<l; i++){
                nameGood[i] = nm[i];
            }
            this->nameGood[l] = '\0';
        }
    }
    
    const char* Good::name() const{
        return nameGood;
    }
    
    const char* Good::sku() const{
        return skuGood;
    }
    
    const char* Good::unit() const{
        return unitGood;
    }
    
    bool Good::taxed() const{
        return isTaxable;
    }
    
    double Good::itemPrice() const{
        return iPrice;
    }
    
    double Good::itemCost() const{
        double cost =0.00;
        if (isTaxable){
            cost = iPrice*(1+tax_rate);
        }else{
            cost = iPrice;
        }
        return cost;
    }
    
    void Good::message(const char* msg){
        eState.Error::message(msg);
    }
    
    bool Good::isClear() const{
        return eState.Error::isClear();
    }
    
    Good::Good(char gType){
        this->typeGood = gType;
        this->setEmpty();
    }
    
    Good::Good(const Good& cp){
        set(cp.skuGood,cp.nameGood,cp.unitGood,cp.qtyOnHand,cp.isTaxable,cp.iPrice,cp.qtyNeed);
    }
    
    Good& Good::operator=(const Good& cp){
        set(cp.skuGood,cp.nameGood,cp.unitGood,cp.qtyOnHand,cp.isTaxable,cp.iPrice,cp.qtyNeed);
        return *this;
    }
    
    Good::~Good(){
        delete [] nameGood;
        nameGood = nullptr;
    }
    
    fstream& Good::store(fstream& file, bool newLine) const{
        file << typeGood << ',' << skuGood << ',' << nameGood << ',' << unitGood << ',' << isTaxable << ',' << iPrice << ',' << qtyOnHand << ',' << qtyNeed;
        if(newLine)
            file << endl;
        return file;
        
    }
    
    fstream& Good::load(fstream& file){
// set temporary object to help to get and set the current object from the file.
        Good temp;
        temp.nameGood = new char[max_name_length+1];
        
        if (file.is_open()){
            char temp_type = this->typeGood;

            file.getline(temp.skuGood, max_sku_length, ',');
            file.getline(temp.nameGood,max_name_length+1,',');
            file.getline(temp.unitGood, max_unit_length, ',');
            file >> temp.isTaxable;
            file.ignore();
            file >> temp.iPrice;
            file.ignore();
            file >> temp.qtyOnHand;
            file.ignore();
            file >> temp.qtyNeed;
            file.ignore();
       
            *this = temp;
            this->typeGood = temp_type;
        }
        return file;
    }
    
    ostream& Good::write(ostream& os, bool linear) const{
        if(!eState.isClear()){
            os << eState.message();
        }else if (!isEmpty()){
            if (linear){
                os << setw(max_sku_length) << left << skuGood << '|';
                os << setw(20) << left << name() << '|';
                os << setw(7) << right << fixed << setprecision(2) << itemCost() << '|';
                os << setw(4) << right << qtyOnHand << '|';
                os << setw(10) << left << unitGood << '|';
                os << setw(4) << right << qtyNeed << '|';
            }else{
                os << " Sku: " << skuGood << endl << " Name (no spaces): " << nameGood << endl << " Price: " << iPrice << endl;
                if (isTaxable){
                    os << " Price after tax: " << itemCost() << endl;
                } else {
                    os << " Price after tax:  N/A" <<  endl;
                }
                os << " Quantity on Hand: " << qtyOnHand << " "  << unitGood << endl << " Quantity needed: " << qtyNeed ;
            }
        }
        return os;
    }
    
    istream& Good::read(istream& is){
        
       
        char* name = new char[max_name_length + 1];
        char tax = '\0';
        int onhand = 0;
        int needed = 0;
        double initialP = 0.0;
        
        is.clear();
        
        cout << " Sku: ";
        is >> skuGood;
        cout << " Name (no spaces): ";
        is >> name;
        this->name(name);
        cout << " Unit: ";
        is >> unitGood;
        cout << " Taxed? (y/n): ";
        
        is >> tax;
        
        if (tax == 'y' || tax == 'Y'){
            isTaxable = true;
        }else if(tax =='n' || tax == 'N'){
            isTaxable = false;
        }else{
            eState.message("Only (Y)es or (N)o are acceptable");
            is.istream::setstate(ios::failbit);
        }
        
    
        if (!is.fail()) {
            cout << " Price: ";
            is >> initialP;
            
            if (is.fail()){
                eState.message("Invalid Price Entry");
                is.istream::setstate(ios::failbit);
            } else {
                this->iPrice = initialP;
            }
        }
        
        if (!is.fail()){
            cout << " Quantity on hand: ";
            is >> onhand;
            if (is.fail()){
                eState.message("Invalid Quantity Entry");
                is.istream::setstate(ios::failbit);
            } else {
                quantity(onhand);
            }
        }
        
        if (!is.fail()){
            cout << " Quantity needed: ";
            is >> needed;
            cin.ignore();
            
            if (is.fail()) {
                eState.message("Invalid Quantity Needed Entry");
                is.istream::setstate(ios::failbit);
            } else {
                this->qtyNeed = needed;
                eState.clear();
            }
        }
        return is;
    }
    
    
    bool Good::operator==(const char* sku) const{
        bool result=true;
        int i;
        int k=0;
        for (i=0;i<(int)strlen(sku);i++){
            if(this->skuGood[i] != sku[i]){
                k++;
            }
        }
        if (k>0)
            result=false;
        return result;
    }
    
    double Good::total_cost() const{
        double total=0;
        total = iPrice * (double)qtyOnHand * (1+tax_rate);
        return total;
    }
    
    void Good::quantity(int q){
        this->qtyOnHand = q;
    }
    
    bool Good::isEmpty() const{
        return (skuGood[0] == '\0' && unitGood[0] == '\0' && nameGood == nullptr && !isTaxable && iPrice == 0 && qtyNeed == 0 && qtyOnHand == 0);
    }
    
    int Good::qtyNeeded() const{
        return this->qtyNeed;
    }
    
    int Good::quantity() const{
        return this->qtyOnHand;
    }
    
    bool Good::operator>(const char* sku) const{
        return strncmp(this->skuGood, sku, max_sku_length)>0;
    }
    
    bool Good::operator>(const iGood& nm) const{
        return strncmp(this->nameGood, nm.name() , max_name_length)>0;
    }
    
    int Good::operator+=(int add){
        if(add>0)
            this->qtyOnHand += add;
        return this->qtyOnHand;
    }
    
    //helper functions
    //helper operator for output
    ostream& operator<<(ostream& os, const iGood& good){
        good.write(os,true);
        return os;
    }
    //helper operator for inputs
    istream& operator>>(istream& is,iGood& good){
        good.read(is);
        return is;
    }
    
    double operator+=(double& add, const iGood& good){
        return add + good.total_cost();
    }
}
