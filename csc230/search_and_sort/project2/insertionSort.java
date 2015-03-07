/**
 * this class is used to run the insertion sort method
 * @Jake Orben
 */

import java.lang.System;

public class insertionSort {

	/** starts metrics */

	static long estimatedTime;
	static long startTime = System.nanoTime();
	static long calculations = 0;

	/**
	 * scans the array for the smallest element and puts it in the front of the
	 * array
	 */

	public static void iSort(chemical[] importChemicalList) {

		chemical[] chemicalList = importChemicalList;

		for (int i = 1; i < chemicalList.length; i++) {

			chemical key = chemicalList[i];

			for (int j = i; j > 0; j--) {

				calculations++;

				try {
					if (chemicalList[j - 1].compareTo(key) > 0) {

						chemicalList[j] = chemicalList[j - 1];

					}
				}

				/** used in case an element in the array is null */

				catch (NullPointerException npe) {
					continue;
				}

			}

		}

		estimatedTime = System.nanoTime() - startTime;

		chemicalList = null;
	}

	public static void setEstimatedTime(long XEstimatedTime) {
		estimatedTime = XEstimatedTime;
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
