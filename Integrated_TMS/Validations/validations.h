#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include<iostream>
#include<string>
#include<regex>
#include<fstream>

using namespace std;

class Validations
{
	public:
		Validations()=default;
		bool isValidVisitor(const string& );
		bool validate_phone(long);
		bool validate_mail(const string&);
		bool validate_name(const string&);
		bool validate_date(int,int,int);
		bool validate_houseType(const string&);
		bool validate_houseNum(const string&);
		bool validate_pan(const string&);
		bool checkPan(const string&,ifstream&);
		bool validate_tenantHouseId(string);
		bool validate_ownerHouseId(string );
		bool validate_houseId(string);
};
#endif
