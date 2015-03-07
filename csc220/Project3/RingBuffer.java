/**********************************************************************************
 *
 *  This is a template file for RingBuffer.java. It lists the constructors and
 *  methods you need, along with descriptions of what they're supposed to do.
 *  
 *  Note: it won't compile until you fill in the constructors and methods
 *        (or at least commment out the ones whose return type is non-void).
 *
 **********************************************************************************/

public class RingBuffer {
    private int first;            // index of first item in buffer
    private int last;             // index of last item in buffer
    private int size;             // current number of items of buffer
    private double[] buffer;

    // create an empty buffer, with given max capacity
    public RingBuffer(int capacity) {
        // YOUR CODE HERE
	buffer = new double[capacity];
	first =0;
	last  =capacity-1;
	size  =0;
    }

    // return number of items currently in the buffer
    public int size() {
        // YOUR CODE HERE
	return size;
    }

    // is the buffer empty (size equals zero)?
    public boolean isEmpty() {
        // YOUR CODE HERE
	if (size == 0) 
	    return true;
	else 
	    return false;
    }

    // is the buffer full (size equals array capacity)?
    public boolean isFull() {
        // YOUR CODE HERE
	if (size == buffer.length)
	    return true;  
        else
	    return false;

    }

    // add item x to the end
    public void enqueue(double x) {
        if (isFull()) { throw new RuntimeException("Ring buffer overflow"); }
        // YOUR CODE HERE
	last = (last+1)%buffer.length;
	buffer[last]=x;
	size++;
    }

    // delete and return item from the front
    public double dequeue() {
        if (isEmpty()) { throw new RuntimeException("Ring buffer underflow"); }
        // YOUR CODE HERE
	double temp = buffer[first];
	first = (first+1)% buffer.length;
	size--;
	return temp;
    }

    // return (but do not delete) item from the front
    public double peek() {
        if (isEmpty()) { throw new RuntimeException("Ring buffer underflow"); }
        // YOUR CODE HERE
	return buffer[first];
    }

    // a simple test of the constructor and methods in RingBuffer
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        RingBuffer buffer = new RingBuffer(N);
        for (int i = 1; i <= N; i++) {
            buffer.enqueue(i);
        }
	double t = buffer.dequeue();
	buffer.enqueue(t);
	System.out.println("Size after wrap-around is " + buffer.size);
        while (buffer.size() >= 2) {
            double x = buffer.dequeue();
            double y = buffer.dequeue();
            buffer.enqueue(x + y);
        }
        System.out.println(buffer.peek());
    }

}
