#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "TicTacToe.h"

TicTacToe$state$ tictactoe;

void check_invariant(CuTest* tc, TicTacToe$state$ tictactoe) {
	
	if(!((!((ThreeInRow(bposn) == true)) || (ThreeInRow(rposn) == false)))){
		CuFail(tc, "The invariant '((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE))' was unsatisfied");
	}
	
   
	if(!((!((ThreeInRow(rposn) == true)) || (ThreeInRow(bposn) == false)))){
		CuFail(tc, "The invariant '((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE))' was unsatisfied");
	}
	
   
	if(!((!((turn == blue)) || (card(bposn) <= card(rposn) && card(rposn) <= (card(bposn) + 1))))){
		CuFail(tc, "The invariant '((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1)))' was unsatisfied");
	}
	
   
	if(!((!((turn == red)) || (card(rposn) <= card(bposn) && card(bposn) <= (card(rposn) + 1))))){
		CuFail(tc, "The invariant '((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1)))' was unsatisfied");
	}
	
   
	if(!(bposn /\ rposn == {})){
		CuFail(tc, "The invariant 'bposn /\ rposn = {}' was unsatisfied");
	}
	
   // Predicate 'bposn <: 0..8' can't be automatically translated 
   // Predicate 'rposn <: 0..8' can't be automatically translated 
   // Predicate 'turn : Player' can't be automatically translated 
   
}
		 

/**
* Test Case 1
* Formula: pp : ((8 + 1))..MAXINT & ((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE)) & ((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE)) & ((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1))) & pp /: bposn \/ rposn & ((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1))) & bposn /\ rposn = {} & rposn <: 0..8 & turn : Player & ThreeInRow(rposn) = FALSE & bposn <: 0..8 & turn = blue
* Negative Test
*/
void TicTacToe_BlueMove_test_case_1(CuTest* tc)
{
	TicTacToe$init$(&tictactoe);
	
	int32_t[] bposn = {}; 
	tictactoe.bposn = bposn; 
	int32_t[] rposn = {}; 
	tictactoe.rposn = rposn; 
	Player turn = blue; 
	tictactoe.turn = turn; 
	
	int32_t pp = 9; 
	
	TicTacToe$BlueMove(&tictactoe, pp);
	
	 
	int32_t[] bposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.bposn == bposnExpected);			
	
	int32_t[] rposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.rposn == rposnExpected);			
	
	Player turnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.turn == turnExpected);			
	 
	check_invariant(tc, tictactoe);
}
		 
/**
* Test Case 2
* Formula: pp : ((8 + 1))..MAXINT & ((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE)) & ((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE)) & ((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1))) & pp /: bposn \/ rposn & ((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1))) & bposn /\ rposn = {} & rposn <: 0..8 & turn : Player & not(ThreeInRow(rposn) = FALSE) & bposn <: 0..8 & not(turn = blue)
* Negative Test
*/
void TicTacToe_BlueMove_test_case_2(CuTest* tc)
{
	TicTacToe$init$(&tictactoe);
	
	int32_t[] bposn = {3, 4, 6}; 
	tictactoe.bposn = bposn; 
	int32_t[] rposn = {0, 1, 2}; 
	tictactoe.rposn = rposn; 
	Player turn = red; 
	tictactoe.turn = turn; 
	
	int32_t pp = 9; 
	
	TicTacToe$BlueMove(&tictactoe, pp);
	
	 
	int32_t[] bposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.bposn == bposnExpected);			
	
	int32_t[] rposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.rposn == rposnExpected);			
	
	Player turnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.turn == turnExpected);			
	 
	check_invariant(tc, tictactoe);
}
		 
/**
* Test Case 3
* Formula: pp : 0..8 & ((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE)) & ((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE)) & ((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1))) & not(pp /: bposn \/ rposn) & ((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1))) & bposn /\ rposn = {} & rposn <: 0..8 & turn : Player & not(ThreeInRow(rposn) = FALSE) & bposn <: 0..8 & not(turn = blue)
* Negative Test
*/
void TicTacToe_BlueMove_test_case_3(CuTest* tc)
{
	TicTacToe$init$(&tictactoe);
	
	int32_t[] bposn = {3, 4, 6}; 
	tictactoe.bposn = bposn; 
	int32_t[] rposn = {0, 1, 2}; 
	tictactoe.rposn = rposn; 
	Player turn = red; 
	tictactoe.turn = turn; 
	
	int32_t pp = 0; 
	
	TicTacToe$BlueMove(&tictactoe, pp);
	
	 
	int32_t[] bposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.bposn == bposnExpected);			
	
	int32_t[] rposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.rposn == rposnExpected);			
	
	Player turnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.turn == turnExpected);			
	 
	check_invariant(tc, tictactoe);
}
		 
/**
* Test Case 4
* Formula: pp : 0..8 & ((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE)) & ((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE)) & ((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1))) & pp /: bposn \/ rposn & ((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1))) & bposn /\ rposn = {} & rposn <: 0..8 & turn : Player & ThreeInRow(rposn) = FALSE & bposn <: 0..8 & turn = blue
* Positive Test
*/
void TicTacToe_BlueMove_test_case_4(CuTest* tc)
{
	TicTacToe$init$(&tictactoe);
	
	int32_t[] bposn = {}; 
	tictactoe.bposn = bposn; 
	int32_t[] rposn = {}; 
	tictactoe.rposn = rposn; 
	Player turn = blue; 
	tictactoe.turn = turn; 
	
	int32_t pp = 0; 
	
	TicTacToe$BlueMove(&tictactoe, pp);
	
	 
	int32_t[] bposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.bposn == bposnExpected);			
	
	int32_t[] rposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.rposn == rposnExpected);			
	
	Player turnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.turn == turnExpected);			
	 
	check_invariant(tc, tictactoe);
}
		 
/**
* Test Case 5
* Formula: pp : MININT..((0 - 1)) & ((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE)) & ((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE)) & ((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1))) & pp /: bposn \/ rposn & ((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1))) & bposn /\ rposn = {} & rposn <: 0..8 & turn : Player & ThreeInRow(rposn) = FALSE & bposn <: 0..8 & not(turn = blue)
* Negative Test
*/
void TicTacToe_BlueMove_test_case_5(CuTest* tc)
{
	TicTacToe$init$(&tictactoe);
	
	int32_t[] bposn = {}; 
	tictactoe.bposn = bposn; 
	int32_t[] rposn = {}; 
	tictactoe.rposn = rposn; 
	Player turn = red; 
	tictactoe.turn = turn; 
	
	int32_t pp = -1; 
	
	TicTacToe$BlueMove(&tictactoe, pp);
	
	 
	int32_t[] bposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.bposn == bposnExpected);			
	
	int32_t[] rposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.rposn == rposnExpected);			
	
	Player turnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.turn == turnExpected);			
	 
	check_invariant(tc, tictactoe);
}
		 
/**
* Test Case 6
* Formula: pp : MININT..((0 - 1)) & ((ThreeInRow(rposn) = TRUE) => (ThreeInRow(bposn) = FALSE)) & ((ThreeInRow(bposn) = TRUE) => (ThreeInRow(rposn) = FALSE)) & ((turn = red) => (card(rposn) <= card(bposn) & card(bposn) <= (card(rposn) + 1))) & pp /: bposn \/ rposn & ((turn = blue) => (card(bposn) <= card(rposn) & card(rposn) <= (card(bposn) + 1))) & bposn /\ rposn = {} & rposn <: 0..8 & turn : Player & not(ThreeInRow(rposn) = FALSE) & bposn <: 0..8 & turn = blue
* Negative Test
*/
void TicTacToe_BlueMove_test_case_6(CuTest* tc)
{
	TicTacToe$init$(&tictactoe);
	
	int32_t[] bposn = {3, 4}; 
	tictactoe.bposn = bposn; 
	int32_t[] rposn = {0, 1, 2}; 
	tictactoe.rposn = rposn; 
	Player turn = blue; 
	tictactoe.turn = turn; 
	
	int32_t pp = -1; 
	
	TicTacToe$BlueMove(&tictactoe, pp);
	
	 
	int32_t[] bposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.bposn == bposnExpected);			
	
	int32_t[] rposnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.rposn == rposnExpected);			
	
	Player turnExpected; // Add expected value here.
	CuAssertTrue(tc, tictactoe.turn == turnExpected);			
	 
	check_invariant(tc, tictactoe);
}
		 
/**
* Test Suite
* Machine: TicTacToe
* Operation: BlueMove
*
* Testing Strategy: Input Space Partition
* Coverage Criteria: Equivalent Classes (Pairwise)
* Oracle Strategy: Exception, State Variables, Return Values, State Invariant
*/
CuSuite* TicTacToe_BlueMove_test_suite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, TicTacToe_BlueMove_test_case_1);
	SUITE_ADD_TEST(suite, TicTacToe_BlueMove_test_case_2);
	SUITE_ADD_TEST(suite, TicTacToe_BlueMove_test_case_3);
	SUITE_ADD_TEST(suite, TicTacToe_BlueMove_test_case_4);
	SUITE_ADD_TEST(suite, TicTacToe_BlueMove_test_case_5);
	SUITE_ADD_TEST(suite, TicTacToe_BlueMove_test_case_6);
	
	return suite;
}
		