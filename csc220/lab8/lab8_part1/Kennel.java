import java.util.Scanner;

public class Kennel {

    public static void main(String[] args) {

	String value1 = null;
	int value2 = 0;
	String value3 = null;
	int value4 = 0;
	String value5 = null;
	int value6 = 0;
	
	Scanner scanner = new Scanner(System.in);

	/**scanner.nextLine(); is added to remove InputMismatchException*/

	while (scanner.hasNextLine()){
	    
	    value1 = scanner.nextLine();
	    value2 = scanner.nextInt();
	    scanner.nextLine();
	    value3 = scanner.nextLine();
	    value4 = scanner.nextInt();
	    scanner.nextLine();
	    value5 = scanner.nextLine();
	    value6 = scanner.nextInt();
	    scanner.nextLine();
	}

	/**sets and gets info for the three "Dogs"*/

	Dog Dog1 = new Dog();

	Dog1.setName(value1);
	Dog1.getName();
	Dog1.setAge(value2);
	Dog1.getAge();
	Dog1.setHumanYears(value2);
	Dog1.getHumanYears();
	Dog1.toString();

	Dog Dog2 = new Dog();

	Dog2.setName(value3);
	Dog2.getName();
	Dog2.setAge(value4);
	Dog2.getAge();
	Dog2.setHumanYears(value4);
	Dog2.getHumanYears();
	Dog2.toString();

	Dog Dog3 = new Dog();

	Dog3.setName(value5);
	Dog3.getName();
	Dog3.setAge(value6);
	Dog3.getAge();
	Dog3.setHumanYears(value6);
	Dog3.getHumanYears();
	Dog3.toString();

	/**prints out the information*/

	System.out.println(Dog1.toString());
	System.out.println(Dog2.toString());
	System.out.println(Dog3.toString());

    }
}