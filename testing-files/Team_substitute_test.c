#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "Team.h"


void check_invariant(CuTest* tc) {
	
	if(!(card(team) == 11)){
		CuFail(tc, "The invariant 'card(team) = 11' was unsatisfied");
	}
	
   // Predicate 'team <: PLAYER' can't be automatically translated 
   
}
		 

/**
* Test Case 1
* Formula: rr : PLAYER & team <: PLAYER & not(rr /: team) & card(team) = 11 & not(pp : team)
* Negative Test
*/
void Team_substitute_test_case_1(CuTest* tc)
{
	Team__INITIALISATION();
	
	PLAYER[] team = {PLAYER2, PLAYER3, PLAYER4, PLAYER5, PLAYER6, PLAYER7, PLAYER8, PLAYER9, PLAYER10, PLAYER11, PLAYER12}; 
	Team__team = team; 
	
	pp pp = PLAYER1; 
	PLAYER rr = PLAYER2; 
	
	Team__substitute(pp, rr);
	
	 
	PLAYER[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, Team__team == teamExpected);			
	 
	check_invariant(tc);
}
		 
/**
* Test Case 2
* Formula: rr : PLAYER & team <: PLAYER & not(rr /: team) & card(team) = 11 & pp : team
* Negative Test
*/
void Team_substitute_test_case_2(CuTest* tc)
{
	Team__INITIALISATION();
	
	PLAYER[] team = {PLAYER1, PLAYER2, PLAYER3, PLAYER4, PLAYER5, PLAYER6, PLAYER7, PLAYER8, PLAYER9, PLAYER10, PLAYER11}; 
	Team__team = team; 
	
	team pp = PLAYER1; 
	PLAYER rr = PLAYER1; 
	
	Team__substitute(pp, rr);
	
	 
	PLAYER[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, Team__team == teamExpected);			
	 
	check_invariant(tc);
}
		 
/**
* Test Case 3
* Formula: rr : PLAYER & team <: PLAYER & rr /: team & card(team) = 11 & not(pp : team)
* Negative Test
*/
void Team_substitute_test_case_3(CuTest* tc)
{
	Team__INITIALISATION();
	
	PLAYER[] team = {PLAYER2, PLAYER3, PLAYER4, PLAYER5, PLAYER6, PLAYER7, PLAYER8, PLAYER9, PLAYER10, PLAYER11, PLAYER12}; 
	Team__team = team; 
	
	pp pp = PLAYER1; 
	PLAYER rr = PLAYER1; 
	
	Team__substitute(pp, rr);
	
	 
	PLAYER[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, Team__team == teamExpected);			
	 
	check_invariant(tc);
}
		 
/**
* Test Case 4
* Formula: rr : PLAYER & team <: PLAYER & rr /: team & card(team) = 11 & pp : team
* Positive Test
*/
void Team_substitute_test_case_4(CuTest* tc)
{
	Team__INITIALISATION();
	
	PLAYER[] team = {PLAYER1, PLAYER3, PLAYER4, PLAYER5, PLAYER6, PLAYER7, PLAYER8, PLAYER9, PLAYER10, PLAYER11, PLAYER12}; 
	Team__team = team; 
	
	team pp = PLAYER1; 
	PLAYER rr = PLAYER2; 
	
	Team__substitute(pp, rr);
	
	 
	PLAYER[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, Team__team == teamExpected);			
	 
	check_invariant(tc);
}
		 
/**
* Test Suite
* Machine: Team
* Operation: substitute
*
* Testing Strategy: Input Space Partition
* Coverage Criteria: Equivalent Classes (All-Combinations)
* Oracle Strategy: Exception, State Variables, Return Values, State Invariant
*/
CuSuite* Team_substitute_test_suite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, Team_substitute_test_case_1);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_2);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_3);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_4);
	
	return suite;
}
		