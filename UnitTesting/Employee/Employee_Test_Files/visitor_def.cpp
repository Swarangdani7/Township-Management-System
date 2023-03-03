#include "visitor.h"

Visitor::Visitor():Person(){} // using member initializer list

Visitor::Visitor(const string& pan, const string& fname, const string& lname, long phone, const string& mail):Person(fname,lname,pan,phone,mail){} // using member initializer list

/* Function to accept Visitor Details */
bool Visitor::acceptVisitor(string pan, string fname, string lname, long ph, string mail)
{ 
	bool flg = true;
	Validations *vptr = new Validations(); // validator class. Includes validations for pan,name,phone,mail,etc
	
	if(vptr->validate_pan(pan))
	{
		this->setPan(pan);
	}
	else flg = false;
	
	if(vptr->validate_name(fname))
	{
		this->setFname(fname);
	}
	else flg = false;

	if(vptr->validate_name(lname))
	{
		this->setLname(lname);
	} 
	else flg = false;
	
	if(vptr->validate_mail(mail))
	{
		this->setMail(mail);	
	} 
	else flg = false;
	
	string phone = to_string(ph);
	if(all_of(phone.begin(),phone.end(),::isdigit) && vptr->validate_phone(stol(phone))) // checking if phone number entered contains characters or digits	 and it should contain 10 digits
	{
		this->setPhone(stol(phone));
	}
	else flg = false;
	
	if(flg)	
	{
		fstream out;
		out.open("Employee_Test_Files/visitor_details.txt", ios::app);
			
		if(!out.is_open())
		{
			cout<<"\nLine No: 103 :: Error! Cannot Open File\n";
			exit(1);
		}
			
		out<<this->getPan()<<","<<this->getFname()<<","<<this->getLname()<<","<<this->getMail()<<","<<this->getPhone()<<"\n";
		out.close();
	}
	delete vptr;
	return flg;
}
