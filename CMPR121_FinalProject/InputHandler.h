#include <fstream>
#include <string>
#include "CandidateList.h"
void createCandidateList(std::ifstream& infile, CandidateList& candidateList)
{
	int ssn = 0;
	int allVotes[NUM_OF_CAMPUSES];
	std::string fName, lName;
	infile >> ssn;
	while (ssn != -999)
	{
		CandidateType newCandidate;
		infile >> fName;
		infile >> lName;
		newCandidate.setPersonInfo(fName, lName, ssn);
		for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByCampus(i, allVotes[i]);
		}
		candidateList.addCandidate(newCandidate);
		infile >> ssn;
	}
}

void readCandidateData(CandidateList& candidateList)
{
	std::ifstream infile;
	infile.open("C:/Users/jbenj/OneDrive/Desktop/School/Spring2023/CMPR-121/FinalProject/CMPR121_FinalProject/Candidate_data-1.txt");
	if (!infile)
	{
		std::cerr << "Input file does not exist." << std::endl;
		exit(1);
	}
	createCandidateList(infile, candidateList);
	infile.close();
}