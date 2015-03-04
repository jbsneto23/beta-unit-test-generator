package model;

public enum OracleStrategy {

	STATE_INVARIANT("Check the state invariants", "StateInvariant()"),
	RETURN_VALUES("Check return values", "ReturnValues()"),
	STATE_VARIABLES("Check the state variables", "StateVariables()"),
	EXCEPTION("Check for exceptions", "Exception()");
	
	private OracleStrategy(String strategy, String rascalValue){
		this.strategy = strategy;
		this.rascalValue = rascalValue;
	}
	
	private String strategy;
	private String rascalValue;
	
	public String getStrategy() {
		return strategy;
	}

	public String getRascalValue() {
		return rascalValue;
	}
	
}
