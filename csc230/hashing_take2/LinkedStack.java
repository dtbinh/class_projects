public class LinkedStack{
    private int count;
    private LinearNode top;
    
    /** creates an empty linked stack with a sentinel node*/
    public LinkedStack(){
        count = 0;
        LinearNode dummyNode = new LinearNode();
        top = dummyNode;
    }
    /**pops the the top element off of the stack*/
    public String pop(){
        /**if the list is empty, then pop fails*/
        if (count == 0){
            System.out.println("Pop failed, the stack is empty");
            System.exit(0);
        }
        
        String result = top.getElement();
        top = top.getNext();
        count--;
        return result;
    }
    /** pushes a node onto the stack*/
    public void push(String a){
        LinearNode node = new LinearNode(a);
        node.setNext(top);
        top = node;
        
        count ++;
    }
    /** returns the length of the stack*/
    public int getLength(){
        return count;
    }
    
}
    