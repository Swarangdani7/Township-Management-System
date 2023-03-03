//Owner header file - "owner.h"

#ifndef OWNER_H
#define OWNER_H

#include<iostream>
#include<string>
#include<cstring>
#include "../Person/person.h"
#include "../House_Details/housedetails.h"
#include "../Validations/validations.h"


#define OWNER_ADD_OWNER 1
#define OWNER_UPDATE_OWNER 2
#define OWNER_DISPLAY_OWNER 3
#define OWNER_DELETE_OWNER 4

#define UPDATE_OWNER_FNAME 1
#define UPDATE_OWNER_LNAME 2 
#define UPDATE_OWNER_PAN 3
#define UPDATE_OWNER_PHONE 4
#define UPDATE_OWNER_EMAIL 5
#define UPDATE_OWNER_NUMBER_OF_HOUSES 6


using namespace std;

class Owner:public Person
{
	public:
		Owner()=default;
		Owner(string,string,string,string,long,string); //ownId,fname,lname,pan,phone,mail
		string getOwnId();
		void setOwnId(string);
		void setNoOfHouses(int);
		int getNoOfHouses();
		
		void ownerMenu();
		void addOwner();
		void updateOwner();
		void deleteOwner();
		void displayOwner();
		
		
		
	private:
		int noOfHouses;
		string ownId; 
		HouseDetails houseDetails;
		//char role; //For seceretory it is 'S', for others it is 'N'
		
};

#endif
