/*
	CMPR-121 SPRING 2023
	FINAL PROJECT: PART C
	AUTHOR: DECLAN TRAN
	COLLABORATORS: TAD MARTINEZ, ANTHONY RODRIGUEZ, JACOB WASHINGTON
	DESCRIPTION: CANDIDATE_LIST CLASS IMPLEMENTATION FILE
*/

#include "CandidateList.h"

// Initializing count
int CandidateList::count = 0;

CandidateList::CandidateList()
{
	first = nullptr;
	last = nullptr;

}// Default contructor

// Setters
void CandidateList::addCandidate(const CandidateType& candidate)
{
	if (first == nullptr) // If first node
	{
		first = new Node(candidate, nullptr);
		last = first; // One node, first and last same
	}
	else // Add new node to end of list
	{
		// Create new node
		Node* temp = new Node(candidate, nullptr);

		Node* lastNode = first;

		// Go to end of list
		while (lastNode->getLink() != nullptr)
		{
			lastNode = lastNode->getLink();
		}

		// Add node to end of list
		lastNode->setLink(temp);

		temp = nullptr; // Dangling pointer
	}

	// Increment count for new object
	count++;
}

// Getters
int CandidateList::getWinner() const
{
	// Create variable for most votes and winner
	int mostVotes = 0;
	CandidateType winner;

	// Make sure nodes exist
	if (this->first != nullptr)
	{
		for (Node* curNode = this->first; curNode != nullptr; curNode = curNode->getLink())
		{
			CandidateType candidate = curNode->getCandidate();
			if (candidate.getTotalVotes() > mostVotes)
			{
				// Update higest votes and current winner
				mostVotes = candidate.getTotalVotes();
				winner = candidate;
			}
		}

		return winner.getSSN();
	}
	else
	{
		// List is empty
		std::cout << "=> List is empty.\n\n";
		return 0;
	}
}

bool CandidateList::searchCandidate(int SSN) const
{
	// Create int for found and current node
	bool found = false;
	Node* curNode = first;

	// Check if list is empty
	if (first == nullptr)
	{
		std::cout << "=> List is empty.\n\n";
		return false;
	}

	while (!found && curNode != nullptr)
	{
		// Access candidates
		CandidateType temp = curNode->getCandidate();

		if (SSN == temp.getSSN())
		{
			// Found matching SSN
			found = true;
		}

		// Move to next node
		curNode = curNode->getLink();
	}

	// Display if SSN not found
	if (!found)
	{
		std::cout << "=> SSN not in the list.\n\n";
	}

	curNode = nullptr; // Dangling pointer

	if (found)
		return true;
	else
		return false;
}

void CandidateList::printCandidateName(int SSN) const
{
	// Create int for found and current node
	bool found = false;
	Node* curNode = first;

	// Check if list is empty
	if (first == nullptr)
	{
		std::cout << "=> List is empty.\n\n";
	}
	else
	{
		while (!found && curNode != nullptr)
		{

			// Access candidates
			CandidateType temp = curNode->getCandidate();

			if (SSN == temp.getSSN())
			{
				// Found matching SSN
				found = true;

				// Print name
				temp.PersonType::printName();
				std::cout << "\n";
			}

			// Move to next node
			curNode = curNode->getLink();
		}

		if (!found)
		{
			std::cout << "=> SSN not in the list.\n\n";
		}
	}

	curNode = nullptr; // Dangling pointer
}

void CandidateList::printAllCandidates() const
{
	// Test if list empty
	if (first != nullptr)
	{
		for (Node* curNode = first; curNode != nullptr; curNode = curNode->getLink())
		{
			// Access candidates
			CandidateType temp = curNode->getCandidate();

			// Print info
			temp.printCandidateInfo();
			std::cout << "\n";
		}
	}
	else
	{
		// List is empty
		std::cout << "=> List is empty.\n\n";
	}
}

void CandidateList::printCandidateCampusVotes(int SSN, int divisionNum) const
{
	// Create int for found and current node
	bool found = false;
	Node* curNode = first;

	// Check if list is empty
	if (first == nullptr)
	{
		std::cout << "=> List is empty.\n\n";
	}
	else
	{
		while (!found && curNode != nullptr)
		{
			// Access candidates
			CandidateType temp = curNode->getCandidate();

			if (SSN == temp.getSSN())
			{
				// Found matching SSN
				found = true;

				// Print votes for campus
				std::cout << "Votes for ";
				switch (divisionNum)
				{
				case 1:
					std::cout << "Santiago Canyon College: ";
					break;
				case 2:
					std::cout << "Santa Ana College: ";
					break;
				case 3:
					std::cout << "Orange Coast College: ";
					break;
				case 4:
					std::cout << "Coastline Community College: ";
					break;
				}

				std::cout << temp.getVotesByCampus(divisionNum) << "\n\n";
			}

			// Move to next node
			curNode = curNode->getLink();
		}
	}

	curNode = nullptr; // Dangling pointer
}

void CandidateList::printCandidateTotalVotes(int SSN) const
{
	// Create int for found and current node
	bool found = false;
	Node* curNode = first;

	// Check if list is empty
	if (first == nullptr)
	{
		std::cout << "=> List is empty.\n\n";
	}
	else
	{
		while (!found && curNode != nullptr)
		{
			// Access candidates
			CandidateType temp = curNode->getCandidate();

			if (SSN == temp.getSSN())
			{
				// Found matching SSN
				found = true;

				// Print total votes
				std::cout << "Total Votes: " << temp.getTotalVotes() << "\n\n";

			}

			// Move to next node
			curNode = curNode->getLink();
		}

	}
	curNode = nullptr; // Dangling pointer
}

// Deconstructor & destroyer
void CandidateList::destroyList()
{
	// Create pointer for second node
	Node* temp = first;

	while (temp != nullptr)
	{
		// Assign temp to next node
		temp = temp->getLink();

		// Destroy node
		delete first;

		// Set first to new first
		first = temp;
	}

	// Reset variables
	last = nullptr;
	count = 0;
}

CandidateList::~CandidateList()
{
	destroyList();
}