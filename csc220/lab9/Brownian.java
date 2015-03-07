public class Brownian {
    // midpoint displacement method
    public static void curve(double x0, double y0, double x1, double y1, double var, double s) {
	// stop if interval is sufficiently small
	if (x1 - x0 < .01) {
	    StdDraw.line(x0, y0, x1, y1);
	    return;
	}

	/**calculates xm and ym*/
	double xm = (x0 + x1)/2;
	/**combined gaussian step*/
	double ym = (y0 + y1)/2 + StdRandom.gaussian(0, Math.sqrt(var));
	/** inputs cuve data*/
	curve(x0, y0, xm, ym,var/s,s);// draw the left part of the curve, the right part of the curve
	curve(xm, ym, x1, y1, var/s, s);// the variance of these two parts are var/s
    }
    public static void main(String[] args) {
	double H = Double.parseDouble(args[0]);
	double s = Math.pow(2, 2*H);
	curve(0.0, 0.5, 1.0, 0.5, .01, s);
    }
}
