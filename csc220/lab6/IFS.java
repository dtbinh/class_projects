/**********************************************************************
* Compilation: javac IFS.java
* Execution:
java IFS N < input.txt
* Dependencies: StdDraw.java
*
*
**********************************************************************/
import java.util.Scanner;
public class IFS {


    // return i with probability a[i]
    // precondition: sum of array entries equals 1
    public static int discrete(double[] a) {
	double r = Math.random();
	double sum = 0.0;
	for (int i = 0; i < a.length; i++) {
	    sum = sum + a[i];
	    if (sum >= r) return i;
	}
	assert (false);
	return -1;
    }
    public static void main(String[] args) {
	int i, j;
	// number of iterations
	int T = Integer.parseInt(args[0]);
	Scanner scan = new Scanner (System.in);
	// probability distribution for choosing each rule
	
	// read size of dist[]
	i = scan.nextInt();
	double[] dist = new double [i];
	// please create array dist[], read values from input to this array
	for (int a = 0; a < i; a++)
	     dist [a] = scan.nextDouble();
	// update matrices
	
	// i is the number of possible choices
	i = scan.nextInt();
	j = scan.nextInt();

	double[][] cx = new double [i][j];

	for (int a = 0; a < i; a++){
	    for (int b = 0; b < j; b++){
		cx[a][b] = scan.nextDouble(); 
	    }
	}

	// j is number of the coefficient values



	// read values from input to i and j



	// please create the array cx[][]



	// read values from input to cx[][]

	

	
	// i is the number of possible choices
	i = scan.nextInt();
	j = scan.nextInt();

	double[][] cy = new double [i][j];

	for (int a = 0; a < i; a++){
	    for (int b = 0; b < j; b++){
		cy[a][b] = scan.nextDouble(); 
	    }
	}
	
	
	// j is number of the coefficient values



	// read values from input to i and j

	

	// please create the array cy[][]

	

	// read values from input to cy[][]



	// current value of (x, y)
	double x = 0.0, y = 0.0;
	StdDraw.setPenColor(StdDraw.BLUE);


	// do T iterations of the chaos game
	for (int t = 0; t < T; t++) {


	    // pick a random rule according to the probability distribution
	    int r = StdRandom.discrete(dist);
	    // do the update
	    double x0 = cx[r][0]*x + cx[r][1]*y + cx[r][2];
	    double y0 = cy[r][0]*x + cy[r][1]*y + cy[r][2];

	    x = x0;
	    y = y0;
	    // draw the resulting point
	    StdDraw.point(x, y);
	    // for efficiency, only display every 100 iterations
	    if (t % 1000 == 0) StdDraw.show(10);
	    if (t % 10000 == 0) System.out.println(t);
	}
    }
}
