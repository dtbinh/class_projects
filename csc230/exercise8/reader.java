import java.util.Scanner;

/**
 * this is a class to read the words in a sentence backwords.
 * 
 * @author Jake
 * 
 */

public class reader {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		/** takes the input from the user */
		System.out.print("Please enter a sentence: ");
		String input = scan.nextLine();

		Scanner word = new Scanner(input);

		/** holds the finished sentence */
		char[] finHold = new char[input.length()];

		/**
		 * counts the position in finHold so that the words are added in the
		 * correct place.
		 */
		int k = 0;

		while (word.hasNext()) {

			/** used to count each word backwards */
			int y = 1;

			String buffer = word.next();

			/**
			 * puts the stack of characters in the array for holding the
			 * completed sentence 
			 * note:charAt is being used in place of pop()
			 */
			for (int j = 0; j < buffer.length(); j++) {
				finHold[k] = buffer.charAt(buffer.length() - y);
				y++;
				k++;
			}

			/** add a space to the end of each word */
			if (k < input.length()) {
				finHold[k] = ' ';
				k++;
			}

		}

		/** prints out the sentence */
		for (int l = 0; l < input.length(); l++)
			System.out.print(finHold[l]);

	}

}
