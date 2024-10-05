import java.util.Scanner;

public class SpiralPattern {
    public static void main(String[] args) {
        
        Scanner sc= new Scanner(System.in);

        int n=sc.nextInt();

        int arr[][]=new int[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j]=sc.nextInt();
            }
        }

        int topR=0, bottomR=n-1, leftC=0, rightC=n-1;

        int curr=1;

        while(curr<=n*n){

            for(int i=leftC; i<=rightC && curr<=n*n; i++){
                arr[topR][i] = curr++;
            }
            topR++;

            for(int j=topR; j<=bottomR && curr<=n*n; j++){
                arr[j][rightC] = curr++;
            }
            rightC--;

            for(int i=rightC; i>=leftC && curr<=n*n; i--){
                arr[bottomR][i]= curr++;    
            }
            bottomR--;
            
            for(int j=bottomR; j>=topR && curr<=n*n; j--){
                arr[j][leftC] = curr++;
            }
            leftC++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}
