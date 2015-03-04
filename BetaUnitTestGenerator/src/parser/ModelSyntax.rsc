module parser::ModelSyntax

//lexical Id = ([a-z A-Z 0-9 _] !<< [a-z A-Z][a-z A-Z 0-9 _]* !>> [a-z A-Z 0-9 _]); 
lexical Content = ![ \ Keyword];
layout Whitespaces = [\t\n\ \r\f]*;
keyword Keywords = "test-suite" | "end-test-suite" | "machine-name" | "end-machine-name" | "machine-invariant" | "end-machine-invariant"
					| "invariant-clause" | "end-invariant-clause" | "operation-under-test"| "end-operation-under-test" | "testing-strategy" 
					| "end-testing-strategy" | "coverage-criteria" | "end-coverage-criteria" | "oracle-strategy" | "end-oracle-strategy" 
					| "state-variables" | "end-state-variables" | "return-variables" | "end-return-variables" | "invariant-ok" | "end-invariant-ok" 
					| "test-cases" | "end-test-cases" | "test-case" | "end-test-case" | "id" | "end-id" | "formula" | "end-formula"
					| "isNegative" | "end-isNegative" | "state-variables" | "end-state-variables" | "operation-parameters" | "end-operation-parameters"
					| "variable" | "end-variable" | "identifier" | "end-identifier" | "values" | "end-values" | "value" | "end-value"
					| "parameter" | "end-parameter";
lexical Integer_literal = [0-9]+;

start syntax TestSuiteXML = 
	"test-suite"  
		"machine-name" Content machineName "end-machine-name"
		"machine-invariant"
        	("invariant-clause" Content invariantClause "end-invariant-clause")* machineInvariant
	    "end-machine-invariant"
	    "operation-under-test" Content operationUnderTest "end-operation-under-test"
        "testing-strategy" Content testingStrategy "end-testing-strategy"
    	"coverage-criteria" Content coverageCriteria "end-coverage-criteria"
	    "oracle-strategy"
        	"state-variables" BoolValue stateVariableOS  "end-state-variables"
 	        "return-variables" BoolValue returnVariableOS "end-return-variables"
        	"invariant-ok" BoolValue invariantCheckOS "end-invariant-ok"
 	    "end-oracle-strategy"
 	    "test-cases"
 	    	TestCaseXML+ testCases
 	    "end-test-cases"
	"end-test-suite";

syntax TestCaseXML = 
	"test-case"
            "id" Integer_literal id "end-id"
            "formula" Content formula "end-formula"
            "isNegative" BoolValue negative "end-isNegative"
            ("state-variables" VariableXML* stateVariables "end-state-variables")?
            ("operation-parameters" ParameterXML* perationParameters "end-operation-parameters")?
            ("return-variables" VariableXML* returnVariables "end-return-variables")?
     "end-test-case";

syntax VariableXML = 
	"variable"
    	"identifier" Content identifier "end-identifier" 
        "values"
        	("value" Content value "end-value")* values 
        "end-values"
    "end-variable";
    
syntax ParameterXML = 
	"parameter"
    	"identifier" Content identifier "end-identifier" 
        "values"
        	("value" Content value "end-value")* values 
        "end-values"
    "end-parameter";

syntax BoolValue = t : "true" | f : "false";

