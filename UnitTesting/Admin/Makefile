CC = g++
CFLAGS = -Wall -g

all: test

test: test.o Admin_Test_Files/person_def.o Admin_Test_Files/admin_def.o Admin_Test_Files/tenant_def.o Admin_Test_Files/validations_def.o Admin_Test_Files/housedetails_def.o
	$(CC) $(CFLAGS) test.o Admin_Test_Files/person_def.o Admin_Test_Files/admin_def.o Admin_Test_Files/tenant_def.o Admin_Test_Files/validations_def.o Admin_Test_Files/housedetails_def.o -lcppunit -ldl -o test   
	
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
	
person_def.o: Admin_Test_Files/person_def.cpp
	$(CC) $(CFLAGS) -c Admin_Test_Files/person_def.cpp

admin_def.o: Admin_Test_Files/admin_def.cpp
	$(CC) $(CFLAGS) -c Admin_Test_Files/admin_def.cpp
	
tenant_def.o: Admin_Test_Files/tenant_def.cpp
	$(CC) $(CFLAGS) -c Admin_Test_Files/tenant_def.cpp
	
validations_def.o: Admin_Test_Files/validations_def.cpp
	$(CC) $(CFLAGS) -c Admin_Test_Files/validations_def.cpp
	
housedetails_def.o: Admin_Test_Files/housedetails_def.cpp
	$(CC) $(CFLAGS) -c Admin_Test_Files/housedetails_def.cpp
	
clean:
	rm *.o test
	rm Admin_Test_Files/*.o
