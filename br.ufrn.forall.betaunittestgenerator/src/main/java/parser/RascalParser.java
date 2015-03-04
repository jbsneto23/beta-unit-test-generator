package parser;

import model.OracleStrategy;
import model.Parameter;
import model.TestCase;
import model.TestSuite;
import model.Variable;

public class RascalParser {

	private static String replaceRascalEscapedCharacter(String str){
		String escaped = "";
		for(int i = 0; i < str.length(); i++){
			char ch = str.charAt(i);
			if(ch == '<'){
				escaped = escaped + "\\<";
			}else if(ch == '>'){
				escaped = escaped + "\\>";
			}else if(ch == '\"'){
				escaped = escaped + "\\\"";
			}else if(ch == '\''){
				escaped = escaped + "\\\'";
			}else if(ch == '\\'){
				escaped = escaped + "\\\\";
			}else{
				escaped = escaped + ch;
			}
		}
		return escaped;
	}
	
	public static String rascalFromTestSuite(TestSuite testSuite) {
		String rascal = "";
		rascal = rascal + "str machineName = \"" + replaceRascalEscapedCharacter(testSuite.getMachineName()) + "\";"+ "\n";
		rascal = rascal + "list[str] machineInvariant = [];"+ "\n";
		for(String m : testSuite.getMachineInvariant()){
			rascal = rascal + "machineInvariant = machineInvariant + \"" + replaceRascalEscapedCharacter(m) + "\";"+ "\n";
		}
		rascal = rascal + "str operationUnderTest = \"" + replaceRascalEscapedCharacter(testSuite.getOperationUnderTest()) + "\";"+ "\n";
		rascal = rascal + "str testingStrategy = \"" + replaceRascalEscapedCharacter(testSuite.getTestingStrategy()) + "\";"+ "\n";
		rascal = rascal + "str coverageCriteria = \"" + replaceRascalEscapedCharacter(testSuite.getCoverageCriteria()) + "\";"+ "\n";
		rascal = rascal + "list[OracleStrategy] oracleStrategies = [Exception()];"+ "\n";
		for(OracleStrategy os : testSuite.getOracleStrategies()){
			rascal = rascal + "oracleStrategies = oracleStrategies + " + os.getRascalValue() + ";"+ "\n";
		}
		rascal = rascal + "list[TestCase] testCases = [];"+ "\n";
		for(int i = 0; i < testSuite.getTestCases().size(); i++){
			TestCase testCase = testSuite.getTestCases().get(i);
			rascal = rascal + "int id_" + i + " = " + testCase.getId() + ";"+ "\n";
			rascal = rascal + "str formula_" + i + " = \""+ replaceRascalEscapedCharacter(testCase.getFormula()) + "\";"+ "\n"; 
			rascal = rascal + "bool negative_" + i + " = " + testCase.isNegative() + ";"+ "\n";
			rascal = rascal + "list[Variable] stateVariables_" + i + " = [];"+ "\n";
			rascal = rascal + "list[Parameter] operationParameters_" + i + " = [];"+ "\n"; 
			rascal = rascal + "list[Variable] returnVariables_" + i + " = [];"+ "\n";
			rascal = rascal + "str identifier_" + i + " = \"\";"+ "\n";
			rascal = rascal + "list[str] values_" + i + " = [];"+ "\n";
			for(Variable variable : testCase.getStateVariables()){
				rascal = rascal + "identifier_" + i + " = \"" + replaceRascalEscapedCharacter(variable.getIdentifier()) + "\";"+ "\n";
				rascal = rascal + "values_" + i + " = [];"+ "\n";
				for(String v : variable.getValues()){
					rascal = rascal + "values_" + i + " = values_" + i + " + \"" + replaceRascalEscapedCharacter(v) + "\";"+ "\n";
				}
				rascal = rascal + "stateVariables_" + i + " = stateVariables_" + i + " + Variable(identifier_" + i + ", values_" + i + ");"+ "\n";
			}
			for(Parameter parameter : testCase.getOperationParameters()){
				rascal = rascal + "identifier_" + i + " = \"" + replaceRascalEscapedCharacter(parameter.getIdentifier()) + "\";"+ "\n";
				rascal = rascal + "values_" + i + " = [];"+ "\n";
				for(String v : parameter.getValues()){
					rascal = rascal + "values_" + i + " = values_" + i + " + \"" + replaceRascalEscapedCharacter(v) + "\";"+ "\n";
				}
				rascal = rascal + "operationParameters_" + i + " = operationParameters_" + i + " + Parameter(identifier_" + i + ", values_" + i + ");"+ "\n";
			}
			for(Variable variable : testCase.getReturnVariables()){
				rascal = rascal + "identifier_" + i + " = \"" + replaceRascalEscapedCharacter(variable.getIdentifier()) + "\";"+ "\n";
				rascal = rascal + "values_" + i + " = [];"+ "\n";
				for(String v : variable.getValues()){
					rascal = rascal + "values_" + i + " = values_" + i + " + \"" + replaceRascalEscapedCharacter(v) + "\";"+ "\n";
				}
				rascal = rascal + "returnVariables_" + i + " = returnVariables_" + i + " + Variable(identifier_" + i + ", values_" + i + ");"+ "\n";
			}
			rascal = rascal + "testCases = testCases + TestCase(id_" + i + ", formula_" + i + ", negative_" + i + ", stateVariables_" + i + ", operationParameters_" + i + ", returnVariables_" + i + ");"+ "\n";
		}
		rascal = rascal + "TestSuite testSuite = TestSuite(machineName, machineInvariant, operationUnderTest, testingStrategy, coverageCriteria, testCases, oracleStrategies);";
		return rascal;
	}
	
}
