
public class Application {
	
	public static void main (String[] args){
	
	int x = Integer.parseInt(args[0]);
	int y = Integer.parseInt(args[1]);
	double radius = Double.parseDouble(args[2]);
	double height = Double.parseDouble(args[3]);

	Point[] CapmCrunch = new Point[3];
	
	Point Sailboat = new Point(x, y);
	Circle EyeGlass = new Circle(x, y, radius);
	Cylinder KingHat = new Cylinder(x, y, radius, height);
	
	/**this fancy nonsense*/
	
	CapmCrunch[0] = Sailboat;
	CapmCrunch[1] = EyeGlass;
	CapmCrunch[2] = KingHat;
	
	System.out.println("X and Y Coordinates are: " + CapmCrunch[0]);
	System.out.println(CapmCrunch[1]);
	System.out.println(CapmCrunch[2]);
	
	}
}