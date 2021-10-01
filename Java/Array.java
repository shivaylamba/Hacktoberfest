package _01_Arrays_and_ArrayLists;

public class Array {
    public static void main(String[] args) {

//        Declaring an array.
        //Syntax:
        //datatype[] variableName = new datatype[size];
        //eg: store 5 roll numbers.
        int[] rollnos = new int[5];
        int[] rollnos2 = {1, 2, 3, 4, 5};
        System.out.println(rollnos2[0]);
        System.out.println(rollnos2[4]);

        int[] ros; //Declaration of array. ros is getting defined in the stack.
        ros = new int[5]; //Initialisation. Object is being created in the heap memory.

        String[] arr = new String[5];
        System.out.println(arr[0]); //Will give us null as output.
    }

}
