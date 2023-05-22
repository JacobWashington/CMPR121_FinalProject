/*
	CMPR-121 SPRING 2023
	FINAL PROJECT: PART C
	AUTHOR: DECLAN TRAN
	COLLABORATORS: TAD MARTINEZ, ANTHONY RODRIGUEZ, JACOB WASHINGTON
	DESCRIPTION: CANDIDATE_LIST CLASS PROTOTYPE
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include <iostream>
#include "Node.h"

class CandidateList
{
private:
	Node* first;
	Node* last;
	static int count;

public:
	CandidateList(); // Default contructor

	// Setters
	void addCandidate(const CandidateType& candidate);

	// Getters
	int getWinner() const;
	bool searchCandidate(int SSN) const;
	void printCandidateName(int SSN) const;
	void printAllCandidates() const;
	void printCandidateCampusVotes(int SSN, int divisionNum) const;
	void printCandidateTotalVotes(int SSN) const;

	// Deconstructor & destroyer
	void destroyList();
	~CandidateList();
};

#endif
