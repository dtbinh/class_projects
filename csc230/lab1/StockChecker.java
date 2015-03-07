import java.io.*;
import java.util.Scanner;

/**
*This class defines the parameters for stocks that are in and out of range
*
*@Jake Orben
*@Kyle Bijou
*/

public class StockChecker {

	/**A variable used to count total number of correct stocks*/
	
    private int count = 0;

	/**A variable used to determine the sum of all of the stocks combined*/

    private int sum = 0;
	

	/** retrieves and scans file for exceptions */
	public void process() throws FileNotFoundException	
	{
		Scanner scan = new Scanner (new File("lab1inp.txt"));
		while (scan.hasNext()) {
			String inputLine = scan.nextLine();
			try {
				if (checkValue (inputLine)) {
					count ++;
					sum += Integer.parseInt(inputLine);
					}
			}
			
			/**If a number is invalid that number is printed along with a message*/

			catch (OutOfRangeException oore) {
				System.out.println(inputLine + " is not a valid number.");
			}
		}
		System.out.println("Total number of shares processed is: " + sum);
		System.out.println("Average number of shares per transaction is: " + sum/count); 

	}
	
	/**
	*Defines the number of didged that are in the range
	*/
	
	private boolean checkValue (String inputLine){
		String value;
		value = inputLine;
		if (value.length() == 7) {
			
					
			boolean validResult = true;
			return validResult;
			
		}
		else{
			throw new OutOfRangeException ("incorrect value");	
		}
	
	}
		
}			
