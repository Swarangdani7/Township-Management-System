#include"housedetails.h"

void HouseDetails::setHouseId(string id)
{
	this->houseId=id;
}

string HouseDetails::getHouseId()
{
	return this->houseId;
}

void HouseDetails::setHouseType(string type)
{
	this->houseType=type;
}

string HouseDetails::getHouseType()
{
	return this->houseType;
}

int HouseDetails::HouseMenu(string pid)
{
	int opt=0;
	int num;
	string id=pid;
	
		cout<<"\nChoose an option to update Owner details with Owner ID: "<<id<<endl;
		cout<<"1) Add House Details\n2) Update house details \n3) Delete House Details\nOption: ";
		cin>>opt;
	
	
		switch(opt)
		{
			case 1:
				num=AddHouseDetails(id);
				break;
			case 2:
				UpdateHouseDetails(id);
				num=0;
				break;
			case 3:
				DeleteHouseDetails(id);
				num=-1;
				break;
			
			default:
				cout<<"\nInvalid choice"<<endl;
				break;
		}
		return num;
	
}


int HouseDetails::AddHouseDetails(string id)
{
	int num;
	HouseDetails h;
	Validations v;
	vector<HouseDetails> houses;
	string house_type,house_no;
	cout<<"\nEnter number of houses you want to add: ";
	cin>>num;
	
	for(int i=0;i<num;i++)
	{
		cout<<"\nEnter house details for house "<<i+1<<" ::"<<endl;
		while(1)
		{
			cout<<"\nEnter house ID: ";
			cin>>house_no;
			if(v.validate_houseId(house_no))
			{
				
				if(!v.validate_ownerHouseId(house_no))
				{
					cout<<"\nHouse Id already exists !!!\n";
					
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
		
		h.setHouseId(house_no);
		h.setHouseType(house_type);
		
		houses.push_back(h);
	
	}
	
	ofstream h_out;
	h_out.open("Files/House_details.txt",ios::app);
	if(!h_out.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	
	for(int i=0;i<(int)houses.size();i++)
		h_out<<houses[i].getHouseId()<<","<<id<<","<<houses[i].getHouseType()<<endl;
	
	h_out.close();
	return num;

}


void HouseDetails::UpdateHouseDetails(string id)
{
	string hid,h_no,h_type;
	Validations v;
	cout<<"\nEnter house id: ";
	cin>>hid;
	int i;
	string con,temp;
	ifstream in;
	
	vector<vector<string>> h_lines;
	vector<string> word;
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
				
		if(h_lines[i][1]==id&& h_lines[i][0]==hid)
		{
			cout<<endl<<"Enter new house details: "<<endl;
			while(1)
			{
				cout<<"\nEnter house ID: ";
				cin>>h_no;
				if(v.validate_houseId(h_no))
					break;
				else
					cout<<"\nEnter valid House ID !!\n";
			}
			
			while(1)
			{
				cout<<"\nEnter house type: ";
				cin>>h_type;
				if(v.validate_houseType(h_type))
					break;
				else
					cout<<"\nEnter valid House Type...should be Row/Flat only !!\n";
			}
			
			h_lines[i][0]=h_no;
			h_lines[i][2]=h_type;
			break;
		}
	}
			
	ofstream out;
	out.open("Files/House_details.txt");
	if(!out.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	for(i=0;i<(int)h_lines.size();i++)
		out<<h_lines[i][0]<<","<<h_lines[i][1]<<","<<h_lines[i][2]<<endl;
	out.close();
}


void HouseDetails::DeleteHouseDetails(string id)
{
	string hid,h_type;
	cout<<"\nEnter House id: ";
	cin>>hid;
	int i;
	string con,temp;
	ifstream in;
	
	vector<vector<string>> h_lines;
	vector<string> word;
	vector<vector<string>>::iterator it;
	ifstream fin;
	fin.open("Files/House_details.txt");
	if(!fin.is_open())
	{
		cout<<"\nCannot open House_details file...!!\n";
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
        it=h_lines.begin();
        vector<vector<vector<string>>::iterator> index;
        int n = (int)h_lines.size();
		
	ofstream dout;
	dout.open("Files/house_history.txt",ios::app);
	   if(!dout.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
	for(i=0;i<(int)h_lines.size();i++)
	{
				
		if(h_lines[i][1]==id && h_lines[i][0]==hid)
		{
			
			cout<<endl<<"Found: "<<h_lines[i][0]<<","<<h_lines[i][1]<<","<<h_lines[i][2]<<endl;
			dout<<h_lines[i][0]<<","<<h_lines[i][1]<<","<<h_lines[i][2]<<endl;
			h_lines.erase(it);
			break;
		}
		advance(it,1);
	}
	if(i==n)
		cout<<"\nHouse details not found with the given Owner ID and House Id..:(\n";
	else
	{	

		ofstream out;
		out.open("Files/House_details.txt");
		if(!out.is_open())
		{
			cout<<"\nCannot open file...!!\n";
			exit(0);
		}
		
		for(i=0;i<(int)h_lines.size();i++)
			out<<h_lines[i][0]<<","<<h_lines[i][1]<<","<<h_lines[i][2]<<endl;
		out.close();
		
	}
	dout.close();
}
