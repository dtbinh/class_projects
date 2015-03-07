public class RandomWalkers {
    public static void main(String[] args) {

	/**starts vars for program*/

	int N = Integer.parseInt(args[0]);
	int T = Integer.parseInt(args[1]);
	double sqtotal = 0;
	double r;
	double avg;

	/**number of trials loop*/
	
	for (int count=0;count<T;count++) {

	    /**started here so that x * y reset at each trial*/

	    int x = 0;
	    int y = 0;

	    /**loop for steps*/
	    for (int steps=0;steps<N;steps++) {

		r = Math.random();
		if      (r < 0.25) x--;
		else if (r < 0.50) x++;
		else if (r < 0.75) y--;
		else if (r < 1.00) y++;

		}
	    /**squared total distance after each trial*/
	    sqtotal = sqtotal + (x*x+y*y);

	}
	
	/**average of squared total*/

	avg = sqtotal/T;
	System.out.println(avg);

    }
}