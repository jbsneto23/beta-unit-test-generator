package generator;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

import model.TestSuite;
import parser.RascalParser;
import parser.XMLParser;

public class UnitTestGenerator {

	private String rascalShell;
	private String unitTestGeneratorRascalProject;
	private static final String rascalMainModule = "UnitTestGenerator.rsc";
	private String unitTestTemplateModule;

	public UnitTestGenerator(String rascalShell, String unitTestGeneratorRascalProject, String unitTestTemplateModule) {
		this.rascalShell = rascalShell;
		this.unitTestGeneratorRascalProject = unitTestGeneratorRascalProject;
		this.unitTestTemplateModule = unitTestTemplateModule;
	}

	public void generateUnitTest(String xmlFilePath) {
		System.out.println("BETA's Unit Test Generator");
		TestSuite testSuite = XMLParser.testSuiteFromXML(xmlFilePath);
		File xmlFile = new File(xmlFilePath);
		String testSuiteRascalFileName = xmlFile.getParent()
				+ System.getProperty("file.separator")
				+ testSuite.getMachineName()
				+ testSuite.getOperationUnderTest() + "TestSuite.rsc";
		String testSuiteRascalContent = RascalParser
				.rascalFromTestSuite(testSuite);
		createTestSuiteRascalFile(testSuiteRascalFileName, testSuiteRascalContent);
		executeRascalCommandOnTerminal(testSuiteRascalFileName);
		deleteTestSuiteRascalFile(testSuiteRascalFileName);
	}
	
	private void createTestSuiteRascalFile(String fileName, String content){
		try {
			System.out.print("Rascal Shell ");
			FileOutputStream f = new FileOutputStream(fileName);
			PrintStream ps = new PrintStream(f);
			ps.println(content);
			f.close();
		} catch (Exception e) {
			System.err
					.println("Error while trying to create the Rascal Test Suite File.");
			e.printStackTrace();
		}
	}
	
	private void deleteTestSuiteRascalFile(String fileName){
		File f = new File(fileName);
		f.deleteOnExit();
	}

	private void executeRascalCommandOnTerminal(String testSuiteRascalFileName){
		try {
			ProcessBuilder builder = new ProcessBuilder(rascalCommand(testSuiteRascalFileName));
			builder.directory(new File(this.unitTestGeneratorRascalProject));
			Process process = builder.start();
			BufferedReader cmdOutput = new BufferedReader(new InputStreamReader(process.getInputStream()));
			BufferedReader cmdOutputErrors = new BufferedReader(new InputStreamReader(process.getErrorStream()));
			printCommandOutput(cmdOutput);
			printCommandErrorOutput(cmdOutputErrors);
		} catch (IOException e) {
			System.err.println("Error while trying to execute the Rascal command.");
			e.printStackTrace();
		}
	}
	
	private String[] rascalCommand(String testSuiteRascalPath) {
		String[] command = new String[] { "java", "-Xmx1G", "-Xss32m", "-jar",
				this.rascalShell, rascalMainModule, testSuiteRascalPath, this.unitTestTemplateModule };

		return command;
	}
	
	private void printCommandOutput(BufferedReader cmdOutput) {
		String line = "";
		try {
			while ((line = cmdOutput.readLine()) != null) {
				System.out.println(line);
			}
		} catch (IOException e) {
			System.err.println("Error while trying to print Rascal output message.");
		}
	}
	
	private void printCommandErrorOutput(BufferedReader cmdOutput) {
		String line = "";
		try {
			while ((line = cmdOutput.readLine()) != null) {
				System.err.println(line);
			}
		} catch (IOException e) {
			System.err.println("Error while trying to print Rascal output error message.");
		}
	}

}
