//this file contains various file declarations and use data in the client code.

/*this is the user defined header
 file containing function declarations, macros and definitions of the classes used*/
#include"TMS.h"

//functions to display menu 
void displayMenu()
{
    printf("\n----------------***WELCOME TO TOWNSHIP MANAGEMENT SYSTEM***----------------\n");
    printf("\n-----------------MENU------------------");
    printf("\n\t Enter:\n\t 1 if you are Admin\
	\n\t 2 if you are an Employee\
	\n\t 0 to exit\n");
	printf("---------------------------------------\n");
}//displayMenu() function ends.



/*getChoice() function takes no parameters and also do not returns any value.
It takes input from user the choice  and helps the user to traverse in the system*/
void getChoice()
{	
    int choice;
    do 		//infinite loop to run our program till exit(0) is encountered i.e. till user enters zero(0)
    {
        system("clear");
        displayMenu();
        cout<<"\n  Enter your choice: ";
        cin>>choice;
        cout<<"---------------------------------------\n";
        
        Person *ptr;
        switch(choice)
        {
            case CLIENT_EMPLOYEE:
            		ptr=new Employee();
            		dynamic_cast<Employee*>(ptr)->loginEmployee();
            		delete ptr;
            		break;
            case CLIENT_ADMIN:
            		ptr=new Admin();
            		dynamic_cast<Admin*>(ptr)->adminMenu();
            		delete ptr;
            		break;
            case CLIENT_EXIT:
		    	cout<<"\n                ***Thank You for using Township Managemnet System***\n\n";
		    	exit(0);
            default:
            	cout<<"\n  Invalid Choice, Enter a valid option\n";
            	cout<<"---------------------------------------\n";
            	getchar();
            	cout<<"\n  Enter any key to continue";
            	getchar();
        }
        
    }while(choice!= CLIENT_EXIT);
}//getChoice() function ends.
