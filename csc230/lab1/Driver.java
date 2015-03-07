/** 
*This is the driver class the initiates the program
*@Jake Orben
*@Kyle Bijou
*/

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Driver {

/**
*This is a method to check for exceptions
*It also  throws an error message when the requested file could not be located
*
*/

	
	public static void main(String[] args) throws OutOfRangeException{
	
		StockChecker checker = new StockChecker();
		try {
			checker.process();
		} catch (FileNotFoundException e) {
			System.err.println("The requested file could not be found.");
		}		
	
	}

}