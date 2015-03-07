/**
 * this class is used to instanciate the merge sort
 * @Jake Orben
 */

import java.lang.System;

public class mergeSort {

	static long estimatedTime;
	static long startTime = System.nanoTime();
	static long calculations = 0;

	/**
	 * recusrively sorts data
	 */

	public static void mSort(chemical[] importChemicalList, int min, int max) {

		chemical[] chemicalList = importChemicalList;

		if (min < max) {

			int mid = (min + max) / 2;
			mSort(chemicalList, min, mid);
			mSort(chemicalList, mid + 1, max);
			merge(chemicalList, min, mid, max);

		}

		estimatedTime = System.nanoTime() - startTime;

	}

	/**
	 * this method is called to recursively and is used to merge the smalles
	 * number in a given array, base case is a one element array
	 */

	public static void merge(chemical[] importChemicalList, int first, int mid,
			int last) {

		chemical[] chemicalList = importChemicalList;

		chemical[] temp = new chemical[chemicalList.length];

		int first1 = first;
		int last1 = mid;
		int first2 = mid + 1;
		int last2 = last;
		int i = first1;

		try {

			while (first1 <= last1 && first2 <= last2) {

				calculations++;

				if (chemicalList[first1].compareTo(chemicalList[first2]) < 0) {
					temp[i] = chemicalList[first1];
					first1++;
				}

				else {
					temp[i] = chemicalList[first2];
					first2++;
				}
				i++;
			}

			while (first1 <= last1) {

				calculations++;

				temp[i] = chemicalList[first1];
				first1++;
				i++;
			}

			while (first2 <= last2) {

				calculations++;

				temp[i] = chemicalList[first2];
				first2++;
				i++;
			}

			for (i = first; i <= last; i++)
				chemicalList[i] = temp[i];

		}

		/** used in case an element in the array is null */
		
		catch (NullPointerException npe) {

		}

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
