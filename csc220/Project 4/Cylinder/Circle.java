
public class Circle extends Point {
	
	private double radius = 0.0;
	int x = getValuex();
	int y = getValuey();
	
	public Circle(int x, int y, double value){

		super (x, y);
		
		if (value > 0)
			radius = value;
		if (value <= 0){
			System.out.println("You have entered an invalid raidus, please enter another one.");
			
		
		}
	}

		public void setRadius(double value){
			radius = value;
		}
		
		public double getRadius(){
			return radius;
		}
		public String toString(){
			super.toString(); 
			return "The radius is: " + radius + " and the area of the circle is: " + Math.PI*Math.pow(radius, 2);
		}

	
}
