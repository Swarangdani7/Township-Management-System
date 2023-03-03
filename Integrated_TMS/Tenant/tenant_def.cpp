//including required user defined header files
#include"tenant.h"

//defining the parameter constructor of Admin class
Tenant::Tenant(string id,string fname,string lname,string pan,long phone,string mail):Person(fname,lname,pan,phone,mail)
{
	this->tenantId=id;
}

//defining getters and setters of Admin class
string Tenant::getTenantId()
{
	return this->tenantId;
}

void Tenant::setTenantId(string id)
{
	this->tenantId=id;
}

//defining function to display Tenant Menu
void Tenant::tenantMenu()
{
	int opt;
	while(1)
		{
			cout<<"\n--------------TENANT MENU--------------\n\n";
			cout<<"Choose an option...\n1) Add Tenant Details\n2) Update Tenant Details\n3) Delete Tenant Details\n66) Back\n0) Exit\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case ADD_TENANT:
					addTenant();
					continue;
				case UPDATE_TENANT:
					updateTenant();
					continue;
				case DELETE_TENANT:
					deleteTenant();
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

//defining function to perform add Tenant
void Tenant::addTenant()
{
	string str,temp;
	int count=0;
	string firstname,lastname,pannum,mail,hid,htype;
	long phonenum;
	//Tenant *tptr = new Tenant();
	Validations *vptr = new Validations();
	tenantId="T999";
	cout<<"\nEnter new Tenant Details here...\n";
	ifstream in;
	in.open("Files/tenant_details.txt");
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
				tenantId=str;
				count++;
			}
		}
		count=0;
	}
	string rand = tenantId.substr(1);
	int id = stoi(rand);
	id++;
	string val = to_string(id);
	tenantId="T"+val;
	in.clear();
	in.seekg(0);
	
	while(1)
	{
		cout<<"\nEnter Tenant First Name: ";
		cin>>firstname;
		if(vptr->validate_name(firstname))
			break;
		else
			cout<<"\nEnter valid name..No special characters !!!\n";
	}
	this->setFname(firstname);
	
	while(1)
	{
		cout<<"\nEnter Tenant Last Name: ";
		cin>>lastname;
		if(vptr->validate_name(lastname))
			break;
		else
			cout<<"\nEnter valid name..No special characters !!!\n";
	}
	this->setLname(lastname);
	
	while(1)
	{
		cout<<"\nEnter Tenant PAN Number: ";
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
	this->setPan(pannum);
	in.close();
	
	while(1)
	{
		cout<<"\nEnter Tenant Phone Number: ";
		cin>>phonenum;
		if(vptr->validate_phone(phonenum))
			break;
		else
			cout<<"\nEnter valid phone number..Must contain 10 digits !!!\n";
	}
	this->setPhone(phonenum);
	
	while(1)
	{
		cout<<"\nEnter Tenant Email ID: ";
		cin>>mail;
		if(vptr->validate_mail(mail))
			break;
		else
			cout<<"\nEnter valid mail !!!\n";
	}
	this->setMail(mail);
	
	while(1)
	{
		cout<<"\nEnter your House ID: ";
		cin>>hid;
		if(vptr->validate_tenantHouseId(hid))
			break;
		else
			cout<<"\nEnter existing House ID !!!\n";
	}
	hd.setHouseId(hid);
	
	vector<vector<string>>record;
	vector<string> strings;

	in.open("Files/House_details.txt");
	if(!in.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	while(getline(in,temp))
	{
		strings.clear();
		stringstream data(temp);
		while(getline(data,str,','))
			strings.push_back(str);
	 	record.push_back(strings);
	}
	in.close();
	
	for(int i=0;i<(int)record.size();i++)
	{
		if(record[i][0]==hid)
		{
			htype=record[i][2];
			break;
		}
	}	
	hd.setHouseType(htype);
	
	cout<<"\n Thank you for providing the details... ";
	
	ofstream out;
	out.open("Files/tenant_details.txt",ios::app);
	if(!out.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	out<<tenantId<<","<<this->getFname()<<","<<this->getLname()<<","<<this->getPan()<<","<<this->getPhone()<<","<<this->getMail()<<","<<hd.getHouseId()<<","<<hd.getHouseType()<<endl;
	out.close();
	
	cout<<"\nTenant Details added succesfully !!\n";
	cout<<"\n Your Tenant ID is "<<tenantId<<endl; 
	
	//delete tptr;
	delete vptr;
}

//defining function to perform update tenant
void Tenant::updateTenant()
{
	string id;
	int i,opt=0;
	Validations *vptr = new Validations();
	cout<<"\nUpdate your tenant details here..\n";
	cout<<"\nEnter Tenant ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/tenant_details.txt");
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
		cout<<"\nTenant details not found with the given Tenant ID..:(\n";
	else
	{
		while(opt!=88)
		{
			cout<<"\nChoose an option to update Tenant details with Tenant ID: "<<id<<endl;
			cout<<"1) Update First Name\n2) Update Last Name\n3) Update PAN Number\n4) Update Phone Number\n5) Update Email ID\n6) Update House ID\n88) Done Updating\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case TENANT_UPDATE_FNAME:
					while(1)
					{
						cout<<"\nEnter Tenant First Name: ";
						cin>>lines[i][1];
						if(vptr->validate_name(lines[i][1]))
							break;
						else
							cout<<"\nEnter valid name..No special characters !!!\n";
					}
					continue;
				case TENANT_UPDATE_LNAME:
					while(1)
					{
						cout<<"\nEnter Tenant Last Name: ";
						cin>>lines[i][2];
						if(vptr->validate_name(lines[i][2]))
							break;
						else
							cout<<"\nEnter valid name..No special characters !!!\n";
					}
					continue;
				case TENANT_UPDATE_PAN:
					while(1)
					{
						cout<<"\nEnter Tenant PAN Number: ";
						cin>>lines[i][3];
						if(vptr->validate_pan(lines[i][3]))
						{
							
							if(vptr->checkPan(lines[i][3],in))
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
				case TENANT_UPDATE_PHONE:
					while(1)
					{
						cout<<"\nEnter Tenant Phone Number: ";
						cin>>lines[i][4];
						if(vptr->validate_phone(stol(lines[i][4])))
							break;
						else
							cout<<"\nEnter valid phone number..Must contain 10 digits !!!\n";
					}
					continue;
				case TENANT_UPDATE_EMAIL:
					while(1)
					{
						cout<<"\nEnter Tenant Email ID: ";
						cin>>lines[i][5];
						if(vptr->validate_mail(lines[i][5]))
							break;
						else
							cout<<"\nEnter valid mail !!!\n";
					}
					continue;
				case TENANT_UPDATE_HOUSEID:
					while(1)
					{
						cout<<"\nEnter your House ID: ";
						cin>>lines[i][6];
						if(vptr->validate_tenantHouseId(lines[i][6]))
							break;
						else
							cout<<"\nEnter valid House ID !!!\n";
					}
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
		out.open("Files/tenant_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		for(i=0;i<(int)lines.size();i++)
			out<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<","<<lines[i][7]<<endl;
		out.close();
					
		cout<<"\nTenant Details updated succesfully !!\n";
	}
	
	delete vptr;
}

void Tenant::displayTenant()
{
	string t_id,line,inter;
	vector<string>rec;
	bool flg = false; // to check whether tenant exists in file or not
	
	cout<<"\n\n-------------*** Display Tenant Details ***-------------\n\n";
	cout<<"Enter Tenant ID: ";
	cin>>t_id;
	
	ifstream in;
	in.open("Files/tenant_details.txt");
		
	if(!in.is_open())
	{
		cout<<"\nError! Cannot Open File\n";
		exit(1);
	}
		
	while(getline(in,line)) // reading record from file line by line
	{
		istringstream ss(line); //stringstream object
		getline(ss,inter,','); // reading single value seperated by comma into inter variable and it will contain 1st value of the entry in the file i.e. tenantId 
		
		if(inter == t_id)//checking if user entered tenantId is equal to any of the tenantId present in the file if yes we will push that record into vector rec 
		{
			flg = true;
			while(getline(ss,inter,','))
			{
				rec.push_back(inter);
			}
			break;
		}
		line.clear();
	}
	
	in.close();
	
	if(flg)
	{
		cout<<"\nTenant Details: \n\n";
		cout<<"Tenant ID: "<<t_id<<"\n";
		cout<<"Name: "<<rec[0]<<" "<<rec[1]<<"\n";
		cout<<"PAN: "<<rec[2]<<"\n";
		cout<<"Phone: "<<rec[3]<<"\n";
		cout<<"Mail: "<<rec[4]<<"\n";
		cout<<"House ID: "<<rec[5]<<endl;
		cout<<"House Type: "<<rec[6]<<endl;
	}
	else
	{	
		cout<<"\n---------------------------------------------------\n";
		cout<<"Cannot Display Tenant details! Tenant does not exist\n";
		cout<<"---------------------------------------------------\n";
	}
}


//defining function to delete Tenant Details
void Tenant::deleteTenant()
{
	string id;
	int i;
	cout<<"\nEnter Tenant ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/tenant_details.txt");
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
	int n = lines.size();
	for(i=0;i<(int)lines.size();i++)
	{
		if(lines[i][0]==id)
		{
			ofstream dout;
			dout.open("Files/tenant_history.txt",ios::app);
			if(!dout.is_open())
			{
				cout<<"\nCannot open file...!!\n";
				exit(0);
			}
			dout<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<","<<lines[i][7]<<endl;
			dout.close();
			lines.erase(it);
			break;
		}
		advance(it,1);
	}
	if(i==n)
		cout<<"\nTenant details not found with the given Tenant ID..:(\n";
	else
	{
		ofstream out;
		out.open("Files/tenant_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		for(i=0;i<(int)lines.size();i++)
			out<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<","<<lines[i][7]<<endl;
		out.close();
		cout<<"\nTenant details with Tenant ID: "<<id<<" are succesfully deleted !!!"<<endl;
	}
}
