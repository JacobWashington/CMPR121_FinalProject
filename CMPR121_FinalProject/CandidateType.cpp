/*
	CMPR-121 SPRING 2023
	FINAL PROJECT: PART B
	AUTHOR: JACOB WASHINGTON
	COLLABORATORS: TAD MARTINEZ, DECLAN TRAN, ANTHONY RODRIGUEZ
	DESCRIPTION: CANDIDATE_TYPE CLASS IMPLEMENTATION FILE
*/


#include "CandidateType.h"
#include <iostream>
#include <string>

/****   DEFAULT CONSTRUCTOR   ****/
CandidateType::CandidateType() {
	numVotes = 0; // initializes total votes to 0
	for (int i = 0; i < NUM_OF_CAMPUSES; i++) {
		campuses[i] = 0; // initializes campus votes to 0
	}
}

/****   OVERLOAD CONSTRUCTOR   ****/
CandidateType::CandidateType(std::string fName, std::string lName, int ssn)
	: PersonType(fName, lName, ssn) // initializes parent class with person data
{ 
	numVotes = 0; // initializes total votes to 0
	for (int i = 0; i < NUM_OF_CAMPUSES; i++) {
		campuses[i] = 0; // initializes campus votes to 0
	}
}

/****   UPDATES VOTES BY CAMPUS   ****/
void CandidateType::updateVotesByCampus(int campusNum, int numVotes) {
	campuses[campusNum - 1] = numVotes;

	CandidateType::numVotes += campuses[campusNum - 1];
}

/****   GETS TOTAL VOTES   ****/
int CandidateType::getTotalVotes() const {
	return numVotes;
}

/****   GETS VOTES BY CAMPUS   ****/
int CandidateType::getVotesByCampus(int campusNum) const {
	return campuses[campusNum-1];
}

/****   PRINTS PERSON INFO   ****/
void CandidateType::printCandidateInfo() const {
	printPersonInfo();
}

/****   PRINTS CANDIDATE TOTAL VOTES   ****/
void CandidateType::printCandidateTotalVotes() const {
	std::cout << getLastName() << ", " << getFirstName() << '\n';
	std::cout << "\tTotal Votes (all campuses): " << '\n';
}

/****   PRINTS CANDIDATE VOTES BY CAMPUS   ****/
void CandidateType::printCandidateCampusVotes(int campusNum) const {
	std::cout << getLastName() << ", " << getFirstName() << '\n';
	std::cout << "\tCampus " << campusNum << " total votes: " << '\n';
}

/****   DESTRUCTOR   ****/
CandidateType::~CandidateType() {
	// destructor, left empty
}