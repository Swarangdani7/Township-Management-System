//def file of visit.h this is visit_def.cpp

#include"visit.h"

/*Function to add visit in the visit_details text file.
It neither takes any input nor returns anything*/
void Visit::addVisit()
{
	string pan;
	Validations *vptr = new Validations(); // validator class. Includes validations for pan,name,phone,mail,etc
	
	cout<<"\n\n-------------*** Add Visit Details ***-------------\n\n";
	while(1)
	{
		cout<<"Enter Visitor PAN: ";
		cin>>pan;
		if(vptr->validate_pan(pan))	// validation for pan. Returns True if PAN is valid else returns False
			 break; 
		else
		{
			cout<<"\n------------------\n";
			cout<<"Enter Valid PAN\n";
			cout<<"------------------\n\n";
		}
	}
	
	if(!vptr->isValidVisitor(pan)) // Function to check if visitor exists. Returns True if exists else Returns False
	{
		cout<<"\n--------------------------------------\n";
		cout<<"Cannot Add Visit! Visitor does not exists\n";
		cout<<"--------------------------------------\n";
	}
	
	else
	{
		string houseType;
		string houseNum;
		visitorPan=pan;
		
		while(1)
		{
			cout<<"Enter House Type visitor wants to visit(Row/Flat): ";
			cin>>houseType;
			if(vptr->validate_houseType(houseType))
				break;
			else
			{
				cout<<"\n------------------\n";
				cout<<"Enter Valid House Type!! A valid house type can be row or flat only.\n";
				cout<<"------------------\n\n";
			}
		}
		visitorHouseType=houseType;
		
		while(1)
		{
			cout<<"Enter House Number visitor wants to visit: ";
			cin>>houseNum;
			if(vptr->validate_houseNum(houseNum))
				break;
			else
			{
				cout<<"\n------------------\n";
				cout<<"Enter Valid House Number!! House Number starts with H followed by number.\n";
				cout<<"------------------\n\n";
			}
		}
		visitorHouseNum=houseNum;
		
		fstream out;
		out.open("Files/visit_details.txt", ios::app);
		
		if(!out.is_open())
		{
			cout<<"\nError! Cannot Open File\n";
			exit(1);
		}
		
				  out<<visitorPan<<","<<visitorHouseNum<<","<<visitorHouseType<<","<<Date::getDay()<<"/"<<Date::getMonth()<<"/"<<Date::getYear()<<","<<Time::getHour()<<":"<<Time::getMinute()<<":"<<Time::getSecond()<<"\n";
		
		out.close();
		
		cout<<"\n------------------------------------";
		cout<<"\nVisit Details Added Successfully\n";
		cout<<"------------------------------------\n";
	}
	delete vptr;
}

/*Function to display visit details from the visit_details text file.
It neither takes any input nor returns anything*/
void Visit::displayVisit()
{
	string pan,line,inter;
	vector<vector<string>> lines;
	vector<string> rec;
	bool flag = false;// to chech whether a visitor exists in file or not
	bool flag2=true;
	cout<<"\n\n-------------*** Display Visit Details ***-------------\n\n";
	cout<<"Enter Visitor PAN: ";
	cin>>pan;
	
	ifstream in;
	in.open("Files/visit_details.txt");
		
	if(!in.is_open())
	{
		cout<<"\nError! Cannot Open File\n";
		exit(1);
	}
		
	while(getline(in,line)) // reading record from file line by line
	{
		rec.clear();
		istringstream ss(line);
		while(getline(ss,inter,',')) // reading single value seperated by comma into inter variable and it will contain 1st value of the entry in the file i.e. pan no 
			rec.push_back(inter);
		lines.push_back(rec);
	}
	in.close();
	
	for(int i=0;i<(int)lines.size();i++)
	{
		if(lines[i][0]==pan)
		{
			flag=true;
			if(flag2)
			{
				flag2=false;
				cout<<"\nVisits Made by Visitor with PAN Number : "<<pan <<"\n\n";
			}
			
			cout<<"House Number: "<<lines[i][1]<<"\n";
			
			if(lines[i][2]=="row" || lines[i][2]=="ROW" || lines[i][2]=="Row" )
				cout<<"House Type: Row House"<<"\n";
			else
				cout<<"House Type: Flat"<<"\n";
				
			cout<<"Date: "<<lines[i][3]<<"\n";
			cout<<"Time: "<<lines[i][4]<<"\n";
			cout<<"-------------------------------------\n";
		}
	}
	if(!flag)
	{
		cout<<"\n----------------------------------------\n";
		cout<<"Cannot Display the visit details!!Visitor's visit details does not exist!!\n";
		cout<<"----------------------------------------\n";
	}
}

void Visit::adminDisplayVisit()
{
	string date,type;
	int f=0;
	cout<<"\nEnter date to display visits by date: ";
	cin>>date;
	
	int i;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("Files/visit_details.txt");
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
	cout<<"\nDetails of visit on Date: "<<date<<endl;
	cout<<"\nVisitor PAN Number\tVisited House No\tVisit Time\tHouse Type\n";
	for(i=0;i<(int)lines.size();i++)
	{
		if(date==lines[i][3])
		{
			f=1;
			if(lines[i][2]=="row" || lines[i][2]=="ROW" || lines[i][2]=="Row" )
				type="Row House";
			else
				type="Flat";
			
			cout<<lines[i][0]<<"\t\t"<<lines[i][1]<<"\t\t\t"<<lines[i][4]<<"\t"<<type<<endl;
		}
	}
	
	if(f==0)
		cout<<"\n\t\tNo Visits :(\n";
}
