#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "Team.h"

Team$state$ team;

void check_invariant(CuTest* tc, Team$state$ team) {
	
	if(!(card(team) == 11)){
		CuFail(tc, "The invariant 'card(team) = 11' was unsatisfied");
	}
	
   // Predicate 'team <: 1..22' can't be automatically translated 
   
}
		 

/**
* Test Case 1
* Formula: team <: 1..22 & not(rr /: team) & rr : 1..22 & card(team) = 11 & not(pp : team) & pp : ((22 + 1))..MAXINT
* Negative Test
*/
void Team_substitute_test_case_1(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	int32_t pp = 23; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 2
* Formula: team <: 1..22 & not(rr /: team) & rr : 1..22 & card(team) = 11 & not(pp : team) & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_2(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	int32_t pp = 2; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 3
* Formula: team <: 1..22 & not(rr /: team) & rr : 1..22 & card(team) = 11 & not(pp : team) & pp : MININT..((1 - 1))
* Negative Test
*/
void Team_substitute_test_case_3(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	int32_t pp = -1; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 4
* Formula: team <: 1..22 & not(rr /: team) & rr : 1..22 & card(team) = 11 & pp : team & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_4(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	team pp = 1; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 5
* Formula: team <: 1..22 & rr /: team & rr : ((22 + 1))..MAXINT & card(team) = 11 & not(pp : team) & pp : ((22 + 1))..MAXINT
* Negative Test
*/
void Team_substitute_test_case_5(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	int32_t pp = 23; 
	int32_t rr = 23; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 6
* Formula: team <: 1..22 & rr /: team & rr : ((22 + 1))..MAXINT & card(team) = 11 & not(pp : team) & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_6(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	int32_t pp = 1; 
	int32_t rr = 23; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 7
* Formula: team <: 1..22 & rr /: team & rr : ((22 + 1))..MAXINT & card(team) = 11 & not(pp : team) & pp : MININT..((1 - 1))
* Negative Test
*/
void Team_substitute_test_case_7(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	int32_t pp = -1; 
	int32_t rr = 23; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 8
* Formula: team <: 1..22 & rr /: team & rr : ((22 + 1))..MAXINT & card(team) = 11 & pp : team & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_8(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	team pp = 1; 
	int32_t rr = 23; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 9
* Formula: team <: 1..22 & rr /: team & rr : 1..22 & card(team) = 11 & not(pp : team) & pp : ((22 + 1))..MAXINT
* Negative Test
*/
void Team_substitute_test_case_9(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	int32_t pp = 23; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 10
* Formula: team <: 1..22 & rr /: team & rr : 1..22 & card(team) = 11 & not(pp : team) & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_10(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	int32_t pp = 1; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 11
* Formula: team <: 1..22 & rr /: team & rr : 1..22 & card(team) = 11 & not(pp : team) & pp : MININT..((1 - 1))
* Negative Test
*/
void Team_substitute_test_case_11(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	int32_t pp = -1; 
	int32_t rr = 1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 12
* Formula: team <: 1..22 & rr /: team & rr : 1..22 & card(team) = 11 & pp : team & pp : 1..22
* Positive Test
*/
void Team_substitute_test_case_12(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	team pp = 1; 
	int32_t rr = 2; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 13
* Formula: team <: 1..22 & rr /: team & rr : MININT..((1 - 1)) & card(team) = 11 & not(pp : team) & pp : ((22 + 1))..MAXINT
* Negative Test
*/
void Team_substitute_test_case_13(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	int32_t pp = 23; 
	int32_t rr = -1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 14
* Formula: team <: 1..22 & rr /: team & rr : MININT..((1 - 1)) & card(team) = 11 & not(pp : team) & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_14(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 
	team.team = team; 
	
	int32_t pp = 1; 
	int32_t rr = -1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 15
* Formula: team <: 1..22 & rr /: team & rr : MININT..((1 - 1)) & card(team) = 11 & not(pp : team) & pp : MININT..((1 - 1))
* Negative Test
*/
void Team_substitute_test_case_15(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	int32_t pp = -1; 
	int32_t rr = -1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
}
		 
/**
* Test Case 16
* Formula: team <: 1..22 & rr /: team & rr : MININT..((1 - 1)) & card(team) = 11 & pp : team & pp : 1..22
* Negative Test
*/
void Team_substitute_test_case_16(CuTest* tc)
{
	Team$init$(&team);
	
	int32_t[] team = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	team.team = team; 
	
	team pp = 1; 
	int32_t rr = -1; 
	
	Team$substitute(&team, pp, rr);
	
	 
	int32_t[] teamExpected; // Add expected value here.
	CuAssertTrue(tc, team.team == teamExpected);			
	 
	check_invariant(tc, team);
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
	SUITE_ADD_TEST(suite, Team_substitute_test_case_5);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_6);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_7);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_8);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_9);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_10);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_11);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_12);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_13);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_14);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_15);
	SUITE_ADD_TEST(suite, Team_substitute_test_case_16);
	
	return suite;
}
		