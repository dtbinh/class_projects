public class RandomWalker {
    public static void main(String[] args) {

	/**starts vars*/

	int N = Integer.parseInt(args[0]);
	int x = 0;
	int y = 0;
	double r;
	
	/**loop for desired number of steps, starts at 0 to save space*/
	for (int steps=0;steps<N;steps++) {

	    r = Math.random();
	    if      (r < 0.25) x--;
            else if (r < 0.50) x++;
            else if (r < 0.75) y--;
            else if (r < 1.00) y++;
	    /**current location*/
	    System.out.println("(" + x + "," + y + ")");
		}
	/**square of N steps*/
	System.out.println((x*x+y*y));
    }
}
