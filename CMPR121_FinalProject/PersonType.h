/*
	CMPR-121 SPRING 2023
	FINAL PROJECT: PART A
	AUTHOR: ANTHONY RODRIGUEZ
	COLLABORATORS: TAD MARTINEZ, DECLAN TRAN, JACOB WASHINGTON
	DESCRIPTION: PERSON_TYPE CLASS PROTOTYPE
*/

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

class PersonType {
public:
	// Default constructor declaration
	PersonType();
	// Overloaded constructor declaration
	PersonType(std::string fName, std::string lName, int ssn);
	// Function to set the person's information
	void setPersonInfo(std::string fName, std::string lName, int ssn);
	// Function to get the person's first name
	std::string getFirstName() const;
	// Function to get the person's last name
	std::string getLastName() const;
	// Function to get the person's SSN
	int getSSN() const;
	// Function to print the person's full name
	void printName() const;
	// Function to print the person's information
	void printPersonInfo() const;
	// Function to print the person's SSN
	void printSSN() const;
	// Destructor declaration
	~PersonType();

private:
	// Member variables for the person's first name, last name, and SSN
	std::string firstName;
	std::string lastName;
	int SSN;
};

// End of the include guard
#endif
