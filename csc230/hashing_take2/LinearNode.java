public class LinearNode{
    private LinearNode next;
    private String element;
    
    /**creates an empty node*/
    public LinearNode(){
        next = null;
        element = "";
    }
    /**creates a node with a specified value */
    public LinearNode (String elem){
        next = null;
        element = elem;
    }
    /**gets the next value for a node*/
    public LinearNode getNext(){
        return next;
    }
    /**sets the next value for a node*/
    public void setNext(LinearNode a){
        next = a;
    }
    /**gets the element value of a specific node*/
    public String getElement(){
        return element;
    }
    /** sets the element value of a specific node*/
    public void setElement (String elem){
        element = elem;
    }
}


