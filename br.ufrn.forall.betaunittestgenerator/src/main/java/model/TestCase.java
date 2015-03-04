package model;

import java.util.List;

public class TestCase {

	private int id; 
	private String formula; 
	private boolean negative; 
	private List<Variable> stateVariables;
	private List<Parameter> operationParameters; 
	private List<Variable> returnVariables;
	
	public TestCase(int id, String formula, boolean negative,
			List<Variable> stateVariables, List<Parameter> operationParameters,
			List<Variable> returnVariables) {
		super();
		this.id = id;
		this.formula = formula;
		this.negative = negative;
		this.stateVariables = stateVariables;
		this.operationParameters = operationParameters;
		this.returnVariables = returnVariables;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getFormula() {
		return formula;
	}
	public void setFormula(String formula) {
		this.formula = formula;
	}
	public boolean isNegative() {
		return negative;
	}
	public void setNegative(boolean negative) {
		this.negative = negative;
	}
	public List<Variable> getStateVariables() {
		return stateVariables;
	}
	public void setStateVariables(List<Variable> stateVariables) {
		this.stateVariables = stateVariables;
	}
	public List<Parameter> getOperationParameters() {
		return operationParameters;
	}
	public void setOperationParameters(List<Parameter> operationParameters) {
		this.operationParameters = operationParameters;
	}
	public List<Variable> getReturnVariables() {
		return returnVariables;
	}
	public void setReturnVariables(List<Variable> returnVariables) {
		this.returnVariables = returnVariables;
	}


	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((formula == null) ? 0 : formula.hashCode());
		result = prime * result + id;
		result = prime * result + (negative ? 1231 : 1237);
		result = prime
				* result
				+ ((operationParameters == null) ? 0 : operationParameters
						.hashCode());
		result = prime * result
				+ ((returnVariables == null) ? 0 : returnVariables.hashCode());
		result = prime * result
				+ ((stateVariables == null) ? 0 : stateVariables.hashCode());
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		TestCase other = (TestCase) obj;
		if (formula == null) {
			if (other.formula != null)
				return false;
		} else if (!formula.equals(other.formula))
			return false;
		if (id != other.id)
			return false;
		if (negative != other.negative)
			return false;
		if (operationParameters == null) {
			if (other.operationParameters != null)
				return false;
		} else if (!operationParameters.equals(other.operationParameters))
			return false;
		if (returnVariables == null) {
			if (other.returnVariables != null)
				return false;
		} else if (!returnVariables.equals(other.returnVariables))
			return false;
		if (stateVariables == null) {
			if (other.stateVariables != null)
				return false;
		} else if (!stateVariables.equals(other.stateVariables))
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "TestCase [id=" + id + ", formula=" + formula + ", negative="
				+ negative + ", stateVariables=" + stateVariables
				+ ", operationParameters=" + operationParameters
				+ ", returnVariables=" + returnVariables + "]";
	}
	
}
