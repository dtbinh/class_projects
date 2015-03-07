/**
 * 
 * This class is used to efficiently search for items in lists throughout the
 * main program.
 * 
 * @author Jake
 * @author people who wrote the book
 * 
 */

public class binarySearch {

	public static int binarySearch(Comparable[] data, Comparable target) {
		Comparable result = null;
		int first = 0, last = data.length - 1, mid = -1;

		/** if the value entered is null returns -1 */

		try {
			if (target.equals(null))
				return -1;
		} catch (NullPointerException npe) {
			return -1;
		}
		while (result == null && first <= last) {
			mid = (first + last) / 2; // determine midpoint

			if (data[mid].compareTo(target) == 0)
				result = data[mid];
			else if (data[mid].compareTo(target) > 0)
				last = mid - 1;
			else
				first = mid + 1;
		}

		/** if the item in question is not found returns -1 */

		if (result == null) {
			return -1;
		}

		/** returns index for character/issue */

		return mid;
	}

}
