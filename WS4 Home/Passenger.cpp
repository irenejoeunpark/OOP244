
// Jo Eun Park
// 147 824 189
// OOP244 SBB

// TODO: add file header comments here
#include <cstring>
#include <iostream>
using namespace std;
// TODO: add your headers here
#include "Passenger.h"


// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {	
		strncpy(this->pName, "", SIZE - 1);
		strncpy(this->destination, "", SIZE - 1);
		this->year = 0;
		this->month = 0;
		this->day = 0;


	}

    
    // TODO: implement the constructor with 2 parameters here
    
    
    
    Passenger::Passenger(const char *nm, const char *dst) {
        if  (nm != nullptr && strlen(nm) != 0) {
            strncpy(this->pName, nm, SIZE-1);
            year = 2019;
            month = 10;
            day = 1;
        }
        else {
            strncpy(this->pName, "", SIZE-1);
            
        }
        
        if (dst != nullptr && strlen(dst) != 0) {
            strncpy(this->destination, dst, SIZE-1);
            year = 2019;
            month = 10;
            day = 1;
        }
        else {
            strncpy(this->destination, "", SIZE-1);
            
        }
        this->pName[SIZE-1] = '\0';
    }
    
 
        


	Passenger::Passenger(const char *n, const char *d, int y, int m, int date) {

        if(n != nullptr && d != nullptr && y >= 2019 && y <= 2021 && m >=1 && m<=12 && date >=1 && date <=31){
            strncpy(this->pName,n,SIZE-1);
            strncpy(this->destination,d,SIZE-1);
            year = y;
            month = m;
            day = date;
            
        }
        else{
            *this = Passenger();
            
        }
		

	}



 // TODO: implement isEmpty query here
	bool Passenger::isEmpty() const{
		bool result = false;
        
        if(strlen(this->pName)==0 || strlen(this->destination)==0){
            result = true;
        }
        return result;
	}
    
    
 // TODO: implement display query here
	void Passenger::display() const{

		if (isEmpty() == false) {
            if (this->day < 10){
                 cout << this->pName << " - " << this->destination << " on " << this->year << "/" << this->month << "/" << "0" << this->day << endl;
            }
            else{
                cout << this->pName << " - " << this->destination << " on " << this->year << "/" << this->month << "/" << this->day << endl;
                
            }
           
		}
		else {

			cout << "No passenger!" << endl;

		}
	


	}

	const char* Passenger::name() const {
		if (isEmpty() == false) {
			return this->pName;

		}
		else {
			return "";
		}
		 
	}

    bool Passenger::canTravelWith(const Passenger& p) const {

        
        bool result = ((*this).day == p.day) && ((*this).month == p.month) && ((*this).year == p.year);
        
        return result;
        }
    
    


}




 

