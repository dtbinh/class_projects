/**
 * this is the clas for the binary search method
 * @Jake Orben
 */

import java.lang.System;

public class binarySearch {

	/** starts metrics */

	static long estimatedTime;
	static long startTime = System.nanoTime();
	static long calculations = 0;

	public static chemical bSearch(chemical[] importChemicalList,
			String requestedValue) {

		chemical result = null;
		int first = 0;
		int last = importChemicalList.length - 1;
		int mid;

		/** as long as there is no result and the array is not at the end */

		while (result == null && first <= last) {

			calculations++;

			/** sets the midpoint */

			mid = (first + last) / 2;

			/**
			 * constantly splits the array in half looking for the
			 * requestedValue
			 */

			try {

				if (importChemicalList[mid].getCASNumber().compareTo(
						requestedValue) == 0) {
					result = importChemicalList[mid];
				}

				else {
					if (importChemicalList[mid].getCASNumber().compareTo(
							requestedValue) > 0) {
						last = mid - 1;
					} else {
						first = mid + 1;
					}

				}
			}

			/** used in case an element in the array is null */

			catch (NullPointerException npe) {
				calculations++;
				/**
				 * if it is getting a null value it is too close to the front of
				 * the array, sends the search further backwards
				 */
				first = mid + 1;
			}

		}

		estimatedTime = System.nanoTime() - startTime;

		return result;

	}

	public static void setStartTime(long XStartTime) {
		startTime = XStartTime;
	}

	public static long getStartTime() {
		return startTime;
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
