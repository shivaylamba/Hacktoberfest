import java.util.*;
public class linkedlist {
    public static void main (String [] args){
        LinkedList<Integer> list=new LinkedList<Integer>();

        for (int i =1;i<=6;i++){
            list.add(i*20);
        }
        System.out.println(list);
        list.remove(3);
        System.out.println(list);


    }
    
}
