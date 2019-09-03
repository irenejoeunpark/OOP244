// Jo Eun Park
// 147 824 189
// ipark10@myseneca.ca
// OOP244 SBB

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
#include "CRA_Account.h"

namespace sict {



	void CRA_Account::set(const char* fName, const char* gName, int SN) {

		if (SN > max_sin || SN < min_sin || strlen(fName) == 0 || strlen(gName) == 0) {
			this->sin = 0;
		}
		else {
			if (strlen(fName) > max_name_length || strlen(gName) > max_name_length) {
				this->sin = 0;
			}
			else {
				int last_digit = SN % 10;
				int eight = (SN / 10) % 10;
				int seven = (SN / 100) % 10;
				int six = (SN / 1000) % 10;
				int five = (SN / 10000) % 10;
				int four = (SN / 100000) % 10;
				int three = (SN / 1000000) % 10;
				int two = (SN / 10000000) % 10;
				int one = (SN / 100000000) % 10;
				

				
				int sum_even = ((eight * 2) % 10) + ((eight * 2 / 10) % 10) + ((six * 2) % 10) + ((six * 2 / 10) % 10) + ((four * 2) % 10) + ((four * 2 / 10) % 10) + ((two * 2) % 10) + ((two * 2 / 10) % 10);
				int sum_odd = one + three + five + seven;

				int total = (sum_even) + sum_odd;
				int nxt_multiple;

				if (total % 10 == 0) {
					nxt_multiple = total;
				}
				else {
					nxt_multiple = total - (total % 10) + 10;

				}
				
				int diff = nxt_multiple - total;

				if (diff == last_digit) {
					
					this->familyName = new char[max_name_length + 1];
					this->givenName = new char[max_name_length + 1];
					this->sin = SN;
					strncpy(this->familyName, fName, max_name_length + 1);
					strncpy(this->givenName, gName, max_name_length + 1);
				}
				else {
					sin = 0;

				}


				
			}
		}
		
	


	}

	bool CRA_Account::isEmpty() const {
		bool isEmpty = false;

		if (sin == 0)
			isEmpty = true;
		
		return isEmpty;
	}

	void CRA_Account::display() const {
		if (isEmpty() == false) {
			cout << "Family Name: " << this->familyName << endl;
			cout << "Given Name : " << this->givenName << endl;
			cout << "CRA Account: " << this->sin << endl;
			for (int i = 0; i < max_yrs; i++) {
				if (this->balance[i] > 2) {
					cout << fixed << setprecision(2) << "Year (" << this->year[i] << ") balance owing: " << this->balance[i] << endl;
				}
				else if (this->balance[i] < -2) {
					cout << fixed << setprecision(2) << "Year (" << this->year[i] << ") refund due: " << (this->balance[i])*(-1) << endl;
				}
				else {
					cout << "Year (" << this->year[i] << ") No balance owing or refund due!" << endl;
				}
					

			}
			

		}
		else {
			cout << "Account object is empty!" << endl;

		}

	}

	void CRA_Account::set(int tYear, double tBalance) {

		if (isEmpty() == false) {
			this->year[nYears] = tYear;
			this->balance[nYears] = tBalance;
			this->nYears++;


		}


	}
}