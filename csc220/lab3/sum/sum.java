import java.util.Scanner;

public class sum{
    /** takes input from user to run throughout the program*/
    
    public static void main (String[] args){

	int num;

	float total = 0;

	int count = 0;

	Scanner scan = new Scanner (System.in);

	while (count < 5){

	    System.out.println ("Enter a number (0 to 100): ");
	    num = scan.nextInt();
       	
	    total = num + total;

	    count = count + 1;

        }

	System.out.println(total);

	total = total/5;

	System.out.println(total);

	}
}