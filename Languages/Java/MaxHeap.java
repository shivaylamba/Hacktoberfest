package Java;
import java.util.ArrayList;
import java.util.Scanner;

public class MaxHeap {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);

        System.out.println("Enter the size of array:");
        int n = Integer.parseInt(console.nextLine());
        ArrayList<Integer> arr = buildArrayList(n);
        arr = arrangeMaxHeap(arr, n);

        showElements(arr);
    }

    private static ArrayList<Integer> buildArrayList(int n) {
        Scanner console = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<>();

        System.out.println("Enter array values:");
        for (int i = 0; i < n; i++) {
            System.out.println("Enter value for index " + i);
            int value = Integer.parseInt(console.nextLine());
            arr.add(value);
        }
        console.close();

        return arr;
    }

    private static ArrayList<Integer> arrangeMaxHeap(ArrayList<Integer> unsortedHeap, int heapSize) {
        ArrayList<Integer> maxHeap = null;
        for (int i = (int) Math.floor(heapSize / 2.0) + 1; i > 0; i--) {
            maxHeap = maxHeapify(unsortedHeap, i);
        }

        return maxHeap;
    }

    private static ArrayList<Integer> maxHeapify(ArrayList<Integer> arrayList, int index)  {
        int heapSize = arrayList.size();

        while (2 * index + 1 < heapSize) {
            int indexOfLargestVal;
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;

            if (leftChildIndex < heapSize && arrayList.get(leftChildIndex) > arrayList.get(index)) {
                indexOfLargestVal = leftChildIndex;
            } else {
                indexOfLargestVal = index;
            }

            if (rightChildIndex < heapSize && arrayList.get(rightChildIndex) > arrayList.get(indexOfLargestVal)) {
                indexOfLargestVal = rightChildIndex;
            }

            if (indexOfLargestVal != index) {
                int tempVal = arrayList.get(index);
                arrayList.set(index, arrayList.get(indexOfLargestVal));
                arrayList.set(indexOfLargestVal, tempVal);

                index = indexOfLargestVal;
            } else {
                return arrayList;
            }
        }
        return arrayList;
    }

    private static void showElements(ArrayList<Integer> arr) {
        int elementCounter = 0;
        System.out.println("Ordered elements in Max-Heap:");
        for (Integer integer : arr) {
            elementCounter++;
            System.out.printf("%d.) %d\n", elementCounter, integer);
        }
    }
}
