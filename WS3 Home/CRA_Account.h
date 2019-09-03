// Jo Eun Park
// 147 824 189
// ipark10@myseneca.ca
// OOP244 SBB


#pragma once
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;




	class CRA_Account {
		public:
			void set(const char* familyName, const char* givenName, int sin);
			bool isEmpty() const;
			void display() const;
			void set(int year, double balance);

		private:
			char * familyName;
			char * givenName;
			int sin;
			int year[max_yrs];
			double balance[max_yrs];
			int nYears = 0;

	};


}






#endif