#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/extensions/TestFactoryRegistry.h>
#include<cppunit/TestCase.h>
#include<cppunit/extensions/HelperMacros.h>

#include "Employee_Test_Files/employee.h"

/* class for testing Employee Module */
class EmployeeTestCase : public CppUnit::TestCase // inheriting base class TestCase 
{
		CPPUNIT_TEST_SUITE(EmployeeTestCase); // to start the test suite definition
			CPPUNIT_TEST(testConstructor); // test case 1 
			CPPUNIT_TEST(testEmployeeLogin); // test case 2
			CPPUNIT_TEST(testAcceptVisitor); // test case 3
 		CPPUNIT_TEST_SUITE_END(); // to end test suite definition	
    
	public:
	
		void testConstructor(); // testing constructor of Employee class
		void testEmployeeLogin(); // testing Employee Login
		void testAcceptVisitor(); // testing Accept Visitor function of Employee Menu
		
	private:
		Employee *obj;
};

CPPUNIT_TEST_SUITE_REGISTRATION(EmployeeTestCase);
		
void EmployeeTestCase::testConstructor() 
{
	obj = new Employee("E100","john@123","John","Doe","ABCDE1234P",7451256589,"john123@gmail.com");
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Employee ID.. ","E100" == obj->getEmpId());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Employee Password.. ","john@123" == obj->getEmpPassword());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched First Name.. ","John" == obj->getFname());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Last Name.. ","Doe" == obj->getLname());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched PAN..","ABCDE1234P" == obj->getPan());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Phone Number..",7451256589 == obj->getPhone());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Mail ID.. ","john123@gmail.com" == obj->getMail());
	
	delete obj;
}
		
void EmployeeTestCase::testEmployeeLogin() 
{
	obj = new Employee();
	
	obj->loginEmployee("E100","john@123");
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("E100" == obj->getEmpId() && "john@123" == obj->getEmpPassword()));
			
	delete obj;
}
		
void EmployeeTestCase::testAcceptVisitor() 
{
	Person *ptr = new Visitor();
	bool flg;
	
	flg = dynamic_cast<Visitor*>(ptr)->acceptVisitor("ABCDE1234P","Vinay","Singh",7215489892,"vinaysingh@gmail.com"); // returns true if visitor is accepted without errors
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Visitor PAN.. ","ABCDE1234P" == ptr->getPan());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched First Name.. ","Vinay" == ptr->getFname());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Last Name.. ","Singh" == ptr->getLname());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Phone Number..",7215489892 == ptr->getPhone());
			
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Mail ID.. ","vinaysingh@gmail.com" == ptr->getMail());
	
	CPPUNIT_ASSERT(flg == true);
			
	delete ptr;
}

int main(int argc, char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run();

	return 0;
}
