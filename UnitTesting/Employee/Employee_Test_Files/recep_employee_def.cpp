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

bool Employee::loginEmployee(string id, string pass)
{
	bool flg=false;
	string line,inter;
		
	ifstream in;
	in.open("Employee_Test_Files/employee_details.txt");
		
	if(!in.is_open())
	{
		cout<<"\n(recep_employee_def): Line No 114 :: Error! Cannot Open File\n";
		exit(1);
	}
		
	while(in)
	{
		getline(in,line);
		istringstream ss(line);
		getline(ss, inter, ',');
		if(inter == id)
		{
			getline(ss,inter,',');
			if(inter == pass)
			{
				flg = true;
				break;
			}
		}
	}
	in.close();
	if(flg)
	{
		setEmpId(id);
		setEmpPassword(pass);
	}
	return flg;
}
