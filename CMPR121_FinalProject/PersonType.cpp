/*
    CMPR-121 SPRING 2023
    FINAL PROJECT: PART A
    AUTHOR: ANTHONY RODRIGUEZ
    COLLABORATORS: TAD MARTINEZ, DECLAN TRAN, JACOB WASHINGTON
    DESCRIPTION: PERSON_TYPE CLASS IMPLEMENTATION FILE
*/

#include "PersonType.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
PersonType::PersonType() {
    SSN = 0;
}

// Overloaded constructor
PersonType::PersonType(string fName, string lName, int ssn) {
    firstName = fName;
    lastName = lName;
    SSN = ssn;
}

// Setter function to set person's info
void PersonType::setPersonInfo(string fName, string lName, int ssn) {
    firstName = fName;
    lastName = lName;
    SSN = ssn;
}

// Getter function to get person's first name
string PersonType::getFirstName() const {
    return firstName;
}

// Getter function to get person's last name
string PersonType::getLastName() const {
    return lastName;
}

// Getter function to get person's SSN
int PersonType::getSSN() const {
    return SSN;
}

// Function to print person's name in last name, first name format
void PersonType::printName() const {
    cout << lastName << ", " << firstName << endl;
}

// Function to print person's info, including SSN
void PersonType::printPersonInfo() const {
    printSSN(); // calls printSSN() function to print SSN in ###-##-####
    cout << " " << firstName << " " << lastName << endl;
}

// Function to print person's SSN in ###-##-#### format
void PersonType::printSSN() const {
    string SSN_String = to_string(SSN); // converts SSN int to a string
    for (int i = 0; i < SSN_String.size(); i++) { // loops through SSN_String and prints in ###-##-#### format
		if (i == 3 || i == 5) {
			cout << '-' << SSN_String[i];
        }
        else {
            cout << SSN_String[i];
        };
    }
}

// Destructor
PersonType::~PersonType() {
    // left empty
}

