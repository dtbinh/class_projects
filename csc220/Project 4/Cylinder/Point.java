/**disco bandio*/

public class Point {
	
	private int x = 0;
	private int y = 0;
	public Point(int X, int Y){
		x = X;
		y = Y;
	}
	
	public void setValuex(int value){
		x = value;
	}
	public int getValuex(){
		return x;
	}
	
	
	public void setValuey(int value){
		y=value;
	}
	public int getValuey(){
		return y;
	}
	
	
	public String toString(){
		return x + ", " + y;
	}
}
