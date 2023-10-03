import java.util.*;

public class arrayOfObjects {
    int rollno;
    String name;

    arrayOfObjects(int rollno, String name) {
        this.rollno = rollno;
        this.name = name;
    }

    void display() {
        System.out.println(rollno + " " + name + " ");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int n = sc.nextInt();

        arrayOfObjects[] arr = new arrayOfObjects[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the roll number: ");
            int rollno = sc.nextInt();
            System.out.println("Enter the name: ");
            String name = sc.next();
            arr[i] = new arrayOfObjects(rollno, name);
        }
        
        System.out.println("Student details: ");
        for (arrayOfObjects s : arr) {
            s.display();
        }
        sc.close();
    }
}
