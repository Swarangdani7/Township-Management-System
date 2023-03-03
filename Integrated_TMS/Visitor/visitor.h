//visitor header file - "visitor.h"
#ifndef VISITOR_H
#define VISITOR_H

#include<iostream>
#include<string>
#include<algorithm>
#include "../Person/person.h"
#include "../Validations/validations.h"
#include "../Global_Functions/global.h"

#define VISITOR_UPDATE_FNAME 1
#define VISITOR_UPDATE_LNAME 2
#define VISITOR_UPDATE_MAIL 3
#define VISITOR_UPDATE_PHONE 4

using namespace std;

class Visitor:public Person
{
	public:
		Visitor(); // default constructor
		Visitor(const string&, const string&, const string&, long, const string&); // parameterized constructor
		
		//bool isValidVisitor(const string&); // function to check for valid visitor based on pan. Function takes 1 parameter PAN. Function returns boolean 
		void acceptVisitor(); // function to accept Visitor Details. Function takes 0 parameter. Function returns void 
		void modifyVisitor(); // function to update Visitor Details. Function takes 0 parameter. Function returns void
		void displayVisitor(); // function to display Visitor Details. Function takes 0 parameter. Function returns void
		
	private:
		// inheriting name,pan,phone,mail from person
};
#endif
