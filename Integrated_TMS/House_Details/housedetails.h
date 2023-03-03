#ifndef HOUSEDETAILS_H
#define HOUSEDETAILS_H

#include<iostream>
#include<string>
#include"../Validations/validations.h"

#define OWNER_ADD_HOUSE 1
#define OWNER_UPDATE_HOUSE 2
#define OWNER_DELETE_HOUSE 3

using namespace std;

class HouseDetails
{
	public:
		HouseDetails()=default;
		
		void setHouseId(string);
		string getHouseId();
		void setHouseType(string);
		string getHouseType();
		
		int HouseMenu(string);
		void UpdateHouseDetails(string);
		void DeleteHouseDetails(string);
		int AddHouseDetails(string);
	private:
		string houseId="\0";
		string houseType="\0";
};
#endif
