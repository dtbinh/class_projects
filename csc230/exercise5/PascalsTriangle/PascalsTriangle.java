/**
 * @JakeOrben
 * @ErinWojciechowski
 * CSC 230
 * 
 * This is a program to calculate the Nth row of Pascal's Triangle
 */

import java.util.Scanner;

public class PascalsTriangle {

	public static void main(String[] args) {
	       
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Please enter the row of Pascal's triangle that you would like to see: ");
	
		int n = scan.nextInt();
	       
	    int[] prevHolder = new int[0];
	    
	    /**this is a loop that runs n times, where n is the row number that the user wants to see*/
	    
	    for (int i = 0; i < n; i++) {
	          
	    	/** calls the "process" method handing it the "prevHolder" array*/
	        prevHolder = process(prevHolder);
	        
	    }
	    
	    /**prints out the last line of Pascal's triangle*/
	    for (int i = 0; i < n; i++)
	    	System.out.print(prevHolder[i] + " ");
	 }
	 
	 public static int[] process(int[] prevHolder) {
	       
	     /**creates an array called "holder" that is 1 larger than the array fed into it*/ 
		 int[] holder = new int[prevHolder.length + 1];
	       
	     /**the first entry in holder will always be 1*/	    
	     holder[0] = 1;
	    
	     /**this loop populates the numbers inbetween the first and last index values, the first and last values are already handled*/
	     for (int i = 1; i < holder.length - 1; i++) {
	    	 holder[i] = prevHolder[i-1] + prevHolder[i];
	    }
	    
	     /**the last entry in holder is always 1*/
	     holder[holder.length - 1] = 1;
	      
	     
	    /**returns the result from this iteration of the for loop in the main method to be used in the next iteration*/	    
	    return holder;
	 }
}
	

