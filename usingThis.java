
/* NOTES:

This is an example codes on how to implement or use of "this" keyword in Java

"this" keyword:

-to refer current class instance variable
-to refer current class constructor
-to refer current class methods

The example is demonstrated by doing a simple Book's Storage Java program.

*/
import java.util.Scanner;

class usingthis {

    // declaring data members

    private String title; // 1. member variable called "title"
    private String author;
    private String publisher;
    private int copiesSold;

    // constructor: Initializes the data member
    public usingthis(String title, String author, String publisher, int copiesSold) { // 2.method's argument also called
                                                                                      // "title"

        this.title = title; // 3. "this.title" refers to this instance's member variable //"title" resolved
                            // to the method's argument
        this.author = author;
        this.publisher = publisher;
        this.copiesSold = copiesSold;
    }

    void setTitle(String title) {

        this.title = title;
    }

    void setAuthor(String author) {

        this.author = author;
    }

    void setPublisher(String publisher) {

        this.publisher = publisher;
    }

    void setcopiesSold(int copiesSold) {

        this.copiesSold = copiesSold;
    }

    String getTitle() {
        return title;
    }

    String getAuthor() {
        return author;
    }

    String getPublisher() {
        return publisher;
    }

    int getcopiesSold() {
        return copiesSold;
    }

    public static void main(String[] args) { // output
        Scanner scan = new Scanner(System.in);

        System.out.print("Your book title:");
        String title = scan.nextLine();

        System.out.print("The author: ");
        String author = scan.nextLine();

        System.out.print("Published by: ");
        String publisher = scan.nextLine();

        System.out.print("Number of copies sold: ");
        int copiesSold = scan.nextInt();
    }

}

/*
 * 
 * Sample output:
 * 
 * Your book title:him The author: qiha Published by: cranial publications
 * Number of copies sold: 45
 * 
 */
