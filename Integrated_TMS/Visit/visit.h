//header file:visit.h
#ifndef VISIT_H
#define VISIT_H

#include<iostream>
#include<string>
#include "../Global_Functions/global.h"
#include "../Validations/validations.h"
#include "../Visitor/visitor.h"

using namespace std;

class Visit
{
	public:
		Visit()=default;
		
		void addVisit();
		void displayVisit();
		void adminDisplayVisit();
	private:
		string visitorPan;
		string visitorHouseType;
		string visitorHouseNum;
};

#endif
