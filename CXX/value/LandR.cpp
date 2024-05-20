#include <iostream>

void printName(std::string& name)
{
	std::cout << name << std::endl;
}

void printName_const(const std::string& name)
{
	std::cout << name << std::endl;
}

void printName_Rref(std::string&& name)
{
	std::cout << name << std::endl;
}

int main()
{
	std::string firstName = "Harry";
	std::string lastName = "Potter";

	std::string fullName = firstName + lastName;


	/**************************************************************************/

	/**
	 * R-value: "Harry", "Potter", firstName + lastName (expressions)
	 * 
	 * L-value: firstName, lastName, fullName
	 * 
	 * L-value must have real memory location
	 */

	printName(fullName); // ok

	// printName("Harry"); // err
	printName(firstName + " " + lastName);
	std::cout << &(firstName + lastName) << std::endl;
	firstName + lastName = "";
	std::cout << firstName << "\n";
	std::cout << lastName << "\n";
	/**
	 * printName(std::string& name)
	 * 
	 * a reference cannot refer a R-value (a reference cannot be init with a R-value)
	 * 
	 */


	/**************************************************************************/

	printName_const("Harry"); // ok
	/**
	 * const reference can be init with a R-value
	 * 
	 * int a = 1;
	 * int &b = a; // ok
	 * 
	 * int &a = 1; // error
	 * 
	 * const &a = 1; // ok
	 * 
	 */


	/**************************************************************************/

	printName_Rref("Harry");

	return 0;
}
