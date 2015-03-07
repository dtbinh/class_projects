/**
 * this is the class used to define chemical data
 * 
 * @author Jake
 * 
 */

public class chemical implements Comparable<Object> {

	static long startTime = System.nanoTime();

	/** stores the indicated elements */

	protected String chemicalName;
	protected String casNumber;
	protected String cleanAirAct;
	protected String classification;
	protected String metal;
	protected int metalCategory;
	protected String carcinogen;
	protected String formType;
	protected String unitOfMeasurment;
	protected String riskFactor;

	public chemical(String XChemicalName, String XCASNumber,
			String XCleanAirAct, String XClassification, String XMetal,
			int XMetalCategory, String XCarcinogen, String XFormType,
			String XUnitOfMeasurment, String XRiskFactor) {

		chemicalName = XChemicalName;
		casNumber = XCASNumber;
		cleanAirAct = XCleanAirAct;
		classification = XClassification;
		metal = XMetal;
		metalCategory = XMetalCategory;
		carcinogen = XCarcinogen;
		formType = XFormType;
		unitOfMeasurment = XUnitOfMeasurment;
		riskFactor = XRiskFactor;

	}

	/** all of the setters and getters you will ever need */

	public void setChemicalName(String XChemicalName) {
		this.chemicalName = XChemicalName;
	}

	public String getChemicalName() {
		return chemicalName;
	}

	public void setCASNumber(String XCASNumber) {
		this.casNumber = XCASNumber;
	}

	public String getCASNumber() {
		return casNumber;
	}

	public void setCleanAirAct(String XCleanAirAct) {
		this.cleanAirAct = XCleanAirAct;
	}

	public String getCleanAirAct() {
		return cleanAirAct;
	}

	public void setClassification(String XClassification) {
		this.classification = XClassification;
	}

	public String getClassification() {
		return classification;
	}

	public void setMetal(String XMetal) {
		this.metal = XMetal;
	}

	public String getMetal() {
		return metal;
	}

	public void setMetalCategory(int XMetalCategory) {
		this.metalCategory = XMetalCategory;
	}

	public int getMetalCategory() {
		return metalCategory;
	}

	public void setCarcinogen(String XCarcinogen) {
		this.carcinogen = XCarcinogen;
	}

	public String getCarcinogen() {
		return carcinogen;
	}

	public void setFormType(String XFormType) {
		this.formType = XFormType;
	}

	public String getFormType() {
		return formType;
	}

	public void setUnitOfMeasurment(String XUnitOfMeasurment) {
		this.unitOfMeasurment = XUnitOfMeasurment;
	}

	public String getUnitOfMeasurment() {
		return unitOfMeasurment;
	}

	public void setRiskFactor(String XRiskFactor) {
		this.riskFactor = XRiskFactor;
	}

	public String getRiskFactor() {
		return riskFactor;
	}

	/** used by other classes to compare different elements in the array */

	public int compareTo(Object o) {

		chemical chemical2 = (chemical) o;

		if (casNumber.compareTo(chemical2.getCASNumber()) < 0)
			return -1;

		else if (casNumber.compareTo(chemical2.getCASNumber()) > 0)
			return 1;

		else if (casNumber.compareTo(chemical2.getCASNumber()) == 0)
			return 0;

		else
			return 0;

	}

}
