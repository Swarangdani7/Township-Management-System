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

HouseDetails Tenant::getHouseObject()
{
	return this->hd;
}

//defining function to perform add Tenant
bool Tenant::addTenant(string firstname, string lastname, string pannum, long phonenum, string mail, string hid, string htype)
{
	string str,temp;
	int count=0;
	Tenant *tptr = new Tenant();
	Validations *vptr = new Validations();
	tenantId="T999";
	bool flg = true;
	
	ifstream in;
	in.open("Admin_Test_Files/tenant_details.txt");
	if(!in.is_open())
	{
		cout<<"\n(Tenant_def): Line No. 36 :: Cannot open file...!!\n";
		exit(1);
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
	
	in.close();
	
	string rand = tenantId.substr(1);
	int id = stoi(rand);
	id++;
	string val = to_string(id);
	tenantId="T"+val;
	in.clear();
	in.seekg(0);
	
	
	if(vptr->validate_name(firstname)) setFname(firstname);
	else flg = false;
	
	if(vptr->validate_name(lastname)) setLname(lastname);
	else flg = false;
	
	if(vptr->validate_pan(pannum)) setPan(pannum);
	else flg = false;
	
	if(vptr->validate_phone(phonenum)) setPhone(phonenum);
	else flg = false;
	
	if(vptr->validate_mail(mail)) setMail(mail);
	else flg = false;
	
	if(vptr->validate_tenantHouseId(hid)) hd.setHouseId(hid);
	else flg = false;
	
	if(vptr->validate_houseType(htype)) hd.setHouseType(htype);
	else flg = false;
	
	if(flg)
	{
		ofstream out;
		out.open("Admin_Test_Files/tenant_details.txt",ios::app);
		if(!out.is_open())
		{
			cout<<"\n(tenant_def): Line No. 96 :: Cannot open file...!!\n";
			exit(0);
		}
		out<<tenantId<<","<<getFname()<<","<<getLname()<<","<<getPan()<<","<<getPhone()<<","<<getMail()<<","<<hd.getHouseId()<<","<<hd.getHouseType()<<endl;
		out.close();
	}
	return flg;
}
