CC = g++
CFLAGS = -Wall -g

PERSON_DIR = Person
EMPLOYEE_DIR = Employee
VISITOR_DIR = Visitor
VISIT_DIR = Visit
GLOBAL_DIR = Global_Functions
ADMIN_DIR = Admin
TENANT_DIR = Tenant
VALIDATIONS_DIR = Validations
HOUSE_DETAILS_DIR = House_Details
OWNER_DIR = Owner

all: tms

tms: TMSclientcode.o TMSdef.o person_def.o recep_employee_def.o visitor_def.o visit_def.o global_def.o admin_def.o admin_employee_def.o tenant_def.o validations_def.o housedetails_def.o owner_def.o
	$(CC) $(CFLAGS) TMSclientcode.o TMSdef.o person_def.o recep_employee_def.o visitor_def.o visit_def.o global_def.o admin_def.o admin_employee_def.o tenant_def.o validations_def.o housedetails_def.o owner_def.o -o tms
	
TMSclientcode.o: TMSclientcode.cpp
	$(CC) $(CFLAGS) -c TMS.h TMSclientcode.cpp
	
TMSdef.o: TMSdef.cpp
	$(CC) $(CFLAGS) -c TMS.h TMSdef.cpp
	
person_def.o: $(PERSON_DIR)/person_def.cpp
	$(CC) $(CFLAGS) -c $(PERSON_DIR)/person.h $(PERSON_DIR)/person_def.cpp
	
recep_employee_def.o: $(EMPLOYEE_DIR)/recep_employee_def.cpp
	$(CC) $(CFLAGS) -c $(EMPLOYEE_DIR)/employee.h $(EMPLOYEE_DIR)/recep_employee_def.cpp
	
visitor_def.o: $(VISITOR_DIR)/visitor_def.cpp
	$(CC) $(CFLAGS) -c $(VISITOR_DIR)/visitor.h $(VISITOR_DIR)/visitor_def.cpp
	
visit_def.o: $(VISIT_DIR)/visit_def.cpp
	$(CC) $(CFLAGS) -c $(VISIT_DIR)/visit.h $(VISIT_DIR)/visit_def.cpp
	
global_def.o: $(GLOBAL_DIR)/global_def.cpp
	$(CC) $(CFLAGS) -c $(GLOBAL_DIR)/global.h $(GLOBAL_DIR)/global_def.cpp

admin_def.o: $(ADMIN_DIR)/admin_def.cpp
	$(CC) $(CFLAGS) -c $(ADMIN_DIR)/admin.h $(ADMIN_DIR)/admin_def.cpp
	
admin_employee_def.o: $(EMPLOYEE_DIR)/admin_employee_def.cpp
	$(CC) $(CFLAGS) -c $(EMPLOYEE_DIR)/employee.h $(EMPLOYEE_DIR)/admin_employee_def.cpp

tenant_def.o: $(TENANT_DIR)/tenant_def.cpp
	$(CC) $(CFLAGS) -c $(TENANT_DIR)/tenant.h $(TENANT_DIR)/tenant_def.cpp
	
validations_def.o: $(VALIDATIONS_DIR)/validations_def.cpp
	$(CC) $(CFLAGS) -c $(VALIDATIONS_DIR)/validations.h $(VALIDATIONS_DIR)/validations_def.cpp
	
housedetails_def.o: $(HOUSE_DETAILS_DIR)/housedetails_def.cpp
	$(CC) $(CFLAGS) -c $(HOUSE_DETAILS_DIR)/housedetails.h $(HOUSE_DETAILS_DIR)/housedetails_def.cpp

owner_def.o: $(OWNER_DIR)/owner_def.cpp
	$(CC) $(CFLAGS) -c $(OWNER_DIR)/owner.h $(OWNER_DIR)/owner_def.cpp

clean: clean_tms clean_person clean_employee clean_visitor clean_visit clean_global clean_admin clean_tenant clean_validations clean_house_details clean_owner 

clean_person:
	rm $(PERSON_DIR)/*.gch
	
clean_employee:
	rm $(EMPLOYEE_DIR)/*.gch
	
clean_visitor:
	rm $(VISITOR_DIR)/*.gch
	
clean_visit:
	rm $(VISIT_DIR)/*.gch
	
clean_global:
	rm $(GLOBAL_DIR)/*.gch
	
clean_admin:
	rm $(ADMIN_DIR)/*.gch
	
clean_tenant:
	rm $(TENANT_DIR)/*.gch
	
clean_validations:
	rm $(VALIDATIONS_DIR)/*.gch
	
clean_house_details:
	rm $(HOUSE_DETAILS_DIR)/*.gch

clean_owner:
	rm $(OWNER_DIR)/*.gch
	
clean_tms:
	rm *.o *.gch tms

