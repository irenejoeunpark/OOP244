// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
#include <iostream>


// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 

		// TODO: declare private member functions
	private:
		int numerator;
		int denominator;
		int max() const;
		int min() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);

		
		void reduce();
		int gcd() const;
		bool isEmpty() const;
		void display() const;



		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
        Fraction operator*(const Fraction& rhs) const;
        bool operator==(const Fraction& rhs) const;
        bool operator!=(const Fraction& rhs) const;
        Fraction& operator+=(const Fraction& rhs);
        
    };
    
};


#endif
