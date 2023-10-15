
using System;

class BinarySearch
{

    public static void Main(String[] args){
        
        int[] arr = new int[7] { 1, 5, 7, 4, 6, 2, 3 };
        Array.Sort(arr);

        Console.Write("The elements of Sorted Array: ");
        display(arr);
        object s = 8;
        result(arr, s);
        
        object s1 = 4;
        result(arr, s1);
    }


    static void result(int[] arr2, object k){

        int res = Array.BinarySearch(arr2, k);
        if (res < 0)
        {
            Console.WriteLine("\nThe element to search for " + "({0}) is not found.", k);
        }
        else
        {
            Console.WriteLine("The element to search for " + "({0}) is at index {1}.", k, res);
        }
    }


    static void display(int[] arr1){
        foreach (int i in arr1)
            Console.Write(i + " ");
    }
}
