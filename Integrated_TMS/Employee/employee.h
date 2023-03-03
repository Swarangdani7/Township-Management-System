//Employee header file - "employee.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

#include "../Visitor/visitor.h"
#include "../Visit/visit.h"
#include "../Owner/owner.h"
#include "../Tenant/tenant.h"

#define EMP_ADD_VISITOR 1
#define EMP_MODIFY_VISITOR 2
#define EMP_DISPLAY_VISITOR 3
#define EMP_ADD_VISIT_DETAILS 4
#define EMP_DISPLAY_VISIT_DETAILS 5
#define EMP_DISPLAY_OWNER_DETAILS 6
#define EMP_DISPLAY_TENANT_DETAILS 7
#define EMP_LOGOUT 8

#define ADD_EMPLOYEE 1
#define DISPLAY_EMPLOYEE 3
#define UPDATE_EMPLOYEE 2
#define DELETE_EMPLOYEE 4
#define UPDATE_EMPLOYEE_FNAME 1
#define UPDATE_EMPLOYEE_LNAME 2
#define UPDATE_EMPLOYEE_PAN 3
#define UPDATE_EMPLOYEE_PHONE 4
#define UPDATE_EMPLOYEE_MAIL 5
#define UPDATE_EMPLOYEE_PASS 6

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
		
		void loginEmployee();
		void Recep_EmployeeMenu();
		
		void addVisit();
		void displayVisit();
		void displayOwner();
		void displayTenant();
		
		bool validateEmployee(int,string);
		void employeeMenu();
		void addEmployee();
		void updateEmployee();
		void deleteEmployee();
		void displayEmployee();
		
	private:
		string empId;
		string empPassword;
};
#endif
