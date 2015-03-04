@license{
	Copyright (c) 2014, Ernesto C. B. de Matos, Anamaria M. Moreira, João B. de S. Neto.
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without modification, are permitted provided that 
	the following conditions are met:
	
	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the 
		following disclaimer.
	
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 
		following disclaimer in the documentation and/or other materials provided with the distribution.
	
	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote 
		products derived from this software without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
	USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
}
@contributor{João Batista de Souza Neto}

module UnitTestGenerator

import IO;
import util::Eval;
import String;
import parser::XMLParser;
import parser::Model;

private list[str] importsCommand(){
	list[str] command = [];
	command += "import IO;";
	command += "import String;";
	command += "import parser::XMLParser;";
	command += "import parser::Model;";
	return command;
}

private list[str] loadTestSuiteCommand(str testSuiteRascalFile){
list[str] command = [];
	command += "loc testSuiteRascalFileLocation = toLocation(\"" + testSuiteRascalFile + "\");";
	command += "testSuiteRascalFileLocation.scheme = \"file\";";
loc testSuiteRascalFileLocation = toLocation(testSuiteRascalFile);
	testSuiteRascalFileLocation.scheme = "file";
	command += readFile(testSuiteRascalFileLocation);
	return command;
}

private list[str] templateCallCommand(str templateModule){
	list[str] command = [];
	command += "import template::" + templateModule + ";"; // assumes that templateModule exists and is in the correct template directory
	command += "str testContent = template(testSuite);";
	return command;
}

private list[str] createTestFileCommand(){
	list[str] command = [];
	command += "loc outputFolder = testSuiteRascalFileLocation.parent;";
	command += "str outputFileName = fileName(testSuite);";
	command += "loc outputFile = outputFolder + outputFileName;";
	command += "writeFile(outputFile, testContent);";
	command += "println(\"Unit Test file \" + outputFile.file + \" created.\");";
	return command;
}

// 1st argument is the Test Suite Rascal path
// 2nd argument is the name of Template Module (containing a public function template that receives a TestSuite as argument and returns an string)
public void main(list[str] args){
	
	list[str] command = [];
	command += importsCommand();
	command += loadTestSuiteCommand(args[0]);
	command += templateCallCommand(args[1]);
	command += createTestFileCommand();
	eval(command);
	}