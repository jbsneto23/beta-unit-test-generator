import generator.UnitTestGenerator;


public class Main {

	public static void main(String[] args) {
		UnitTestGenerator generator = new UnitTestGenerator("/Users/joaosouza/Projetos/beta-unit-test-generator/dependencies/rascal-shell-stable.jar", "/Users/joaosouza/Projetos/beta-unit-test-generator/BetaUnitTestGenerator/src/", "CuTest");
		generator.generateUnitTest("/Users/joaosouza/Projetos/beta-unit-test-generator/testing-files/report_for_BlueMove_from_TicTacToe_EC-PW_2505151214.xml");
	}

}
