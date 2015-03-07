import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * This is a class to read in all of the data necessary to generate an adjency
 * matrix, it also generates the matrix and runs the core functionality for
 * searching for characters and issues as well as determing the shortest path
 * between any two verticies.
 * 
 * 
 * Note: in for loops I tried to avoid using the same counter two times, as I
 * ran into some strange results once.
 * 
 * @author Jake
 * 
 */

public class reader {

	/** starts the search method used throughout the entire class */

	static binarySearch search = new binarySearch();

	/**
	 * reads in all of the data and parses it, also used to run core methods
	 * (character search, issue search and shortest path)
	 */

	public static void parse() {

		/** variables used for the file read in and generation of adjency matrix */

		File characters = new File("marvelCharacterVertices.txt");
		File issues = new File("marvelIssueVertices.txt");
		File matrix = new File("marvelGraph.tsv");
		int characterCount = 0;
		int issueCount = 0;
		int matrixCount = 0;
		int characterIndex = 0;
		int issueIndex = 0;
		int matrixIndex = -1;

		/**
		 * counts the number of element being scanned in so an array can be made
		 * without resizing
		 */

		/** used for character */

		try {
			Scanner characterCountScan = new Scanner(characters);
			while (characterCountScan.hasNextLine() == true) {

				characterCount++;
				characterCountScan.nextLine();

			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		/** used for issues */

		try {
			Scanner issueCountScan = new Scanner(issues);
			while (issueCountScan.hasNextLine() == true) {

				issueCount++;
				issueCountScan.nextLine();

			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		/** used for connection list */

		try {
			Scanner matrixCountScan = new Scanner(matrix);
			while (matrixCountScan.hasNextLine() == true) {

				matrixCount++;
				matrixCountScan.nextLine();

			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		/** arrays that contain the names of characters and issues */

		String[] characterList = new String[characterCount];
		String[] issueList = new String[issueCount];

		/** scans in all of the characters and removes vertex numbers */

		try {
			Scanner characterScan = new Scanner(characters);
			while (characterScan.hasNext() == true) {

				String characterTemp = null;
				String[] clean0;

				characterTemp = characterScan.nextLine();

				clean0 = characterTemp.split(": ");

				/** pares out extra spaces at the end of entries */

				if (clean0.length != 1) {
					characterList[characterIndex] = clean0[1];
					if (characterList[characterIndex].endsWith(" ")) {
						characterList[characterIndex] = characterList[characterIndex]
								.substring(
										0,
										characterList[characterIndex].length() - 1);
					}
				}

				else {
					characterList[characterIndex] = "emptyEDNE";
				}
				// System.out.println(characterList[characterIndex]);

				characterIndex++;

			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		/** scans in all of the issues and removes vertex number */

		try {
			Scanner issueScan = new Scanner(issues);
			while (issueScan.hasNextLine() == true) {

				String issueTemp = null;
				String[] clean1;

				issueTemp = issueScan.nextLine();

				clean1 = issueTemp.split(": ");

				issueList[issueIndex] = clean1[1];

				/** parses out spaces at the end of entries */

				if (clean1.length != 1) {
					issueList[issueIndex] = clean1[1];
					if (issueList[issueIndex].endsWith(" ")) {
						issueList[issueIndex] = issueList[issueIndex]
								.substring(0,
										issueList[issueIndex].length() - 1);
					}

					issueIndex++;

				}

			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		String[][] connectionMatrix = new String[matrixCount][2];

		/** scans in the list of connections into 2D array */

		try {
			Scanner matrixScan = new Scanner(matrix);
			while (matrixScan.hasNextLine() == true) {

				String matrixTemp = null;

				matrixTemp = matrixScan.nextLine();

				Scanner scan = new Scanner(matrixTemp);
				scan.useDelimiter("\t");

				matrixIndex++;

				/**
				 * parses out quotes and extra characters at the beginning and
				 * end of entries
				 */

				connectionMatrix[matrixIndex][0] = scan.next();
				if (connectionMatrix[matrixIndex][0].startsWith("\"")) {
					connectionMatrix[matrixIndex][0] = connectionMatrix[matrixIndex][0]
							.substring(1,
									connectionMatrix[matrixIndex][0].length());
				}
				if (connectionMatrix[matrixIndex][0].endsWith("\"")) {
					connectionMatrix[matrixIndex][0] = connectionMatrix[matrixIndex][0]
							.substring(
									0,
									connectionMatrix[matrixIndex][0].length() - 1);
				}
				if (connectionMatrix[matrixIndex][0].endsWith(" ")) {
					connectionMatrix[matrixIndex][0] = connectionMatrix[matrixIndex][0]
							.substring(
									0,
									connectionMatrix[matrixIndex][0].length() - 1);
				}

				/**
				 * used in case there is a null value in the first slot of the
				 * input
				 */

				try {

					/**
					 * parses out quotes and extra characters at the beginning
					 * and end of entries
					 */

					connectionMatrix[matrixIndex][1] = scan.next();
					if (connectionMatrix[matrixIndex][1].startsWith("\"")) {
						connectionMatrix[matrixIndex][1] = connectionMatrix[matrixIndex][1]
								.substring(1, connectionMatrix[matrixIndex][1]
										.length());
					}
					if (connectionMatrix[matrixIndex][1].endsWith("\"")) {
						connectionMatrix[matrixIndex][1] = connectionMatrix[matrixIndex][1]
								.substring(0, connectionMatrix[matrixIndex][1]
										.length() - 1);
					}
					if (connectionMatrix[matrixIndex][1].endsWith(" ")) {
						connectionMatrix[matrixIndex][1] = connectionMatrix[matrixIndex][1]
								.substring(0, connectionMatrix[matrixIndex][1]
										.length() - 1);
					}

				} catch (NoSuchElementException nsee) {
					connectionMatrix[matrixIndex][1] = connectionMatrix[matrixIndex][0];
					connectionMatrix[matrixIndex][0] = null;
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		boolean[][] adjencyMatrix = new boolean[characterCount][issueCount];

		/**
		 * for (int l = 0; l < connectionMatrix.length; l++){
		 * System.out.print(connectionMatrix[l][0]); System.out.print("\t");
		 * System.out.println(connectionMatrix[l][1]); }
		 */
		/** populates truth table */

		Arrays.sort(characterList);
		Arrays.sort(issueList);

		/** generates the adjency matrix for all of the connections */

		for (int i = 0; i < connectionMatrix.length; i++) {
			try {
				adjencyMatrix[search.binarySearch(characterList,
						connectionMatrix[i][0])][search.binarySearch(issueList,
						connectionMatrix[i][1])] = true;
			} catch (ArrayIndexOutOfBoundsException aioobe) {
				continue;
			}

		}

		/** prints adjency matrix */

		/**
		 * for (int check0 = 0; check0 < adjencyMatrix.length; check0++){ for
		 * (int check1 = 0; check1 < adjencyMatrix[0].length; check1++){ if
		 * (check1 != adjencyMatrix[0].length -1){
		 * System.out.print(adjencyMatrix[check0][check1]);
		 * System.out.print("\t"); } else
		 * System.out.println(adjencyMatrix[check0][check1]); } }
		 */

		/** scans for user input */
		Scanner userInput = new Scanner(System.in);
		String userRequest = null;

		System.out
				.println("What character would you like to search for relationships?");

		userRequest = userInput.nextLine();

		characterSearch(userRequest, characterList, issueList, adjencyMatrix);

		System.out
				.println("What issue would you like to search for relationships?");

		userRequest = userInput.nextLine();

		issueSearch(userRequest, characterList, issueList, adjencyMatrix);

		/** would run the shortest path method if it worked. */

		/**
		 * int distance = 0;
		 * 
		 * distance = shortestPath("VENOM/EDDIE BROCK", "DEMOGOBLIN",
		 * characterList, issueList, adjencyMatrix);
		 * 
		 * if (distance == -1){ System.out.println(
		 * "The character that you have enterd is not connected to the desired character"
		 * ); }
		 * 
		 * distance = distance/2;
		 * 
		 * System.out.println(distance);
		 */
	}

	/** searches for issues connected to a given character */

	public static void characterSearch(String target, String[] charList,
			String[] issueList, boolean[][] adjencyMatrix) {

		int index = 0;
		index = search.binarySearch(charList, target);
		if (index == -1) {
			System.out
					.println("The character that you have entered is invalid.");
			return;
		}
		for (int i = 0; i < adjencyMatrix[0].length; i++) {

			if (adjencyMatrix[index][i] == true) {
				System.out.println(issueList[i]);

			}

		}

	}

	/** searches for characters connected to a given issue */

	public static void issueSearch(String target, String[] charList,
			String[] issueList, boolean[][] adjMatrix) {

		int index = 0;
		index = search.binarySearch(issueList, target);
		if (index == -1) {
			System.out.println("The issue that you have entered is invalid.");
			return;
		}
		for (int i = 0; i < adjMatrix.length; i++) {

			if (adjMatrix[i][index] == true) {
				System.out.println(charList[i]);

			}

		}

	}

	static LinkedQueue<String> queue = new LinkedQueue();
	static LinearNode<String> visited = new LinearNode();
	static int currentPath = 0;
	static int shortestPath = 0;

	/** used to determine the shortest path between any two characters */

	public static int shortestPath(String character0, String character1,
			String[] charList, String[] issueList, boolean[][] adjMatrix) {

		int index = 0;
		boolean isValid = true;
		String tester = visited.getElement();
		String[] holding;

		/** splits the string to determine if it is a character or an issue */

		holding = character0.split(": :");
		if (holding.length == 2)
			character0 = holding[1];

		if (holding.length == 1)
			character0 = holding[0];

		/**
		 * base case, if there is nothing in the queue and the character being
		 * look for is the same as the character being found
		 */

		if (character0.equals(character1) && queue.isEmpty() == true) {
			return shortestPath;
		}

		/**
		 * if a path is found but there are still other paths to explore this
		 * occures
		 */

		if (character0.equals(character1)) {
			shortestPath(queue.dequeue(), character1, charList, issueList,
					adjMatrix);
		}

		/** determines if an element has been visited before */

		while (visited.getElement() != null && visited.getNext() != null) {
			if (character0.equals(tester)) {
				isValid = false;
			}
			tester = visited.getNext().getElement();
		}

		/** if this is the first itiration or if a character is being scanned in */

		if ((holding[0].equals("character") && isValid == true)
				|| holding.length == 1) {

			index = search.binarySearch(charList, character0);

			/**
			 * looks through adjency matrix to determine truth values for a
			 * given row
			 */

			for (int i = 0; i < adjMatrix[0].length - 1; i++) {

				if (adjMatrix[index][i] == true) {
					queue.enqueue("issue: :" + issueList[i]);
				}

			}

			/** calls next item in the queue */

			shortestPath(queue.dequeue(), character1, charList, issueList,
					adjMatrix);

		}

		/** used if an issue is being scanned in */

		if (holding[0].equals("issue") && isValid == true) {

			index = search.binarySearch(issueList, character0);

			/**
			 * looks through truth table to determine truth values for a given
			 * column
			 */

			for (int i = 0; i < adjMatrix.length - 1; i++) {

				if (adjMatrix[i][index] == true) {
					queue.enqueue("character: :" + charList[i]);
				}

			}

			/** calls next item in the queue */

			shortestPath(queue.dequeue(), character1, charList, issueList,
					adjMatrix);

		}

		/** returns -1 if there is no path to the character */

		return -1;

	}

}
