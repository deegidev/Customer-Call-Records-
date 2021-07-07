/*DRIVER*/

//#include <iostream>
//#include <string>
//#include <fstream>
//
//
//using namespace std;
#include "call_class.h"

//driver to test the functionality of your class.
int main()
{
	//int tester; //to keep black box open

	cout << "TEST1: Testing the Default Constructor, is_full and double_size\n";
	call_class MyClass;
	MyClass.process();
	cout << "Finish TEST1: testing the default constructor\n\n\n\n";

	cout << "Test2: Testing add, double_size, process, and is_full() \n";
	MyClass.add();
	MyClass.process();
	cout << "Finish TEST2\n\n\n\n";

	cout << "Test3: Testing operator-, serach, and is_empty\n";
	MyClass - "5617278899" - "9546321555" - "1234567890";
	MyClass.process();
	cout << "Finish TEST3\n\n\n\n";

	cout << "Test4: Testing operator<<\n\n";
	cout << MyClass << endl;
	MyClass.process();
	cout << "Finish TEST4\n\n\n\n";



	cout << "Test5: Testing copy constructor\n\n";

	call_class YourClass = MyClass;
	cout << YourClass << endl;
	MyClass.process();
	cout << "Finish TEST5\n\n\n\n";

	cout << "The destructor will be called automatically\n";

	//cin >> tester;

	return 0;
}




