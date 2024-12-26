package employee.login;
import java.io.*;
import java.util.*;

public class Login {
	
	//Private Variables
	private int id;
	private String password;
	
	
	
	
	
	//Parameterized Constructor
	public Login(int id, String password){
		this.id = id;
		this.password = password;
	}
	
	

	//Method to check whether the given Id and Password is in the system
	public int checkIdPass() {

		int a = 0;
		
		//Opening file 
		File file = new File("C:\\Users\\" + System.getProperty("user.name") + "\\Documents\\Product Management\\"+this.id+".txt");
		
		
		//Checking whether the file exists in the given Path
		if(file.exists()){
			
			//Exception Handling for opening the file and reading from it
			try {
				
				Scanner reader = new Scanner(file);
				String mainPass = reader.nextLine();
				
				//Checking whether the password inside the file is the same password given by the user
				if(this.password.equals(mainPass)) {
					a = 2;
				}
				else {
					a = 1;
				}
				
				
				//Closing the opened file
				reader.close();
				
			//Catching Exception if the file hasn't been found by the scanner
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				
			}
		}
		
		//If the file doesn't exist
		else {
			a = 0;
		}
	
		
		//Returning the value of a based upon the above conditions
		return a;
	}
	
	
	

}
