import java.net.*;
import java.io.*;
import java.util.*;

/**
 * This is a class that reads in data from a web source, parses the information
 * and puts it into an array.
 * 
 * @author Jake
 * 
 */

public class reader {

	public void run() throws IOException {

		customers[] customerList;

		/** fetches the specified website information */
		URL personalData = new URL(
				"http://s3.amazonaws.com/depasquale/datasets/personalData.txt");

		BufferedReader in = new BufferedReader(new InputStreamReader(
				personalData.openStream()));

		/** there are 40,000 items in the web source so the array is 40,000 long */
		customerList = new customers[40000];

		in.readLine();

		String inputLine;

		/**
		 * used to count which iteration of the loop is currently being parsed,
		 * also used to assign array index values
		 */
		int i = 0;

		/** as long as there is another line of input, this loop runs */
		while ((inputLine = in.readLine()) != null) {

			Scanner scan = new Scanner(inputLine);

			/** sets the delimiter to tab */
			scan.useDelimiter("\t");

			int CustomerID = scan.nextInt();
			String Gender = scan.next();
			String FirstName = scan.next();
			String MiddleInitial = scan.next();
			String LastName = scan.next();
			String StreetAddress = scan.next();
			String City = scan.next();
			String State = scan.next();
			int ZipCode = scan.nextInt();
			String EmailAddress = scan.next();
			String TelephoneNumber = scan.next();
			String NationalID = scan.next();
			String Birthday = scan.next();
			String CreditCardType = scan.next();

			/** if there is no credit card information, a customer is created */
			if (CreditCardType.length() == 0) {
				customers customer = new customers(CustomerID, Gender,
						FirstName, MiddleInitial, LastName, StreetAddress,
						City, State, ZipCode, EmailAddress, TelephoneNumber,
						NationalID, Birthday);

				customerList[i] = customer;
			}

			/**
			 * if there is credit card information, then a purchasingCustomer is
			 * created
			 */
			else {
				long CreditCardNumber = scan.nextLong();
				int CreditCardConfirmationNumber = scan.nextInt();
				String ExpirationDate = scan.next();
				String UPSTrackingInfo = scan.next();

				purchasingCustomers pCustomer = new purchasingCustomers(
						CustomerID, Gender, FirstName, MiddleInitial, LastName,
						StreetAddress, City, State, ZipCode, EmailAddress,
						TelephoneNumber, NationalID, Birthday, CreditCardType,
						CreditCardNumber, CreditCardConfirmationNumber,
						ExpirationDate, UPSTrackingInfo);

				customerList[i] = pCustomer;
			}

			i++;
		}

		/** closes the web input stream */
		in.close();

		System.out.println("Your data file has been successfully submitted.");

		Arrays.sort(customerList);

		System.out.println("Your data has been sorted.");

		fileWriter fWrite = new fileWriter(customerList);

		fWrite.writer();

	}

}