public class BouncingBall {
    public static void main (String[] args) {

	/** starting location of ball */
	double rx = .480, ry = .860;
	/** speed of the ball */
	double vx = .015, vy = .023;
	/** size of the ball */
	double radius = .05;

	double rx1 = .180, ry1 = .560;
	double vx1 = .015, vy1 = .023;

	/** set the drawing area to be [-1,1] */
	StdDraw.setXscale(-1.0, +1.0);
	StdDraw.setYscale(-1.0, +1.0);

	while(true) {
	    /** new location is outside of the area reverse direction */
	    if (Math.abs(rx + vx) > 1.0) vx = -vx;
	    if (Math.abs(ry + vy) > 1.0) vy = -vy;

	    if (Math.abs(rx1 + vx1) > 1.0) vx1 = -vx1;
	    if (Math.abs(ry1 + vy1) > 1.0) vy1 = -vy1;

	    /** calculate the new location */
	    rx = rx + vx;
	    ry = ry + vy;

	    rx1 = rx1 + vx1;
	    ry1 = ry1 + vy1;

	    /** set background color, ball color and screen pause */
	    StdDraw.clear(StdDraw.GRAY);
	    StdDraw.setPenColor(StdDraw.RED);
	    StdDraw.filledCircle(rx, ry, radius);
	    StdDraw.setPenColor(StdDraw.BLUE);
	    StdDraw.filledCircle(rx1, ry1, radius);
	    StdDraw.show(50);
	}
    }
}