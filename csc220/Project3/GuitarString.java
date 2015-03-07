/**********************************************************************************
 *
 *  This is a template file for GuitarString.java. It lists the constructors and
 *  methods you need, along with descriptions of what they're supposed to do.
 *  
 *  Note: it won't compile until you fill in the constructors and methods
 *        (or at least commment out the ones whose return type is non-void).
 *
 **********************************************************************************/

public class GuitarString {

    private RingBuffer buffer; // ring buffer
    // YOUR OTHER INSTANCE VARIABLES HERE
    private int ticTimes = 0;
    // create a guitar string of the given frequency
    public GuitarString(double frequency) {
        // YOUR CODE HERE
	int N;
	N = (int)(44100/frequency);
	buffer = new RingBuffer(N);
	for (int i=1; i <=N; i++ ){
	   buffer.enqueue(0.0);        
        }
    }

    // create a guitar string whose size and initial values are given by the array
    public GuitarString(double[] init) {
        // YOUR CODE HERE
	buffer = new RingBuffer(init.length);
	for (int i = 0; i < init.length; i++){
	    buffer.enqueue(init[i]);
        }
    }

    // pluck the guitar string by setting the buffer to white noise
    public void pluck() {
        // YOUR CODE HERE
	while(!buffer.isEmpty()) buffer.dequeue();
	while(!buffer.isFull()){
	    buffer.enqueue(Math.random()-0.5);
	}
    }

    // advance the simulation one time step
    public void tic() {
        // YOUR CODE HERE
	double value1, value2;
	value1 = buffer.dequeue();
	value2 = buffer.peek();
	buffer.enqueue(((value1+value2)/2)*0.996);
	ticTimes++;
    }

    // return the current sample
    public double sample() {
        // YOUR CODE HERE
	return buffer.peek();
    }

    // return number of times tic was called
    public int time() {
        // YOUR CODE HERE

	return ticTimes;
    }


  public static void main(String[] args) {
      int N = Integer.parseInt(args[0]);
      double[] samples = { .2, .4, .5, .3, -.2, .4, .3, .0, -.1, -.3 };  
      GuitarString testString = new GuitarString(samples);
      for (int i = 0; i < N; i++) {
          int t = testString.time();
          double sample = testString.sample();
          System.out.printf("%6d %8.4f\n", t, sample);
          testString.tic();
      }
  }

}
