import java.util.Scanner;

public class StopWatch {
    
    private long startTime = 0;
    private long stopTime = 0;
    private boolean running = false;

    
    public void start() {
        this.startTime = System.currentTimeMillis();
        this.running = true;
    }

    
    public void stop() {
        this.stopTime = System.currentTimeMillis();
        this.running = false;
    }

    
    //elaspsed time in milliseconds
    public long getElapsedTime() {
        long elapsed;
        if (running) {
             elapsed = (System.currentTimeMillis() - startTime);
        }
        else {
            elapsed = (stopTime - startTime);
        }
        return elapsed;

    }

    public String toString() {

	/**use "" to convert long int to string*/

	return ""+ this.getElapsedTime();

    }
    
    
    //elaspsed time in seconds
    public long getElapsedTimeSecs() {
        long elapsed;
        if (running) {
            elapsed = ((System.currentTimeMillis() - startTime) / 1000);
        }
        else {
            elapsed = ((stopTime - startTime) / 1000);
        }
        return elapsed;
    }
    //sample usage
    public static void main(String[] args) {
        StopWatch s = new StopWatch();
        s.start();
        double z =0.0;
        //use scanner to get an string from keyboard
	
	/**program runs until the system is given an input by the Scanner class*/
	Scanner scan = new Scanner(System.in);
	String pancake = scan.nextLine();

        s.stop();
        System.out.println("elapsed time in milliseconds: " + s);
   

    }    
}