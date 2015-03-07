public class roseDraw {
    public static void main(String[] args) {

	int N = Integer.parseInt(args[0]);
	int points = Integer.parseInt(args[1]);
	double[] a = new double[points+2];
	double [] x = new double [points+2];
	double [] y = new double [points+2];
	for (int i=0; i<=points; i++) {

	double theta = (2.0*Math.PI*i)/points; 

	a[i] = Math.sin(theta*N);
	x[i] = a[i]*Math.cos(theta);
	y[i] = a[i]*Math.sin(theta);
	}

	StdDraw.setXscale(-1.0, 1.0);
	StdDraw.setYscale(-1.0, 1.0);
	for(int i=1; i<=points; i++){
	   
	    StdDraw.line(x[i], y[i], x[i+1], y[i+1]);
	}

    }
}