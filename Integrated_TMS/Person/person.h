#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>
#include "../Validations/validations.h"

using namespace std;

//defining macros
#define BACK 66
#define DONE 88
#define LOGOUT 99
#define EXIT 0

class Person
{
	public:
		Person(); // default constructor
		Person(const string&, const string&, const string&, long, const string&); // parameterized constructor
		
		void setFname(const string&); // function to set Person First Name
		string getFname(); // function to get Person First Name
		
		void setLname(const string&); // function to set Person Last Name
		string getLname(); // function to get Person Last Name
		
		void setPan(const string&); // function to set PAN
		string getPan(); // function to get PAN
		
		void setPhone(long); // function to set Phone
		long getPhone(); // function to get Phone
		
		void setMail(const string&); // function to set Mail
		string getMail(); // function to get Mail
		
		//user defined destructor for dynamic cast
		virtual ~Person(){}
		
	private:
		string fname;
		string lname;
		string pan;
		long phone;
		string mail;
};
#endif
