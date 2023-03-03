//definition file for owner

#include"owner.h"

//Defining parameter constructor of owner class
Owner::Owner(string id,string fname,string lname,string pan,long phone,string mail):Person(fname,lname,pan,phone,mail)
{
	this->ownId=id;
}

//Defining getters and setters of owner class

void Owner::setOwnId(string id)
{
	this->ownId=id;
}

string Owner::getOwnId()
{
	return this->ownId;
}

void Owner::setNoOfHouses(int num)
{
	noOfHouses=num;
}

int Owner::getNoOfHouses()
{
	
	return this->noOfHouses;
}

void Owner::ownerMenu()
{
	int opt;
	
	while(1)
		{
			cout<<"\n--------------OWNER MENU--------------\n\n";
			cout<<"Choose an option...\n1) Add Owner Details\n2) Update Owner Details\n3) Display Owner Details\n4) Delete Owner Details\n66) Back\n0) Exit\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case OWNER_ADD_OWNER:
					addOwner();
					continue;
				case OWNER_UPDATE_OWNER:
					updateOwner();
					continue;
				case OWNER_DISPLAY_OWNER:
					displayOwner();
					continue;
				case OWNER_DELETE_OWNER:
					deleteOwner();
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

//defining function to perform add Owner
void Owner::addOwner()
{
	string str,temp;
	int count=0;
	char ch;
	string firstname,lastname,pannum,mail,phonenum;
	Owner *optr = new Owner();
	ownId="O999";
	
	cout<<"\nEnter new Owner Details here...\n";
	ifstream in;
	in.open("Files/owner_details.txt");
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
				ownId=str;
				count++;
			}
		}
		count=0;
	}
	string rand = ownId.substr(1);
	int id = stoi(rand);
	id++;
	string val = to_string(id);
	
	cout<<"\n Are you a secretary (y/n) ? : ";
	cin>>ch;
	if(ch=='y' || ch=='Y')
		ownId="S"+val;
	else
		ownId="O"+val;
	
	//in.close();
	in.clear();
	in.seekg(0);
	Validations v;
	
	cout<<"\nEnter Owner First Name: ";
	cin>>firstname;
	
	while(!v.validate_name(firstname)) //Checking for valid first name
	                                   //loop runs until 1 is returned from the funciton
	{
		
		cout<<"\nEnter valid first name: ";
		cin>>firstname;
		
	}
	optr->setFname(firstname);
	cout<<"\nEnter Owner Last Name: ";
	cin>>lastname;
	
	while(!v.validate_name(lastname)) //Checking for valid last name
	                                   //loop runs until 1 is returned from the funciton
	{
		
		cout<<"\nEnter valid last name: ";
		cin>>lastname;
		
	}
	optr->setLname(lastname);
	
	while(1)
	{
		cout<<"\nEnter Owner PAN Number: ";
		cin>>pannum;
		if(v.validate_pan(pannum))
		{
			
			if(v.checkPan(pannum,in))
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
	optr->setPan(pannum);
	in.close();
	cout<<"\nEnter Owner Phone Number: ";
	cin>>phonenum;
	while(1)  //Checking for valid phone number.
	{  // checking if phone no. contains only digits not charaters // checking if phone no. contains 10 digits 
		if(all_of(phonenum.begin(),phonenum.end(),::isdigit) && v.validate_phone(stol(phonenum)))
		{
			break;
		}
		else
		{
			cout<<"\nEnter valid phone number of 10 digits: ";
			cin>>phonenum;
		}
	}
	
	optr->setPhone(stol(phonenum));
	
	cout<<"\nEnter Owner Email ID: ";
	cin>>mail;
	
	while(!v.validate_mail(mail)) //Checkig for valid mail
								  //loop runs until 1 is returned from the funciton
	 {
		 cout<<"\nEnter valid mail: ";
		 cin>>mail;
	 }
	optr->setMail(mail);
	
	vector<HouseDetails> houses;
	string house_type,house_no;
	cout<<"\nEnter number of houses: ";
	cin>>noOfHouses;
	
	for(int i=0;i<noOfHouses;i++)
	{
		cout<<"\nEnter Details of House "<<i+1<<" ::"<<endl;
		while(1)
		{
			cout<<"\nEnter house ID: ";
			cin>>house_no;
			if(v.validate_houseId(house_no))
			{
				
				if(!v.validate_ownerHouseId(house_no))
				{
					cout<<"\nHouse Id already exists !!!!\n";
					
				}
				else
					break;
			}
			else
				cout<<"\nEnter valid House Number !!!\n";
		}
	
		
		while(1)
		{
			cout<<"\nEnter house type: ";
			cin>>house_type;
			if(v.validate_houseType(house_type))
				break;
			else
				cout<<"\nEnter valid House Type...should be Row/Flat only !!\n";
		}
		
		houseDetails.setHouseId(house_no);
		houseDetails.setHouseType(house_type);
		
		houses.push_back(houseDetails);
	}
	
	ofstream h_out;
	h_out.open("Files/House_details.txt",ios::app);
	if(!h_out.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	
	for(int i=0;i<(int)houses.size();i++)
	{
	
	h_out<<houses[i].getHouseId()<<","<<ownId<<","<<houses[i].getHouseType()<<endl;
	
	}
	h_out.close();
	
	cout<<"\n Thank you for providing the details.\nDetails have been added succesfully \n";
	
	ofstream out;
	out.open("Files/owner_details.txt",ios::app);
	if(!out.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	
	out<<ownId<<","<<optr->getFname()<<","<<optr->getLname()<<","<<optr->getPan()<<","<<optr->getPhone()<<","<<optr->getMail()<<","<<noOfHouses<<endl;
	out.close();
	
	cout<<"\nOwner Details added succesfully !!\n";
	cout<<"\n Your Owner ID is "<<ownId<<endl; 
	
	delete optr;
}

//defining function to display Owner Details
void Owner::displayOwner()
{
	string id;
	int i;
	cout<<"\nEnter Owner ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/owner_details.txt");
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
		{
		
			break;
		}
	}
	if(i==(int)lines.size())
		cout<<"\nOwner details not found with the given Owner ID..:(\n";
	else
	{
		cout<<"\nOwner details with Owner ID: "<<id<<endl;
		cout<<"\nOwner First Name: "<<lines[i][1]<<endl;
		cout<<"\nOwner Last Name: "<<lines[i][2]<<endl;
		cout<<"\nOwner PAN Number: "<<lines[i][3]<<endl;
		cout<<"\nOwner Phone Number: "<<lines[i][4]<<endl;
		cout<<"\nOwner Mail: "<<lines[i][5]<<endl;
		cout<<"\nNumber of houses for the owner: "<<lines[i][6]<<endl;
		
		cout<<endl<<"Owner house details:\n";
		vector<vector<string>> h_lines;
		ifstream fin;
		fin.open("Files/House_details.txt");
		if(!fin.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		while(getline(fin,temp))
		{
			word.clear();
			stringstream data(temp);
			
			while(getline(data,con,','))
				word.push_back(con);
			h_lines.push_back(word);
		}
		fin.close();

		for(i=0;i<(int)h_lines.size();i++)
		{
			if(h_lines[i][1]==id)
				cout<<"\nHouse number: "<<h_lines[i][0]<<"\tHouse type: "<<h_lines[i][2]<<endl;
		}
	}
}

//defining function to update Owner Details
void Owner::updateOwner()
{
	string id;
	int i,opt=0;
	Validations v;
	string firstname,lastname,pannum,mail,phonenum;
	cout<<"\nUpdate your Owner details here..\n";
	cout<<"\nEnter Owner ID: ";
	cin>>id; //
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/owner_details.txt");
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
	//in.close();
	in.clear();
	in.seekg(0);
	for(i=0;i<(int)lines.size();i++)
	{
		if(lines[i][0]==id)
			break;
	}
	if(i==(int)lines.size())
		cout<<"\nOwner details not found with the given Owner ID..:(\n";
	else
	{
		while(opt!=88)
		{
			cout<<"\nChoose an option to update Owner details with Owner ID: "<<id<<endl;
			cout<<"1) Update First Name\n2) Update Last Name\n3) Update PAN Number\n4) Update Phone Number\n5) Update Email ID\n6)Update House details\n88) Done Updating\nOption: ";
			cin>>opt;
			switch(opt)
			{
				case UPDATE_OWNER_FNAME:
					cout<<"\nEnter Owner's new First Name: ";
					cin>>firstname;
					while(!v.validate_name(firstname)) //Checking for valid first name
													 //loop runs until 1 is returned from the funciton
					{
		
							cout<<"\nEnter valid first name: ";
							cin>>firstname;
					}
					lines[i][1]=firstname;
					continue;
				case UPDATE_OWNER_LNAME:
					cout<<"\nEnter Owner's new Last Name: ";
					cin>>lastname;
					while(!v.validate_name(lastname)) //Checking for valid last name
													 //loop runs until 1 is returned from the funciton
	                  		{
		
							cout<<"\nEnter valid last name: ";
							cin>>lastname;
					}
					lines[i][2]=lastname;
					continue;
				case UPDATE_OWNER_PAN:
					//cout<<"\nEnter Owner PAN Number: ";
					//cin>>lines[i][3];
					while(1)
					{
						cout<<"\nEnter Owner's new PAN Number: ";
						cin>>lines[i][3];
						if(v.validate_pan(lines[i][3]))
						{
							
							if(v.checkPan(lines[i][3],in))
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
				case UPDATE_OWNER_PHONE:
					cout<<"\nEnter Owner's new Phone Number: ";
					cin>>phonenum;
					while(1)  //Checkig for valid phone number.
					{  // checking if phone no. contains only digits not charaters // checking if phone no. contains 10 digits 
						if( all_of(phonenum.begin(),phonenum.end(),::isdigit) && v.validate_phone(stol(phonenum)) )
						{
							break;
						}
						else
						{
							cout<<"\nEnter valid phone number of 10 digits: ";
							cin>>phonenum;
						}
					}
					
					lines[i][4]=phonenum;
					continue;
				case UPDATE_OWNER_EMAIL:
					cout<<"\nEnter Owner's new Email ID: ";
					cin>>mail;
					while(!v.validate_mail(mail)) //Checkig for valid mail
								  //loop runs until 1 is returned from the funciton
					{
						cout<<"\nEnter valid mail: ";
						cin>>mail;
					}
					lines[i][5]=mail;
					continue;
				case UPDATE_OWNER_NUMBER_OF_HOUSES:
					noOfHouses=stoi(lines[i][6])+houseDetails.HouseMenu(id);
					lines[i][6]= to_string(noOfHouses);
					
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
		out.open("Files/owner_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		for(i=0;i<(int)lines.size();i++)
			out<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<endl;
		out.close();
		
		cout<<"\nOwner Details updated succesfully !!\n";
	}
}
//defining function to delete Owner Details
void Owner::deleteOwner()
{
	string id;
	int i;
	cout<<"\nEnter Owner ID: ";
	cin>>id;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/owner_details.txt");
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
			ofstream dout;
			dout.open("Files/owner_history.txt",ios::app);
			if(!dout.is_open())
			{
				cout<<"\nCannot open file...!!\n";
				exit(0);
			}
			dout<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<endl;
			dout.close();
			
			
			lines.erase(it);
			break;
		}
		advance(it,1);
	}
	if(i==n)
		cout<<"\nOwner details not found with the given Owner ID..:(\n";
	else
	{
		ofstream out;
		out.open("Files/owner_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		for(i=0;i<(int)lines.size();i++)
			out<<lines[i][0]<<","<<lines[i][1]<<","<<lines[i][2]<<","<<lines[i][3]<<","<<lines[i][4]<<","<<lines[i][5]<<","<<lines[i][6]<<endl;
		out.close();
		//cout<<"\nOwner details with Owner ID: "<<id<<" are succesfully deleted."<<endl;
	}
	/*...................................................................................................*/
	
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
		while(getline(data,con,','))
			strings.push_back(con);
	 	record.push_back(strings);
	}
	in.close();
	
	ofstream out;
	out.open("Files/House_details.txt");
	
	ofstream dout;
	dout.open("Files/house_history.txt",ios::app);
    if(!dout.is_open())
		{
			cout<<"\nCannot open house_history sfile...!!\n";
			exit(0);
		}
	
	it = record.begin();
	vector<vector<vector<string>>::iterator> index;
	for(i=0;i<(int)record.size();i++)
	{
		if(record[i][1]==id)
		{
			
			dout<<record[i][0]<<","<<record[i][1]<<","<<record[i][2]<<endl;
			
		}	
		else
		{
			out<<record[i][0]<<","<<record[i][1]<<","<<record[i][2]<<endl;
		}
		advance(it,1);
	}
	dout.close();
	out.close();
	cout<<"\nOwner and owner house details with Owner ID: "<<id<<" are succesfully deleted."<<endl;
}
