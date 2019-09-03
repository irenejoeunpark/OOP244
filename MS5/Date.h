//
//  Date.h
//  Milestone1
//  Jo Eun Park - 147 824 189
//  ipark10@myseneca.ca
//

#ifndef AID_DATE_H_
#define AID_DATE_H_

#include <iostream>
#include <iomanip>

namespace aid{
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int DAY_ERROR = 2;
    const int MON_ERROR = 3;
    const int YEAR_ERROR = 4;
    const int PAST_ERROR = 5;
    
    const int min_year = 2018;
    const int max_year = 2038;
    const int min_date = 751098;
    
    class Date{
        int year;
        int month;
        int day;
        int comparator;
        int errorState;
        void errCode(int errorCode);
        int mdays(int year, int month) const;
        
        //private member functions to help constructor and other functions
        void set(int y, int m, int d);
        void setEmpty();
        bool isValid(int y, int m, int d);
        
    public:
        Date();
        Date(int, int, int);
        bool operator == (const Date& rhs) const;
        bool operator != (const Date& rhs) const;
        bool operator < (const Date& rhs) const;
        bool operator > (const Date& rhs) const;
        bool operator <= (const Date& rhs) const;
        bool operator >= (const Date& rhs) const;
        int errCode() const;
        bool bad() const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
 
    };
    std::ostream& operator << (std::ostream&, Date&);
    std::istream& operator >> (std::istream&, Date&);

}




#endif
