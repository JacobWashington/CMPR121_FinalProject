/*
	CMPR-121 SPRING 2023
	FINAL PROJECT: PART A
	AUTHOR: JACOB WASHINGTON
	COLLABORATORS: TAD MARTINEZ, DECLAN TRAN, ANTHONY RODRIGUEZ
	DESCRIPTION: CANDIDATE_TYPE CLASS PROTOTYPE
*/

#pragma once
#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "PersonType.h"

const int NUM_OF_CAMPUSES = 4; // constant defining the number of participating campuses

class CandidateType : public PersonType
{
private:
	int numVotes; // total votes a candidate has received
	int campuses[NUM_OF_CAMPUSES]; // array of campus numbers

public:
	/****   DEFAULT CONSTRUCTOR   ****/
	CandidateType();

	/****   OVERLOAD CONSTRUCTOR   ****/
	CandidateType(std::string fName, std::string lName, int ssn);

	/****   UPDATES VOTES BY CAMPUS   ****/
	void updateVotesByCampus(int campusNum, int numVotes);

	/****   GETS TOTAL VOTES   ****/
	int getTotalVotes() const;

	/****   GETS VOTES BY CAMPUS   ****/
	int getVotesByCampus(int campusNum) const;

	/****   PRINTS PERSON INFO   ****/
	void printCandidateInfo() const;

	/****   PRINTS CANDIDATE TOTAL VOTES   ****/
	void printCandidateTotalVotes() const;

	/****   PRINTS CANDIDATE VOTES BY CAMPUS   ****/
	void printCandidateCampusVotes(int campusNum) const;

	/****   DESTRUCTOR   ****/
	~CandidateType();
};

#endif