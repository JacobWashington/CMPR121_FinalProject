/*
    CMPR-121 SPRING 2023
    COLLABORATORS: TAD MARTINEZ, DECLAN TRAN, JACOB WASHINGTON, ANTHONY RODRIGUEZ
    DESCRIPTION: MAIN PROGRAM
*/

#include <iostream>
#include "PersonType.h"
#include "CandidateType.h"

using namespace std;

const int SCC_NUM = 1;
const int SAC_NUM = 2;
const int OCC_NUM = 3;
const int CCC_NUM = 4;

int main() {

    CandidateType candidate1 = CandidateType("Al", "Gore", 634892156);
    CandidateType candidate2 = CandidateType("George W.", "Bush", 74269215);
    PersonType person1 = CandidateType("Abe", "Lincoln", 123658925);
    PersonType person2 = CandidateType("John", "Brown", 364721589);
    candidate1.printCandidateInfo();
	candidate2.printCandidateInfo();
    person1.printPersonInfo();
    person2.printPersonInfo();

    candidate1.~CandidateType();
    candidate2.~CandidateType();
    candidate1.printPersonInfo();

    return 0;
}