import generator.UnitTestGenerator;


public class Main {

	public static void main(String[] args) {
		UnitTestGenerator generator = new UnitTestGenerator("/Users/joaosouza/Dropbox/UFRN/rascal_workspace/rascal-shell-stable.jar", "/Users/joaosouza/Dropbox/UFRN/rascal_workspace/beta-unit-test-generator/BetaUnitTestGenerator/src/", "CuTest");
		generator.generateUnitTest("/Users/joaosouza/Dropbox/UFRN/rascal_workspace/beta-unit-test-generator/testing-files/report_for_balance_from_ATM_EC-EC_1501151329.xml");
	}

}
