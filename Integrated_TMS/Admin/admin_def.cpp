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

//defining adminMenu method of Admin class
void Admin::adminMenu()
{
	int opt;
	string id,pwd;
	char ch;
	cout<<"\n--------------------WELCOME ADMIN--------------------\n\n";
	cout<<"Admin Login::\n";
	cout<<"\nEnter Admin ID: ";
	cin>>id;
	cout<<"Enter password: ";
	cin>>pwd;
	if(validate_admin(id,pwd))		//validates admin
	{
		cout<<"\nLogged in successfully...\n\n";
		Person *cptr;
		Visit v;
		while(1)
		{
			cout<<"\n--------------ADMIN MENU--------------\n\n";
			cout<<"Choose an option...\n1) Owner\n2) Display Visits by Date\n3) Tenant\n4) Employee\n99) LogOut\n0) Exit\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case ADMIN_OWNER:
					cptr=new Owner();
					dynamic_cast<Owner*>(cptr)->ownerMenu();
					delete cptr;
					continue;
				case ADMIN_DISPLAY_VISIT:
					v.adminDisplayVisit();
					continue;
				case ADMIN_TENANT:
					cptr=new Tenant();
					dynamic_cast<Tenant*>(cptr)->tenantMenu();
					delete cptr;
					continue;
				case ADMIN_EMPLOYEE:
					cptr=new Employee();
					dynamic_cast<Employee*>(cptr)->employeeMenu();
					delete cptr;
					continue;
				case LOGOUT:
					cout<<"Logged out successfully..\n\n";
					cout<<"Do you want to login again..?\n";
					cout<<"Choose y/n : ";
					while(getchar()!='\n');
					ch=getchar();
					if(ch=='Y' || ch=='y')
					{
						adminMenu();
						break;
					}
					else
						return;
				case EXIT:
					printf("\nThank you for using our services \nExited from Township Management System..\n\n");
					exit(0);
				default:
					printf("Invalid Option!! Choose a valid option...\n");
					continue;
			}
		}
	}
	else	//if Invalid admin
	{
		cout<<"\nIncorrect Admin ID/Password !!!\n";
		cout<<"Do you want to login again..?\n";
		cout<<"Choose y/n : ";
		while(getchar()!='\n');
		ch=getchar();
		if(ch=='Y' || ch=='y')
			adminMenu();
		else
			return;
	}
}

//defining function to validate admin
bool Admin::validate_admin(string id,string pwd)
{
	int i;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/admin_details.txt");
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
			return true;
		}
	}
	
	return false;
}
