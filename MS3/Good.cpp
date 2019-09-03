//
//  Good.cpp
//  MS3
//
//  Created by Irene Park on 2019-07-30.
//  Copyright © 2019 Irene Park. All rights reserved.
//

#include <iostream>
#include <fstream> // to use fstream functions
#include <cstring>

#include "Good.h"

using namespace std;
namespace aid{


    void Good::set(const char* sku, const char* nm, const char* unit, int qty, bool taxable, double price, int numItem){
        
        strncpy(this->skuGood, sku, max_sku_length);
        name(nm);
        strncpy(this->unitGood, unit, max_unit_length);
        this->qtyOnHand = qty;
        this->isTaxable = taxable;
        this->iPrice = price;
        this->qtyNeed = numItem;
    }
    
    void Good::setEmpty(){
        this->nameGood[0] ='\0';
        this->skuGood[0] ='\0';
        this->unitGood[0] ='\0';
        this->qtyOnHand = 0;
        this->qtyNeed = 0;
        this->iPrice = 0;
        this->isTaxable = false;
    }
 
    
    void  Good::name(const char* nm){
        if (nm == nullptr){
            delete[] nm;
        }else{
            int l = (int)strlen(nm);
            this->nameGood = new char[l];
            strncpy(this->nameGood,nm,l);
            this->nameGood[strlen(nm)] = '\0';
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
        bool result = false;
        result = eState.Error::isClear();
        return result;
    }
    
    Good::Good(char gType){
        this->typeGood = gType;
        this->setEmpty();
    }
    
    Good::Good(const char* sku, const char* nm, const char* unit, int qty, bool taxable, double price, int numItem){
        
        set(sku,nm,unit,qty,taxable,price,numItem);
    
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
    }
    
    std::fstream& Good::store(std::fstream& file, bool newLine) const{
        file << typeGood << ',' << skuGood << ',' << nameGood << ',' << unitGood << ',' << isTaxable << ',' << iPrice << ',' << qtyOnHand << ',' << qtyNeed;
        if(newLine)
            file << endl;
        return file;
        
    }
    
    std::fstream& Good::load(std::fstream& file){
        Good temp;
        temp.nameGood = new char[max_name_length+1];
        if (file.is_open()){
            file << temp.typeGood << ',' << temp.skuGood << ',' << temp.nameGood << ',' << temp.unitGood << ',' << temp.isTaxable << ',' << temp.iPrice << ',' << temp.qtyOnHand << ',' << temp.qtyNeed;
            
            *this = temp;
        }
        return file;
    }
    
    std::ostream& Good::write(std::ostream& os, bool linear) const{
        if (linear){
            os << setw(max_sku_length) << left << skuGood << '|' << setw(20) << left << nameGood << '|' << setw(7) << right << fixed << setprecision(2) << itemCost() << '|' << setw(4) << right << qtyOnHand << '|' << setw(10) << left << unitGood << '|' << setw(4) << right << qtyNeed << '|';
        }else{
            os << "Sku: " << skuGood << "|" << endl << "Name: " << nameGood << "|" << endl << "Price: " << iPrice << "|" << endl;
            if (isTaxable){
                os << "Price after tax: " << itemCost() << "|" << endl;
            } else {
                os << "N/A" << "|" << endl;
            }
            os << "Quantity On hand: " << qtyOnHand << "|" << endl << "Quantity needeed: " << qtyNeed << "|" << endl;
        }
        return os;
    }
    
    std::istream& Good::read(std::istream& is){
        
        char sku[max_sku_length + 1];
        char* name = new char[max_name_length + 1];
        char unit[max_unit_length + 1];
        char tax;
        bool taxable = false;
        int onhand = 0;
        int needed = 0;
        double initialP = 0.0;
        
        cout << " Sku: ";
        is >> sku;
        cout << " Name (no spaces): ";
        is >> name;
        cout << " Unit: ";
        is >> unit;
        cout << " Taxed? (y/n): ";
        
        is >> tax;
        
        if (tax == 'y' || tax == 'Y'){
            taxable = true;
        }else if(tax =='n' || tax == 'N'){
            taxable = false;
        }else{
            eState.message("Only (Y)es or (N)o are acceptable");
            is.std::istream::setstate(std::ios::failbit);
        }
        
        
        if (!is.fail()) {
            cout << " Price: ";
            is >> initialP;
            
            if (is.fail()){
                eState.message("Invalid Price Entry");
            }
        }
        
        if (!is.fail()){
            cout << " Quantity on hand: ";
            is >> onhand;
            if (is.fail()){
                eState.message("Invalid Quantity Entry");
            }
        }
        
        if (!is.fail()){
            cout << " Quantity needed: ";
            is >> needed;
            if (is.fail()) {
                eState.message("Invalid Quantity Needed Entry");
            }
        }
        
        if (!is.fail()) {
            Good temp = Good(sku,name,unit,onhand,taxable,initialP,needed);
            *this = temp;
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
        bool result = false;
        if (typeGood == 'N')
            result = true;
        return result;
    }
    
    int Good::qtyNeeded() const{
        return this->qtyNeed;
    }
    
    int Good::quantity() const{
        return this->qtyOnHand;
    }
    
    bool Good::operator>(const char* sku) const{
        bool result = false;
        if (strncmp(this->skuGood, sku, max_sku_length)>0)
            result = true;
        return result;
    }
    
    bool Good::operator>(const Good& nm) const{
        bool result = false;
        if (strncmp(this->nameGood, nm.nameGood , max_name_length)>0)
            result = true;
        return result;
    }
    
    int Good::operator+=(int add){
        if(add>0)
            this->qtyOnHand += add;
        return this->qtyOnHand;
    }
    
    std::ostream& operator<<(std::ostream& os, const Good& good){
        good.write(os,true);
        return os;
    }
    
    std::istream& operator>>(std::istream& is,Good& good){
        good.read(is);
        return is;
    }
    
    double operator+=(double& add, const Good& good){
        return add + good.total_cost();
    }
    
}
