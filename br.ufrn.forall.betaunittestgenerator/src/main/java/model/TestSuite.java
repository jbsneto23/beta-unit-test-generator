package model;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TestSuite {

	private String machineName; 
	private List<String> machineInvariant; 
	private String operationUnderTest;
	private String testingStrategy; 
	private String coverageCriteria;
	private List<TestCase> testCases; 
	private List<OracleStrategy> oracleStrategies;
	
	public TestSuite(String machineName, List<String> machineInvariant,
			String operationUnderTest, String testingStrategy,
			String coverageCriteria, List<TestCase> testCases,
			List<OracleStrategy> oracleStrategies) {
		super();
		this.machineName = machineName;
		this.machineInvariant = machineInvariant;
		this.operationUnderTest = operationUnderTest;
		this.testingStrategy = testingStrategy;
		this.coverageCriteria = coverageCriteria;
		this.testCases = testCases;
		this.oracleStrategies = oracleStrategies;
	}
	
	public TestSuite(String machineName, List<String> machineInvariant,
			String operationUnderTest, String testingStrategy,
			String coverageCriteria, List<TestCase> testCases) {
		super();
		this.machineName = machineName;
		this.machineInvariant = machineInvariant;
		this.operationUnderTest = operationUnderTest;
		this.testingStrategy = testingStrategy;
		this.coverageCriteria = coverageCriteria;
		this.testCases = testCases;
		this.oracleStrategies = new ArrayList<OracleStrategy>();
		this.oracleStrategies.add(OracleStrategy.EXCEPTION); // default
	}
	
	public TestSuite(String machineName, List<String> machineInvariant,
			String operationUnderTest, String testingStrategy,
			String coverageCriteria, List<TestCase> testCases, OracleStrategy... oracleStrategies) {
		super();
		this.machineName = machineName;
		this.machineInvariant = machineInvariant;
		this.operationUnderTest = operationUnderTest;
		this.testingStrategy = testingStrategy;
		this.coverageCriteria = coverageCriteria;
		this.testCases = testCases;
		this.oracleStrategies = Arrays.asList(oracleStrategies);
	}

	public TestSuite() {
		// TODO Auto-generated constructor stub
	}

	public String getMachineName() {
		return machineName;
	}

	public void setMachineName(String machineName) {
		this.machineName = machineName;
	}

	public List<String> getMachineInvariant() {
		return machineInvariant;
	}

	public void setMachineInvariant(List<String> machineInvariant) {
		this.machineInvariant = machineInvariant;
	}

	public String getOperationUnderTest() {
		return operationUnderTest;
	}

	public void setOperationUnderTest(String operationUnderTest) {
		this.operationUnderTest = operationUnderTest;
	}

	public String getTestingStrategy() {
		return testingStrategy;
	}

	public void setTestingStrategy(String testingStrategy) {
		this.testingStrategy = testingStrategy;
	}

	public String getCoverageCriteria() {
		return coverageCriteria;
	}

	public void setCoverageCriteria(String coverageCriteria) {
		this.coverageCriteria = coverageCriteria;
	}

	public List<TestCase> getTestCases() {
		return testCases;
	}

	public void setTestCases(List<TestCase> testCases) {
		this.testCases = testCases;
	}

	public List<OracleStrategy> getOracleStrategies() {
		return oracleStrategies;
	}

	public void setOracleStrategies(List<OracleStrategy> oracleStrategies) {
		this.oracleStrategies = oracleStrategies;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime
				* result
				+ ((coverageCriteria == null) ? 0 : coverageCriteria.hashCode());
		result = prime
				* result
				+ ((machineInvariant == null) ? 0 : machineInvariant.hashCode());
		result = prime * result
				+ ((machineName == null) ? 0 : machineName.hashCode());
		result = prime
				* result
				+ ((operationUnderTest == null) ? 0 : operationUnderTest
						.hashCode());
		result = prime
				* result
				+ ((oracleStrategies == null) ? 0 : oracleStrategies.hashCode());
		result = prime * result
				+ ((testCases == null) ? 0 : testCases.hashCode());
		result = prime * result
				+ ((testingStrategy == null) ? 0 : testingStrategy.hashCode());
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
		TestSuite other = (TestSuite) obj;
		if (coverageCriteria == null) {
			if (other.coverageCriteria != null)
				return false;
		} else if (!coverageCriteria.equals(other.coverageCriteria))
			return false;
		if (machineInvariant == null) {
			if (other.machineInvariant != null)
				return false;
		} else if (!machineInvariant.equals(other.machineInvariant))
			return false;
		if (machineName == null) {
			if (other.machineName != null)
				return false;
		} else if (!machineName.equals(other.machineName))
			return false;
		if (operationUnderTest == null) {
			if (other.operationUnderTest != null)
				return false;
		} else if (!operationUnderTest.equals(other.operationUnderTest))
			return false;
		if (oracleStrategies == null) {
			if (other.oracleStrategies != null)
				return false;
		} else if (!oracleStrategies.equals(other.oracleStrategies))
			return false;
		if (testCases == null) {
			if (other.testCases != null)
				return false;
		} else if (!testCases.equals(other.testCases))
			return false;
		if (testingStrategy == null) {
			if (other.testingStrategy != null)
				return false;
		} else if (!testingStrategy.equals(other.testingStrategy))
			return false;
		return true;
	}

	@Override
	public String toString() {
		return "TestSuite [machineName=" + machineName + ", machineInvariant="
				+ machineInvariant + ", operationUnderTest="
				+ operationUnderTest + ", testingStrategy=" + testingStrategy
				+ ", coverageCriteria=" + coverageCriteria + ", testCases="
				+ testCases + ", oracleStrategies=" + oracleStrategies + "]";
	}

}
