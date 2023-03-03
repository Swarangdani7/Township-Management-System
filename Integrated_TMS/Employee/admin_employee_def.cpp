//definition file of admin: "employee_def.cpp"

//including the required user defined header files
#include"employee.h"

//defining function to display Employee Menu
void Employee::employeeMenu()
{
	int opt;
	while(1)
		{
			cout<<"\n--------------EMPLOYEE MENU--------------\n\n";
			cout<<"Choose an option...\n1) Add Employee Details\n2) Update Employee Details\n3) Display Employee Details\n4) Delete Employee Details\n66) Back\n0) Exit\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case ADD_EMPLOYEE:
					addEmployee();
					continue;
				case UPDATE_EMPLOYEE:
					updateEmployee();
					continue;
				case DISPLAY_EMPLOYEE:
					displayEmployee();
					continue;
				case DELETE_EMPLOYEE:
					deleteEmployee();
					continue;
				case BACK:
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

//defining function to perform add Employee
void Employee::addEmployee()
{
	string str,temp;
	int count=0;
	string firstname,lastname,pannum,mail;
	long phonenum;
	Employee *eptr = new Employee();
	Validations *vptr = new Validations();
	empId="E999";
	cout<<"\nEnter new Employee Details here...\n";
	ifstream in;
	in.open("Files/employee_details.txt");
	if(!in.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	while(getline(in,temp))
	{
		stringstream data(temp);
		while(getline(data,str,','))
		{
			if(count==0)
			{
				empId=str;
				count++;
			}
		}
		count=0;
	}
	string rand = empId.substr(1);
	int id = stoi(rand);
	id++;
	string val = to_string(id);
	empId="E"+val;
	in.clear();
	in.seekg(0);
	
	while(1)
	{
		cout<<"\nEnter Employee First Name: ";
		cin>>firstname;
		if(vptr->validate_name(firstname))
			break;
		else
			cout<<"\nEnter valid name..No special characters !!!\n";
	}
	eptr->setFname(firstname);
	
	while(1)
	{
		cout<<"\nEnter Employee Last Name: ";
		cin>>lastname;
		if(vptr->validate_name(lastname))
			break;
		else
			cout<<"\nEnter valid name..No special characters !!!\n";
	}
	eptr->setLname(lastname);
	
	while(1)
	{
		cout<<"\nEnter Employee PAN Number: ";
		cin>>pannum;
		if(vptr->validate_pan(pannum))
		{
			
			if(vptr->checkPan(pannum,in))
			{
				cout<<"\nPAN Number already exists !!!\n";
				in.clear();
				in.seekg(0);
			}
			else
				break;
		}
		else
			cout<<"\nEnter valid PAN Number !!!\n";
	}
	eptr->setPan(pannum);
	in.close();
	
	while(1)
	{
		cout<<"\nEnter Employee Phone Number: ";
		cin>>phonenum;
		if(vptr->validate_phone(phonenum))
			break;
		else
			cout<<"\nEnter valid phone number..Must contain 10 digits !!!\n";
	}
	eptr->setPhone(phonenum);
	
	while(1)
	{
		cout<<"\nEnter Employee Email ID: ";
		cin>>mail;
		if(vptr->validate_mail(mail))
			break;
		else
			cout<<"\nEnter valid mail !!!\n";
	}
	eptr->setMail(mail);
	
	cout<<"\n Thank you for providing the details...Please set your Password for completing the process \n";
	cout<<"\nEnter your Password: ";
	cin>>empPassword;
	
	ofstream out;
	out.open("Files/employee_details.txt",ios::app);
	if(!out.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	out<<empId<<","<<empPassword<<","<<eptr->getFname()<<","<<eptr->getLname()<<","<<eptr->getPan()<<","<<eptr->getPhone()<<","<<eptr->getMail()<<endl;
	out.close();
	
	cout<<"\nEmployee Details added succesfully !!\n";
	cout<<"\n Your Employee ID is "<<empId<<endl; 
	
	delete eptr;
	delete vptr;
}

//defining function to display Employee Details
void Employee::displayEmployee()
{
	string id;
	int i;
	cout<<"\nEnter Employee ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/employee_details.txt");
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
		if(lines[i][0]==id)
			break;
	}
	if(i==(int)lines.size())
		cout<<"\nEmployee details not found with the given Employee ID..:(\n";
	else
	{
		cout<<"\nEmployee details with Employee ID: "<<id<<endl;
		cout<<"\nEmployee First Name: "<<lines[i][2]<<endl;
		cout<<"\nEmployee Last Name: "<<lines[i][3]<<endl;
		cout<<"\nEmployee PAN Number: "<<lines[i][4]<<endl;
		cout<<"\nEmployee Phone Number: "<<lines[i][5]<<endl;
		cout<<"\nEmployee Mail: "<<lines[i][6]<<endl;
	}
}

//defining function to update Employee Details
void Employee::updateEmployee()
{
	string id;
	int i,opt=0;
	Validations *vptr = new Validations();
	cout<<"\nUpdate your employee details here..\n";
	cout<<"\nEnter Employee ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/employee_details.txt");
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
	in.clear();
	in.seekg(0);
	
	for(i=0;i<(int)lines.size();i++)
	{
		if(lines[i][0]==id)
			break;
	}
	if(i==(int)lines.size())
		cout<<"\nEmployee details not found with the given Employee ID..:(\n";
	else
	{
		while(opt!=88)
		{
			cout<<"\nChoose an option to update Employee details with Employeeee ID: "<<id<<endl;
			cout<<"1) Update First Name\n2) Update Last Name\n3) Update PAN Number\n4) Update Phone Number\n5) Update Email ID\n6 Update Employee Password\n88) Done Updating\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case UPDATE_EMPLOYEE_FNAME:
					while(1)
					{
						cout<<"\nEnter Employee First Name: ";
						cin>>lines[i][2];
						if(vptr->validate_name(lines[i][2]))
							break;
						else
							cout<<"\nEnter valid name..No special characters !!!\n";
					}
					continue;
				case UPDATE_EMPLOYEE_LNAME:
					while(1)
					{
						cout<<"\nEnter Employee Last Name: ";
						cin>>lines[i][3];
						if(vptr->validate_name(lines[i][3]))
							break;
						else
							cout<<"\nEnter valid name..No special characters !!!\n";
					}
					continue;
				case UPDATE_EMPLOYEE_PAN:
					while(1)
					{
						cout<<"\nEnter Employee PAN Number: ";
						cin>>lines[i][4];
						if(vptr->validate_pan(lines[i][4]))
						{
							
							if(vptr->checkPan(lines[i][4],in))
							{
								cout<<"\nPAN Number already exists !!!\n";
								in.clear();
								in.seekg(0);
							}
							else
								break;
						}
						else
							cout<<"\nEnter valid PAN Number !!!\n";
					}
					in.clear();
					in.seekg(0);
					continue;
				case UPDATE_EMPLOYEE_PHONE:
					while(1)
					{
						cout<<"\nEnter Employee Phone Number: ";
						cin>>lines[i][5];
						if(vptr->validate_phone(stol(lines[i][5])))
							break;
						else
							cout<<"\nEnter valid phone number..Must contain 10 digits !!!\n";
					}
					continue;
				case UPDATE_EMPLOYEE_MAIL:
					while(1)
					{
						cout<<"\nEnter Employee Email ID: ";
						cin>>lines[i][6];
						if(vptr->validate_mail(lines[i][6]))
							break;
						else
							cout<<"\nEnter valid mail !!!\n";
					}
					continue;
				case UPDATE_EMPLOYEE_PASS:
					cout<<"\nEnter Employee Password: ";
					cin>>lines[i][1];
					continue;
				case DONE:
					continue;
				default:
					printf("Invalid Option!! Choose a valid option...\n");
					continue;
			}
		}
		in.close();
		
		ofstream out;
		out.open("Files/employee_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		for(i=0;i<(int)lines.size();i++)
			out<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<endl;
		out.close();
		
		cout<<"\nEmployee Details updated succesfully !!\n";
	}
	delete vptr;
}


//defining function to delete Employee Details
void Employee::deleteEmployee()
{
	string id;
	int i;
	cout<<"\nEnter Employee ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/employee_details.txt");
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
	vector<vector<string>>::iterator it;
	it = lines.begin();
	int n = (int)lines.size();
	for(i=0;i<(int)lines.size();i++)
	{
		if(lines[i][0]==id)
		{
			lines.erase(it);
			break;
		}
		advance(it,1);
	}
	if(i==n)
		cout<<"\nEmployee details not found with the given Employee ID..:(\n";
	else
	{
		ofstream out;
		out.open("Files/employee_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		for(i=0;i<(int)lines.size();i++)
			out<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<endl;
		out.close();
		cout<<"\nEmployee details with Employee ID: "<<id<<" are succesfully deleted."<<endl;
	}
}
