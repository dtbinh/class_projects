import java.io.*;

/**
 * This class prints out the sorted data from the compareTo class.
 * 
 * @author Jake
 * 
 */

public class fileWriter {

	private customers[] customerList;

	public fileWriter(customers[] cArray) {

		customerList = cArray;

	}

	public void writer() {

		try {
			FileWriter fileStream = new FileWriter("sortedData.txt");
			BufferedWriter OO = new BufferedWriter(fileStream);
			PrintWriter out = new PrintWriter(OO);
			out.println("Number" + "\t" + "Gender" + "\t" + "GivenName" + "\t"
					+ "MiddleInitial" + "\t" + "Surname" + "\t"
					+ "StreetAddress" + "\t" + "City" + "\t" + "State" + "\t"
					+ "ZipCode" + "\t" + "EmailAddress" + "\t"
					+ "TelephoneNumber" + "\t" + "NationalID" + "\t"
					+ "Birthday" + "\t" + "CCType" + "\t" + "CCNumber" + "\t"
					+ "CVV2" + "\t" + "CCExpires" + "\t" + "UPS");
			for (int i = 0; i < 40000; i++)
				out.println(customerList[i]);
			out.close();

			System.out
					.println("Your data has been sent to the requested output file.");
		}

		catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
	}
}
