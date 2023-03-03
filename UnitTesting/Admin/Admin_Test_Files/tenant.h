//Tenant header file - "tenant.h"

#ifndef TENANT_H
#define TENANT_H
//including required user defined header files
#include "person.h"
#include "housedetails.h"

using namespace std;

//class Tenant which inherits the Person class
class Tenant:public Person
{
	public:
		//Tenant default constructor
		Tenant()=default;
		
		//Tenant parameterised constructor (tenantId,fname,lname,pan,phone,email)
		Tenant(string,string,string,string,long,string);
		
		//getters and setters for tenant attributes
		string getTenantId();
		void setTenantId(string);
		HouseDetails getHouseObject();
		
		//user defined functions to be performed in tenant
		bool addTenant(string,string,string,long,string,string,string);
		
	//all attributes are declared as private
	private:
		string tenantId="\0";
		HouseDetails hd;
};
#endif
