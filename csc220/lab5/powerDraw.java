public class powerDraw {
    public static void main(String[] args) {

	int points = Integer.parseInt(args[0]);
	double[] a = new double[points+1];
	for (int i=0; i<=points; i++) {

	    a[i]=Math.pow (8.0*i/points, 2) ;
	    }

	StdDraw.setXscale(0,7.0);
	StdDraw.setYscale(0, 10.0);
	for(int i=1; i<=points; i++){
	   
	    StdDraw.line(8.0*(i-1)/points, a[i-1], 8.0*i/points, a[i]);
	}

    }
}