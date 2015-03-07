/**
 * this class is used to instanciate the bucket sort method
 * @Jake Orben
 */

import java.lang.System;

public class bucketSort {

	/** starts metrics */

	static long estimatedTime;
	static long startTime = System.nanoTime();
	static long calculations = 0;

	/** declares top of stack */

	static int topOfStack = -1;
	static chemical[] buffer;

	public static void push(chemical incommingValue) {
		try {
			buffer[topOfStack + 1] = incommingValue;
			topOfStack++;
		}

		/** used in case the elements exceed the size of the array */

		catch (ArrayIndexOutOfBoundsException exception) {
			System.err.println("You have exceeded the array's size limit.");
			exception.printStackTrace();
		}
	}

	public static void bSort(chemical[] importChemicalList) {

		/**
		 * creates an array so that the main array containg data is not
		 * disturbed
		 */

		buffer = new chemical[importChemicalList.length];

		buffer = importChemicalList;

		/** marks how many didgets will be sorted */

		chemical[][] sorter = new chemical[10][importChemicalList.length];

		/** sorts the 10 distinct didgets */

		for (int i = 0; i < 9; i++) {

			for (int j = 0; j < importChemicalList.length; j++) {

				calculations++;

				try {

					if (buffer[j].getCASNumber().length() <= i) {
						sorter[0][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 0) {
						sorter[0][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 1) {
						sorter[1][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 2) {
						sorter[2][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 3) {
						sorter[3][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 4) {
						sorter[4][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 5) {
						sorter[5][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 6) {
						sorter[6][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 7) {
						sorter[7][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 8) {
						sorter[8][j] = buffer[j];
					}

					else if (buffer[j].getCASNumber().charAt(i) == 9) {
						sorter[9][j] = buffer[j];
					}

					else {
						sorter[0][j] = buffer[j];
					}

				}

				/** used in case an element in the array is null */

				catch (NullPointerException npe) {
					continue;
				}

			}

			/** puts all of the items into the correct array */

			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < buffer.length; l++) {
					if (sorter[k][l] != null) {
						push(sorter[k][l]);
					}

				}
				topOfStack = -1;
			}

		}

		estimatedTime = System.nanoTime() - startTime;

		buffer = null;

	}

	public static void setEstimatedTime(long XChemicalData) {
		estimatedTime = XChemicalData;
	}

	public static long getEstimatedTime() {
		return estimatedTime;
	}

	public static void setCalculations(long XCalculaitons) {
		calculations = XCalculaitons;
	}

	public static long getCalculations() {
		return calculations;
	}

}
