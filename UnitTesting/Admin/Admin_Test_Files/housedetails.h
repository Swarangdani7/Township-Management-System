#ifndef HOUSEDETAILS_H
#define HOUSEDETAILS_H

#include<iostream>
#include<string>
#include"validations.h"

using namespace std;

class HouseDetails
{
	public:
		HouseDetails()=default;
		
		void setHouseId(string);
		string getHouseId();
		void setHouseType(string);
		string getHouseType();
		
	private:
		string houseId="\0";
		string houseType="\0";
};
#endif
