/**
 * 
 * This is a method to take in all of the data and call a majority of the other files in this program.
 * @ Jake Orben
 * 
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class chemicalData {

	/** used to check for all input output errors. */

	public void run() throws IOException {

		chemical[] chemicalList = new chemical[2000];

		String inputLine;

		BufferedReader in = new BufferedReader(new FileReader("toxins.csv"));

		in.readLine();

		int i = 0;

		/** used to record all of the incomming data */

		while ((inputLine = in.readLine()) != null) {

			Scanner scan = new Scanner(inputLine);

			scan.useDelimiter(", *");
			String chemicalName = scan.next();
			String casNumber = scan.next();
			String cleanAirAct = scan.next();
			String classification = scan.next();
			String metal = scan.next();
			int metalCategory = scan.nextInt();
			String carcinogen = scan.next();
			String formType = scan.next();
			String unitOfMeasurment = scan.next();
			String riskFactor = scan.next();

			chemical c = new chemical(chemicalName, casNumber, cleanAirAct,
					classification, metal, metalCategory, carcinogen, formType,
					unitOfMeasurment, riskFactor);

			/** used to determine if a number is a duplicate */

			int keeper = 1;

			for (int j = 0; j < i; j++) {
				try {
					if (chemicalList[j].getCASNumber().compareTo(
							c.getCASNumber()) == 0) {
						keeper = 0;
					}

				}

				catch (NullPointerException npe) {
					continue;
				}
			}

			/** puts non duplicate CASNumbers into a chemical array */

			if (keeper == 1) {
				chemicalList[i] = c;
				i++;
			}

		}

		in.close();

		System.out.println("Your data file has been successfully submitted.");

		/**
		 * calls all of the linear searches and has their metrics recorded to
		 * the appropriate file, also sets time and calculations to zero.
		 */

		linearSearch.lSearch(chemicalList, "75887");

		fileWriter.starter();
		fileWriter.writerLinearSearch();
		linearSearch.setCalculations(0);
		linearSearch.setEstimatedTime(0);

		linearSearch.lSearch(chemicalList, "7440473");

		fileWriter.writerLinearSearch();
		linearSearch.setCalculations(0);
		linearSearch.setEstimatedTime(0);

		linearSearch.lSearch(chemicalList, "100425");

		fileWriter.writerLinearSearch();
		linearSearch.setCalculations(0);
		linearSearch.setEstimatedTime(0);

		linearSearch.lSearch(chemicalList, "1");

		fileWriter.writerLinearSearch();
		linearSearch.setCalculations(0);
		linearSearch.setEstimatedTime(0);

		System.out.println("Linear Search completed.");

		/**
		 * calls all of the sorting methods and has their metrics recorded to
		 * the appropriate file.
		 */

		insertionSort.iSort(chemicalList);
		System.out.println("Insertion sort completed.");

		mergeSort.mSort(chemicalList, 0, chemicalList.length - 1);
		System.out.println("Merge sort completed.");

		chemical[] sortedList = new chemical[2000];
		sortedList = quickSort.qSort(chemicalList, 0, chemicalList.length - 1);
		System.out.println("Quick sort completed.");

		bucketSort.bSort(chemicalList);
		System.out.println("Bucket sort completed.");

		/**
		 * calls all of the binary searches and has their metrics written to the
		 * appropriate file, also sets time and calculations to zero
		 */

		binarySearch.bSearch(sortedList, "N982"); // end

		fileWriter.writerSort();
		fileWriter.writerBinarySearch();
		binarySearch.setCalculations(0);
		binarySearch.setEstimatedTime(0);

		binarySearch.bSearch(sortedList, "924425"); // middle

		fileWriter.writerBinarySearch();
		binarySearch.setCalculations(0);
		binarySearch.setEstimatedTime(0);

		binarySearch.bSearch(sortedList, "100425"); // beginning

		fileWriter.writerBinarySearch();
		binarySearch.setCalculations(0);
		binarySearch.setEstimatedTime(0);

		binarySearch.bSearch(sortedList, "1");
		System.out.println("Binary search completed.");

		fileWriter.writerBinarySearch();
		fileWriter.writerClose();

	}

}
