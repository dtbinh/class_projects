/*************************************************************************
* Compilation: javac Tree.java
* Execution:
java Tree N
* Dependencies: StdDraw.java
*
* Plot an order N Tree.
*
* % java Tree 8
*
*************************************************************************/
public class Tree {
    public static void draw(int n, double x, double y, double lx, double ly, float width) {
	if (n == 0) return;
	double length = Math.sqrt((x-lx)*(x-lx)+(y-ly)*(y-ly));
	
	double tempx = (x-lx)*1.618 + lx;
	double tempy = (y-ly)*1.618 + ly;
	
	double x0, y0, x1, y1, x2, y2;
	
	x0=(tempx-x)*Math.cos(Math.toRadians(50))-(tempy - y)*Math.sin(Math.toRadians(50))+x;
	y0=(tempx-x)*Math.sin(Math.toRadians(50))+(tempy - y)*Math.cos(Math.toRadians(50))+y;
	
	x2=(tempx-x)*Math.cos(Math.toRadians(-20))-(tempy - y)*Math.sin(Math.toRadians(-20))+x;
	y2=(tempx-x)*Math.sin(Math.toRadians(-20))+(tempy - y)*Math.cos(Math.toRadians(-20))+y;
	
	tempx = (x-lx)*1.381 + lx;
	tempy = (y-ly)*1.381 + ly;
	
	x1=(tempx-x)*Math.cos(Math.toRadians(15)) - (tempy-y)*Math.sin(Math.toRadians(15))+x;
	y1=(tempx-x)*Math.sin(Math.toRadians(15)) + (tempy-y)*Math.cos(Math.toRadians(15))+y;
	
	float thickness;
	thickness = n * (float) 0.433;
	
	// draw three lines here, width is determined by thickness
	StdDraw.line(x, y, x0, y0, thickness);
	StdDraw.line(x, y, x1, y1, thickness);
	StdDraw.line(x, y, x2, y2, thickness);

	// draw three sub trees, with order n-1, width is determined by thickness value
	draw(n-1, x0, y0, x, y, thickness);
	draw(n-1, x1, y1, x, y, thickness);
	draw(n-1, x2, y2, x, y, thickness);

	
	StdDraw.line(x, y, lx, ly, width);
    }
    public static void main(String[] args) {
	int n = Integer.parseInt(args[0]);
	
	StdDraw.setXscale(-0.5, 1.2);
	StdDraw.setYscale(0, 1.5);
	draw(n, .5, .5, .5, 0.0, n);
    }
}
