public class Ordered{
    public static void main (String args[]){
        
/**declares x variable and sets it equalto keyboard input*/
        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);
        int z = Integer.parseInt(args[2]);
        boolean isOrdered;

        if (((x<y)&&(y<z))||((z<y)&&(y<x))){
        isOrdered = true;
        System.out.println(isOrdered);
        }

        else {
        isOrdered = false;
        System.out.println(isOrdered);
        }

    }
}
