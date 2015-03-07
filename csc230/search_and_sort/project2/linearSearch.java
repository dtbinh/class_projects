/**
 * this class is used for the linear search method
 * @Jake Orben
 */

import java.lang.System;

public class linearSearch {

	static long counter = 0;

	/** starts metrics */
	static long estimatedTime = 0;
	static long startTime = System.nanoTime();
	static long calculations = 0;

	/** main method */

	public static chemical lSearch(chemical[] importChemicalList,
			String requestedValue) {

		chemical result = null;

		/** counter for the while loop */
		int i = 0;

		/**
		 * searches through each element in the array to look for the
		 * requestedValue
		 */

		while (result == null && i < importChemicalList.length) {

			calculations++;

			try {
				if (importChemicalList[i].getCASNumber().equals(requestedValue))
					result = importChemicalList[i];
				i++;
			}

			/** used in case an element in the array is null */

			catch (NullPointerException npe) {
				i++;
			}
		}

		estimatedTime = System.nanoTime() - startTime;

		counter++;

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
