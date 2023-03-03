//this file contains headers to be used in the client code,it is the header file to be included in the client code

#ifndef TMS_H
#define TMS_H

#include<iostream>
#include<cstring>
/*this is the user defined header
 file containing function declarations, macros and definitions of the structures used in the employee's module*/
//#include"Employee/employee.h"

/*this is the user defined header
 file containing function declarations, macros and definitions of the structures used in the admin's module*/
#include"Admin/admin.h"

//various macros used in the module
#define CLIENT_EMPLOYEE 2
#define CLIENT_ADMIN 1
#define CLIENT_EXIT 0

using namespace std;

//***these are the various declarations of the functions used in the client code***

//functions to display menu 
void displayMenu();

//functions to get user's choice
void getChoice();

#endif
