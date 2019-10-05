import java.util.Scanner;

public class DiamondPattern {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int  row=1, col, space, rowno=1;


        while(rowno<=(2*n-1)){
            col=1;
            space=n-1;
            while(space>=row){
                System.out.print(" ");
                space--;
            }
            while(col<=(2*row-1)){
                System.out.print("*");
                col++;
            }
            if(rowno<n){
                row++;
            }
            else{
                row--;
            }
            rowno++;
            System.out.println();
        }
    }
}