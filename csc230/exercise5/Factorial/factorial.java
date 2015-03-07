import java.lang.*;
import java.util.Scanner;

/** 
 * @Jake Orben
 * @Erin Wojciechowski
 *
 * This class will prompt the user to input a number to
 * calculate its factorial.
 */
public class factorial {
    public static void main (String[] args) {
    	
    	Scanner scan = new Scanner(System.in);
    	System.out.println("Please enter a number for its factorial");
    	int N = scan.nextInt();
	/**
	 * The recursion method will be invoked in the main.
	 */
    	System.out.println(findRecursive(N));
    
    }
    
    /** 
	* This is the recurive method. It will take the number, N, 
	* and multiply it by N-1 until it becomes 1.
	*/
    public static int findRecursive(int N){
	
    	if (N == 1){
    		return N;
    	}
	
    	else{
    		return N*findRecursive(N-1);
    	}
    
    }
   
}