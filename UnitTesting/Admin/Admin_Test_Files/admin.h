//Admin header file - "admin.h"	
#ifndef ADMIN_H
#define ADMIN_H

//including the required user defined header files
#include"tenant.h"
#include"person.h"

using namespace std;

//declaring class Admin which contains all the attributes and functions for admin and inherits Person class
class Admin:public Person
{
	//public functions of class Admin
	public:
		//default constructor
		Admin()=default;
		
		//parameterised constructor with parameters (adminId, adminPassword, fname, lname, pan, phone, email)
		Admin(string,string,string,string,string,long,string);
		
		//getters and setters for all the variables
		string getAdminId();
		void setAdminId(string);
		string getAdminPassword();
		void setAdminPassword(string);
		
		//functions to be performed by admin
		bool validate_admin(string,string);
		void adminMenu();
	
	//private attributes of class admin
	private:
		string adminId,adminPassword;
};
#endif
