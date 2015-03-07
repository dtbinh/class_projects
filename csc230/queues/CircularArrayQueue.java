/**
 * @author Jake
 *
 * @param <T>
 */

public class CircularArrayQueue<T> implements Queue<T> {
	private final int DEFAULT_CAPACITY = 10;
	private int front, rear, count;
	private T[] queue;

	// -----------------------------------------------------------------
	// Creates an empty queue using the default capacity.
	// -----------------------------------------------------------------
	public CircularArrayQueue() {
		front = rear = count = 0;
		queue = (T[]) (new Object[DEFAULT_CAPACITY]);
	}

	// -----------------------------------------------------------------
	// Adds the specified element to the rear of this queue, expanding
	// the capacity of the queue array if necessary.
	// -----------------------------------------------------------------
	public void enqueue(T element) {
		if (count == queue.length)
			expandCapacity();
		queue[rear] = element;
		rear = (rear + 1) % queue.length;
		count++;
	}

	// -----------------------------------------------------------------
	// Creates a new array to store the contents of this queue with
	// twice the capacity of the old one.
	// -----------------------------------------------------------------
	public void expandCapacity() {
		T[] larger = (T[]) (new Object[queue.length * 2]);
		for (int index = 0; index < count; index++)
			larger[index] = queue[(front + index) % queue.length];
		front = 0;
		rear = count;
		queue = larger;
	}
	// -----------------------------------------------------------------
	// The following methods are left as programming projects.
	// -----------------------------------------------------------------
	
	public T dequeue() throws EmptyCollectionException{
		
		if (isEmpty() == true)
			throw new EmptyCollectionException("This collection is empty.");
		queue[front] = null;
		front++;
		return queue[front];
		
	}
	
	public T first() throws EmptyCollectionException {
		
		if (isEmpty())
			throw new EmptyCollectionException("This collection is empty.");
		
		return queue[front];
		
	}
	
	public boolean isEmpty() {
		
		if (queue[front] == null)
			return true;
		else
			return false;
		
	}
	public int size() { 
		
		return front + 1;
	
	}
	public String toString() {
		
		String result = "";
		int scan = front;

		while (scan != rear) {
			result += queue[scan].toString() + "\n";
			scan = (scan+1) % queue.length;
		}

		return result;
		
	}
}