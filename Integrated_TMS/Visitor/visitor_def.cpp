#include "visitor.h"

Visitor::Visitor():Person(){} // using member initializer list

Visitor::Visitor(const string& pan, const string& fname, const string& lname, long phone, const string& mail):Person(fname,lname,pan,phone,mail){} // using member initializer list



/* Function to accept Visitor Details */
void Visitor::acceptVisitor()
{
	string pan;
	Validations *vptr = new Validations(); // validator class. Includes validations for pan,name,phone,mail,etc
	
	cout<<"\n\n-------------*** ADD Visitor ***-------------\n\n";
	while(1)
	{
		cout<<"Enter Visitor PAN: ";
		cin>>pan;
		if(vptr->validate_pan(pan)) break; // validation for pan. Returns True if PAN is valid else returns False
		else
		{
			cout<<"\n------------------\n";
			cout<<"Enter Valid PAN\n";
			cout<<"------------------\n\n";
		}
	}
	
	if(vptr->isValidVisitor(pan)) // Function to check if visitor exists. Returns True if exists else Returns False
	{
		cout<<"\n--------------------------------------\n";
		cout<<"Cannot Add! Visitor already exists\n";
		cout<<"--------------------------------------\n";
	}
	
	else
	{
		this->setPan(pan);
		string fname,lname,mail,phone;
		
		while(1)
		{
			cout<<"Enter Visitor First Name: ";
			cin>>fname;
			if(vptr->validate_name(fname)) break; // validation for Name. Returns True if Name is valid else returns False
			else
			{
				cout<<"\n------------------\n";
				cout<<"Enter Valid Name\n";
				cout<<"------------------\n\n";
			}
		}
		this->setFname(fname);
		
		while(1)
		{
			cout<<"Enter Visitor Last Name: ";
			cin>>lname;
			if(vptr->validate_name(lname)) break; // validation for Name. Returns True if Name is valid else returns False
			else
			{
				cout<<"\n------------------\n";
				cout<<"Enter Valid Name\n";
				cout<<"------------------\n\n";
			}
		}
		this->setLname(lname);
		
		while(1)
		{
			cout<<"Enter Visitor Mail ID: ";
			cin>>mail;
			if(vptr->validate_mail(mail)) break; // validation for Mail. Returns True if Name is valid else returns False
			else
			{
				cout<<"\n------------------\n";
				cout<<"Enter Valid Mail ID\n";
				cout<<"------------------\n\n";
			}
		}	
		this->setMail(mail);
		
		while(1)
		{
			cout<<"Enter Visitor Phone Number: ";
			cin>>phone;
			
			if(all_of(phone.begin(),phone.end(),::isdigit) && vptr->validate_phone(stol(phone))) // checking if phone number entered contains characters or digits	 and it should contain 10 digits
			{
				break;
			}
			else
			{
				cout<<"\n---------------------------\n";
				cout<<"Enter Valid Phone Number\n";
				cout<<"---------------------------\n\n";
			}
		}
		this->setPhone(stol(phone));
		
		fstream out;
		out.open("Files/visitor_details.txt", ios::app);
		
		if(!out.is_open())
		{
			cout<<"\nError! Cannot Open File\n";
			exit(1);
		}
		
		out<<this->getPan()<<","<<this->getFname()<<","<<this->getLname()<<","<<this->getMail()<<","<<this->getPhone()<<"\n";
		
		out.close();
		
		cout<<"\n------------------------------------";
		cout<<"\nVisitor Details Successfully Added\n";
		cout<<"------------------------------------\n";
	}
	delete vptr;
}

/* Function to modify Visitor Details */
void Visitor::modifyVisitor()
{
	string pan;
	Validations *vptr = new Validations(); // validator class. Includes validations for pan,name,phone,mail,etc
	
	cout<<"\n\n-------------*** Modify Visitor ***-------------\n\n";
	while(1)
	{
		cout<<"Enter Visitor PAN: ";
		cin>>pan;
		if(vptr->validate_pan(pan)) break; // validation for pan. Returns True if PAN is valid else returns False
		else
		{
			cout<<"\n------------------\n";
			cout<<"Enter Valid PAN\n";
			cout<<"------------------\n\n";
		}
	}
	
	if(!vptr->isValidVisitor(pan)) // Function to check if visitor exists. Returns True if exists else Returns False
	{
		cout<<"\n----------------------------------------\n";
		cout<<"Cannot Modify! Visitor does not exist\n";
		cout<<"----------------------------------------\n";
	}
	else
	{	
		ifstream in;
		in.open("Files/visitor_details.txt");
		
		if(!in.is_open())
		{
			cout<<"\nError! Cannot Open File\n";
			exit(1);
		}
		
		int ch,ind;
		
		vector<vector<string>>record = IO_FILE::readData(in); // reading all records from file
		in.close();
		
		for(int i=0; i<(int)record.size(); ++i)
		{
			if(record[i][0] == pan) // searching a record based on PAN
			{
				ind = i; 
				break;
			}
		}
		
		cout<<"\n1. Update First Name\n2. Update Last Name\n3. Update Mail\n4. Update Phone\n0. Go Back\n\n";
		while(1)
		{
			cout<<"Enter choice: ";
			cin>>ch;
			if(ch >= 0 && ch <= 4) break;
			else
			{
				cout<<"\n---------------------\n";
				cout<<"Enter Valid Choice\n";
				cout<<"---------------------\n\n";
			}
		}
			
		switch(ch)
		{
			case VISITOR_UPDATE_FNAME:
				while(1)
				{
					cout<<"\nEnter First Name: ";
					cin>>record[ind][1];
					if(vptr->validate_name(record[ind][1])) break; // validation for Name. Returns True if Name is valid else returns False
					else
					{
						cout<<"\n------------------\n";
						cout<<"Enter Valid Name\n";
						cout<<"------------------\n";
					}
				}
				break;
			case VISITOR_UPDATE_LNAME:
				while(1)
				{
					cout<<"\nEnter Last Name: ";
					cin>>record[ind][2];
					if(vptr->validate_name(record[ind][2])) break; // validation for Name. Returns True if Name is valid else returns False
					else
					{
						cout<<"\n------------------\n";
						cout<<"Enter Valid Name\n";
						cout<<"------------------\n";
					}
				}
				break;
			case VISITOR_UPDATE_MAIL:
				while(1)
				{
					cout<<"\nEnter Mail: ";
					cin>>record[ind][3];
					if(vptr->validate_mail(record[ind][3])) break; // validation for Mail. Returns True if Mail is valid else returns False
					else
					{
						cout<<"\n------------------\n";
						cout<<"Enter Valid Mail\n";
						cout<<"------------------\n";
					}
				}
				break;
			case VISITOR_UPDATE_PHONE:
				while(1)
				{
					cout<<"\nEnter Phone: ";
					cin>>record[ind][4];
					if(all_of((record[ind][4]).begin(),(record[ind][4]).end(),::isdigit) && vptr->validate_phone(stol(record[ind][4])))// checking if phone number entered contains characters or digits
					{	
						break; // validation for Phone. Returns True if Phone is valid else returns False
					}
					else
					{
						cout<<"\n------------------\n";
						cout<<"Enter Valid Phone\n";
						cout<<"------------------\n";
					}
				}
				break;
			case 0:
				break;
		}
			
		if(ch != 0)
		{
			ofstream out;
			out.open("Files/visitor_details.txt");
			
			if(!out.is_open())
			{
				cout<<"\nError! Cannot Open File\n";
				exit(1);
			}
			
			for(int i=0; i<(int)record.size(); ++i)
			{
				out<<record[i][0]<<","<<record[i][1]<<","<<record[i][2]<<","<<record[i][3]<<","<<record[i][4]<<"\n";
			}
			out.close();	
				
			cout<<"\n---------------------------------";
			cout<<"\nYour Details have been Modified\n";
			cout<<"---------------------------------\n";
		}
	}
	delete vptr;
}

/* Function to display Visitor Details */
void Visitor::displayVisitor()
{
	string pan,line,inter;
	bool flg = false;
	Validations *vptr = new Validations(); // validator class. Includes validations for pan,name,phone,mail,etc
	
	cout<<"\n\n-------------*** Display Visitor ***-------------\n\n";
	while(1)
	{
		cout<<"Enter Visitor PAN: ";
		cin>>pan;
		if(vptr->validate_pan(pan)) break; // validation for pan. Returns True if PAN is valid else returns False
		else
		{
			cout<<"\n------------------\n";
			cout<<"Enter Valid PAN\n";
			cout<<"------------------\n\n";
		}
	}
	
	ifstream in;
	in.open("Files/visitor_details.txt");
		
	if(!in.is_open())
	{
		cout<<"\nError! Cannot Open File\n";
		exit(1);
	}
		
	while(getline(in,line)) // reading record from file line by line
	{
		istringstream ss(line);
		getline(ss,inter,','); // reading single value seperated by comma
		this->setPan(inter); // setting PAN
		
		if(inter == pan)
		{
			flg = true;
			getline(ss,inter,',');
			this->setFname(inter);  // setting First Name
			
			getline(ss,inter,',');
			this->setLname(inter); // setting Last Name
			
			getline(ss,inter,',');
			this->setMail(inter); // setting Mail
			
			getline(ss,inter,',');
			this->setPhone(stol(inter)); // Setting Phone. Using stol() to convert string to long 
			
			break;
		}
		line.clear();
	}
	
	in.close();
	
	if(!flg)
	{
		cout<<"\n----------------------------------------\n";
		cout<<"Cannot Display! Visitor does not exist\n";
		cout<<"----------------------------------------\n";
	}
	else
	{	
		cout<<"\nVisitor Details: \n\n";
		cout<<"PAN: "<<this->getPan()<<"\n";
		cout<<"Name: "<<this->getFname()<<" "<<this->getLname()<<"\n";
		cout<<"Mail: "<<this->getMail()<<"\n";
		cout<<"Phone: "<<this->getPhone()<<"\n";
	}
	delete vptr;
}
