package _01_Arrays_and_ArrayLists;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayList {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);


        //Syntax for ArrayList:
        java.util.ArrayList<Integer> list = new java.util.ArrayList<>(10);

        list.add(120);
        list.add(450);
        list.add(102);
        list.add(1442);
        list.add(975);
        list.add(5072);
        //can add as many values as we need.
        System.out.println(list);

        //Some useful functions:
        list.set(0, 999); //set the 0th index of list to 999.
        list.remove(3);//remove element in 3rd index from list.
        System.out.println(list);

        System.out.println();


        //creating a new ArrayList.
        System.out.println("Enter 6 elements into the new ArrayList ls: ");
        java.util.ArrayList<Integer> ls = new java.util.ArrayList<>(10);
        //input elements to the ArrayList ls.
        for (int i = 0; i < 6; i++)
        {
            ls.add(input.nextInt());
        }

        System.out.println("Printing elements of ls: ");
        //System.out.println(ls);
        //get item at an index:
        for (int i = 0; i < 6; i++)
        {
            System.out.print(ls.get(i) + " ");// pass index here. list[index] syntax will not work here.
        }

    }
}
