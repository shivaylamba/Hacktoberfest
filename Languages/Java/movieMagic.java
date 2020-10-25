
import java.io.*;
import java.util.*;
class movieMagic
{
    int year;
    String title;
    float rating;

    movieMagic()
    {
        year=0;
        title="";
        rating=0.0f;
    }

    void accept()throws IOException
    { 

        BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter year, title and rating");
        year = sc.nextInt();
        title = ob.readLine();
        rating = sc.nextFloat();

    }

    void display()
    {
        System.out.println("title: " + title);
        if(rating>=0.0 && rating<=2.0)
            System.out.println("flop");
        else if(rating<3.5)
            System.out.println("Semi hit");
        else if (rating <= 4.5)
            System.out.println("Hit");
        else
            System.out.println("Super Hit");

    } 
    
    public static void main(String args[])throws IOException
    {
        movieMagic ob= new movieMagic();
        ob.accept();
        ob.display();
    
    }
    
}