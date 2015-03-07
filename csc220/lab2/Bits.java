public class Bits{
    public static void main (String args []){

    /**declares ints and sets input values*/
    int N = Integer.parseInt(args[0]); 
    int Count = 0;
     if (N<0){
     System.out.println("illegal input");
     }
     else {
        while (N > 1){
        N = N/2;
        Count = Count+1;
        }
     }
     System.out.println(Count);
    }
}
