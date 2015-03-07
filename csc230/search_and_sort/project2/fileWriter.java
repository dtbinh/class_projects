import java.io.*;

/**
 * This class prints out the sorted data from the compareTo class.
 * 
 * @author Jake
 * 
 */

public class fileWriter {

	static PrintWriter out;
	static int counterL = 0;
	static int counterB = 0;

	/** starts the output stream for the program */

	public static void starter() throws IOException {
		FileWriter fileStream = new FileWriter("sortingDataMetrics.txt");
		BufferedWriter OO = new BufferedWriter(fileStream);
		out = new PrintWriter(OO);
		out.println("Sort/Search Method" + "\t\t" + "Duration" + "\t"
				+ "Calculations");
	}

	/** writes all of the data for the linear search */

	public static void writerLinearSearch() {

		if (counterL == 0)
			out.print("Linear Search (end):" + "\t\t");
		else if (counterL == 1)
			out.print("Linear Search (middle):" + "\t\t");
		else if (counterL == 2)
			out.print("Linear Search (beginning):" + "\t");
		else if (counterL == 3)
			out.print("Linear Search (DNE):" + "\t\t");
		out.print(linearSearch.getEstimatedTime() + "\t\t");
		out.println(linearSearch.getCalculations());

		counterL++;

	}

	/** writes all of the data for the sorting algorithims */

	public static void writerSort() {

		try {

			out.print("Insertion Sort:" + "\t\t\t");
			out.print(insertionSort.getEstimatedTime() + "\t\t");
			out.println(insertionSort.getCalculations());
			out.print("Merge Sort:" + "\t\t\t");
			out.print(mergeSort.getEstimatedTime() + "\t\t");
			out.println(mergeSort.getCalculations());
			out.print("Quick Sort:" + "\t\t\t");
			out.print(quickSort.getEstimatedTime() + "\t\t");
			out.println(quickSort.getCalculations());
			out.print("Bucket Sort:" + "\t\t\t");
			out.print(bucketSort.getEstimatedTime() + "\t\t");
			out.println(bucketSort.getCalculations());

		}

		catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}

	/** writes all of the data for the binary searches */

	public static void writerBinarySearch() {

		if (counterB == 0)
			out.print("Binary Search (end):" + "\t\t");
		else if (counterB == 1)
			out.print("Binary Search (middle):" + "\t\t");
		else if (counterB == 2)
			out.print("Binary Search (begining):" + "\t");
		else if (counterB == 3)
			out.print("Binary Search (DNE):" + "\t\t");
		out.print(binarySearch.getEstimatedTime() + "\t\t");
		out.println(binarySearch.getCalculations());

		counterB++;

	}

	public static void writerClose() {
		out.close();

		System.out
				.println("Your data has been sent to the requested output file");
	}

}
