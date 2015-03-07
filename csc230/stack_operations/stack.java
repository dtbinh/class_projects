public class stack {

	static int topOfStack = -1;

	static int outgoingValue = 0;

	static int[] stackArray = new int[10];

	public static void main(String[] args) {

		for (int i = 0; i < 10; i++)
			stackArray[i] = -1;

		push(9);

		pop();
		System.out.println(outgoingValue);

		peek();
		System.out.println(outgoingValue);

		size();
		System.out.println(outgoingValue);
	}

	public static void push(int incommingValue) {
		try {
			stackArray[topOfStack + 1] = incommingValue;
			topOfStack++;
		}

		catch (ArrayIndexOutOfBoundsException exception) {
			System.out.println("You have exceeded the arrays");
		}
	}

	public static void pop() {
		if (isEmpty() == true)
			return;
		outgoingValue = stackArray[topOfStack];
		stackArray[topOfStack] = -1;
		topOfStack--;
	}

	public static void peek() {
		outgoingValue = stackArray[topOfStack];
	}

	public static boolean isEmpty() {
		if (stackArray[topOfStack] == -1)
			return true;
		else
			return false;

	}

	public static void size() {
		outgoingValue = topOfStack + 1;
	}

}
