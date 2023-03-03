//Employee header file - "employee.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

#include "visitor.h"

using namespace std;

class Employee:public Person
{
	public:
		Employee();
		Employee(const string&,const string&,const string&,const string&,const string&,long,const string&); 
		
		string getEmpId();
		void setEmpId(const string&);
		
		string getEmpPassword();
		void setEmpPassword(const string&);
		
		bool loginEmployee(string,string);
		void Recep_EmployeeMenu();
		
	private:
		string empId;
		string empPassword;
};
#endif
