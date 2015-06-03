#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"
#include "ATM.h"

ATM$state$ atm;

void check_invariant(CuTest* tc, ATM$state$ atm) {
	
	if(!(account_balance)){
		CuFail(tc, "The invariant 'account_balance : INT' was unsatisfied");
	}
	
	if(!(account_balance >= 0)){
		CuFail(tc, "The invariant 'account_balance >= 0' was unsatisfied");
	}
	
	if(!(account_id)){
		CuFail(tc, "The invariant 'account_id : INT' was unsatisfied");
	}
	
}
		 

/**
* Test Case 1
* Formula: account_balance : INT & account_id : INT & account_balance >= 0
* Positive Test
*/
void ATM_balance_test_case_1(CuTest* tc)
{
	ATM$init$(&atm);
	
	int32_t account_id = -1; 
	atm.account_id = account_id; 
	int32_t account_balance = 0; 
	atm.account_balance = account_balance; 
	
	
	ATM$balance(&atm);
	
	 
	int32_t account_idExpected; // Add expected value here.
	CuAssertTrue(tc, atm.account_id == account_idExpected);			
	
	int32_t account_balanceExpected; // Add expected value here.
	CuAssertTrue(tc, atm.account_balance == account_balanceExpected);			
	 
	check_invariant(tc, atm);
}
		 
/**
* Test Suite
* Machine: ATM
* Operation: balance
*
* Testing Strategy: Input Space Partition
* Coverage Criteria: Equivalent Classes (Each-choice)
* Oracle Strategy: Exception, State Variables, Return Values, State Invariant
*/
CuSuite* ATM_balance_test_suite(void)
{
	CuSuite* suite = CuSuiteNew();
	
	SUITE_ADD_TEST(suite, ATM_balance_test_case_1);
	
	return suite;
}
		