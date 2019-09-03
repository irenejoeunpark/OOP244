//
//  Date.cpp
//  Milestone1
//
//  Jo Eun Park 147 824 189
//

#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace aid{
    
    void Date::set(int y, int m, int d){
        this->year = y;
        this->month = m;
        this->day = d;
        
        
    }
    
    void Date::errCode(int errorCode){
        this->errorState = errorCode;
        
    }
    
    
    int Date::mdays(int year, int mon) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
    Date::Date(){
        this->year=0;
        this->month=0;
        this->day=0;
        this->comparator=0;
        this->errorState=NO_ERROR;
        
    }
    
    Date::Date(int y, int m, int d){
        int date = y*372 + m*31 + d;
        if (y>=min_year && y<=max_year && m>=1 && m<=12 && d>=1 && d<=mdays(y,m) && date>=min_date){
            this->set(y,m,d);
            
            this->comparator = date;
            this->errorState = NO_ERROR;
            
        }else{
            this->set(0,0,0);
            this->comparator =0;
        }

       
    }
    
    

    
    bool Date::operator == (const Date& rhs) const{
        bool result = false;
        if ((this->comparator == rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0))
            result = true;
        return result;
    }
    
    
    bool Date::operator != (const Date& rhs) const{
        bool result = false;
        if ((this->comparator != rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0))
            result = true;
        return result;
        
    }
    
    
    bool Date::operator < (const Date& rhs) const{
        bool result = false;
        if ((this->comparator < rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0))
            result = true;
        return result;
    
    }
    
    
    bool Date::operator > (const Date& rhs) const{
        bool result = false;
        if ((this->comparator > rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0))
            result = true;
        return result;
    }
    
    
    bool Date::operator <= (const Date& rhs) const{
        bool result = false;
        if ((this->comparator <= rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0))
            result = true;
        return result;
        
    }
    
    
    bool Date::operator >= (const Date& rhs) const{
        bool result = false;
        if ((this->comparator >= rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0))
            result = true;
        return result;
    }
    
    
    int Date::errCode() const{
        
        return this->errorState;
        
    }
    
    
    bool Date::bad() const{
        bool result = (errorState != NO_ERROR);
        return result;
    }
    
    
    std::istream& Date::read(std::istream& istr){
     
        int date;
        char s;
        
        istr >> year >> s >> month >> s >> day ;
        
        date = year*372 + month*31 + day;
        this->comparator = date;
        
        if(istr.fail()==true){
            errorState = CIN_FAILED;
        
        }else{
         
            if ((year >= min_year && year <= max_year)&&(month>=1 && month<=12)&&(day>=1 && day<=mdays(year,month))&&(date >= min_date)){
                this->errorState = NO_ERROR;
                

            } else{
                if (year < min_year || year> max_year){

                    errorState=YEAR_ERROR;
                    this->set(0,0,0);
                    this->comparator = 0;
                    
                  
                }else if((year >= min_year && year <= max_year)&&(month<1||month>12)){
                    errorState=MON_ERROR;
                    this->set(0,0,0);
                    this->comparator = 0;
                    
                   }else if((year>= min_year && year<= max_year)&&(month>=1 && month<=12)&&(day<1 || day>31)){
                    errorState=DAY_ERROR;
                    this->set(0,0,0);
                    this->comparator = 0;
            
                }else if(date<min_date){
               
                    errorState=PAST_ERROR;
                    this->set(0,0,0);
                    this->comparator = 0;
        
                }else{
                    this->set(year, month, day);
                    
                }
            }
        }
        
        return istr;
    }
                
                
            
        
            

    
    
    std::ostream& Date::write(std::ostream& ostr) const{
        char s = '/';
        if ((month <10)&&(day<10)){
             ostr << year << s << '0' << month << s << '0' << day;
        }else if((month >=10)&&(day <10)){
            ostr << year << s << month << s << '0' << day;
        }else if ((month <10)&&(day>=10)){
            ostr << year << s << '0' << month << s << day;
        }else{
            ostr << year << s << month << s << day;
        }
        return ostr;
    }
    
    std::ostream& operator << (std::ostream& o, Date& date){
        date.write(o);
        return o;
        
        
    }
    
    std::istream& operator >> (std::istream& i, Date& date){
        date.read(i);
        return i;
        
        
    }
    
    
    
    
    
    
    
}
