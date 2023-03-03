//definition file of admin: "admin_def.cpp"

//including admin header file
#include"admin.h"

//defining the parameter constructor of Admin class
Admin::Admin(string id,string pwd,string fname,string lname,string pan,long phone,string mail):Person(fname,lname,pan,phone,mail)
{
	this->adminId=id;
	this->adminPassword=pwd;
}

//defining getters and setters of Admin class
string Admin::getAdminId()
{
	return this->adminId;
}

void Admin::setAdminId(string id)
{
	this->adminId=id;
}

string Admin::getAdminPassword()
{
	return this->adminPassword;
}

void Admin::setAdminPassword(string pwd)
{
	this->adminPassword=pwd;
}

//defining function to validate admin
bool Admin::validate_admin(string id,string pwd)
{
	int i;
	bool flg = false;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Admin_Test_Files/admin_details.txt");
	if(!in.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	while(getline(in,temp))
	{
		word.clear();
		stringstream data(temp);
		while(getline(data,con,','))
			word.push_back(con);
		lines.push_back(word);
	}
	in.close();
	for(i=0;i<(int)lines.size();i++)
	{
		if(id==lines[i][0] && pwd==lines[i][1])
		{
			flg = true;
			break;
		}
	}
	if(flg)
	{
		setAdminId(id);
		setAdminPassword(pwd);
	}
	
	return flg;
}
