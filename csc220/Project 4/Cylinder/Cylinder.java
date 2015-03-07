
public class Cylinder extends Circle {

		private double height = 0.0;
		int x = super.getValuex();
		int y = super.getValuey();
		double radius = super.getRadius();
		
		public Cylinder(int x, int y, double radius, double h){
			super(x, y, radius);
			height = h;
		}
		
		public void setHeight(double value){
			
			if (height > 0)	
				height = value;
			if (height <= 0)
				System.out.println("You have entered an invalid height, please try again");
		
		}
		
		public double getHeight(){
			return height;
		}
		
		
		public String toString(){
			super.toString();
			return "The height of the cylinder is: " + height + " and the volume of the cylinder is: " + Math.PI*Math.pow(getRadius(), 2)*height;
		}
}