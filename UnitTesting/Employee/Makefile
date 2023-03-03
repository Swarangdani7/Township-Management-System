CC = g++
CFLAGS = -Wall -g

all: test

test: test.o Employee_Test_Files/person_def.o Employee_Test_Files/recep_employee_def.o Employee_Test_Files/visitor_def.o  Employee_Test_Files/validations_def.o 
	$(CC) $(CFLAGS) test.o Employee_Test_Files/person_def.o Employee_Test_Files/recep_employee_def.o Employee_Test_Files/visitor_def.o  Employee_Test_Files/validations_def.o -lcppunit -ldl -o test   
	
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
	
person_def.o: Employee_Test_Files/person_def.cpp
	$(CC) $(CFLAGS) -c Employee_Test_Files/person_def.cpp
	
recep_employee_def.o: Employee_Test_Files/recep_employee_def.cpp
	$(CC) $(CFLAGS) -c Employee_Test_Files/recep_employee_def.cpp
	
visitor_def.o: Employee_Test_Files/visitor_def.cpp
	$(CC) $(CFLAGS) -c Employee_Test_Files/visitor_def.cpp
	
validations_def.o: Employee_Test_Files/validations_def.cpp
	$(CC) $(CFLAGS) -c Employee_Test_Files/validations_def.cpp
	
clean:
	rm *.o test
	rm Employee_Test_Files/*.o
