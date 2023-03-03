#include "person.h"

Person::Person()
{
	fname="\0";
	lname="\0";
	pan="\0";
	phone=0;
	mail="\0";
}

Person::Person(const string &fname,const string &lname,const string &pan,long phone,const string &mail)
{
	this->fname=fname;
	this->lname=lname;
	this->pan=pan;
	this->phone=phone;
	this->mail=mail;
}

void Person::setFname(const string &fname)
{
	this->fname=fname;
}

void Person::setLname(const string &lname)
{
	this->lname=lname;
}

string Person::getFname()
{
	return this->fname;
}

string Person::getLname()
{
	return this->lname;
}

void Person::setPan(const string &pan)
{
	this->pan=pan;
}
string Person::getPan()
{
	return this->pan;
}

void Person::setPhone(long phone)
{
	this->phone=phone;
}
long Person::getPhone()
{
	return this->phone;
}

void Person::setMail(const string &mail)
{
	this->mail=mail;
}

string Person::getMail()
{
	return this->mail;
}
