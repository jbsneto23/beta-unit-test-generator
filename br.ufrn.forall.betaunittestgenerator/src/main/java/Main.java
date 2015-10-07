import java.io.File;

import configurations.Configurations;
import generator.UnitTestGenerator;


public class Main {

	public static void main(String[] args) {
		String rascalShellPath = Configurations.getRascalShellPath();
		String unitTestGeneratorPath = Configurations.getUnitTestGeneratorPath();
		String template = Configurations.getTemplate();
		String xmlFilePath = args[0];
		File file = new File(xmlFilePath);
		if(file.exists() && file.isFile()){
			UnitTestGenerator generator = new UnitTestGenerator(rascalShellPath, unitTestGeneratorPath, template);
			generator.generateUnitTest(xmlFilePath);	
		} else {
			System.out.println("File '" + xmlFilePath + "' does not exists!");
		}
		
	}

}
