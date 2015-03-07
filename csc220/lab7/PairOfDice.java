public class PairOfDice {
    public static void main(String[] args) {

	/**initiates all of the ints*/

	int value1 = 0;

	int value2 = 0;

	int faceTotal1 = 0;
	
	int faceTotal2 = 0;

	Die Die1 = new Die();
	
	Die1.roll();

	Die1.setFaceValue(value1);
	
	Die1.getFaceValue();

	Die1.toString();

	Die Die2 = new Die();
	
	Die2.roll();

	Die2.setFaceValue(value2);

	Die2.getFaceValue();

	Die2.toString();

	/**converts the strings into ints*/

	faceTotal1 = Integer.parseInt(Die1.toString());

	faceTotal2 = Integer.parseInt(Die2.toString());
	
	System.out.println("Die 1 Value: " + faceTotal1);

	System.out.println("Die 2 Value: " + faceTotal2);

	System.out.println("Die Total: " + (faceTotal1 + faceTotal2));

    }
}