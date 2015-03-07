import java.util.Scanner;
import java.text.DecimalFormat;

/**
 * This class stores all of the data sent from the reader class.
 * 
 * @author Jake
 * 
 */

public class customers implements Comparable<Object> {

	/** creates all of the necessary customer variables */
	protected int customerID;
	protected String gender;
	protected String firstName;
	protected String middleInitial;
	protected String lastName;
	protected String streetAddress;
	protected String city;
	protected String state;
	protected int zipCode;
	protected String emailAddress;
	protected String telephoneNumber;
	protected String nationalID;
	protected String birthday;
	protected String editedStreetAddress;

	public customers(int CustomerID, String Gender, String FirstName,
			String MiddleInitial, String LastName, String StreetAddress,
			String City, String State, int ZipCode, String EmailAddress,
			String TelephoneNumber, String NationalID, String Birthday) {

		/** assigns the values of the customer's data sent from the reader class */
		customerID = CustomerID;
		gender = Gender;
		firstName = FirstName;
		middleInitial = MiddleInitial;
		lastName = LastName;
		streetAddress = StreetAddress;
		city = City;
		state = State;
		zipCode = ZipCode;
		emailAddress = EmailAddress;
		telephoneNumber = TelephoneNumber;
		nationalID = NationalID;
		birthday = Birthday;

		Scanner scan = new Scanner(streetAddress);
		scan.nextInt();
		editedStreetAddress = scan.nextLine();
	}

	public void setCustomerID(int CustomerID) {
		this.customerID = CustomerID;
	}

	public int getCustomerID() {
		return customerID;
	}

	public void setGender(String Gender) {
		this.gender = Gender;
	}

	public String getGender() {
		return gender;
	}

	public void setFirstName(String FirstName) {
		this.firstName = FirstName;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setMiddleInitial(String MiddleInitial) {
		this.middleInitial = MiddleInitial;
	}

	public String getMiddleInitial() {
		return middleInitial;
	}

	public void setLastName(String LastName) {
		this.lastName = LastName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setStreetAddress(String StreetAddress) {
		this.streetAddress = StreetAddress;
	}

	public String getStreetAddress() {
		return streetAddress;
	}

	public void setCity(String City) {
		this.city = City;
	}

	public String getCity() {
		return city;
	}

	public void setState(String State) {
		this.state = State;
	}

	public String getState() {
		return state;
	}

	public void setZipCode(int ZipCode) {
		this.zipCode = ZipCode;
	}

	public int getZipCode() {
		return zipCode;
	}

	public void setEmailAddress(String EmailAddress) {
		this.emailAddress = EmailAddress;
	}

	public String getEmailAddress() {
		return emailAddress;
	}

	public void setTelephoneNumber(String TelephoneNumber) {
		this.telephoneNumber = TelephoneNumber;
	}

	public String getTelephoneNumber() {
		return telephoneNumber;
	}

	public void setNationalID(String NationalID) {
		this.nationalID = NationalID;
	}

	public String getNationalID() {
		return nationalID;
	}

	public void setBirthday(String Birthday) {
		this.birthday = Birthday;
	}

	public String getBirthday() {
		return birthday;
	}

	public void setEditedStreetAddress(String editedStreetAddress) {
		this.editedStreetAddress = editedStreetAddress;
	}

	public String getEditedStreetAddress() {
		return editedStreetAddress;
	}

	public String toString() {
		String Output = "";
		DecimalFormat fmt = new DecimalFormat("00000");
		Output += getCustomerID() + "\t" + getGender() + "\t" + getFirstName()
				+ "\t" + getMiddleInitial() + "\t" + getLastName() + "\t"
				+ getStreetAddress() + "\t" + getCity() + "\t" + getState()
				+ "\t" + fmt.format(getZipCode()) + "\t" + getEmailAddress()
				+ "\t" + getTelephoneNumber() + "\t" + getNationalID() + "\t"
				+ getBirthday();
		return Output;
	}

	public int compareTo(Object o) {
		customers customer2 = (customers) o;

		if (state.compareTo(customer2.getState()) < 0)
			return -3;

		if (state.compareTo(customer2.getState()) == 0)
			if (zipCode - (customer2.getZipCode()) > 0)
				return -2;

		if (state.compareTo(customer2.getState()) == 0)
			if (zipCode - (customer2.getZipCode()) == 0)
				if (editedStreetAddress.compareTo(customer2
						.getEditedStreetAddress()) < 0)
					return -1;

		if (state.compareTo(customer2.getState()) == 0)
			if (zipCode - (customer2.getZipCode()) == 0)
				if (editedStreetAddress.compareTo(customer2
						.getEditedStreetAddress()) > 0)
					return 1;

		if (state.compareTo(customer2.getState()) == 0)
			if (zipCode - (customer2.getZipCode()) < 0)
				return 2;

		if (state.compareTo(customer2.getState()) > 0)
			return 3;

		else
			return 0;

	}
}