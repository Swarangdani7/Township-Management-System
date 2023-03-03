#include"validations.h"

bool Validations::validate_phone(long phone)
{
	int count =0;
	while(phone>0)
	{
		count++;            // checking count of phone_no
		phone = phone/10;
	}
	// to see if phone_no count is  equal to 10 or not
	if (count == 10)
		return true;
	else
		return false;
}

bool Validations::validate_mail(const string& mail)
{
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(mail,pattern);
}
	
bool Validations::validate_name(const string &str)
{
	int n,i,check;
	n=str.length();
	for(i=0;i<n;i++)
	{
		if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || str[i]==' ')
			check=0;
		else
			return false;
	}
	
	
	if(check==0)  //To check whether the name is valid
		return true;
	else
		return false;
}

bool Validations::validate_date(int day,int mon,int year)
{
	if(mon < 1 || mon > 12) 
		return false;
	if(year < 1000 || year > 2023)
	 	return false;
	
	if(mon == 2){
		if(day < 0 || day > 29) 
			return false;
		if(day == 29){
			if(year % 4 != 0) 
				return false;
			if(year % 100 == 0 && year % 400 != 0) 
				return false;
		}
	}
	else if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12){
		if(day < 1 || day > 31) 
			return false;
	}
	else{
		if(day < 1 || day > 30) 
			return false;
	}
	
	return true;
}

bool Validations::validate_houseType(const string& type)
{
	if(type=="Row" || type=="ROW" || type=="row" || type=="flat" || type=="FLAT" || type=="Flat")
		return true;
	else
		return false;
}

bool Validations::validate_houseNum(const string& housenum)
{
	const regex pattern("[H]{1}[0-9]*");
	if(housenum.empty())
		return false;
	else if (regex_match(housenum, pattern))
		return true;
	else
		return false;
}

bool Validations::validate_pan(const string& pannum)
{
	const regex pattern ("[A-Z]{5}[0-9]{4}[A-Z]{1}");
	if(pannum.empty())
		return false;
	
	if (regex_match(pannum, pattern))
		return true;
	else
		return false;
}

bool Validations::checkPan(const string& pannum,ifstream& in)
{
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	while(getline(in,temp))
	{
		word.clear();
		stringstream data(temp);
		while(getline(data,con,','))
			word.push_back(con);
		lines.push_back(word);
	}
	for(int i=0;i<(int)lines.size();i++)
	{
		if(lines[i][3]==pannum || lines[i][4]==pannum)
			return true;
	}
	return false;
}

bool Validations::validate_tenantHouseId(string id)
{
	ifstream in;
	string str,temp;
	int count=0;
	in.open("Admin_Test_Files/house_details.txt");
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
				if(id==str)
					return true;
				count++;
			}
		}
		count=0;
	}
	return false;
}

bool Validations::validate_houseId(string id)
{
	if(id.find("H")==0)
		return true;
	else
		return false;
}
