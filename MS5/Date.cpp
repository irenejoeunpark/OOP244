//
//  Date.cpp
//  Milestone1
//  Jo Eun Park - 147 824 189
//  ipark10@myseneca.ca Jo Eun Park 147 824 189
//

#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace aid{

    void Date::set(int y, int m, int d){
        year = y;
        month = m;
        day = d;
        comparator = y*372 + m*31 + d;
    }
    
    void Date::setEmpty(){
        year = 0;
        month = 0;
        day = 0;
        comparator = 0;
        errorState = NO_ERROR;
    }
    
    bool Date::isValid(int y, int m, int d){
        return y>=min_year && y<=max_year && m>=1 && m<=12 && d>=1 && d<=mdays(y,m) && (y*372 + m*31 + d)>=min_date;
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
        setEmpty();
    }
    
    Date::Date(int y, int m, int d){
        if (isValid(y,m,d)){
            this->set(y,m,d);
            this->errorState = NO_ERROR;
            
        }else{
            setEmpty();
        }
    }
    

    bool Date::operator == (const Date& rhs) const{
        return (this->comparator == rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0);
    }
    
    
    bool Date::operator != (const Date& rhs) const{
        return (this->comparator != rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0);
    }
    
    
    bool Date::operator < (const Date& rhs) const{
        return (this->comparator < rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0);
    }
    
    
    bool Date::operator > (const Date& rhs) const{
        return (this->comparator > rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0);
    }
    
    
    bool Date::operator <= (const Date& rhs) const{
        return (this->comparator <= rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator != 0);
    }
    
    
    bool Date::operator >= (const Date& rhs) const{
        return (this->comparator >= rhs.comparator)&&(this->comparator != 0)&&(rhs.comparator)!= 0;
    }
    
    
    int Date::errCode() const{
        return this->errorState;
    }
    
    
    bool Date::bad() const{
        return (errorState != NO_ERROR);
    }
    
    istream& Date::read(istream& istr){
        char s;
        int y,m,d;
        istr >> y >> s >> m >> s >> d;
        int date = y*372 + m*31 + d;
        this->comparator = date;
            if(istr.fail()){
                errorState = CIN_FAILED;
            }else{
            if (isValid(y,m,d)){
                set(y,m,d);
                this->errorState = NO_ERROR;
            } else{
                if (y < min_year || y> max_year){
                    setEmpty();
                    errorState=YEAR_ERROR;
                }else{
                    if(m<1||m>12){
                        setEmpty();
                        errorState=MON_ERROR;
                    }else{
                        if(d<1 || d>31){
                            setEmpty();
                            errorState=DAY_ERROR;
                        }else {
                            if(date<min_date){
                                setEmpty();
                                errorState=PAST_ERROR;
                            } else{
                                this->set(y,m,d);
                            }
                        }
                    }
                }
            }
        }
    return istr;
    }

//output the date with / between each entry
    ostream& Date::write(ostream& ostr) const{
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
    
    ostream& operator << (ostream& o, Date& date){
        return date.write(o);
    }
    
    istream& operator >> (istream& i, Date& date){
        return date.read(i);
    }
}
