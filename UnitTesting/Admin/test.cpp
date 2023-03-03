#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/extensions/TestFactoryRegistry.h>
#include<cppunit/TestCase.h>
#include<cppunit/extensions/HelperMacros.h>

#include "Admin_Test_Files/admin.h"

/* class for testing Admin Module */
class AdminTestCase : public CppUnit::TestCase // inheriting base class TestCase 
{
		CPPUNIT_TEST_SUITE(AdminTestCase); // to start the test suite definition
			CPPUNIT_TEST(testConstructor); // test case 1
			CPPUNIT_TEST(testAdminLogin); // test case 2
			CPPUNIT_TEST(testAddTenant); // test case 3
			
		CPPUNIT_TEST_SUITE_END(); // to end test suite definition	
    
	public:
		void testConstructor(); // testing constructor of Admin class
		void testAdminLogin(); // testing Admin Login
		void testAddTenant(); // testing Add Tenant functionality of Admin Module
		
	private:
		Admin *obj;
};

CPPUNIT_TEST_SUITE_REGISTRATION(AdminTestCase);

void AdminTestCase::testConstructor()
{
	obj = new Admin("A100","john@123","John","Doe","ABCDE1234P",7451256589,"john123@gmail.com");
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Admin ID.. ","A100" == obj->getAdminId());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Admin Password.. ","john@123" == obj->getAdminPassword());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched First Name.. ","John" == obj->getFname());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Last Name.. ","Doe" == obj->getLname());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched PAN..","ABCDE1234P" == obj->getPan());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Phone Number..",7451256589 == obj->getPhone());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Mail ID.. ","john123@gmail.com" == obj->getMail());
	
	delete obj;
}

void AdminTestCase::testAdminLogin()
{
	obj = new Admin();
	
	obj->validate_admin("A100","john@123");
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("A100" == obj->getAdminId() && "john@123" == obj->getAdminPassword()));
	
	delete obj;
}

void AdminTestCase::testAddTenant()
{
	Tenant *obj = new Tenant();
	bool flg;
	
	flg = dynamic_cast<Tenant*>(obj)->addTenant("Rahul","Sharma","ABCDE1234P",9421053568,"rahulsharma@gmail.com","H104","Row"); // function returns true if no errors are found
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched First Name.. ","Rahul" == obj->getFname());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! ! Mismatched Last Name.. ","Sharma" == obj->getLname());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched PAN..","ABCDE1234P" == obj->getPan());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Phone Number..",9421053568 == obj->getPhone());
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched Mail ID.. ","rahulsharma@gmail.com" == obj->getMail());	
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched House ID.. ","H104" == obj->getHouseObject().getHouseId());	
	
	CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Mismatched House Type.. ","Row" == obj->getHouseObject().getHouseType());
	
	CPPUNIT_ASSERT(flg == true);		
	
	delete obj;
}

int main(int argc, char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run();
	
	return 0;
}
