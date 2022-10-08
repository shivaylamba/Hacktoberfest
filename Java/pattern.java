import java.util.*;

public class pattern{
    public static void main(String args[]){
        int n=7;
        for(int i=1; i<=n; i++){
            for (int j=1; j<=i; j++){
                System.out.print(j +" ");
            }
            System.out.println();
        }
    }
}