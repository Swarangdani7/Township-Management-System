//visitor header file - "visitor.h"
#ifndef VISITOR_H
#define VISITOR_H

#include<iostream>
#include<string>
#include<algorithm>

#include "person.h"
#include "validations.h"

using namespace std;

class Visitor:public Person
{
	public:
		Visitor(); // default constructor
		Visitor(const string&, const string&, const string&, long, const string&); // parameterized constructor
		
		//bool isValidVisitor(const string&); // function to check for valid visitor based on pan. Function takes 1 parameter PAN. Function returns boolean 
		bool acceptVisitor(string,string,string,long,string); // function to accept Visitor Details. Function takes 5 parameter. Function returns bool 
		
	private:
		// inheriting name,pan,phone,mail from person
};
#endif
