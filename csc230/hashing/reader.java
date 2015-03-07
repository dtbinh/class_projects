import java.net.*;
import java.io.*;
import java.util.*;

/**
 * 
 * @author Jake Orben this class is for running a hashing function
 * 
 */

public class reader {

	/**
	 * all of the used variabels 0 is for size 10 array 1 is for size 100 array
	 * 2 is for size 1000 array
	 */

	LinearNode[] sites0 = new LinearNode[10];
	LinearNode[] sites1 = new LinearNode[100];
	LinearNode[] sites2 = new LinearNode[1000];
	String current = null;
	long temp = 0;
	int temp0 = 0;
	int temp1 = 0;
	int temp2 = 0;

	public void run() throws IOException {

		/** reads in the file */

		BufferedReader in = new BufferedReader(new FileReader("hostnames.txt"));

		String inputLine;

		int i = 0;

		/** as long as there is another line of input, this loop runs */
		while ((inputLine = in.readLine()) != null) {

			Scanner scan = new Scanner(inputLine);

			current = scan.next();

			if (current.contains("-")) {

				String[] parts = current.split("-");

				current = parts[0] + parts[1];

			}

				
			add(current);
			
		}
			
		String siteName = "tumblr.com";

		System.out.println("Size of 10 hash table: " + size(sites0));
		System.out.println("Size of 100 hash table: " + size(sites1));
		System.out.println("Size of 1000 hash table: " + size(sites2));
		System.out.println("# of tumblr.com hostnames in size 10 hash table: "
				+ countElement(sites0, siteName));
		System.out.println("# of tumblr.com hostnames in size 100 hash table: "
				+ countElement(sites1, siteName));
		System.out
				.println("# of tumblr.com hostnames in size 1000 hash table: "
						+ countElement(sites2, siteName));
		System.out.println("# of collisions in size of 10 hash table: "
				+ collisions(sites0));
		System.out.println("# of collisions in size of 100 hash table: "
				+ collisions(sites1));
		System.out.println("# of collisions in size of 1000 hash table: "
				+ collisions(sites2));
		System.out.println("Longest Chain in size of 10 hash table: "
				+ longestChain(sites0));
		System.out.println("Longest Chain in size of 100 hash table: "
				+ longestChain(sites1));
		System.out.println("Longest Chain in size of 1000 hash table: "
				+ longestChain(sites2));
	}

	/**used if there is a collision*/
	
	public void filler(LinearNode previous, LinearNode input) {

		while (previous.getNext() != null) {

			previous = previous.getNext();

		}

		previous.setNext(input);
		previous = previous.getNext();
		previous.setNext(null);
	}
	
	/**used to get array index*/

	public static int baseCon(long num, int modLength) {
		long length;
		long base = 7;

		/** boolean for the loop */
		boolean isConverted = false;

		LinkedStack stack = new LinkedStack();
		String convertedNum = "";

		/**
		 * conversion loop, pushes the proper number onto the stack
		 */
		do {
			/**
			 * if the num is less than the base, then this is the last time
			 * through the loop
			 */
			if (num < base)
				isConverted = true;

			stack.push(Long.toString(num % base, (int) base).toUpperCase());
			num = num / base;

		} while (!isConverted);

		/** because stack length decreases as you each element is popped in loop */
		length = stack.getLength();

		/** populates a string with the values popped off of the stack (LIFO) */
		for (int i = 0; i < length; i++) {
			convertedNum = convertedNum + stack.pop();
		}

		num = Long.valueOf(convertedNum) % modLength;

		int outgoing = (int) num;

		return outgoing;

	}

	/**adds a new element to each of the three arrays*/
	
	public void add(String input) {

		if (input.contains("-")) {

			String[] parts = input.split("-");

			input = parts[0] + parts[1];

		}

		LinearNode incomming0 = new LinearNode(current);
		LinearNode incomming1 = new LinearNode(current);
		LinearNode incomming2 = new LinearNode(current);

		temp = input.hashCode();

		temp = Math.abs(temp);

		temp0 = baseCon(temp, 10);

		temp1 = baseCon(temp, 100);

		temp2 = baseCon(temp, 1000);

		/**
		 * Array size 10
		 */

		if (sites0[temp0] != null) {

			filler(sites0[temp0], incomming0);

		}

		if (sites0[temp0] == null) {

			sites0[temp0] = incomming0;

		}

		/** array size 100 */

		if (sites1[temp1] != null) {

			filler(sites1[temp1], incomming1);

		}

		if (sites1[temp1] == null) {

			sites1[temp1] = incomming1;

		}

		/** Array size 1000 */

		if (sites2[temp2] != null) {

			filler(sites2[temp2], incomming2);

		}

		if (sites2[temp2] == null) {

			sites2[temp2] = incomming2;

		}

	}

	/**checks to see if an element in the array contains an exact phrase*/
	
	public boolean contains(LinearNode input, String has) {

		if (input.getElement() == has) {
			return true;
		}

		else
			return false;

	}

	/**determines the total number of elements in the hash table*/
	
	public int size(LinearNode[] inputArray) {

		int count = 0;
		for (int i = 0; i < inputArray.length; i++) {
			if (inputArray[i] != null) {
				count++;
				LinearNode holding = new LinearNode();

				holding = inputArray[i];

				while (holding.getNext() != null) {

					holding = holding.getNext();
					count++;

				}

			}

		}

		return count;

	}

	/**used to count the number of collisions in a given hash table*/
	
	public int collisions(LinearNode[] inputArray) {

		int count = 0;

		for (int i = 0; i < inputArray.length; i++) {

			if (inputArray[i] != null) {

				if (inputArray[i].getNext() != null) {

					LinearNode holding = new LinearNode();

					holding = inputArray[i];

					while (holding.getNext() != null) {

						holding = holding.getNext();
						count++;

					}

				}

			}

		}

		return count;

	}

	/**determines the longest chain in a hash table*/
	
	public int longestChain(LinearNode[] inputArray) {

		int count = 0;

		for (int i = 0; i < inputArray.length; i++) {

			int internalCount = 0;

			if (inputArray[i] != null) {

				internalCount++;

				LinearNode holding = new LinearNode();

				holding = inputArray[i];

				while (holding.getNext() != null) {

					holding = holding.getNext();
					internalCount++;

				}

			}

			if (internalCount > count)
				count = internalCount;

		}

		return count;

	}

	/**counts all elements in a hash table that contain a partial or whole string*/
	
	public int countElement(LinearNode[] inputArray, String inputString) {

		int count = 0;

		for (int i = 0; i < inputArray.length; i++) {

			if (inputArray[i] != null) {

				if (inputArray[i].getElement().contains(inputString))
					count++;

				LinearNode holding = new LinearNode();

				holding = inputArray[i];

				while (holding.getNext() != null) {

					holding = holding.getNext();

					if (holding.getElement().contains(inputString))
						count++;

				}

			}

		}

		return count;

	}

}