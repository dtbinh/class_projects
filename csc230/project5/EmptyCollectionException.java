//********************************************************************
// EmptyCollectionException.java     Java Foundations
//
// Represents the situation in which a collection is empty.
//
// Warren Smith, David Piccolella & Kamal Jain
//********************************************************************


public class EmptyCollectionException extends RuntimeException
{
  //------------------------------------------------------------------
  //  Sets up this exception with an appropriate message.
  //------------------------------------------------------------------
  public EmptyCollectionException (String message)
  {
    super (message);
  }
}

