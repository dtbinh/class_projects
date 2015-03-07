public class Dog {    

    String name;
    int age;
    int humanYears;

    public Dog() {

       	name = null;
	age = 0;
	humanYears = 0;
	}

    /**setters and getters for all instance data*/

    public void setName(String newValue){
	name = newValue;
    }

     public String getName() {
	 return name;
    }

    public void setAge(int newValue){
	age = newValue;
    }

    public int getAge(){
	return age;
    }

    public void setHumanYears(int newValue){
	humanYears = newValue * 7;
    }

    public int getHumanYears(){
	return humanYears;
    }

    /**formats all data into a string*/

    public String toString(){

	String formattedAge = ("Name: " + getName() + " |  Age: " + getAge() + " |  Age in human years: " + getHumanYears());

	return formattedAge;
    }

    public static void main(String[] args){

    }
}