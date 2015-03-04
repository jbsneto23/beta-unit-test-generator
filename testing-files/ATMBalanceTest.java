import org.junit.Before;
import org.junit.After;
import org.junit.Test;
import static org.junit.Assert.*;

/**
* Machine: ATM
* Operation: balance
*
* Testing Strategy: Input Space Partition
* Coverage Criteria: Equivalent Classes (Each-choice)
* Oracle Strategy: Exception, State Variables, Return Values, State Invariant
*/
public class ATMBalanceTest { 

	private ATM atm;

	@Before
	public void setUp() throws Exception {
		atm = new ATM();
	} 
	
	@After
	public void checkInvariant() throws Exception {
		
		
		if(!(atm.getAccount_balance() != null /* account_balance : INT */)){
			fail("The invariant 'account_balance : INT' was unsatisfied");
		}
		
		
		if(!(atm.getAccount_balance() >= 0)){
			fail("The invariant 'account_balance >= 0' was unsatisfied");
		}
		
		
		if(!(atm.getAccount_id() != null /* account_id : INT */)){
			fail("The invariant 'account_id : INT' was unsatisfied");
		}
		
	}
			 
	
	/**
	* Test Case 1
	* Formula: account_balance : INT & account_id : INT & account_balance >= 0
	* Positive Test
	*/
	@Test
	public void testCase1() {
		
		int account_id = -1;
		atm.setAccount_id(account_id);
		
		int account_balance = 0;
		atm.setAccount_balance(account_balance);
		 
		
		atm.balance();
		  
		int account_idExpected; // Add expected value here.
		assertEquals(atm.getAccount_id(), account_idExpected);			
		
		int account_balanceExpected; // Add expected value here.
		assertEquals(atm.getAccount_balance(), account_balanceExpected);			
		 
	}
			 
}
		