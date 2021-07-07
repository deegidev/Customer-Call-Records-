/*
Name:	Daija Gibbs (2018)
Project: Customer Call Records
Description:	This program will process a dynamic array of call records using
classes and overloaded fucntions.
*/
#include <iostream>
//#include <string> 
//#include <fstream>

using namespace std;
class call_record
{
public:
string firstname; string lastname; string cell_number; int relays; int call_length; double net_cost; double tax_rate; double call_tax; double total_cost;
>J
class call_class
{
public:
call_class();
~call_class(); //de-allocates all memory allocate to call_DB by operator
new.
bool is_empty(); //inline implementation bool is_full();//inline implementation
int search(const string key);//returns location if item in listl; otherwise return -1
void add(); //adds a call record to call_DB
call_class Soperator-(const string key); //removes an item from the list void double_size(); void processQ;
friend ostream &operator<<(ostream &out_to_file, call_class &0rg); //prints 
all the elements in the
//list to the screen.
private:
int count; int size;
call_record *call_DB;
//Name: DEFAULT CONSTRUCTOR
//Precondition:	Before the functions is called we declared a reference to a
dynamic array of call records, the count of how many
//	values are currently stored in the array,
and a reference to the size of the array.
//Postcondition:	After the function executes the array has been initialiazed
with values from a file and new memory has been allocated
//	to the array to add new information to it.
//Decription:	Reads the data file of call information into the dynamic
array of call record. call_class::call_class()
{
count = 0;
size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
call_DB = new call_record[size]; //call_DB is an array of call records with a capacity of 5
ifstream in;
in.open("callstats_data.txt");
if (in.fail()) //if file not found, opened, etc correctly
{
cout << "Input file did not open orrectly" << endl; exit(l); //exit program
}
while (!in.eof()) //while file is open, until end of file
{
if (is_full()) //CHANGED LINE
{
//cout << endl << "Call_DataBase is full. Calling Double_Size() to add more space to capacity..." << endl;
double_size();
}
in >> call_DB[count].firstname; in >> call_DB[count].lastname; in >> call_DB[count].cell_number; 
call_stats7.cpp in >> call_DB[count].relays; in >> call_DB[count].call_length;
count++;
}
in.close();
}
//Name: IS_FULL()
//Precondition:	Before the function is called it is declared to return true
or false.
//Postcondition:	Checks if count holds the same value as size/the capacity of
the array
//Decription:	Returns true if call_DB is full,
bool call_class::is_full()
{
return count == size;
}
//Name: DOUBLE_SIZE()
//Precondition:	Before Double_size is called we have declared a dynamic
array of call records,
//	count/ the number of elements being used,
and size/ the capacity of the array.
//Postcondition:	A new array of call_reords with a size double of the orginal
has been created and all of the values from the
//	old array have been inserted into it. The
memory from the old array has been de-allocated and the new array has been //	given the same name as the old array.
//Decription:	Doubles the size (capacity) of call_DB
void call_class::double_size()
{
size *= 2;
call_record *temp = new call_record[size];
for (int i = 0; iccount; i++)
{
temp[i] = call_DB[i];
}
delete[] call_DB; call_DB = temp;
}
//Name: ADD()
//Precondition:	Before function is called we declared a dynamic array of
call records, with its count and size already intitialized.
//Postcondition:	Asked and got new name, relay and call length elements and 
cell_number.
//	We checked again to see if the array is full
after we included the new data,
//	and called Double_Size if Is_full returrned
true. Last, we called process to process all the new data.
//Decription:	Add new caller to call_DB; if call_DB is full, double_size
is called to increase the size of call_DB. void call_class::add()
{
// Get phone number from the user inside the add function for cell number cout << "\nWhat is your phone number?" << endl; cin >> call_DB[count].cell_number;
//prompt user for first and last names,relays and minutes inside Add. 
cout << "\nWhat is your first name?" << endl;
cin >> call_DB[count].firstname; 
cout << "What is your last name?" <<endl;
cin >> call_DB[count].lastname; 
cout << "How many relays?"<<endl;
cin >> call_DB[count].relays; 
cout << "What was your call length?" <<endl;
cin >> call_DB[count].call_length; 
count++;

if (is_full()) //If count == size? After count++, YES. --> count =20 and size = 20.
{
double_size(); //Does size=size*2. Then creates new array with the new [size] & deletes the old array.
}
process(); //Call process() if you are adding a new record
}

//Name: PROCESS()
//Precondition:	Before Process is called we declared a dynamic array of call
records.
//Postcondition:	Went through each element of the array and performed
calculations with them.
//Decription:	Calculate the net cost, tax rate, call tax and total cost
for every call record in call_DB. void call_class::process()
{
for (int i = 0; i < count; i++) //loop to keep filling values at given index=i until reached count, which = all filled index locations 
call_stats7.cpp //Step 1: Calculate net cost
call_DB[i].net_cost = (call_DB[i].relays / 50.0 * 0.40 * call_DB[i].call_length);
//Step 2: If/Else statement to creat condition for tax rate
if (0 <= call_DB[i].relays && call_DB[i].relays <= 5)
{
call_DB[i].tax_rate = .01;
}
else if (6 <= call_DB[i].relays && call_DB[i].relays <= 11)
{
call_DB[i].tax_rate = .03;
}
else if (12 <= call_DB[i].relays && call_DB[i].relays <= 20)
{
call_DB[i].tax_rate = .05;
}
else if (21 <= call_DB[i].relays && call_DB[i].relays <= 50)
{
call_DB[i].tax_rate = .08;
}
else if (call_DB[i].relays > 50)
{
call_DB[i].tax_rate = .12;
//Calculate call taxes
call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
//Step 3: Calculate net cost
call_DB[i].net_cost = (call_DB[i].relays / 50.0 * 0.40 * call_DB[i].call_length);
//Step 4: Calculate total cost of call
call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
}

//Name: OPERATOR-()
//Precondition:	Before remove is called we declared the formal parameters a
dynamic array of call records
//	and we have declared a const string to find
the cell_number in the array.
//Postcondition:	We have overloaded the - operator to use the search function
to get the elemenent in the array that we will be removing. 
call_stats7.cpp
//	We search the array for that element and
push the values from the next element into it and decriment //	the amoount of elements we have filled.
//Decription:	Remove key from call_DB if it is there by using instead
of a remove function.
call_class &call_class::operator-(const string key)
{
int location = search(key); //location is index if key is found, if array is empty will return -1
if (location != -1)
{
for (int index = location; index < count - 1; index++)
{
call_DB[index] = call_DB[index + 1];
}
count--;
}
return *this;
} //Name: SEARCHQ
//Precondition:	Before function is called it has declared a constant string
key/phone_number we will be searching for.
//Postcondition:	We checked to see if the array is empty and used the
returned value as the condition to begin checking the array for
//	the elemenent where key is found. We return
the element where key is found the the function that calls this function. //Decription:	Locates key in call_DB if it is there; otherwise -1 is
returned int call_class::search(const string key)
{
if (is_empty()) //Asks If, count = 0 is TRUE(l)? Return -1
// if NOT TRUE(0), which count = 21 at this
point, so NOT TRUE, return index
{
return -1;
}
for (int index = 0; index < count; index++)
{
if (call_DB[index].cell_number == key)
{
return index;
}
} 
}
//Name: IS_EMPTY()
//Precondition:	Before the function is called it is declared to return true
or false. And is passed a
//	count that holds the values of how many
elements are currently filled in the array.
//Postcondition:	Checks if count is 0/ is empty.
//Decription:	Returns true if call_DB is empty
bool call_class::is_empty()
{
return count == 0;
} //Name: OPERATOR<<()
//Precondition:	Before operator- is called it is used to print its right
operand to the screen.
//	Opeerator<< is declared as a friend of our
class.
//Postcondition:	When << is used and its right operand is an object of our
call_class it will print every element to both the screen and a file.
//Decription:	Prints every record of call_DB to the screen and to an
output file.
ostream &operator<<(ostream &out, call_class &Org)
{
/*cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2); */
for (int i = 0; i<Org.count; i++)
{
out << Org.call_DB[i].firstname	<<
<< Org.call_DB[i].lastname << "	"
<< Org.call_DB[i].relays << "	"
<< Org.call_DB[i].cell_number << " << Org.call_DB[i].call_length << " << Org.call_DB[i].net_cost << "	"
<< Org.call_DB[i].tax_rate << "
<< Org.call_DB[i].call_tax << "	"
<< Org.call_DB[i].total_cost << " << endl; 
call_stats7.cpp
//Put code to OPEN and CLOSE an ostream and print to the file "stats7_output.txt".
ofstream output;
output.open("stats7_output.txt");
for (int i = 0; i<0rg.count; i++)
{
output << Org.call_DB[i].firstname << "	"
<< Org.call_DB[i].lastname << "
<< Org.call_DB[i].relays << "	"
<< Org.call_DB[i].cell_number << "	"
<< Org.call_DB[i].call_length	<<	"	"
<< Org.call_DB[i].net_cost	<<	"
<< Org.call_DB[i],tax_rate	<<	"	"
<< Org.call_DB[i].call_tax	<<	"	"
<< Org.call_DB[i].total_cost << "
<< endl;
}
output.close();
return out; //must have this statement
}
//Name: DESTRUCTOR()
//Precondition:	There is memory allocated to our dynamic array of call
records.
//Postcondition:	The memory for our dynamic array of call records has been
de-allocated.
//Decription:	Is called automatically once we leave the scope to
de-allocated the memory that was allocated for our dynmaic array //	of call records.
call_class::~call_class()
{
cout << "	Although this fucntion was never called in main() or any
other functions, this destructor function was called at the end of your program." << endl;
cout << "	All your call_stats7 functions have been successfully
implemented. Goodbye (:" << endl << endl;
}
//driver to test the functionality of your class, int main()
{
//Test is_full() and double_size()
cout << "TEST1: Testing the Default Constructor, is_full and double_size\n"; call_class MyClass; 
call_stats7.cpp
cout << "Finished TEST1: testing the default constructor\n\n\n\n"; //Test 2 adds: process() and add()
cout << "Test2: Testing add, double_size, process, and is_full() \n" MyClass.add();
cout << "Finished TEST2\n\n\n\n";
//Test 3 adds: operator-(), seanch() and is_empty()
cout << "Test3: Testing operator-, serach, and is_empty\n";
MyClass - "5617278899" - "9546321555" - "1234567890"j cout << "Finished TEST3\n\n\n\n";
//Test 4 adds: operator<<()
cout << "Test4: Testing operator<<\n\n"j
cout << MyClass << endl;
cout << "Finished TEST4\n\n\n\n";
cout << "The destructor will be called automatically\n"; 
return 0;
