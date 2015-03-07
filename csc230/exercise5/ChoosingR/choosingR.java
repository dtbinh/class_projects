import java.util.*;
import java.io.*;

/**
 * @Jake Orben
 * @Erin Wojciechowski
 *
 * In this class, the program will test to see if each of the given 
 * values are a valid pair, take the factorial of both numbers, and calculate the 
 * possible choices.
 *
 */
public class choosingR {
    public static void proscess () {

    	int [] n = new int[3];
    	int [] r = new int[3];

		/**
		 * Loop for number N
		 */
    	for (int i = 0; i < 3; i ++){

    		System.out.println("Please enter your 3 N integers using returns to seperate them: ");

    		Scanner scan = new Scanner(System.in);

    		n[i] = scan.nextInt();

    	}
		
		/**
    	 * Loop for number R
    	 */
    	for (int i = 0; i < 3; i ++){

    		System.out.println("Please enter your 3 R integers using returns to seperate them: ");

    		Scanner scan = new Scanner(System.in);

    		r[i] = scan.nextInt();

    	}

    	/**
    	 * This loop will see if the boolean checkValue is true for the coordinates.
    	 * If not it will print an error message.
    	 *
    	 */ 
    	for (int i = 0; i < 3; i ++){

    		try{
				if(checkValue(n[i], r[i])); 
					System.out.println("The number of ways for choosing r for the following items: " + n[i] + ", " + r[i] + " is  " + C(n[i], r[i]));
			}
			catch (OutOfRangeException oore){
				System.err.println(n[i] + ", " + r[i] + " is not a valid set of numbers.");
			}
			
			

    	}

    }

	/**
	 *	This is the boolean method which will return true if n is greater than r, making 
	 * the coordinates valid.
	 */
	 	  
    private static boolean checkValue(int n, int r){
    	
    	if (n > r){
    		boolean validResult = true;
    		return validResult;
    	}
    	else
    		throw new OutOfRangeException("The set (" + n + ", " + r + ") is invalid");
    	
    }  
    
    /**
     * This method calculates the possible choices.
     */
    public static int C(int n, int r) {
    	
    	return findRecursive(n)/(findRecursive(r) * findRecursive(n-r));

    }
	
	/**
	 * This method solves the factorial of the numbers.
	 */
    public static int findRecursive(int n) {
    	
    		if (n == 1) 
    			return n;

    		else 
    			return n * findRecursive(n-1);
    		
	
    }

}