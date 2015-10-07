package configurations;

import java.io.File;

import org.apache.commons.configuration.ConfigurationException;
import org.apache.commons.configuration.PropertiesConfiguration;

public class Configurations {

	private static String getPathToPropertiesFile() {
		File jarFile = new File(Configurations.class.getProtectionDomain().getCodeSource().getLocation().getPath());
		String jarFileDirectory = jarFile.getParentFile().getPath();

		String propertiesFilePath = jarFileDirectory + "/config.properties";
		
		return propertiesFilePath;
	}
	
	public static String getRascalShellPath() {
		String rascalShellPath = null;
		try {
			PropertiesConfiguration config = new PropertiesConfiguration(getPathToPropertiesFile());
			rascalShellPath = config.getString("rascal_shell_path");
		} catch (ConfigurationException e) {
			System.err.println("Could not get Rascal Shell path: " + e.getMessage());
		}
		return rascalShellPath;
	}
	
	public static String getUnitTestGeneratorPath() {
		String unitTestGeneratorPath = null;
		try {
			PropertiesConfiguration config = new PropertiesConfiguration(getPathToPropertiesFile());
			unitTestGeneratorPath = config.getString("unit_test_generator_path");
		} catch (ConfigurationException e) {
			System.err.println("Could not get Unit Test Generator path: " + e.getMessage());
		}
		return unitTestGeneratorPath;
	}
	
	public static String getTemplate() {
		String template = null;
		try {
			PropertiesConfiguration config = new PropertiesConfiguration(getPathToPropertiesFile());
			template = config.getString("template");
		} catch (ConfigurationException e) {
			System.err.println("Could not get Template: " + e.getMessage());
		}
		return template;
	}
	
}
