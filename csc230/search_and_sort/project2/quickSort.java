/**
 * this class is used to run the quick sort method
 * @Jake Orben
 */

import java.lang.System;

public class quickSort {

	/** starts the calculations and time metrics */

	static long estimatedTime;
	static long startTime = System.nanoTime();
	static long calculations = 0;

	/** recursively sorts each side of a partition */

	public static chemical[] qSort(chemical[] importChemicalList, int min,
			int max) {

		chemical[] chemicalList = importChemicalList;

		int pivot;
		if (min < max) {
			pivot = partition(chemicalList, min, max);
			qSort(chemicalList, min, pivot - 1);
			qSort(chemicalList, pivot + 1, max);

		}

		estimatedTime = System.nanoTime() - startTime;

		return chemicalList;

	}

	/**
	 * used in case one number is larger than another, swaps the numbers to the
	 * correct side of the partition.
	 */

	private static void swap(chemical[] importChemicalList, int i1, int i2) {

		chemical[] chemicalList = importChemicalList;

		chemical temp = chemicalList[i1];
		chemicalList[i1] = chemicalList[i2];
		chemicalList[i2] = temp;

	}

	/**
	 * this partition is recursively called and constantly makes a partiton,
	 * which is used seperate smaller and larger values
	 */

	private static int partition(chemical[] importChemicalList, int min, int max) {

		chemical[] chemicalList = importChemicalList;

		chemical PV = chemicalList[min];

		int left = min;
		int right = max;

		try {

			while (left < right) {

				while (chemicalList[left].compareTo(PV) <= 0 && left < right) {
					calculations++;
					left++;
				}
				while (chemicalList[right].compareTo(PV) > 0) {
					calculations++;
					right--;
				}
				if (left < right)
					calculations++;
				swap(chemicalList, left, right);

			}
		}

		/** used in case an element in the array is null */

		catch (NullPointerException npe) {

		}

		swap(chemicalList, min, right);

		return right;

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
