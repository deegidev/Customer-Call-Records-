//IMPLEMENTATION -- CALL_CLASS.CPP
#include "call_class.h"

/************************************************************************************************************************************/
//Name: default constructor
//Precondition: 
//Postcondition: 
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record, 
//call_DB. If the count because equal to the size the function double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
call_class::call_class()
{

	count = 0;
	size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	call_DB = new call_record[size]; //call_DB is an array of call records with a capacity of 5 

	ifstream in;
	in.open("callstats_data.txt");

	if (in.fail()) //if file not found, opened, etc correctly 
	{
		cout << "Input file did not open orrectly" << endl;
		exit(1); //exit program 
	}
	while (!in.eof()) //while file is open, until end of file 
	{

		if (is_full()) //CHANGED LINE
		{
			//cout << endl << "Call_DataBase is full. Calling Double_Size() to add more space to capacity..." << endl;
			double_size();
		}

		in >> call_DB[count].firstname;
		in >> call_DB[count].lastname;
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;

		count++;

	}
	in.close();
}

/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: 
//Postcondition: 
//Decription: performs a deep copy.
/************************************************************************************************************************************/
call_class::call_class(const call_class & org)
{
	cout << "Copy Constructor has been called\n";
	(*this).size = org.size;
	this->count = org.count;

	call_DB = new call_record[size];

	for (int i = 0; i < count; i++)
	{
		call_DB[i] = org.call_DB[i];
	}

}

/***********************************************************************************************************************************/
//Name: is_empty
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/
bool call_class::is_empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
bool call_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int call_class::search(const string key)
{

	for (int index = 0; index < count; index++)
	{
		if (call_DB[index].cell_number == key)
		{
			return index;
		}
	}
		return -1;
	
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: adds the information for a call to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void call_class::add()
{
	count++;

	if (is_full()) {
		double_size();
	}

	call_record temp;

	cout << "Please enter First Name:" << endl;
	cin >> temp.firstname;
	cout << "Please enter Last Name:" << endl;
	cin >> temp.lastname;
	cout << "Please enter the Cell Number" << endl;
	cin >> temp.cell_number;
	cout << "Please enter number of relays:" << endl;
	cin >> temp.relays;
	cout << "Please enter the call length:" << endl;
	cin >> temp.call_length;

	call_DB[count - 1] = temp;

}



/********************************************************************************************************************************/
//Name: operator-
//Precondition: 
//Postcondition: 
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
call_class & call_class::operator-(const string key)
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
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: 
//Postcondition: 
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void call_class::double_size()
{
	size *= 2;
	call_record *temp = new call_record[size];

	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;
	call_DB = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: 
//Postcondition: 
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void call_class::process()
{

	for (int i = 0; i < count; i++) //loop to keep filling values at given index=i until reached count, which = all filled index locations
	{
		//Step 1: Calculate net cost
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
		}

		//Calculate call taxes
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;

		//Step 3: Calculate net cost
		call_DB[i].net_cost = (call_DB[i].relays / 50.0 * 0.40 * call_DB[i].call_length);

		//Step 4: Calculate total cost of call
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
	}
}


/****************************************************************************************************************************/
//Name: operator<<
//Precondition: 
//Postcondition: 
//Decription: Overloading operator<< as a friend function. Prints every field of every call_record in call_DB 
//                   formatted to the screen and a file called "stats7_output.txt".
/***************************************************************************************************************************/
ostream & operator<<(ostream & out, call_class & Org)
{
	for (int i = 0; i<Org.count; i++)
	{
		out << Org.call_DB[i].firstname << "  " << Org.call_DB[i].lastname
			<< "  " << Org.call_DB[i].relays << "  " << Org.call_DB[i].cell_number
			<< "  " << Org.call_DB[i].call_length << endl;
	}

	//Put code to OPEN and CLOSE an ofstream and print to the file "stats7_output.txt".
	ofstream output;
	output.open("stats7_output.txt");

	for (int i = 0; i<Org.count; i++)
	{
		output << Org.call_DB[i].firstname << "  "
			<< Org.call_DB[i].lastname << "  "
			<< Org.call_DB[i].relays << "  "
			<< Org.call_DB[i].cell_number << "  "
			<< Org.call_DB[i].call_length << "  "
			<< Org.call_DB[i].net_cost << "  "
			<< Org.call_DB[i].tax_rate << "  "
			<< Org.call_DB[i].call_tax << "  "
			<< Org.call_DB[i].total_cost << "  "
			<< endl;
	}

	output.close();
	return out;  //must have this statement
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: 
//Postcondition: 
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
call_class::~call_class()
{
	cout << "	Although this fucntion was never called in main() or any other functions, "
		<< "this destructor function was called at the end of your program."
		<< "	All your call_stats7 functions have been successfully implemented. Goodbye (:"
		<< endl;
			

}
