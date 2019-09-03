//
//  Date.h
//  Milestone1
//  Jo Eun Park 147 824 189
//
//
//

#ifndef AID_DATE_H_
#define AID_DATE_H_

#include <iostream>
#include <iomanip>
using namespace std;

namespace aid{
    
    
    
    
    const int min_year = 2018;
    const int max_year = 2038;
    const int min_date = 751098;
    
    
    
    class Date{
        
#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5
        
        
        
    private:
        int year;
        int month;
        int day;
        int comparator;
        int errorState;
        void errCode(int errorCode);
        int mdays(int year, int month) const;
        void set(int y, int m, int d);
        
        
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
