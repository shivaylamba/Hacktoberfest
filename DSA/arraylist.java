import java.util.*;
import java.io.*;

public class arraylist {

    public static void main(String[] args) {

        ArrayList<Integer> all= new ArrayList<Integer>();
        for (int i=1; i<=6; i++){
            all.add(i*10);
        }
        System.out.println(all);

        all.remove(5);

        System.out.println(all);
        all.add(5,100); 
        System.out.println(all);
    }
}