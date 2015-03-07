
/*************************************************************************
 *  Compilation:  javac PlayThatTune.java
 *  Execution:    java PlayThatTune < data.txt
 *
 *  %java PlayThatTune < elise.txt
 *
 *************************************************************************/
import java.util.Scanner;
public class PlayThatTune {

    // take weighted sum of two arrays
    public static double[] sum(double[] a, double[] b, double awt, double bwt) {

        // precondition: arrays have the same length
        assert (a.length == b.length);

        // compute the weighted sum
        double[] c = new double[a.length];
        for (int i = 0; i < a.length; i++) {
            c[i] = a[i]*awt + b[i]*bwt;
        }
        return c;
    } 

    // create a pure tone of the given frequency for the given duration
    public static double[] tone(double hz, double duration) { 
        int SAMPLE_RATE = 44100;
        int N = (int) (SAMPLE_RATE * duration);
        double[] a = new double[N+1];
        for (int i = 0; i <= N; i++) {
            a[i] = Math.sin(2 * Math.PI * i * hz / SAMPLE_RATE);
        }
        return a; 
    } 

    // create a note with harmonics of of the given pitch (0 = middle C)
    public static double[] note(int pitch, double t) {
        double hz = 440.0 * Math.pow(2, pitch / 12.0);
        double[] a  = tone(hz, t);
        double[] hi = tone(2*hz, t);
        double[] lo = tone(hz/2, t);
        double[] h  = sum(hi, lo, .5, .5);
        return sum(a, h, .5, .5);
    }


    // read in notes from standard input and play them on standard audio
    public static void main(String[] args) {

        Scanner scan = new Scanner (System.in);

        // read in pitch-duration pairs from standard input
        while (scan.hasNext()) {
            int pitch = scan.nextInt();
            double duration = scan.nextDouble();
            double[] a = note(pitch, duration);
            StdAudio.play(a);
        }

        // needed to terminate program - known Java bug
        System.exit(0);
    } 
} 