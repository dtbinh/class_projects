
/*************************************************************************
 *  Compilation:  javac StdRandom.java
 *  Execution:    java StdRandom
 *
 *  A library of static methods to generate random numbers from
 *  different distributions (bernouilli, uniform, gaussian, 
 *  discrete, and exponential). Also includes a method for
 *  shuffling an array.
 *
 *  % java StdRandom 5
 *  90 26.36076 false 8.79269 0
 *  13 18.02210 false 9.03992 1
 *  58 56.41176 true  8.80501 0
 *  29 16.68454 false 8.90827 0
 *  85 86.24712 true  8.95228 0
 *
 *
 *  Remark
 *  ------
 *    - Uses Math.random() which generates a pseudorandom real number
 *      in [0, 1)
 *
 *    - This library does not allow you to set the pseudorandom number
 *      seed. See java.util.Random.
 *
 *    - See http://www.honeylocust.com/RngPack/ for an industrial
 *      strength random number generator in Java.
 *  
 *************************************************************************/

public class StdRandom {

    // return a real number uniformly in [0, 1)
    public static double uniform() {
        return Math.random();
    } 

    // return a real number uniformly in [a, b)
    public static double uniform(double a, double b) {
        return a + Math.random() * (b-a);
    } 

    // return an integer uniformly between 0 and N-1
    public static int uniform(int N) {
        return (int) (Math.random() * N);
    } 

    // return a boolean, which is true with prob p and false otherwise
    public static boolean bernoulli(double p) {
        return Math.random() < p;
    } 

    // return a real number with a standard Gaussian distribution
    // uses the polar form of the Box-Muller transform
    public static double gaussian() {
        double r, x, y;
        do {
            x = uniform(-1.0, 1.0);
            y = uniform(-1.0, 1.0);
            r = x*x + y*y;
        } while (r >= 1 || r == 0);
        return x * Math.sqrt(-2 * Math.log(r) / r);

        // Remark:  y * Math.sqrt(-2 * Math.log(r) / r)
        // is an independent random gaussian
    } 

    // return a real number from a gaussian distribution with given mean and stddev
    public static double gaussian(double mean, double stddev) {
        return mean + stddev * gaussian();
    } 

    // return i with probability a[i]
    // precondition: sum of array entries equals 1
    public static int discrete(double[] a)  { 
        double r = Math.random();
        double sum = 0.0;
        for (int i = 0; i < a.length; i++) {
            sum = sum + a[i];
            if (sum >= r) return i;
        }
        assert (false);
        return -1;
    } 

    // exponential random variable with rate lambda
    public static double exp(double lambda) {
        return -Math.log(1 - Math.random()) / lambda;
    }


    // swaps array elements i and j
    public static void exch(String[] a, int i, int j) {
        String swap = a[i];
        a[i] = a[j];
        a[j] = swap;
    }

    // take as input an array of Objects and rearrange them in random order
    public static void shuffle(Object[] a) {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            int r = i + uniform(N-i);     // between i and N-1
            Object temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }

    // take as input an array of doubles and rearrange them in random order
    public static void shuffle(double[] a) {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            int r = i + uniform(N-i);     // between i and N-1
            double temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }

    // take as input an array of doubles and rearrange them in random order
    public static void shuffle(int[] a) {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            int r = i + uniform(N-i);     // between i and N-1
            int temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }


    // unit test
    public static void main(String[] args) { 
        int N = Integer.parseInt(args[0]);

        double[] t = { .5, .3, .1, .1 };

        for (int i = 0; i < N; i++) { 
            StdOut.printf(" %2d " , uniform(100));
            StdOut.printf("%8.5f ", uniform(10.0, 99.0));
            StdOut.printf("%5b "  , bernoulli(.5));
            StdOut.printf("%7.5f ", gaussian(9.0, .2));
            StdOut.printf("%2d "  , discrete(t));
            StdOut.println();
        }
    }

} 
