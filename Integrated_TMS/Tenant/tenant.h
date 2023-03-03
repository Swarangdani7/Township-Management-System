//Tenant header file - "tenant.h"

#ifndef TENANT_H
#define TENANT_H
//including required user defined header files
#include "../Person/person.h"
#include "../House_Details/housedetails.h"

#define ADD_TENANT 1
#define UPDATE_TENANT 2
#define DELETE_TENANT 3

#define TENANT_UPDATE_FNAME 1
#define TENANT_UPDATE_LNAME 2
#define TENANT_UPDATE_PAN 3
#define TENANT_UPDATE_PHONE 4
#define TENANT_UPDATE_EMAIL 5
#define TENANT_UPDATE_HOUSEID 6 

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
		
		//user defined functions to be performed in tenant
		void tenantMenu();
		void addTenant();
		void deleteTenant();
		void updateTenant();
		void displayTenant();
		
	//all attributes are declared as private
	private:
		string tenantId="\0";
		HouseDetails hd;
};
#endif
