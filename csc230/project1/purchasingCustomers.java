/**
 * This class stores all of the information sent from the reader class.
 * 
 * @author Jake
 * 
 */

public class purchasingCustomers extends customers {

	/** creates all of the necessary variables for purchasingCustomers */
	protected String creditCardType;
	protected long creditCardNumber;
	protected int creditCardConfirmationNumber;
	protected String expirationDate;
	protected String upsTrackingInfo;

	public purchasingCustomers(int CustomerID, String Gender, String FirstName,
			String MiddleInitial, String LastName, String StreetAddress,
			String City, String State, int ZipCode, String EmailAddress,
			String TelephoneNumber, String NationalID, String Birthday,
			String CreditCardType, long CreditCardNumber,
			int CreditCardConfirmationNumber, String ExpirationDate,
			String UPSTrackingInfo) {

		/** sends necessary data to customers class */
		super(CustomerID, Gender, FirstName, MiddleInitial, LastName,
				StreetAddress, City, State, ZipCode, EmailAddress,
				TelephoneNumber, NationalID, Birthday);

		/**
		 * assigns all of the purchasingCustomer data sent from the reader class
		 */
		creditCardType = CreditCardType;
		creditCardNumber = CreditCardNumber;
		creditCardConfirmationNumber = CreditCardConfirmationNumber;
		expirationDate = ExpirationDate;
		upsTrackingInfo = UPSTrackingInfo;
	}

	public void setCreditCardType(String CreditCardType) {
		this.creditCardType = CreditCardType;
	}

	public String getCreditCardType() {
		return creditCardType;
	}

	public void setCreditCardNumber(long CreditCardNumber) {
		this.creditCardNumber = CreditCardNumber;
	}

	public long getCreditCardNumber() {
		return creditCardNumber;
	}

	public void setCreditCardConfirmationNumber(int CreditCardConfirmationNumber) {
		this.creditCardConfirmationNumber = CreditCardConfirmationNumber;
	}

	public int getCreditCardConfirmationNumber() {
		return creditCardConfirmationNumber;
	}

	public void setExpirationDate(String ExpirationDate) {
		this.expirationDate = ExpirationDate;
	}

	public String getExpirationDate() {
		return expirationDate;
	}

	public void setUPSTrackingInfo(String UPSTrackingInfo) {
		this.upsTrackingInfo = UPSTrackingInfo;
	}

	public String getUPSTrackingInfo() {
		return upsTrackingInfo;
	}

	public String toString() {
		String CreditCardOutput = super.toString();
		CreditCardOutput += "\t" + getCreditCardType() + "\t"
				+ getCreditCardNumber() + "\t"
				+ getCreditCardConfirmationNumber() + "\t"
				+ getExpirationDate() + "\t" + getUPSTrackingInfo();
		return CreditCardOutput;
	}

}
