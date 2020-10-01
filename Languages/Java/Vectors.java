import java.util.*;

public class VectorExample {

   public static void main(String args[]) {
      // Vector of initial capacity(size) of 2
      Vector<String> vec = new Vector<String>();

      // Adding elements to a vector
      vec.addElement("Sedan");
      vec.addElement("Hatchback");
      vec.addElement("SUV");
      vec.addElement("Sport");

      //check size and capacityIncrement
      System.out.println("Size is: "+vec.size());
      System.out.println("Default capacity increment is: "+vec.capacity());

      vec.addElement("car1");
      vec.addElement("car2");
      vec.addElement("car3");

      //size and capacityIncrement after two insertions
      System.out.println("Size after addition: "+vec.size());
      System.out.println("Capacity after increment is: "+vec.capacity());

      //Display Vector elements
      Enumeration en = vec.elements();
      System.out.println("\nElements are:");
      while(en.hasMoreElements())
         System.out.print(en.nextElement() + " ");
   }
}
