#include "employee.h"

Employee::Employee():Person() // Using member initializer list
{
	empId = "\0";
	empPassword = "\0";
}

Employee::Employee(const string &eid, const string &pass, const string &fname, const string &lname, const string &pan, long phone, const string &mail):Person(fname,lname,pan,phone,mail)
{
	empId = eid;
	empPassword = pass;
}

string Employee::getEmpId()
{
	return this->empId;
}

void Employee::setEmpId(const string &eid)
{
	this->empId = eid;
}

string Employee::getEmpPassword()
{
	return this->empPassword;
}

void Employee::setEmpPassword(const string &pass)
{
	this->empPassword = pass;
}	




void Employee::Recep_EmployeeMenu()
{
	int ch;
	Person *ptr;
	Visit *visitptr;
	do{
		
		while(1){
			cout<<"\n--------------*** Employee Menu ***--------------\n\n";
			cout<<"1. Add Visitor\n2. Modify Visitor\n3. Display Visitor\n4. Add Visit Details\n5. Display Visit Details\n6. Display Owner Details\n7. Display Tenant Details\n8. Logout\n0. Exit\n\n";
		 	
		 	cout<<"Enter choice: ";
			cin>>ch;
			if(ch >= 0 && ch <= 8) break;
		}
		switch(ch)
		{
			case EMP_ADD_VISITOR:
				ptr = new Visitor();
				dynamic_cast<Visitor*>(ptr)->acceptVisitor();
				delete ptr;
				break;
			case EMP_MODIFY_VISITOR:
				ptr = new Visitor();
				dynamic_cast<Visitor*>(ptr)->modifyVisitor();
				delete ptr;
				break;
			case EMP_DISPLAY_VISITOR:
				ptr = new Visitor();
				dynamic_cast<Visitor*>(ptr)->displayVisitor();
				delete ptr;
				break;
			case EMP_ADD_VISIT_DETAILS:
				visitptr=new Visit();
				visitptr->addVisit();
				delete visitptr;
				break;
			case EMP_DISPLAY_VISIT_DETAILS:
				visitptr=new Visit();
				visitptr->displayVisit();
				delete visitptr;
				break;
			case EMP_DISPLAY_OWNER_DETAILS:
				ptr = new Owner();
				dynamic_cast<Owner*>(ptr)->displayOwner();
				delete ptr;
				break;
			case EMP_DISPLAY_TENANT_DETAILS:
				ptr = new Tenant();
				dynamic_cast<Tenant*>(ptr)->displayTenant();
				delete ptr;
				break;
			case EMP_LOGOUT:
				cout<<"\nYou've Been Successfully Logged Out\n\n";
				ch = 0;
				break;
			case 0:
				exit(0);
		}
		
		if(ch != 0){
			cout<<"\nGo Back to Employee Menu (1/0): ";
			cin>>ch;
		}	
	}
	while(ch != 0);
}

void Employee::loginEmployee()
{
	int ch;
	bool flg = false;
	string line,inter;
	
	do{
		ch = 0;
		cout<<"\nEnter Employee ID: ";
		cin>>empId;
		cout<<"Enter Employee Password: ";
		cin>>empPassword;
		
		ifstream in;
		in.open("Files/employee_details.txt");
		
		if(!in.is_open())
		{
			cout<<"\nError! Cannot Open File\n";
			exit(1);
		}
		
		while(in)
		{
			getline(in,line);
			istringstream ss(line);
			getline(ss, inter, ',');
			if(inter == empId)
			{
				getline(ss,inter,',');
				if(inter == empPassword)
				{
					flg = true;
					break;
				}
			}
		}
		in.close();
		
		if(flg)
		{
			cout<<"\nLogin Successfull\n\n";
			Employee::Recep_EmployeeMenu();
		}
		else
		{
			cout<<"\n-------------------------\n";
			cout<<"Enter Valid ID/Password\n";
			cout<<"-------------------------\n\n";
			
			cout<<"Do you wish to Login Again (1/0): ";
			cin>>ch;
		}
	}
	while(ch != 0);
}
