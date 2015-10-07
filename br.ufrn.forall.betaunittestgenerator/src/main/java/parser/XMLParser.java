package parser;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

import model.OracleStrategy;
import model.Parameter;
import model.TestCase;
import model.TestSuite;
import model.Variable;
import nu.xom.Builder;
import nu.xom.Document;
import nu.xom.Element;
import nu.xom.Elements;

public class XMLParser {

	public static TestSuite testSuiteFromXML(String fileName) {

		FileInputStream xmlFile;
		try {
			xmlFile = new FileInputStream(fileName);
			Builder builder = new Builder();
			Document doc = builder.build(xmlFile);
			return testSuiteFromXML(doc);
		} catch (FileNotFoundException e) {
			System.err.println("Error while trying to read the Test Suite XML Specification file.");
			e.printStackTrace();
		} catch (Exception e) {
			System.err.println("Error while trying to parser the Test Suite XML Specification.");
			e.printStackTrace();
		} 
		return null;
	}

	public static TestSuite testSuiteFromXML(Document doc) {
		try {
			Element root = doc.getRootElement();
			String machineName = root.getFirstChildElement("machine-name")
					.getValue();

			Element machineInvariantXML = root.getFirstChildElement(
					"machine-invariant");
			
			List<String> machineInvariant = new ArrayList<String>();
			
			if(machineInvariantXML != null){
				Elements machineInvariantClausesXML = machineInvariantXML.getChildElements("invariant-clause");

				for (int i = 0; i < machineInvariantClausesXML.size(); i++) {
					String invariantClause = machineInvariantClausesXML.get(i).getValue();
					machineInvariant.add(invariantClause);
				}
			}

			String operationUnderTest = root.getFirstChildElement(
					"operation-under-test").getValue();
			String testingStrategy = root.getFirstChildElement(
					"testing-strategy").getValue();
			String coverageCriteria = root.getFirstChildElement(
					"coverage-criteria").getValue();

			Element oracleStrategyXML = root
					.getFirstChildElement("oracle-strategy");

			List<OracleStrategy> oracleStrategies = new ArrayList<OracleStrategy>();

			String stateVariablesOS = oracleStrategyXML.getFirstChildElement(
					"state-variables").getValue();
			String returnVariableOS = oracleStrategyXML.getFirstChildElement(
					"return-variables").getValue();
			String invariantOkOS = oracleStrategyXML.getFirstChildElement(
					"invariant-ok").getValue();

			if (stateVariablesOS.equals("true"))
				oracleStrategies.add(OracleStrategy.STATE_VARIABLES);
			if (returnVariableOS.equals("true"))
				oracleStrategies.add(OracleStrategy.RETURN_VALUES);
			if (invariantOkOS.equals("true"))
				oracleStrategies.add(OracleStrategy.STATE_INVARIANT);

			Elements testCasesXML = root.getFirstChildElement("test-cases")
					.getChildElements("test-case");

			List<TestCase> testCases = new ArrayList<TestCase>();

			for (int i = 0; i < testCasesXML.size(); i++) {
				Element testCaseXML = testCasesXML.get(i);

				int id = Integer.parseInt(testCaseXML
						.getFirstChildElement("id").getValue());
				String formula = testCaseXML.getFirstChildElement("formula")
						.getValue();

				String isNegative = testCaseXML.getFirstChildElement(
						"isNegative").getValue();

				boolean negative = isNegative.equals("true");

				Element stateVariablesMainXML = testCaseXML
						.getFirstChildElement("state-variables");
				List<Variable> stateVariables = new ArrayList<Variable>();

				if (stateVariablesMainXML != null) {
					Elements stateVariablesXML = stateVariablesMainXML
							.getChildElements("variable");

					for (int j = 0; j < stateVariablesXML.size(); j++) {
						Element stateXML = stateVariablesXML.get(j);

						String identifier = stateXML.getFirstChildElement(
								"identifier").getValue();
						Elements valuesXML = stateXML.getFirstChildElement(
								"values").getChildElements("value");
						List<String> values = new ArrayList<String>();
						for (int k = 0; k < valuesXML.size(); k++) {
							String value = valuesXML.get(k).getValue();
							values.add(value);
						}
						Variable variable = new Variable(identifier, values);
						stateVariables.add(variable);
					}
				}

				Element operationParametersMainXML = testCaseXML
						.getFirstChildElement("operation-parameters");
				List<Parameter> operationParameters = new ArrayList<Parameter>();

				if (operationParametersMainXML != null) {
					Elements operationParametersXML = operationParametersMainXML
							.getChildElements("parameter");
					for (int j = 0; j < operationParametersXML.size(); j++) {
						Element parameterXML = operationParametersXML.get(j);
						String identifier = parameterXML.getFirstChildElement(
								"identifier").getValue();
						Elements valuesXML = parameterXML.getFirstChildElement(
								"values").getChildElements("value");
						List<String> values = new ArrayList<String>();
						for (int k = 0; k < valuesXML.size(); k++) {
							String value = valuesXML.get(k).getValue();
							values.add(value);
						}
						Parameter parameter = new Parameter(identifier, values);
						operationParameters.add(parameter);
					}
				}
				
				Element expectedStateVariablesMainXML = testCaseXML
						.getFirstChildElement("expected-state-values");
				List<Variable> expectedStateVariables = new ArrayList<Variable>();

				if (expectedStateVariablesMainXML != null) {
					Elements stateVariablesXML = expectedStateVariablesMainXML
							.getChildElements("variable");

					for (int j = 0; j < stateVariablesXML.size(); j++) {
						Element stateXML = stateVariablesXML.get(j);

						String identifier = stateXML.getFirstChildElement(
								"identifier").getValue();
						Element valueXML = stateXML.getFirstChildElement(
								"values");
						List<String> values = new ArrayList<String>();
						if(valueXML != null){
							Elements valuesXML = valueXML.getChildElements("value");
							for (int k = 0; k < valuesXML.size(); k++) {
								String value = valuesXML.get(k).getValue();
								values.add(value);
							}
						}
						Variable variable = new Variable(identifier, values);
						expectedStateVariables.add(variable);
					}
				}

				Element returnVariablesMainXML = testCaseXML
						.getFirstChildElement("return-variables");
				List<Variable> returnVariables = new ArrayList<Variable>();

				if (returnVariablesMainXML != null) {
					Elements returnVariablesXML = returnVariablesMainXML
							.getChildElements("variable");
					if (returnVariablesXML.size() > 0) {
						for (int j = 0; j < returnVariablesXML.size(); j++) {
							Element stateXML = returnVariablesXML.get(j);

							String identifier = stateXML.getFirstChildElement(
									"identifier").getValue();
							Element valueXML = stateXML.getFirstChildElement(
									"values");
							List<String> values = new ArrayList<String>();
							if(valueXML != null){
								Elements valuesXML = valueXML.getChildElements("value");
							
								for (int k = 0; k < valuesXML.size(); k++) {
									String value = valuesXML.get(k).getValue();
									values.add(value);
								}
							}
							Variable variable = new Variable(identifier, values);
							returnVariables.add(variable);
						}
					}
				}
				TestCase testCase = new TestCase(id, formula, negative,
						stateVariables, operationParameters, expectedStateVariables, returnVariables);

				testCases.add(testCase);
			}

			TestSuite testSuite = new TestSuite(machineName, machineInvariant,
					operationUnderTest, testingStrategy, coverageCriteria,
					testCases, oracleStrategies);
			return testSuite;
		} catch (Exception e) {
			System.err.println("Error while trying to parser the Test Suite XML Specification.");
			e.printStackTrace();
		}
		return null;
	}

}